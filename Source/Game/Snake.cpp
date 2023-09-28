#include "Game/Snake.h"
#include "Game/Grid.h"
#include "Game/Food.h"

#include "Manager/InputManager.h"
#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "GameObject/Light.h"

#include "Resource/Material.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"
#include "Resource/Sound.h"

#include "Utility/GeometryGenerator.h"
#include "Utility/Random.h"

#include <glm/gtc/matrix_transform.hpp>

Snake::~Snake()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Snake::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize snake object...");

	bodyColors_ = 
	{
		EColorType::Red,
		EColorType::Orange,
		EColorType::Yellow,
		EColorType::Green,
		EColorType::Blue,
		EColorType::Indigo,
		EColorType::Violet,
	};

	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateBox(0.7f, 0.7f, 0.7f, vertices, indices);

	Mesh* mesh = ResourceManager::Get().AddResource<Mesh>("SnakeMesh");
	mesh->Initialize(vertices, indices);

	std::map<std::string, std::pair<EColorType, glm::vec3>> materials =
	{
		{ "Red",    { EColorType::Red,     glm::vec3(1.0f, 0.0f, 0.0f) }},
		{ "Orange", { EColorType::Orange,  glm::vec3(1.0f, 0.5f, 0.0f) }},
		{ "Yellow", { EColorType::Yellow,  glm::vec3(1.0f, 1.0f, 0.0f) }},
		{ "Green",  { EColorType::Green,   glm::vec3(0.0f, 1.0f, 0.0f) }},
		{ "Blue",   { EColorType::Blue,    glm::vec3(0.0f, 0.0f, 1.0f) }},
		{ "Indigo", { EColorType::Indigo,  glm::vec3(0.0f, 0.0f, 0.5f) }},
		{ "Violet", { EColorType::Violet,  glm::vec3(0.5f, 0.0f, 0.5f) }},
	};

	for (const auto& material : materials)
	{
		Material* materialPtr = ResourceManager::Get().AddResource<Material>(material.first + "Material");
		materialPtr->Initialize(glm::vec3(0.2f, 0.2f, 0.2f), material.second.second, glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);

		Model* model = ResourceManager::Get().AddResource<Model>(material.first);
		model->Initialize(mesh, materialPtr);

		colorToModels_.insert({ material.second.first, model });
	}

	directionVectors = 
	{
		{ EAxisDirection::None,      glm::vec3(+0.0f, +0.0f, +0.0f) },
		{ EAxisDirection::PositiveX, glm::vec3(+1.0f, +0.0f, +0.0f) },
		{ EAxisDirection::NegativeX, glm::vec3(-1.0f, +0.0f, +0.0f) },
		{ EAxisDirection::PositiveZ, glm::vec3(+0.0f, +0.0f, +1.0f) },
		{ EAxisDirection::NegativeZ, glm::vec3(+0.0f, +0.0f, -1.0f) },
	};

	std::array<EAxisDirection, 4> directions = 
	{
		EAxisDirection::PositiveX,
		EAxisDirection::NegativeX,
		EAxisDirection::PositiveZ,
		EAxisDirection::NegativeZ,
	};
	currentDirection_ = directions[Random::GenerateRandomInt(0, static_cast<int32_t>(directions.size()) - 1)];

	glm::vec3 headPosition = glm::vec3(0.0f, 0.5f, 0.0f);
	for (int32_t bodyIndex = 0; bodyIndex <= 3; ++bodyIndex)
	{
		bodyPositions_.push_back(headPosition - static_cast<float>(bodyIndex) * directionVectors[currentDirection_]);
	}

	moveStepTime_ = maxMoveStepTime_;

	bIsInitialized_ = true;
}

