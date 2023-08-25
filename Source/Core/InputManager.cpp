#include "InputManager.h"

void InputManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize input manager...");

	bIsInitialized_ = true;
}

void InputManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}

LRESULT InputManager::WindowMessageHandler(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam)
{
	switch (messageCode)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(windowHandle, messageCode, wParam, lParam);
}
