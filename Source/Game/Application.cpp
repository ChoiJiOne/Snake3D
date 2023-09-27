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

	GameCamera* camera = ObjectManager::Get().AddGameObject<GameCamera>("Camera");
	camera->Initialize(glm::vec3(0.0f, 15.0f, 25.0f), 45.0f, RenderManager::Get().GetRenderTargetWindowAspectRatio(), 0.1f, 100.0f);

	SpaceBackground* background = ObjectManager::Get().AddGameObject<SpaceBackground>("Background");
	background->Initialize();

	Grid* grid = ObjectManager::Get().AddGameObject<Grid>("Grid");
	grid->Initialize(-10, 10, -10, 10, glm::vec4(0.3f, 0.5f, 1.0f, 1.0f));

	DirectionalLight* light = ObjectManager::Get().AddGameObject<DirectionalLight>("GlobalLight");
	light->Initialize(
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(0.7f, 0.7f, 0.7f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f)
	);

	Snake* snake = ObjectManager::Get().AddGameObject<Snake>("Snake");
	snake->Initialize(glm::vec3(0.1f, 0.5f, 1.0f));

	Food* food = ObjectManager::Get().AddGameObject<Food>("Food");
	food->Initialize();

	std::vector<IGameObject*> updateObjects = {
		camera,
		snake,
		food,
	};
	std::vector<IGameObject*> renderObjects = {
		background,
		grid,
		snake,
		food,
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