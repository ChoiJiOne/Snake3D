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

void InputManager::BindWindowEventAction(const EWindowEvent& windowEvent, const std::function<void()>& eventAction)
{
	ASSERT((windowEventActions_.find(windowEvent) == windowEventActions_.end()), "alreay exist window event action...");
	windowEventActions_.insert({ windowEvent, eventAction });
}

void InputManager::UnbindWindowEventAction(const EWindowEvent& windowEvent)
{
	if (windowEventActions_.find(windowEvent) != windowEventActions_.end())
	{
		windowEventActions_.erase(windowEvent);
	}
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
	windowEventActions_ = std::unordered_map<EWindowEvent, std::function<void()>>();

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

	if (!bShouldCloswWindow_)
	{
		std::copy(currKeyboardState_.begin(), currKeyboardState_.end(), prevKeyboardState_.begin());
		ASSERT(GetKeyboardState(&currKeyboardState_[0]), "failed to update current keyboard state...");

		prevScreenMousePosition_ = currScreenMousePosition_;
		prevWindowMousePosition_ = currWindowMousePosition_;

		currScreenMousePosition_ = GetCurrentScreenMousePosition();
		currWindowMousePosition_ = GetCurrentWindowMousePosition();
	}
}

LRESULT InputManager::ProcessWindowMessage(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam)
{
	EWindowEvent windowEvent = EWindowEvent::NONE;

	switch (messageCode)
	{
	case WM_CREATE:
		WindowHandle_ = windowHandle;
		break;

	case WM_ACTIVATE:
		windowEvent = (LOWORD(wParam) == WA_ACTIVE) ? EWindowEvent::ACTIVE : EWindowEvent::INACTIVE;
		break;

	case WM_MOVE:
		windowEvent = EWindowEvent::MOVE;
		break;

	case WM_CLOSE:
		windowEvent = EWindowEvent::CLOSE;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	if (windowEventActions_.find(windowEvent) != windowEventActions_.end())
	{
		windowEventActions_[windowEvent]();
	}

	return DefWindowProcW(windowHandle, messageCode, wParam, lParam);
}

bool InputManager::IsPressKey(const std::vector<uint8_t>& keyboardState, const EVirtualKey& virtualKey) const
{
	return (keyboardState[static_cast<int32_t>(virtualKey)] & 0x80);
}

Vector2i InputManager::GetCurrentScreenMousePosition()
{
	POINT mousePosition;
	ASSERT(GetCursorPos(&mousePosition), "failed to get current screen mouse position...");

	return Vector2i(static_cast<int32_t>(mousePosition.x), static_cast<int32_t>(mousePosition.y));
}

Vector2i InputManager::GetCurrentWindowMousePosition()
{
	POINT mousePosition;

	ASSERT(GetCursorPos(&mousePosition), "failed to get current screen mouse position...");
	ASSERT(ScreenToClient(WindowHandle_, &mousePosition), "failed to convert mouse position screen to client...");

	return Vector2i(static_cast<int32_t>(mousePosition.x), static_cast<int32_t>(mousePosition.y));
}