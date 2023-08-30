#include "Snake.h"
#include "MainCamera.h"

#include "Manager/InputManager.h"
#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "Resource/ColorMaterial.h"
#include "Resource/Model.h"
#include "Resource/Mesh.h"

#include "Utils/Camera3D.h"
#include "Utils/GameTimer.h"
#include "Utils/GeometryGenerator.h"
#include "Utils/MathHelper.h"

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

	camera_ = ObjectManager::Get().GetGameObject<MainCamera>("MainCamera")->GetCamera3D();

	cubeModel_ = CreateCubeModel(Vector4f(0.0f, 0.0f, 1.0f, 1.0f));

	position_ = Vector3f(0.0f, 0.5f, 0.0f);
	
	bIsInitialized_ = true;
}

void Snake::Update(float deltaSeconds)
{
	if (InputManager::Get().GetKeyPressState(EVirtualKey::CODE_LEFT) == EPressState::PRESSED)
	{
		position_.x -= 1;
	}	
	
	if (InputManager::Get().GetKeyPressState(EVirtualKey::CODE_RIGHT) == EPressState::PRESSED)
	{
		position_.x += 1;
	}	
	
	if (InputManager::Get().GetKeyPressState(EVirtualKey::CODE_UP) == EPressState::PRESSED)
	{
		position_.z += 1;
	}	
	
	if (InputManager::Get().GetKeyPressState(EVirtualKey::CODE_DOWN) == EPressState::PRESSED)
	{
		position_.z -= 1;
	}
}

void Snake::Render()
{
	RenderManager::Get().DrawModel3D(MathHelper::TranslationMatrix(position_.x, position_.y, position_.z), camera_, cubeModel_);
}

void Snake::Release()
{
	ASSERT(bIsInitialized_, "you have to initialize snake object...");

	bIsInitialized_ = false;
}

Model* Snake::CreateCubeModel(const Vector4f& color)
{
	std::vector<VertexPositionColor> vertices;
	std::vector<uint32_t> indices;
	float xsize = 1.0f;
	float ysize = 1.0f;
	float zsize = 1.0f;
	GeometryGenerator::CreateBox(xsize, ysize, zsize, color, vertices, indices);

	Model* model = ResourceManager::Get().AddResource<Model>("SnakeCube");
	model->SetMesh(vertices, indices);

	return model;
}