#include "Manager/RenderManager.h"

#include "Utility/Macro.h"

void RenderManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");

	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}