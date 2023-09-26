#include "Game/Snake.h"

#include "Manager/InputManager.h"
#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "GameObject/SpotLight.h"

#include "Resource/Material.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"

#include "Utility/GeometryGenerator.h"

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

	bIsInitialized_ = true;
}

void Snake::Update(float deltaSeconds)
{
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