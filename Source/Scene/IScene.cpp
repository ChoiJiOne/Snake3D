#include "Scene/IScene.h"

#include "Manager/RenderManager.h"

#include "Utility/Assertion.h"

void IScene::Entry()
{
	ASSERT(!bIsActive_, "already entry scene...");
	bIsActive_ = true;
}

void IScene::Leave()
{
	ASSERT(bIsActive_, "you have never entry scene...");
	bIsActive_ = false;

	if (nextScene_)
	{
		nextScene_->Entry();
	}
}

void IScene::Tick(float deltaSeconds)
{
	if (!bIsActive_) return;

	RenderManager& renderManager = RenderManager::Get();

	for (auto& updateObject : updateObjects_)
	{
		updateObject->Update(deltaSeconds);
	}

	renderManager.BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
	renderManager.SetRenderTargetWindowViewport();

	for (auto& renderObject : renderObjects_)
	{
		renderObject->Render();
	}

	renderManager.EndFrame();
}