#include "Game/GameEngine.h"

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

	uint32_t clientWidth = 0;
	uint32_t clientHeight = 0;
	RenderManager::Get().GetRenderTargetWindow()->GetClientSize(clientWidth, clientHeight);

	while (true)
	{
		InputManager::Get().Tick();
		if (InputManager::Get().ShouldCloseWindow())
		{
			break;
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(clientWidth), static_cast<float>(clientHeight));
		RenderManager::Get().EndFrame(true);
	}

	GameEngine::LaunchShutdown();
	return 0;
}