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

void Snake::Initialize(const glm::vec3& colorRGB)
{
	ASSERT(!bIsInitialized_, "already initialize snake object...");

	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateBox(0.8f, 0.8f, 0.8f, vertices, indices);

	Material* material = ResourceManager::Get().AddResource<Material>("SnakeMaterial");
	material->Initialize(glm::vec3(0.2f, 0.2f, 0.2f), colorRGB, glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);

	Mesh* mesh = ResourceManager::Get().AddResource<Mesh>("SnakeMesh");
	mesh->Initialize(vertices, indices);

	model_ = ResourceManager::Get().AddResource<Model>("SnakeModel");
	model_->Initialize(mesh, material);

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

	if (IsExitGrid())
	{
		currentDirection_ = EAxisDirection::None;
	}

	if (CanEatFood())
	{
		Food* food = ObjectManager::Get().GetGameObject<Food>("Food");
		food->SetActive(false);

		glm::vec3 headPosition = GetHeadPosition();
		bodyPositions_.push_front(headPosition);
	}
}

void Snake::Render()
{
	Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");
	Light* light = ObjectManager::Get().GetGameObject<Light>("GlobalLight");

	glm::mat4 world = glm::mat4(1.0f);
	for (const auto& bodyPosition : bodyPositions_)
	{
		world = glm::translate(glm::mat4(1.0f), bodyPosition);
		RenderManager::Get().RenderModel3D(world, camera, model_, light);
	}
}

void Snake::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
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

	return true;
}

bool Snake::IsExitGrid()
{
	Grid* grid = ObjectManager::Get().GetGameObject<Grid>("Grid");

	glm::vec3 headPosition = GetHeadPosition();
	glm::vec3 minPosition = grid->GetMinPosition();
	glm::vec3 maxPosition = grid->GetMaxPosition();

	return (headPosition.x < minPosition.x || headPosition.x > maxPosition.x)
		|| (headPosition.z < minPosition.z || headPosition.z > maxPosition.z);
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