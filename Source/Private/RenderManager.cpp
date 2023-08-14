#include "RenderManager.h"
#include "Window.h"

void RenderManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");
	ASSERT(renderTargetWindow_ != nullptr, "you have to set render target window...");

	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	
	bIsInitialized_ = false;
}

void RenderManager::SetRenderTargetWindow(Window* window)
{
	ASSERT(window != nullptr, "render target window pointer is nullptr...");
	renderTargetWindow_ = window;
}