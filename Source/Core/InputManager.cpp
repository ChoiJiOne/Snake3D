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