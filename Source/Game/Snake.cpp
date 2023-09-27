#include "Game/Snake.h"
#include "Game/Grid.h"

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

	bIsInitialized_ = true;
}

void Snake::Update(float deltaSeconds)
{
	static std::map<EKeyCode, EMove> keyMoves =
	{
		{ EKeyCode::KEY_UP,    EMove::Straight },
		{ EKeyCode::KEY_LEFT,  EMove::Left     },
		{ EKeyCode::KEY_RIGHT, EMove::Right    },
	};

	InputManager& inputManager = InputManager::Get();
	for (const auto& keyMove : keyMoves)
	{
		EPressState state = inputManager.GetKeyPressState(keyMove.first);

		if (state == EPressState::Pressed)
		{
			Move(keyMove.second);
		}
	}

	moveAccumulateTime_ += deltaSeconds;
	if (moveAccumulateTime_ > moveStepTime_)
	{
		Move(EMove::Straight);
	}

	if (IsExitGrid())
	{
		currentDirection_ = EAxisDirection::None;
	}
}

void Snake::Render()
{
	Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");
	Light* light = ObjectManager::Get().GetGameObject<Light>("GlobalLight");

	glm::mat4 world = glm::translate(glm::mat4(1.0f), position_);
	RenderManager::Get().RenderModel3D(world, camera, model_, light);
}

void Snake::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}

void Snake::Move(const EMove& move)
{
	if (move != EMove::Straight && move != EMove::None) // 직진이 아니라면...
	{
		switch (currentDirection_)
		{
		case EAxisDirection::PositiveX:
			currentDirection_ = (move == EMove::Left) ? EAxisDirection::NegativeZ : EAxisDirection::PositiveZ;
			break;

		case EAxisDirection::NegativeX:
			currentDirection_ = (move == EMove::Left) ? EAxisDirection::PositiveZ : EAxisDirection::NegativeZ;
			break;

		case EAxisDirection::PositiveZ:
			currentDirection_ = (move == EMove::Left) ? EAxisDirection::PositiveX : EAxisDirection::NegativeX;

			break;

		case EAxisDirection::NegativeZ:
			currentDirection_ = (move == EMove::Left) ? EAxisDirection::NegativeX : EAxisDirection::PositiveX;
			break;
		}
	}

	moveAccumulateTime_ = 0.0f;
	position_ += directionVectors.at(currentDirection_);
}

bool Snake::IsExitGrid()
{
	Grid* grid = ObjectManager::Get().GetGameObject<Grid>("Grid");

	glm::vec3 minPosition = grid->GetMinPosition();
	glm::vec3 maxPosition = grid->GetMaxPosition();

	return (position_.x < minPosition.x || position_.x > maxPosition.x)
		|| (position_.z < minPosition.z || position_.z > maxPosition.z);
}