#include "Resource/Sound.h"

#include "Manager/AudioManager.h"

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
	ASSERT((soundID_ != -1), "failed to create sound resource...");

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
	AudioManager::Get().SetSoundVolume(soundID_, volume);
}

float Sound::GetVolume()
{
	return AudioManager::Get().GetSoundVolume(soundID_);
}

void Sound::SetLooping(bool bIsLoop)
{
	AudioManager::Get().SetSoundLooping(soundID_, bIsLoop);
}

bool Sound::IsLooping()
{
	return AudioManager::Get().IsSoundLooping(soundID_);
}

void Sound::Play()
{
	AudioManager::Get().PlaySound(soundID_);
}

bool Sound::IsPlaying()
{
	return AudioManager::Get().IsPlayingSound(soundID_);
}

bool Sound::IsDone()
{
	return AudioManager::Get().IsDoneSound(soundID_);
}

void Sound::Stop()
{
	AudioManager::Get().StopSound(soundID_);
}

bool Sound::IsStopping()
{
	return AudioManager::Get().IsStoppingSound(soundID_);
}

void Sound::Reset()
{
	AudioManager::Get().ResetSound(soundID_);
}