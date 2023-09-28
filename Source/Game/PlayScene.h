#pragma once

#include "Scene/IScene.h"


/**
 * @brief 게임의 플레이 씬입니다.
 */
class PlayScene : public IScene
{
	/**
	 * @brief 게임 플레이 씬의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	PlayScene() = default;


	/**
	 * @brief 게임 플레이 씬의 가상 소멸자입니다.
	 */
	virtual ~PlayScene();


	/**
	 * @brief 게임 플레이 씬의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(PlayScene);


	/**
	 * @brief 게임 플레이 씬에 접근합니다.
	 */
	virtual void Entry() override;


	/**
	 * @brief 게임 플레이 씬에서 나갑니다.
	 */
	virtual void Leave() override;


	/**
	 * @brief 게임 플레이 씬을 한 프레임 수행합니다.
	 *
	 * @param deltaSeconds 초단위 델타 시간값입니다.
	 */
	virtual void Tick(float deltaSeconds) override;
};