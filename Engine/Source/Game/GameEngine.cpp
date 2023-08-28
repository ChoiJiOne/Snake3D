#include "Game/GameEngine.h"

bool GameEngine::bIsInitialized_ = false;

void GameEngine::LaunchStartup()
{
	ASSERT(!bIsInitialized_, "already launch game engine startup...");

	bIsInitialized_ = true;
}

void GameEngine::LaunchShutdown()
{
	ASSERT(bIsInitialized_, "you have to launch game engine startup...");

	bIsInitialized_ = false;
}
