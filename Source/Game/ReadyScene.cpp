#include "Game/ReadyScene.h"
#include "Game/GameCamera.h"
#include "Game/SpaceBackground.h"

#include "GameObject/UIPanel.h"
#include "GameObject/UIButton.h"

#include "Manager/ObjectManager.h"
#include "Manager/ResourceManager.h"
#include "Manager/RenderManager.h"

#include "Resource/TTFont.h"
#include "Resource/Sound.h"

#include "Utility/Assertion.h"

ReadyScene::~ReadyScene()
{
}

void ReadyScene::Entry()
{
	bDetectSwitch_ = false;

	ObjectManager& objectManager = ObjectManager::Get();

	GameCamera* camera = objectManager.GetGameObject<GameCamera>("Camera");
	if (camera == nullptr)
	{
		camera = objectManager.AddGameObject<GameCamera>("Camera");
		camera->Initialize(glm::vec3(0.0f, 28.0f, 10.0f), 45.0f, RenderManager::Get().GetRenderTargetWindowAspectRatio(), 0.1f, 100.0f);
	}

	SpaceBackground* background = objectManager.GetGameObject<SpaceBackground>("Background");
	if (background == nullptr)
	{
		background = objectManager.AddGameObject<SpaceBackground>("Background");
		background->Initialize();
	}

	UIPanel* mainTitle = objectManager.GetGameObject<UIPanel>("MainTitle");
	if (mainTitle == nullptr)
	{
		TTFont* font64 = ResourceManager::Get().GetResource<TTFont>("Font64");

		mainTitle = objectManager.AddGameObject<UIPanel>("MainTitle");
		mainTitle->Initialize(
			400.0f,
			200.0f,
			glm::vec2(400.0f, 200.0f),
			L"Snake3D",
			font64,
			glm::vec3(0.227f, 0.663f, 1.0f),
			glm::vec3(0.094f, 0.122f, 0.165f),
			glm::vec3(0.227f, 0.663f, 1.0f),
			0.7f
		);
	}

	UIButton* startButton = objectManager.GetGameObject<UIButton>("StartButton");
	if (startButton == nullptr)
	{
		TTFont* font32 = ResourceManager::Get().GetResource<TTFont>("Font32");

		startButton = objectManager.AddGameObject<UIButton>("StartButton");
		startButton->Initialize(
			150.0f, 50.0f,
			glm::vec2(400.0f, 400.0f),
			L"Start",
			font32,
			glm::vec3(0.227f, 0.663f, 1.0f),
			glm::vec3(0.118f, 0.180f, 0.286f),
			glm::vec3(0.145f, 0.267f, 0.431f),
			glm::vec3(0.224f, 0.486f, 0.804f),
			glm::vec3(0.227f, 0.663f, 1.0f),
			[&]() { 
				bDetectSwitch_ = true;

				Sound* click = ResourceManager::Get().GetResource<Sound>("Click");
				click->SetVolume(0.5f);
				click->Play();
			},
			0.5f
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
			0.5f
		);
	}

	updateObjects_ = {
		startButton,
		quitButton,
	};

	renderObjects_ = {
		mainTitle,
		startButton,
		quitButton,
	};

	background_ = background;
}

void ReadyScene::Leave()
{
	bDetectSwitch_ = false;
}

void ReadyScene::Tick(float deltaSeconds)
{
	RenderManager& renderManager = RenderManager::Get();

	for (auto& updateObject : updateObjects_)
	{
		updateObject->Update(deltaSeconds);
	}

	renderManager.BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
	renderManager.SetRenderTargetWindowViewport();

	background_->Render();
	renderManager.BlurEffect(300.0f);

	for (auto& renderObject : renderObjects_)
	{
		renderObject->Render();
	}

	renderManager.EndFrame();
}