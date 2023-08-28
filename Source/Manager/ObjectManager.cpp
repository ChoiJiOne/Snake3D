#include "Manager/ObjectManager.h"

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

	gameObjects_[signature]->Release();
	gameObjects_.erase(signature);
}