#include "Resource/Sound.h"

#include "Manager/AudioManager.h"

#include "Utility/Assertion.h"


Sound::~Sound()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Sound::Initialize(const std::string& path)
{
	ASSERT(!bIsInitialized_, "already initialize sound resource...");

	soundID_ = AudioManager::Get().CreateSound(path);
	ASSERT((soundID_ != -1), "failed to initialize sound resource...");

	bIsInitialized_ = true;
}

void Sound::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	AudioManager::Get().DestroySound(soundID_);

	bIsInitialized_ = false;
}

void Sound::SetVolume(float volume)
{
	AudioManager::Get().SetVolume(soundID_, volume);
}

float Sound::GetVolume()
{
	return AudioManager::Get().GetVolume(soundID_);
}

void Sound::SetLooping(bool bIsLoop)
{
	AudioManager::Get().SetLooping(soundID_, bIsLoop);
}

bool Sound::IsLooping()
{
	return AudioManager::Get().IsLooping(soundID_);
}

void Sound::Play()
{
	AudioManager::Get().Play(soundID_);
}

bool Sound::IsPlaying()
{
	return AudioManager::Get().IsPlaying(soundID_);
}

bool Sound::IsDone()
{
	return AudioManager::Get().IsDone(soundID_);
}

void Sound::Stop()
{
	AudioManager::Get().Stop(soundID_);
}

bool Sound::IsStopping()
{
	return AudioManager::Get().IsStopping(soundID_);
}

void Sound::Reset()
{
	AudioManager::Get().Reset(soundID_);
}