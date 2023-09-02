#include "Game/MainCamera.h"
#include "Game/Feed.h"
#include "Game/Grid.h"
#include "Game/Snake.h"

#include "Engine/GameEngine.h"

/**
 * @brief Windows ���ø����̼��� ��Ʈ�� ����Ʈ�Դϴ�.
 *
 * @param hInstance �ν��Ͻ��� ���� �ڵ� �̰ų� ��⿡ ���� �ڵ��Դϴ�
 * @param hPrevInstance 16��Ʈ Windows���� ���Ǿ��� ���Դϴ�.
 * @param cmdLine �����ڵ� ���ڿ��� ���Ե� ����� �μ��Դϴ�.
 * @param showCmd �⺻ ���ø����̼� â�� �ּ�ȭ, �ִ�ȭ �Ǵ� ���������� ǥ�õǴ��� ���θ� ��Ÿ���� �÷����Դϴ�.
 *
 * @see https://learn.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point
 */
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR cmdLine, _In_ int showCmd)
{
	GameEngine::LaunchStartup();

	MainCamera* mainCamera = ObjectManager::Get().AddGameObject<MainCamera>("MainCamera");
	mainCamera->SetUpdateOrder(0);
	mainCamera->SetRenderOrder(0);
	mainCamera->Initialize(Vector3f(0.0f, 15.0f, -25.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 1.0f, 0.0f));

	Grid* grid = ObjectManager::Get().AddGameObject<Grid>("Grid");
	grid->SetUpdateOrder(2);
	grid->SetRenderOrder(1);
	grid->Initialize(-10, 10, -10, 10);

	Snake* snake = ObjectManager::Get().AddGameObject<Snake>("Snake");
	snake->SetUpdateOrder(3);
	snake->SetRenderOrder(2);
	snake->Initialize();

	Feed* feed = ObjectManager::Get().AddGameObject<Feed>("Feed");
	feed->SetUpdateOrder(4);
	feed->SetRenderOrder(3);
	feed->Initialize();

	GameTimer gameTimer;
	gameTimer.Reset();

	while (true)
	{
		gameTimer.Tick();
		InputManager::Get().Tick();
		if (InputManager::Get().ShouldCloseWindow())
		{
			break;
		}

		ObjectManager::Get().UpdateAllObjects(gameTimer.GetDeltaSeconds());

		RenderManager::Get().BeginFrame(0.427f, 0.988f, 0.941f, 1.0f);
		RenderManager::Get().SetWindowViewport();

		ObjectManager::Get().RenderAllObjects();

		RenderManager::Get().EndFrame(true);
	}

	GameEngine::LaunchShutdown();
	return 0;
}