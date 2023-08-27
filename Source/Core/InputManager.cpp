#include "InputManager.h"

/**
 * @brief 윈도우 프로시저를 처리하기 위한 포인터 변수입니다.
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

void InputManager::Tick()
{
	MSG msg = {};
	while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);

		if (msg.message == WM_QUIT)
		{
			bShouldCloswWindow_ = true;
		}
	}
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
