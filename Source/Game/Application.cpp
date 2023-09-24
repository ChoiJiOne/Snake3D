#include "Game/MovableCamera.h"
#include "Game/SpaceBackground.h"

#include "GameEngine/GameEngine.h"

#include <glfw3.h>

int32_t main(int32_t argc, char* argv[])
{
	GameEngine::PreInitialize(argc, argv);

	Window window;
	window.Create("Snake3D", 800, 600);

	GameEngine::PostInitialize(&window);

	MovableCamera* camera = ObjectManager::Get().AddGameObject<MovableCamera>("Camera");
	camera->Initialize(glm::vec3(0.0f, 10.0f, 10.0f), 45.0f, RenderManager::Get().GetRenderTargetWindowAspectRatio(), 0.1f, 100.0f);

	SpaceBackground* background = ObjectManager::Get().AddGameObject<SpaceBackground>("Background");
	background->Initialize("Camera");

	std::vector<IGameObject*> updateObjects = {
		camera,
	};
	std::vector<IGameObject*> renderObjects = {
		background,
	};

	GameTimer gameTimer;
	gameTimer.Reset();

	while (!glfwWindowShouldClose(window.GetWindowPtr()))
	{
		gameTimer.Tick();

		glfwPollEvents();
		if (glfwGetKey(window.GetWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window.GetWindowPtr(), true);
		}

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