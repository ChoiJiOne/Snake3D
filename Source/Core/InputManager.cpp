#include "InputManager.h"

/**
 * @brief ������ ���ν����� ó���ϱ� ���� ������ �����Դϴ�.
 */
static InputManager* inputManager = nullptr;

LRESULT InputManager::WindowMessageHandler(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam)
{
	return inputManager->ProcessWindowMessage(windowHandle, messageCode, wParam, lParam);
}

void InputManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize input manager...");

	inputManager = this;
	bIsInitialized_ = true;
}

void InputManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	inputManager = nullptr;
	bIsInitialized_ = false;
}

LRESULT InputManager::ProcessWindowMessage(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam)
{
	switch (messageCode)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(windowHandle, messageCode, wParam, lParam);
}
