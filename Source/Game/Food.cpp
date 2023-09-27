#include "Game/Food.h"
#include "Game/Grid.h"
#include "Game/Snake.h"

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

Food::~Food()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Food::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize food object...");

	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateSphere(1.0f, 50, 50, vertices, indices);

	Mesh* mesh = ResourceManager::Get().AddResource<Mesh>("FoodMesh");
	mesh->Initialize(vertices, indices);



	
	bIsInitialized_ = true;
}

void Food::Update(float deltaSeconds)
{
}

void Food::Render()
{
}

void Food::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}