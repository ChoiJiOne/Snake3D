#include "Manager/ResourceManager.h"

void ResourceManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize resource manager...");

	bIsInitialized_ = true;
}

void ResourceManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}