#include "Game/SpaceBackground.h"

#include "GameObject/Camera3D.h"

#include "Manager/ObjectManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/RenderManager.h"

#include "Resource/CubeMap.h"

#include "Utility/CommandLine.h"

SpaceBackground::~SpaceBackground()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void SpaceBackground::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize  space background object...");

	std::string resourcePath = CommandLine::GetValue("Resource");
	cubeMap_ = ResourceManager::Get().AddResource<CubeMap>("CubeMap");
	cubeMap_->Initialize(
		resourcePath + "Skybox\\right.png",
		resourcePath + "Skybox\\left.png",
		resourcePath + "Skybox\\top.png",
		resourcePath + "Skybox\\bottom.png",
		resourcePath + "Skybox\\front.png",
		resourcePath + "Skybox\\back.png"
	);

	bIsInitialized_ = true;
}

void SpaceBackground::Update(float deltaSeconds)
{
	// 스페이스 백그라운드 오브젝트는 업데이트할 요소가 없습니다.
}

void SpaceBackground::Render()
{
	Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");
	RenderManager::Get().RenderCubeMap(camera, cubeMap_);
}

void SpaceBackground::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}