#include "Manager/InputManager.h"

#include "Utility/Assertion.h"
#include "Utility/Window.h"

void InputManager::Initialize(Window* inputControlWindow)
{
	ASSERT(!bIsInitialized_, "already initialize input manager...");

	ASSERT(inputControlWindow_, "inpu control window is nullptr");
	inputControlWindow_ = inputControlWindow;

	bIsInitialized_ = true;
}

void InputManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	inputControlWindow_ = nullptr;

	bIsInitialized_ = false;
}