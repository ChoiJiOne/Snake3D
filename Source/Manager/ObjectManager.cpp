#include "Manager/ObjectManager.h"

#include <algorithm>

void ObjectManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize object manager...");

	gameObjects_ = std::unordered_map<std::string, std::unique_ptr<IGameObject>>();

	bIsInitialized_ = true;
}

void ObjectManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	for (auto& object : gameObjects_)
	{
		object.second->Release();
		object.second.reset();
	}

	bIsInitialized_ = false;
}

void ObjectManager::RemoveGameObject(const std::string& signature)
{
	ASSERT((gameObjects_.find(signature) != gameObjects_.end()), "not exist game object signature key...");

	IGameObject* object = gameObjects_.at(signature).get();

	for (IGameObject* updateObject : updateObjects_)
	{
		if (updateObject == object)
		{
			updateObjects_.remove(updateObject);
			break;
		}
	}

	for (IGameObject* renderObject : renderObjects_)
	{
		if (renderObject == object)
		{
			renderObjects_.remove(renderObject);
			break;
		}
	}

	object->Release();
	gameObjects_.erase(signature);
}

void ObjectManager::UpdateAllObjects(float deltaSeconds)
{
	if (bNeedsToBeSortedUpdate_)
	{
		updateObjects_.sort([](const IGameObject* lhs, const IGameObject* rhs) -> bool
			{
				return lhs->GetUpdateOrder() < rhs->GetUpdateOrder();
			});

		bNeedsToBeSortedUpdate_ = false;
	}

	for (IGameObject* object : updateObjects_)
	{
		object->Update(deltaSeconds);
	}
}

void ObjectManager::RenderAllObjects()
{
	if (bNeedsToBeSortedRender_)
	{
		renderObjects_.sort([](const IGameObject* lhs, const IGameObject* rhs) -> bool
			{
				return lhs->GetRenderOrder() < rhs->GetRenderOrder();
			});

		bNeedsToBeSortedRender_ = false;
	}

	for (IGameObject* object : renderObjects_)
	{
		object->Render();
	}
}