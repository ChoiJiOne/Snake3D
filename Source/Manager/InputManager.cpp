#include "Manager/InputManager.h"

#include "Utility/Assertion.h"
#include "Utility/Window.h"

#include <glfw3.h>

std::array<EKeyCode, InputManager::NUM_OF_KEY_CODES> InputManager::KEY_CODES =
{
	EKeyCode::KEY_UNKNOWN,
	EKeyCode::KEY_SPACE,
	EKeyCode::KEY_APOSTROPHE,
	EKeyCode::KEY_COMMA,
	EKeyCode::KEY_MINUS,
	EKeyCode::KEY_PERIOD,
	EKeyCode::KEY_SLASH,
	EKeyCode::KEY_0,
	EKeyCode::KEY_1,
	EKeyCode::KEY_2,
	EKeyCode::KEY_3,
	EKeyCode::KEY_4,
	EKeyCode::KEY_5,
	EKeyCode::KEY_6,
	EKeyCode::KEY_7,
	EKeyCode::KEY_8,
	EKeyCode::KEY_9,
	EKeyCode::KEY_SEMICOLON,
	EKeyCode::KEY_EQUAL,
	EKeyCode::KEY_A,
	EKeyCode::KEY_B,
	EKeyCode::KEY_C,
	EKeyCode::KEY_D,
	EKeyCode::KEY_E,
	EKeyCode::KEY_F,
	EKeyCode::KEY_G,
	EKeyCode::KEY_H,
	EKeyCode::KEY_I,
	EKeyCode::KEY_J,
	EKeyCode::KEY_K,
	EKeyCode::KEY_L,
	EKeyCode::KEY_M,
	EKeyCode::KEY_N,
	EKeyCode::KEY_O,
	EKeyCode::KEY_P,
	EKeyCode::KEY_Q,
	EKeyCode::KEY_R,
	EKeyCode::KEY_S,
	EKeyCode::KEY_T,
	EKeyCode::KEY_U,
	EKeyCode::KEY_V,
	EKeyCode::KEY_W,
	EKeyCode::KEY_X,
	EKeyCode::KEY_Y,
	EKeyCode::KEY_Z,
	EKeyCode::KEY_LEFT_BRACKET,
	EKeyCode::KEY_BACKSLASH,
	EKeyCode::KEY_RIGHT_BRACKET,
	EKeyCode::KEY_GRAVE_ACCENT,
	EKeyCode::KEY_WORLD_1,
	EKeyCode::KEY_WORLD_2,
	EKeyCode::KEY_ESCAPE,
	EKeyCode::KEY_ENTER,
	EKeyCode::KEY_TAB,
	EKeyCode::KEY_BACKSPACE,
	EKeyCode::KEY_INSERT,
	EKeyCode::KEY_DELETE,
	EKeyCode::KEY_RIGHT,
	EKeyCode::KEY_LEFT,
	EKeyCode::KEY_DOWN,
	EKeyCode::KEY_UP,
	EKeyCode::KEY_PAGE_UP,
	EKeyCode::KEY_PAGE_DOWN,
	EKeyCode::KEY_HOME,
	EKeyCode::KEY_END,
	EKeyCode::KEY_CAPS_LOCK,
	EKeyCode::KEY_SCROLL_LOCK,
	EKeyCode::KEY_NUM_LOCK,
	EKeyCode::KEY_PRINT_SCREEN,
	EKeyCode::KEY_PAUSE,
	EKeyCode::KEY_F1,
	EKeyCode::KEY_F2,
	EKeyCode::KEY_F3,
	EKeyCode::KEY_F4,
	EKeyCode::KEY_F5,
	EKeyCode::KEY_F6,
	EKeyCode::KEY_F7,
	EKeyCode::KEY_F8,
	EKeyCode::KEY_F9,
	EKeyCode::KEY_F10,
	EKeyCode::KEY_F11,
	EKeyCode::KEY_F12,
	EKeyCode::KEY_F13,
	EKeyCode::KEY_F14,
	EKeyCode::KEY_F15,
	EKeyCode::KEY_F16,
	EKeyCode::KEY_F17,
	EKeyCode::KEY_F18,
	EKeyCode::KEY_F19,
	EKeyCode::KEY_F20,
	EKeyCode::KEY_F21,
	EKeyCode::KEY_F22,
	EKeyCode::KEY_F23,
	EKeyCode::KEY_F24,
	EKeyCode::KEY_F25,
	EKeyCode::KEY_KP_0,
	EKeyCode::KEY_KP_1,
	EKeyCode::KEY_KP_2,
	EKeyCode::KEY_KP_3,
	EKeyCode::KEY_KP_4,
	EKeyCode::KEY_KP_5,
	EKeyCode::KEY_KP_6,
	EKeyCode::KEY_KP_7,
	EKeyCode::KEY_KP_8,
	EKeyCode::KEY_KP_9,
	EKeyCode::KEY_KP_DECIMAL,
	EKeyCode::KEY_KP_DIVIDE,
	EKeyCode::KEY_KP_MULTIPLY,
	EKeyCode::KEY_KP_SUBTRACT,
	EKeyCode::KEY_KP_ADD,
	EKeyCode::KEY_KP_ENTER,
	EKeyCode::KEY_KP_EQUAL,
	EKeyCode::KEY_LEFT_SHIFT,
	EKeyCode::KEY_LEFT_CONTROL,
	EKeyCode::KEY_LEFT_ALT,
	EKeyCode::KEY_LEFT_SUPER,
	EKeyCode::KEY_RIGHT_SHIFT,
	EKeyCode::KEY_RIGHT_CONTROL,
	EKeyCode::KEY_RIGHT_ALT,
	EKeyCode::KEY_RIGHT_SUPER,
	EKeyCode::KEY_MENU,
};

