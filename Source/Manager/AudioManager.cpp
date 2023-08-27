#include "Manager/AudioManager.h"

#include <algorithm>
#include <memory>
#include <vector>

// @third party code - BEGIN
#include <miniaudio/miniaudio.h>
// @third party code - END


/**
 * @brief miniaudio 엔진입니다.
 */
static std::unique_ptr<ma_engine> miniaudioEngine = nullptr;


/**
 * @brief miniaudio의 사운드 리소스입니다.
 */
static std::vector<std::unique_ptr<ma_sound>> soundResources;

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
	std::unique_ptr<ma_sound> sound = std::make_unique<ma_sound>();

	if (ma_sound_init_from_file(miniaudioEngine.get(), path.c_str(), 0, nullptr, nullptr, sound.get()) != MA_SUCCESS)
	{
		return -1;
	}

	soundResources.push_back(std::move(sound));
	return countSoundResource_++;
}

void AudioManager::DestroySound(int32_t soundID)
{
	ASSERT((0 <= soundID && soundID < countSoundResource_), "out of range sound id...");
	ASSERT((soundResources[soundID] != nullptr), "already destroy sound...");

	ma_sound_uninit(soundResources[soundID].get());
	soundResources[soundID].reset();
}

void AudioManager::SetSoundVolume(int32_t soundID, float volume)
{
	if (soundID == -1) return;

	volume = std::clamp<float>(volume, 0.0f, 1.0f);
	ma_sound_set_volume(soundResources[soundID].get(), volume);
}

float AudioManager::GetSoundVolume(int32_t soundID)
{
	if (soundID == -1) return 0.0f;

	return ma_sound_get_volume(soundResources[soundID].get());
}

void AudioManager::SetSoundLooping(int32_t soundID, bool bIsLoop)
{
	if (soundID == -1) return;

	ma_sound_set_looping(soundResources[soundID].get(), static_cast<ma_bool32>(bIsLoop));
}

bool AudioManager::IsSoundLooping(int32_t soundID)
{
	if (soundID == -1) return false;

	return ma_sound_is_looping(soundResources[soundID].get()) == MA_TRUE;
}

void AudioManager::PlaySound(int32_t soundID)
{
	if (soundID == -1) return;

	ma_sound_start(soundResources[soundID].get());
}

bool AudioManager::IsPlayingSound(int32_t soundID)
{
	if (soundID == -1) return false;

	return ma_sound_is_playing(soundResources[soundID].get()) == MA_TRUE;
}

bool AudioManager::IsDoneSound(int32_t soundID)
{
	if (soundID == -1) return false;

	return ma_sound_at_end(soundResources[soundID].get()) == MA_TRUE;
}

void AudioManager::StopSound(int32_t soundID)
{
	if (soundID == -1) return;

	ma_sound_stop(soundResources[soundID].get());
}

bool AudioManager::IsStoppingSound(int32_t soundID)
{
	if (soundID == -1) return false;

	return !IsDoneSound(soundID) && !IsPlayingSound(soundID);
}

void AudioManager::ResetSound(int32_t soundID)
{
	if (soundID == -1) return;

	ma_sound_seek_to_pcm_frame(soundResources[soundID].get(), 0);
}