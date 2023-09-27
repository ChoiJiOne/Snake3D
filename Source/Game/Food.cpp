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

#include <list>

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

	bIsActive_ = true;
	currentType_ = GetRandomFoodType();
	BatchRandomPosition();

	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateSphere(0.5f, 50, 50, vertices, indices);

	Mesh* mesh = ResourceManager::Get().AddResource<Mesh>("FoodMesh");
	mesh->Initialize(vertices, indices);

	std::map<std::string, std::pair<EType, glm::vec3>> materials = 
	{
		{ "Gray",    { EType::Gray,     glm::vec3(0.3f, 0.3f, 0.3f) }},
		{ "BrightRed",     { EType::Red,      glm::vec3(1.0f, 0.2f, 0.2f) }},
		{ "BrightGreen",   { EType::Green,    glm::vec3(0.2f, 1.0f, 0.2f) }},
		{ "BrightBlue",    { EType::Blue,     glm::vec3(0.2f, 0.2f, 1.0f) }},
		{ "BrightYellow",  { EType::Yellow,   glm::vec3(1.0f, 1.0f, 0.2f) }},
		{ "BrightMagenta", { EType::Magenta,  glm::vec3(1.0f, 0.2f, 1.0f) }},
		{ "BrightCyan",    { EType::Cyan,     glm::vec3(0.2f, 1.0f, 1.0f) }},
	};

	for (const auto& material : materials)
	{
		Material* materialPtr = ResourceManager::Get().AddResource<Material>(material.first + "Material");
		materialPtr->Initialize(glm::vec3(0.2f, 0.2f, 0.2f), material.second.second, glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);

		Model* model = ResourceManager::Get().AddResource<Model>(material.first);
		model->Initialize(mesh, materialPtr);

		typeToModels_.insert( { material.second.first, model } );
	}
	
	bIsInitialized_ = true;
}

void Food::Update(float deltaSeconds)
{
	if(bIsActive_)
	{ 
		accumulateTime_ += deltaSeconds;

		position_.y = (0.2f * std::abs(sinf(2.0f * accumulateTime_)) + 0.5f);
	}
	else
	{
		responeAccumulateTime_ += deltaSeconds;

		if (responeAccumulateTime_ > responeStepTime_)
		{
			responeAccumulateTime_ = 0.0f;

			bIsActive_ = true;
			currentType_ = GetRandomFoodType();
			BatchRandomPosition();
		}
	}
}

void Food::Render()
{
	Model* model = typeToModels_.at(currentType_);

	if (bIsActive_)
	{
		Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");
		Light* light = ObjectManager::Get().GetGameObject<Light>("GlobalLight");

		glm::mat4 world = glm::translate(glm::mat4(1.0f), position_);
		RenderManager::Get().RenderModel3D(world, camera, model, light);
	}
	else
	{
		Material* material = model->GetMaterial();
		glm::vec3 diffuseColor = material->GetDiffuse();

		RenderManager::Get().ColorEffect(diffuseColor.r, diffuseColor.g, diffuseColor.b);
	}
}

void Food::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}

Food::EType Food::GetRandomFoodType() const
{
	static std::array<EType, 7> types =
	{
		EType::Gray,
		EType::Red,
		EType::Green,
		EType::Blue,
		EType::Yellow,
		EType::Magenta,
		EType::Cyan,
	};

	return types[Random::GenerateRandomInt(0, static_cast<int32_t>(types.size()) - 1)];
}

void Food::BatchRandomPosition()
{
	bool bCanBatch = false;

	Grid* grid = ObjectManager::Get().GetGameObject<Grid>("Grid");
	Snake* snake = ObjectManager::Get().GetGameObject<Snake>("Snake");

	glm::vec3 minPosition = grid->GetMinPosition();
	glm::vec3 maxPosition = grid->GetMaxPosition();
	const std::list<glm::vec3>& bodyPositions = snake->GetBodyPositions();

	while (!bCanBatch)
	{
		position_ = glm::vec3(
			static_cast<float>(Random::GenerateRandomInt(static_cast<int32_t>(minPosition.x), static_cast<int32_t>(maxPosition.x))),
			0.5f,
			static_cast<float>(Random::GenerateRandomInt(static_cast<int32_t>(minPosition.z), static_cast<int32_t>(maxPosition.z)))
		);

		if ((position_.x < minPosition.x || position_.x > maxPosition.x) || (position_.z < minPosition.z || position_.z > maxPosition.z))
		{
			continue;
		}

		for (const auto& bodyPosition : bodyPositions)
		{
			if ((position_.x != bodyPosition.x) && (position_.z != bodyPosition.z))
			{
				bCanBatch = true;
			}
		}
	}
}