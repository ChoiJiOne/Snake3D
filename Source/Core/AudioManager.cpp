#include "Core/AudioManager.h"

#include <algorithm>
#include <memory>
#include <vector>

// @third party code - BEGIN
#include <miniaudio/miniaudio.h>
// @third party code - END

void AudioManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize audio manager...");

	bIsInitialized_ = true;
}

void AudioManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}