#include "Game/Feed.h"
#include "Game/MainCamera.h"

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

Feed::~Feed()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Feed::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize feed object...");

	camera_ = ObjectManager::Get().GetGameObject<MainCamera>("MainCamera")->GetCamera3D();

	cubeModel_ = CreateCubeModel(Vector4f(0.0f, 1.0f, 0.0f, 1.0f));

	position_ = Vector3f(8.0f, 0.5f, 6.0f);

	bIsInitialized_ = true;
}

void Feed::Update(float deltaSeconds)
{
}

void Feed::Render()
{
	RenderManager::Get().DrawModel3D(MathHelper::TranslationMatrix(position_.x, position_.y, position_.z), camera_, cubeModel_);
}

void Feed::Release()
{
	ASSERT(bIsInitialized_, "you have to initialize feed object...");

	bIsInitialized_ = false;
}

Model* Feed::CreateCubeModel(const Vector4f& color)
{
	std::vector<VertexPositionColor> vertices;
	std::vector<uint32_t> indices;
	float xsize = 1.0f;
	float ysize = 1.0f;
	float zsize = 1.0f;
	GeometryGenerator::CreateBox(xsize, ysize, zsize, color, vertices, indices);

	Model* model = ResourceManager::Get().AddResource<Model>("FeedCube");
	model->SetMesh(vertices, indices);

	return model;
}