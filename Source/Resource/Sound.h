#pragma once

#include "Utils/Macro.h"


/**
 * @brief 게임 내에서 출력될 사운드입니다.
 */
class Sound
{
public:
	/**
	 * @brief 게임 내에서 출력될 사운드의 기본 생성자입니다.
	 *
	 * @note 초기화를 수행하기 위해서는 반드시 Initialzie 메서드를 호출해야 합니다.
	 */
	Sound() = default;


	/**
	 * @brief 게임 내에서 출력될 사운드의 가상 소멸자입니다.
	 *
	 * @note 해제를 수행하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Sound();


	/**
	 * @brief 게임 내에서 출력될 사운드 클래스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Sound);


	/**
	 * @brief 게임 내에서 출력될 사운드를 초기화합니다.
	 */
	void Initialize(const std::string& path);


	/**
	 * @brief 게임 내에서 출력될 사운드 리소스를 정리합니다.
	 */
	void Release();


	/**
	 * @brief 사운드의 크기를 설정합니다.
	 *
	 * @param volume 사운드의 크기입니다. 범위는 0.0 ~ 1.0 입니다.
	 */
	void SetVolume(float volume);


	/**
	 * @brief 현재 사운드의 크기를 얻습니다.
	 *
	 * @note 사운드 크기의 범위는 0.0 ~ 1.0 입니다.
	 *
	 * @return 현재 사운드의 크기를 얻습니다.
	 */
	float GetVolume();


	/**
	 * @brief 사운드의 반복 여부를 설정합니다.
	 *
	 * @param bIsLoop 사운드 반복 여부입니다.
	 */
	void SetLooping(bool bIsLoop);


	/**
	 * @brief 사운드의 반복 여부를 얻습니다.
	 *
	 * @return 사운드가 반복한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsLooping();


	/**
	 * @brief 사운드를 플레이합니다.
	 *
	 * @note 이전에 중지한 적이 있다면 중지한 시점부터 플레이됩니다.
	 */
	void Play();


	/**
	 * @brief 사운드가 플레이중인지 확인합니다.
	 *
	 * @return 사운드가 플레이 중이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsPlaying();


	/**
	 * @brief 사운드 플레이가 끝났는지 확인합니다.
	 *
	 * @return 사운드 플레이가 끝났다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsDone();


	/**
	 * @brief 사운드 플레이를 중지합니다.
	 */
	void Stop();


	/**
	 * @brief 사운드 플레이가 중지 되었는지 확인합니다.
	 *
	 * @return 사운드 플레이가 중지 되었다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsStopping();


	/**
	 * @brief 사운드를 초기화합니다.
	 */
	void Reset();


private:
	/**
	 * @brief 게임 내에서 출력될 사운드가 초기화된 적이 있는지 확인합니다.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief 사운드 리소스의 아이디입니다.
	 *
	 * @note -1 값은 유효하지 않는 값으로 이는 사운드 리소스 생성에 실패한 것입니다.
	 */
	int32_t soundID_ = -1;
};