#include "Manager/InputManager.h"

#include "Utility/Assertion.h"
#include "Utility/Window.h"

#include <glfw3.h>

void InputManager::Initialize(Window* inputControlWindow)
{
	ASSERT(!bIsInitialized_, "already initialize input manager...");

	ASSERT(inputControlWindow, "input control window is nullptr");
	inputControlWindow_ = inputControlWindow;

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
}