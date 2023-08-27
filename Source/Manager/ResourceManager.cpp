#include "Manager/ResourceManager.h"

void ResourceManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize resource manager...");

	resources_ = std::unordered_map<std::string, std::unique_ptr<IResource>>();

	bIsInitialized_ = true;
}

void ResourceManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	for (auto& resource : resources_)
	{
		resource.second->Release();
		resource.second.reset();
	}

	bIsInitialized_ = false;
}

void ResourceManager::RemoveResource(const std::string& signature)
{
	ASSERT((resources_.find(signature) != resources_.end()), "not exist resource signature key...");

	resources_[signature]->Release();
	resources_.erase(signature);
}