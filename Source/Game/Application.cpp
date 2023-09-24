#include "GameEngine/GameEngine.h"

#include <glfw3.h>

int32_t main(int32_t argc, char* argv[])
{
	GameEngine::PreInitialize(argc, argv);

	Window window;
	window.Create("Snake3D", 800, 600);

	GameEngine::PostInitialize(&window);

	GameTimer gameTimer;
	std::vector<IGameObject*> updateObjects;
	std::vector<IGameObject*> renderObjects;
	
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