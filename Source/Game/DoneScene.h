#pragma once

#include "Scene/IScene.h"


/**
 * @brief 게임의 종료 씬입니다.
 */
class DoneScene : public IScene
{
public:
	/**
	 * @brief 게임 종료 씬의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	DoneScene() = default;


	/**
	 * @brief 게임 종료 씬의 가상 소멸자입니다.
	 */
	virtual ~DoneScene();


	/**
	 * @brief 게임 종료 씬의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(DoneScene);


	/**
	 * @brief 게임 종료 씬에 접근합니다.
	 */
	virtual void Entry() override;


	/**
	 * @brief 게임 종료 씬에서 나갑니다.
	 */
	virtual void Leave() override;


	/**
	 * @brief 게임 종료 씬을 한 프레임 수행합니다.
	 *
	 * @param deltaSeconds 초단위 델타 시간값입니다.
	 */
	virtual void Tick(float deltaSeconds) override;
};