#include "LogManager.h"

void LogManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize log manager...");

	bIsInitialized_ = true;
}

void LogManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}