std::array<EMouseButton, InputManager::NUM_OF_MOUSEBUTTON> InputManager::MOUSE_BUTTONS =
{
	EMouseButton::BUTTON_LEFT,
	EMouseButton::BUTTON_RIGHT,
};

InputManager* inputManager = &InputManager::Get();

void ProcessWindowPosCallback(GLFWwindow* window, int32_t xpos, int32_t ypos)
{
	inputManager->ProcessWindowEvent(EWindowEvent::Move);
}

void ProcessWindowResizeCallback(GLFWwindow* window, int32_t width, int32_t height)
{
	inputManager->ProcessWindowEvent(EWindowEvent::ResizeWindow);
}

void ProcessWindowCloseCallback(GLFWwindow* window)
{
	inputManager->ProcessWindowEvent(EWindowEvent::Close);
}

void ProcessWindowRefreshCallback(GLFWwindow* window)
{
	inputManager->ProcessWindowEvent(EWindowEvent::Refresh);
}

void ProcessWindowFocusCallback(GLFWwindow* window, int32_t focused)
{
	if (focused)
	{
		inputManager->ProcessWindowEvent(EWindowEvent::GainFocus);
	}
	else
	{
		inputManager->ProcessWindowEvent(EWindowEvent::LostFocus);
	}
}

void ProcessWindowMinimizeCallback(GLFWwindow* window, int32_t minimized)
{
	if (minimized)
	{
		inputManager->ProcessWindowEvent(EWindowEvent::Minimize);
	}
}

void ProcessWindowMaximizeCallback(GLFWwindow* window, int32_t maximized)
{
	if (maximized)
	{
		inputManager->ProcessWindowEvent(EWindowEvent::Maximize);
	}
}

void ProcessFramebufferResizeCallback(GLFWwindow* window, int32_t width, int32_t height)
{
	inputManager->ProcessWindowEvent(EWindowEvent::ResizeFramebuffer);
}

void ProcessWindowContentScaleCallback(GLFWwindow* window, float xscale, float yscale)
{
	inputManager->ProcessWindowEvent(EWindowEvent::ChangeDisplay);
}

