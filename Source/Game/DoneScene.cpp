#include "Game/DoneScene.h"
#include "Game/Food.h"
#include "Game/GameCamera.h"
#include "Game/Grid.h"
#include "Game/Snake.h"
#include "Game/SpaceBackground.h"

#include "GameObject/UIPanel.h"
#include "GameObject/UIButton.h"

#include "Manager/ObjectManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/RenderManager.h"

#include "Resource/TTFont.h"

#include "Utility/Assertion.h"

DoneScene::~DoneScene()
{
}

void DoneScene::Entry()
{
	bDetectSwitch_ = false;

	ObjectManager& objectManager = ObjectManager::Get();

	GameCamera* camera = objectManager.GetGameObject<GameCamera>("Camera");
	SpaceBackground* background = objectManager.GetGameObject<SpaceBackground>("Background");

	UIPanel* gameOverTitle = objectManager.GetGameObject<UIPanel>("GameOverTitle");
	if (gameOverTitle == nullptr)
	{
		TTFont* font64 = ResourceManager::Get().GetResource<TTFont>("Font64");

		gameOverTitle = objectManager.AddGameObject<UIPanel>("GameOverTitle");
		gameOverTitle->Initialize(
			400.0f,
			200.0f,
			glm::vec2(400.0f, 200.0f),
			L"Game Over",
			font64,
			glm::vec3(0.227f, 0.663f, 1.0f),
			glm::vec3(0.094f, 0.122f, 0.165f),
			glm::vec3(0.227f, 0.663f, 1.0f),
			0.9f
		);
	}

	UIButton* continueButton = objectManager.GetGameObject<UIButton>("ContinueButton");
	if (continueButton == nullptr)
	{
		TTFont* font32 = ResourceManager::Get().GetResource<TTFont>("Font32");

		continueButton = objectManager.AddGameObject<UIButton>("ContinueButton");
		continueButton->Initialize(
			150.0f, 50.0f,
			glm::vec2(400.0f, 400.0f),
			L"Continue",
			font32,
			glm::vec3(0.227f, 0.663f, 1.0f),
			glm::vec3(0.118f, 0.180f, 0.286f),
			glm::vec3(0.145f, 0.267f, 0.431f),
			glm::vec3(0.224f, 0.486f, 0.804f),
			glm::vec3(0.227f, 0.663f, 1.0f),
			[&]() {
				bDetectSwitch_ = true;
			},
			0.7f
		);
	}

	UIButton* quitButton = objectManager.GetGameObject<UIButton>("QuitButton");
	if (quitButton == nullptr)
	{
		TTFont* font32 = ResourceManager::Get().GetResource<TTFont>("Font32");

		quitButton = objectManager.AddGameObject<UIButton>("QuitButton");
		quitButton->Initialize(
			150.0f, 50.0f,
			glm::vec2(400.0f, 470.0f),
			L"Quit",
			font32,
			glm::vec3(0.227f, 0.663f, 1.0f),
			glm::vec3(0.118f, 0.180f, 0.286f),
			glm::vec3(0.145f, 0.267f, 0.431f),
			glm::vec3(0.224f, 0.486f, 0.804f),
			glm::vec3(0.227f, 0.663f, 1.0f),
			[&]() {
				quitLoopEvent_();
			},
			0.7f
		);
	}

	Grid* grid = ObjectManager::Get().GetGameObject<Grid>("Grid");
	Snake* snake = ObjectManager::Get().GetGameObject<Snake>("Snake");
	Food* food = ObjectManager::Get().GetGameObject<Food>("Food");

	updateObjects_ = {
		continueButton,
		quitButton,
	};

	object3Ds_ = {
		background,
		grid,
		snake,
		food,
	};

	renderObjects_ = {
		gameOverTitle,
		continueButton,
		quitButton,
	};
}

void DoneScene::Leave()
{
	ObjectManager::Get().RemoveGameObject("Snake");
	ObjectManager::Get().RemoveGameObject("Food");

	bDetectSwitch_ = false;
}

void DoneScene::Tick(float deltaSeconds)
{
	RenderManager& renderManager = RenderManager::Get();

	for (auto& updateObject : updateObjects_)
	{
		updateObject->Update(deltaSeconds);
	}

	renderManager.BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
	renderManager.SetRenderTargetWindowViewport();

	for (auto& object3D : object3Ds_)
	{
		object3D->Render();
	}

	renderManager.GrayScaleEffect();

	for (auto& renderObject : renderObjects_)
	{
		renderObject->Render();
	}

	renderManager.EndFrame();
}