void Snake::Update(float deltaSeconds)
{
	static std::map<EKeyCode, EAxisDirection> keyMoves =
	{
		{ EKeyCode::KEY_UP,    EAxisDirection::NegativeZ },
		{ EKeyCode::KEY_DOWN,  EAxisDirection::PositiveZ },
		{ EKeyCode::KEY_LEFT,  EAxisDirection::NegativeX },
		{ EKeyCode::KEY_RIGHT, EAxisDirection::PositiveX },
	};

	InputManager& inputManager = InputManager::Get();
	for (const auto& keyMove : keyMoves)
	{
		EPressState state = inputManager.GetKeyPressState(keyMove.first);

		if (state == EPressState::Pressed && CanMove(keyMove.second))
		{
			currentDirection_ = keyMove.second;
			Move();
		}
	}

	moveAccumulateTime_ += deltaSeconds;
	if (moveAccumulateTime_ > moveStepTime_)
	{
		if (CanMove(currentDirection_))
		{
			Move();
		}
		else
		{
			currentDirection_ = EAxisDirection::None;
		}
	}

	if (CanEatFood())
	{
		Food* food = ObjectManager::Get().GetGameObject<Food>("Food");
		food->SetActive(false);

		glm::vec3 headPosition = GetHeadPosition();
		bodyPositions_.push_front(headPosition);

		numOfEatingFood_++;
		if (numOfEatingFood_ >= maxNumOfEatingFood_)
		{
			numOfEatingFood_ = 0;
			moveStepTime_ -= 0.1f;
			moveStepTime_ = glm::clamp<float>(moveStepTime_, minMoveStepTime_, maxMoveStepTime_);

			Sound* levelup = ResourceManager::Get().GetResource<Sound>("Levelup");

			levelup->Reset();
			levelup->SetVolume(0.5f);
			levelup->Play();
		}

		Sound* collision = ResourceManager::Get().GetResource<Sound>("Collision");

		collision->Reset();
		collision->SetVolume(0.5f);
		collision->Play();
	}
}

void Snake::Render()
{
	Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");
	Light* light = ObjectManager::Get().GetGameObject<Light>("GlobalLight");

	int32_t bodyColorIndex = 0;
	glm::mat4 world = glm::mat4(1.0f);
	for (const auto& bodyPosition : bodyPositions_)
	{
		EColorType colorType = bodyColors_[bodyColorIndex];
		bodyColorIndex = (bodyColorIndex + 1) % bodyColors_.size();

		world = glm::translate(glm::mat4(1.0f), bodyPosition);
		RenderManager::Get().RenderModel3D(world, camera, colorToModels_.at(colorType), light);
	}
}

void Snake::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	std::vector<std::string> resources =
	{
		"SnakeMesh",
		"RedMaterial",
		"OrangeMaterial",
		"YellowMaterial",
		"GreenMaterial",
		"BlueMaterial",
		"IndigoMaterial",
		"VioletMaterial",
		"Red",
		"Orange",
		"Yellow",
		"Green",
		"Blue",
		"Indigo",
		"Violet",
	};

	for (const auto& resource : resources)
	{
		ResourceManager::Get().RemoveResource(resource);
	}

	bIsInitialized_ = false;
}

glm::vec3 Snake::GetHeadPosition() const
{
	return bodyPositions_.front();
}

void Snake::Move()
{
	moveAccumulateTime_ = 0.0f;

	std::list<glm::vec3>::iterator tail = --bodyPositions_.end();
	bodyPositions_.erase(tail);

	glm::vec3 headPosition = GetHeadPosition();
	headPosition += directionVectors.at(currentDirection_);
	bodyPositions_.push_front(headPosition);
}

bool Snake::CanMove(const EAxisDirection& axisDirection)
{
	glm::vec3 headPosition = GetHeadPosition();
	headPosition += directionVectors.at(axisDirection);

	std::list<glm::vec3>::iterator tail = --bodyPositions_.end();
	for (std::list<glm::vec3>::iterator iter = bodyPositions_.begin(); iter != tail; ++iter)
	{
		if (iter->x == headPosition.x && iter->z == headPosition.z)
		{
			return false;
		}
	}

	Grid* grid = ObjectManager::Get().GetGameObject<Grid>("Grid");

	headPosition -= directionVectors.at(axisDirection);
	glm::vec3 minPosition = grid->GetMinPosition();
	glm::vec3 maxPosition = grid->GetMaxPosition();

	return (minPosition.x <= headPosition.x && headPosition.x <= maxPosition.x)
		&& (minPosition.z <= headPosition.z && headPosition.z <= maxPosition.z);
}

bool Snake::CanEatFood()
{
	Food* food = ObjectManager::Get().GetGameObject<Food>("Food");
	if (!food->IsActive())
	{
		return false;
	}

	glm::vec3 foodPosition = food->GetPosition();
	glm::vec3 headPosition = GetHeadPosition();

	return (headPosition.x == foodPosition.x) && (headPosition.z == foodPosition.z);
}