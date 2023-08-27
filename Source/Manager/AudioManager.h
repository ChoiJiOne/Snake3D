#pragma once

#include "Utils/Macro.h"

#include "Manager/IManager.h"


/**
 * @brief 오디오 처리를 수행하는 매니저입니다.
 */
class AudioManager : public IManager
{
public:
	/**
	 * @brief 오디오 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(AudioManager);


	/**
	 * @brief 오디오 처리를 수행하는 메니저를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 오디오 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 사운드 리소스를 생성합니다.
	 *
	 * @param path 사운드 리소스의 경로입니다.
	 *
	 * @return 생성된 사운드 리소스의 아이디를 반환합니다. 생성에 실패하면 -1을 반환합니다.
	 */
	int32_t CreateSound(const std::string& path);


	/**
	 * @brief 사운드 리소스를 파괴합니다.
	 * 
	 * @param soundID 파괴할 사운드의 아이디입니다.
	 */
	void DestroySound(int32_t soundID);


	/**
	 * @brief 사운드의 크기를 설정합니다.
	 *
	 * @param soundID 크기를 설정할 사운드의 아이디입니다.
	 * @param volume 사운드의 크기입니다. 범위는 0.0 ~ 1.0 입니다.
	 */
	void SetSoundVolume(int32_t soundID, float volume);


	/**
	 * @brief 현재 사운드의 크기를 얻습니다.
	 *
	 * @param soundID 소리 크기를 얻을 사운드의 아이디입니다.
	 *
	 * @return 현재 사운드의 크기를 얻습니다.
	 */
	float GetSoundVolume(int32_t soundID);


	/**
	 * @brief 사운드의 반복 여부를 설정합니다.
	 *
	 * @param soundID 반복 여부를 설정할 사운드의 아이디입니다.
	 * @param bIsLoop 사운드 반복 여부입니다.
	 */
	void SetSoundLooping(int32_t soundID, bool bIsLoop);


	/**
	 * @brief 사운드의 반복 여부를 얻습니다.
	 *
	 * @param soundID 반복 여부를 확인할 사운드의 아이디입니다.
	 *
	 * @return 사운드가 반복한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsSoundLooping(int32_t soundID);


	/**
	 * @brief 사운드를 플레이합니다.
	 *
	 * @note 이전에 중지한 적이 있다면 중지한 시점부터 플레이됩니다.
	 *
	 * @param soundID 플레이할 사운드의 아이디입니다.
	 */
	void PlaySound(int32_t soundID);


	/**
	 * @brief 사운드가 플레이중인지 확인합니다.
	 *
	 * @param soundID 플레이 중인지 확인할 사운드 아이디입니다.
	 *
	 * @return 사운드가 플레이 중이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsPlayingSound(int32_t soundID);


	/**
	 * @brief 사운드 플레이가 끝났는지 확인합니다.
	 *
	 * @param soundID 플레이가 끝났는지 확인할 사운드 아이디입니다.
	 *
	 * @return 사운드 플레이가 끝났다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsDoneSound(int32_t soundID);


	/**
	 * @brief 사운드 플레이를 중지합니다.
	 *
	 * @param soundID 플레이를 중지할 사운드 아이디입니다.
	 */
	void StopSound(int32_t soundID);


	/**
	 * @brief 사운드 플레이가 중지 되었는지 확인합니다.
	 *
	 * @param soundID 플레이가 중지 되었는지 확인할 사운드 아이디입니다.
	 *
	 * @return 사운드 플레이가 중지 되었다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsStoppingSound(int32_t soundID);


	/**
	 * @brief 사운드를 초기화합니다.
	 *
	 * @param soundID 초기화할 사운드의 아이디입니다.
	 */
	void ResetSound(int32_t soundID);


private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(AudioManager);


private:
	/**
	 * @brief 현재까지 생성된 사운드 리소스의 수입니다.
	 */
	int32_t countSoundResource_ = 0;
};