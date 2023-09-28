#include "Game/Food.h"
#include "Game/Grid.h"
#include "Game/GameCamera.h"
#include "Game/Snake.h"
#include "Game/SpaceBackground.h"

#include "GameEngine/GameEngine.h"

int32_t main(int32_t argc, char* argv[])
{
	GameEngine::PreInitialize(argc, argv);

	Window window;
	window.Create("Snake3D", 800, 600);

	GameEngine::PostInitialize(&window);

	TTFont* font = ResourceManager::Get().AddResource<TTFont>("Font");
	font->Initialize(CommandLine::GetValue("Resource") + "Font\\SeoulNamsanEB.ttf", 32, 127, 32.0f);

	GameCamera* camera = ObjectManager::Get().AddGameObject<GameCamera>("Camera");
	camera->Initialize(glm::vec3(0.0f, 28.0f, 10.0f), 45.0f, RenderManager::Get().GetRenderTargetWindowAspectRatio(), 0.1f, 100.0f);

	SpaceBackground* background = ObjectManager::Get().AddGameObject<SpaceBackground>("Background");
	background->Initialize();

	std::vector<IGameObject*> updateObjects = {
		camera,
	};
	std::vector<IGameObject*> renderObjects = {
		background,
	};

	GameTimer gameTimer;
	gameTimer.Reset();

	bool bIsDone = false;
	InputManager::Get().BindWindowEventAction(EWindowEvent::Close, [&]() { bIsDone = true; });

	while (!bIsDone)
	{
		gameTimer.Tick();
		InputManager::Get().Tick();

		for (auto& updateObject : updateObjects)
		{
			updateObject->Update(gameTimer.GetDeltaSeconds());
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetRenderTargetWindowViewport();

		for (auto& renderObject : renderObjects)
		{
			renderObject->Render();
		}

		RenderManager::Get().EndFrame();
	}

	GameEngine::Release();
	return 0;
}