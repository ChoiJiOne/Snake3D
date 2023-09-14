#include "Manager/ObjectManager.h"

#include "Utility/Assertion.h"

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
	if (gameObjects_.find(signature) != gameObjects_.end())
	{
		gameObjects_.at(signature).get()->Release();
		gameObjects_.erase(signature);
	}
}