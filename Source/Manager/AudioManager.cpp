#include "Manager/AudioManager.h"

#include "Utility/Assertion.h"
#include "Utility/FileSystem.h"

#include <algorithm>
#include <memory>

#include <miniaudio/miniaudio.h>

static std::unique_ptr<ma_engine> miniaudioEngine = nullptr; // miniaudio 엔진입니다.
static std::vector<std::unique_ptr<ma_sound>> soundResources; // 사운드 리소스입니다.

void AudioManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize audio manager...");

	miniaudioEngine = std::make_unique<ma_engine>();
	ASSERT((ma_engine_init(nullptr, miniaudioEngine.get()) == MA_SUCCESS), "failed to initialize miniaudio engine...");

	soundResources = std::vector<std::unique_ptr<ma_sound>>();
	countSoundResource_ = 0;

	bIsInitialized_ = true;
}

void AudioManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	for (auto& soundResource : soundResources)
	{
		if (soundResource != nullptr)
		{
			ma_sound_uninit(soundResource.get());
			soundResource.reset();
		}
	}

	ma_engine_uninit(miniaudioEngine.get());
	miniaudioEngine.reset();

	bIsInitialized_ = false;
}

int32_t AudioManager::CreateSound(const std::string& path)
{
	if (!FileSystem::IsValidPath(path))
	{
		ERROR_LOG("invalid sound resource : %s", path.c_str());
		return -1;
	}

	std::unique_ptr<ma_sound> sound = std::make_unique<ma_sound>();
	if (ma_sound_init_from_file(miniaudioEngine.get(), path.c_str(), 0, nullptr, nullptr, sound.get()) != MA_SUCCESS)
	{
		ERROR_LOG("failed to create sound resource : %s", path.c_str());
		return -1;
	}

	soundResources.push_back(std::move(sound));
	return countSoundResource_++;
}

void AudioManager::DestroySound(int32_t soundID)
{
	ASSERT((0 <= soundID && soundID < countSoundResource_), "out of range sound id : %d", soundID);
	ASSERT((soundResources[soundID] != nullptr), "already destroy sound id : %d", soundID);

	ma_sound_uninit(soundResources[soundID].get());
	soundResources[soundID].reset();
}

void AudioManager::SetVolume(int32_t soundID, float volume)
{
	volume = std::clamp<float>(volume, 0.0f, 1.0f);
	ma_sound_set_volume(soundResources[soundID].get(), volume);
}

float AudioManager::GetVolume(int32_t soundID)
{
	if (soundID == -1) return 0.0f;

	return ma_sound_get_volume(soundResources[soundID].get());
}

void AudioManager::SetLooping(int32_t soundID, bool bIsLoop)
{
	if (soundID == -1) return;

	ma_sound_set_looping(soundResources[soundID].get(), static_cast<ma_bool32>(bIsLoop));
}

bool AudioManager::IsLooping(int32_t soundID)
{
	if (soundID == -1) return false;

	return ma_sound_is_looping(soundResources[soundID].get()) == MA_TRUE;
}

void AudioManager::Play(int32_t soundID)
{
	if (soundID == -1) return;

	ma_sound_start(soundResources[soundID].get());
}

bool AudioManager::IsPlaying(int32_t soundID)
{
	if (soundID == -1) return false;

	return ma_sound_is_playing(soundResources[soundID].get()) == MA_TRUE;
}

bool AudioManager::IsDone(int32_t soundID)
{
	if (soundID == -1) return false;

	return ma_sound_at_end(soundResources[soundID].get()) == MA_TRUE;
}

void AudioManager::Stop(int32_t soundID)
{
	if (soundID == -1) return;

	ma_sound_stop(soundResources[soundID].get());
}

bool AudioManager::IsStopping(int32_t soundID)
{
	if (soundID == -1) return false;

	return !IsDone(soundID) && !IsPlaying(soundID);
}

void AudioManager::Reset(int32_t soundID)
{
	if (soundID == -1) return;

	ma_sound_seek_to_pcm_frame(soundResources[soundID].get(), 0);
}