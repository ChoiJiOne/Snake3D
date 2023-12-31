#pragma once

#include <functional>

#include "Scene/IScene.h"

class IGameObject;


/**
 * @brief 게임의 준비 씬입니다.
 */
class ReadyScene : public IScene
{
public:
	/**
	 * @brief 게임 준비 씬의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	ReadyScene() = default;


	/**
	 * @brief 게임 준비 씬의 가상 소멸자입니다.
	 */
	virtual ~ReadyScene();


	/**
	 * @brief 게임 준비 씬의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ReadyScene);


	/**
	 * @brief 게임 준비 씬에 접근합니다.
	 */
	virtual void Entry() override;


	/**
	 * @brief 게임 준비 씬에서 나갑니다.
	 */
	virtual void Leave() override;


	/**
	 * @brief 게임 준비 씬을 한 프레임 수행합니다.
	 *
	 * @param deltaSeconds 초단위 델타 시간값입니다.
	 */
	virtual void Tick(float deltaSeconds) override;


	/**
	 * @brief 루프 종료 이벤트를 설정합니다.
	 * 
	 * @param quitLoopEvent 설정할 루프 종료 이벤트입니다.
	 */
	void SetQuitLoopEvent(const std::function<void()>& quitLoopEvent)
	{
		quitLoopEvent_ = quitLoopEvent;
	}


private:
	/**
	 * @brief 백그라운드 오브젝트입니다.
	 */
	IGameObject* background_ = nullptr;

	
	/**
	 * @brief 루프 종료 이벤트입니다.
	 */
	std::function<void()> quitLoopEvent_;
};