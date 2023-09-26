#include "Game/Grid.h"

#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"

#include "Utility/Assertion.h"

Grid::~Grid()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Grid::Initialize(int32_t minX, int32_t maxX, int32_t minZ, int32_t maxZ, const glm::vec4& color)
{
	ASSERT(!bIsInitialized_, "already initialize space background object...");

	minX = glm::min<int32_t>(minX, maxX);
	maxX = glm::max<int32_t>(minX, maxX);

	minZ = glm::min<int32_t>(minZ, maxZ);
	maxZ = glm::max<int32_t>(minZ, maxZ);
	
	minPosition_ = glm::vec3(static_cast<float>(minX), 0.0f, static_cast<float>(minZ));
	maxPosition_ = glm::vec3(static_cast<float>(maxX), 0.0f, static_cast<float>(maxZ));

	color_ = color;

	bIsInitialized_ = true;
}

void Grid::Update(float deltaSeconds)
{
}

void Grid::Render()
{
	RenderManager& renderManager = RenderManager::Get().Get();

	float startXPosition = minPosition_.x - 0.5f;
	float startZPosition = minPosition_.z - 0.5f;

	float endXPosition = maxPosition_.x + 0.5f;	
	float endZPosition = maxPosition_.z + 0.5f;

	Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");

	for (float x = startXPosition; x <= endXPosition; x += 1.0f)
	{
		renderManager.RenderLine3D(camera, glm::vec3(x, 0.0f, startZPosition), glm::vec3(x, 0.0f, endZPosition), color_);
	}

	for (float z = startZPosition; z <= endZPosition; z += 1.0f)
	{
		renderManager.RenderLine3D(camera, glm::vec3(startXPosition, 0.0f, z), glm::vec3(endXPosition, 0.0f, z), color_);
	}
}

void Grid::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}