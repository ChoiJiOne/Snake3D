#include "InputManager.h"

/**
 * @brief 윈도우 프로시저를 처리하기 위한 포인터 변수입니다.
 */
static InputManager* inputManager = nullptr;

EPressState InputManager::GetKeyPressState(const EVirtualKey& virtualKey) const
{
	EPressState PressState = EPressState::NONE;

	if (IsPressKey(prevKeyboardState_, virtualKey))
	{
		if (IsPressKey(currKeyboardState_, virtualKey))
		{
			PressState = EPressState::HELD;
		}
		else
		{
			PressState = EPressState::RELEASED;
		}
	}
	else
	{
		if (IsPressKey(currKeyboardState_, virtualKey))
		{
			PressState = EPressState::PRESSED;
		}
		else
		{
			PressState = EPressState::NONE;
		}
	}

	return PressState;
}

LRESULT InputManager::WindowMessageHandler(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam)
{
	return inputManager->ProcessWindowMessage(windowHandle, messageCode, wParam, lParam);
}

void InputManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize input manager...");

	prevKeyboardState_ = std::vector<uint8_t>(KEYBOARD_BUFFER_SIZE);
	currKeyboardState_ = std::vector<uint8_t>(KEYBOARD_BUFFER_SIZE);

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

	std::copy(currKeyboardState_.begin(), currKeyboardState_.end(), prevKeyboardState_.begin());
	ASSERT(GetKeyboardState(&currKeyboardState_[0]), "failed to update current keyboard state...");
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

bool InputManager::IsPressKey(const std::vector<uint8_t>& keyboardState, const EVirtualKey& virtualKey) const
{
	return (keyboardState[static_cast<int32_t>(virtualKey)] & 0x80);
}