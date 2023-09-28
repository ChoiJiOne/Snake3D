#include "Game/PlayScene.h"
#include "Game/Food.h"
#include "Game/Grid.h"
#include "Game/Snake.h"
#include "Game/SpaceBackground.h"

#include "GameObject/DirectionalLight.h"
#include "GameObject/UIPanel.h"

#include "Manager/ObjectManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/RenderManager.h"

#include "Resource/TTFont.h"

#include "Utility/Assertion.h"

PlayScene::~PlayScene()
{
}

void PlayScene::Entry()
{
	bDetectSwitch_ = false;

	ObjectManager& objectManager = ObjectManager::Get();

	SpaceBackground* background = objectManager.GetGameObject<SpaceBackground>("Background");

	Grid* grid = ObjectManager::Get().GetGameObject<Grid>("Grid");
	if(grid == nullptr)
	{
		grid = ObjectManager::Get().AddGameObject<Grid>("Grid");
		grid->Initialize(-10, 10, -10, 10, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	}

	DirectionalLight* light = ObjectManager::Get().GetGameObject<DirectionalLight>("GlobalLight");
	if(light == nullptr)
	{
		light = ObjectManager::Get().AddGameObject<DirectionalLight>("GlobalLight");
		light->Initialize(
			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.7f, 0.7f, 0.7f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec3(-1.0f, -1.0f, -1.0f)
		);
	}

	Snake* snake = ObjectManager::Get().GetGameObject<Snake>("Snake");
	if(snake == nullptr)
	{
		snake = ObjectManager::Get().AddGameObject<Snake>("Snake");
		snake->Initialize();
	}

	Food* food = ObjectManager::Get().GetGameObject<Food>("Food");
	if(food == nullptr)
	{
		food = ObjectManager::Get().AddGameObject<Food>("Food");
		food->Initialize();
	}

	updateObjects_ = {
		snake,
		food,
	};

	renderObjects_ = {
		background,
		grid,
		snake,
		food,
	};
}

void PlayScene::Leave()
{
	bDetectSwitch_ = false;
}

void PlayScene::Tick(float deltaSeconds)
{
	RenderManager& renderManager = RenderManager::Get();

	for (auto& updateObject : updateObjects_)
	{
		updateObject->Update(deltaSeconds);
	}

	renderManager.BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
	renderManager.SetRenderTargetWindowViewport();
	
	for (auto& renderObject : renderObjects_)
	{
		renderObject->Render();
	}

	Snake* snake = ObjectManager::Get().GetGameObject<Snake>("Snake");
	if (snake->GetAxisDirection() == Snake::EAxisDirection::None)
	{
		bDetectSwitch_ = true;
	}
	
	renderManager.EndFrame();
}
