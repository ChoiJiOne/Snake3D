#include "Game/DoneScene.h"
#include "Game/Food.h"
#include "Game/GameCamera.h"
#include "Game/Grid.h"
#include "Game/PlayScene.h"
#include "Game/ReadyScene.h"
#include "Game/Snake.h"
#include "Game/SpaceBackground.h"

#include "GameEngine/GameEngine.h"

int32_t main(int32_t argc, char* argv[])
{
	GameEngine::PreInitialize(argc, argv);

	Window window;
	window.Create("Snake3D", 800, 600);

	GameEngine::PostInitialize(&window);

	std::string resourcePath = CommandLine::GetValue("Resource");

	TTFont* font32 = ResourceManager::Get().AddResource<TTFont>("Font32");
	font32->Initialize(resourcePath + "Font\\SeoulNamsanEB.ttf", 32, 127, 32.0f);

	TTFont* font64 = ResourceManager::Get().AddResource<TTFont>("Font64");
	font64->Initialize(resourcePath + "Font\\SeoulNamsanEB.ttf", 32, 127, 64.0f);

	Sound* click = ResourceManager::Get().AddResource<Sound>("Click");
	click->Initialize(resourcePath + "Audio\\Click.mp3");

	Sound* collision = ResourceManager::Get().AddResource<Sound>("Collision");
	collision->Initialize(resourcePath + "Audio\\Collision.mp3");	
	
	Sound* levelup = ResourceManager::Get().AddResource<Sound>("Levelup");
	levelup->Initialize(resourcePath + "Audio\\Levelup.mp3");

	std::unique_ptr<ReadyScene> readyScene = std::make_unique<ReadyScene>();
	std::unique_ptr<PlayScene> playScene = std::make_unique<PlayScene>();
	std::unique_ptr<DoneScene> doneScene = std::make_unique<DoneScene>();

	readyScene->SetNextScene(playScene.get());
	playScene->SetNextScene(doneScene.get());
	doneScene->SetNextScene(readyScene.get());

	IScene* currentScene = readyScene.get();

	GameTimer gameTimer;
	gameTimer.Reset();

	bool bIsDone = false;
	auto quitLoopEvent = [&]() { bIsDone = true; };

	InputManager::Get().BindWindowEventAction(EWindowEvent::Close, quitLoopEvent);
	readyScene->SetQuitLoopEvent(quitLoopEvent);
	doneScene->SetQuitLoopEvent(quitLoopEvent);

	currentScene->Entry();
	while (!bIsDone)
	{
		gameTimer.Tick();
		InputManager::Get().Tick();

		currentScene->Tick(gameTimer.GetDeltaSeconds());

		if (currentScene->IsDetectSwitch())
		{
			IScene* nextScene = currentScene->GetNextScene();
			currentScene->Leave();
			nextScene->Entry();

			currentScene = nextScene;
		}
	}

	GameEngine::Release();
	return 0;
}