void InputManager::Initialize(Window* inputControlWindow)
{
	ASSERT(!bIsInitialized_, "already initialize input manager...");

	ASSERT(inputControlWindow, "input control window is nullptr");
	inputControlWindow_ = inputControlWindow;

	prevKeyStates_ = std::unordered_map<EKeyCode, int32_t>();
	currKeyStates_ = std::unordered_map<EKeyCode, int32_t>();

	for (const auto& keyCode : KEY_CODES)
	{
		prevKeyStates_.insert({ keyCode , 0 });
		currKeyStates_.insert({ keyCode , 0 });
	}

	prevMouseButtonStates_ = std::unordered_map<EMouseButton, int32_t>();
	currMouseButtonStates_ = std::unordered_map<EMouseButton, int32_t>();

	for (const auto& mouseButton : MOUSE_BUTTONS)
	{
		prevMouseButtonStates_.insert({ mouseButton, 0 });
		currMouseButtonStates_.insert({ mouseButton, 0 });
	}

	windowEventActions_ = std::unordered_map<EWindowEvent, std::function<void()>>();

	GLFWwindow* window = inputControlWindow_->GetWindowPtr();
	glfwSetWindowPosCallback(window, ProcessWindowPosCallback);
	glfwSetWindowSizeCallback(window, ProcessWindowResizeCallback);
	glfwSetWindowCloseCallback(window, ProcessWindowCloseCallback);
	glfwSetWindowRefreshCallback(window, ProcessWindowRefreshCallback);
	glfwSetWindowFocusCallback(window, ProcessWindowFocusCallback);
	glfwSetWindowIconifyCallback(window, ProcessWindowMinimizeCallback);
	glfwSetWindowMaximizeCallback(window, ProcessWindowMaximizeCallback);
	glfwSetFramebufferSizeCallback(window, ProcessFramebufferResizeCallback);
	glfwSetWindowContentScaleCallback(window, ProcessWindowContentScaleCallback);

	bIsInitialized_ = true;
}

void InputManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	inputControlWindow_ = nullptr;

	bIsInitialized_ = false;
}

void InputManager::Tick()
{
	glfwPollEvents();

	GLFWwindow* window = inputControlWindow_->GetWindowPtr();
	for (const auto& keyCode : KEY_CODES)
	{
		prevKeyStates_[keyCode] = currKeyStates_[keyCode];
		currKeyStates_[keyCode] = glfwGetKey(window, static_cast<int32_t>(keyCode));
	}

	for (const auto& mouseButton : MOUSE_BUTTONS)
	{
		prevMouseButtonStates_[mouseButton] = currMouseButtonStates_[mouseButton];
		currMouseButtonStates_[mouseButton] = glfwGetMouseButton(window, static_cast<int32_t>(mouseButton));
	}
}

EPressState InputManager::GetKeyPressState(const EKeyCode& keyCode) const
{
	EPressState state = EPressState::None;

	if (prevKeyStates_.at(keyCode))
	{
		if (currKeyStates_.at(keyCode))
		{
			state = EPressState::Held;
		}
		else
		{
			state = EPressState::Released;
		}
	}
	else
	{
		if (currKeyStates_.at(keyCode))
		{
			state = EPressState::Pressed;
		}
		else
		{
			state = EPressState::None;
		}
	}

	return state;
}

EPressState InputManager::GetMouseButtonPressState(const EMouseButton& mouseButton) const
{
	EPressState state = EPressState::None;

	if (prevMouseButtonStates_.at(mouseButton))
	{
		if (currMouseButtonStates_.at(mouseButton))
		{
			state = EPressState::Held;
		}
		else
		{
			state = EPressState::Released;
		}
	}
	else
	{
		if (currMouseButtonStates_.at(mouseButton))
		{
			state = EPressState::Pressed;
		}
		else
		{
			state = EPressState::None;
		}
	}

	return state;
}

glm::vec2 InputManager::GetCurrentMousePosition() const
{
	double xPosition = 0.0;
	double yPosition = 0.0;
	glfwGetCursorPos(inputControlWindow_->GetWindowPtr(), &xPosition, &yPosition);

	return glm::vec2(static_cast<float>(xPosition), static_cast<float>(yPosition));
}

void InputManager::BindWindowEventAction(const EWindowEvent& windowEvent, const std::function<void()>& eventAction)
{
	ASSERT(windowEventActions_.find(windowEvent) == windowEventActions_.end(), "already bind window event action...");
	windowEventActions_.insert({ windowEvent , eventAction });
}

void InputManager::UnbindWindowEventAction(const EWindowEvent& windowEvent)
{
	if (windowEventActions_.find(windowEvent) != windowEventActions_.end())
	{
		windowEventActions_.erase(windowEvent);
	}
}

void InputManager::ProcessWindowEvent(const EWindowEvent& windowEvent)
{
	if (windowEventActions_.find(windowEvent) != windowEventActions_.end())
	{
		windowEventActions_.at(windowEvent)();
	}
}