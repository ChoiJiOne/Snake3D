#pragma once

#include <vector>

#include "GameObject/IGameObject.h"


/**
 * @brief 게임 씬 인터페이스입니다.
 */
class IScene
{
public:
	/**
	 * @brief 게임 씬 인터페이스의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	IScene() = default;


	/**
	 * @brief 게임 씬 인터페이스의 가상 소멸자입니다.
	 */
	virtual ~IScene() {}


	/**
	 * @brief 게임 씬 인터페이스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IScene);


	/**
	 * @brief 현재 씬에 접근합니다.
	 */
	virtual void Entry() = 0;


	/**
	 * @brief 현재 씬에서 나갑니다.
	 */
	virtual void Leave() = 0;


	/**
	 * @brief 씬을 한 프레임 수행합니다.
	 *
	 * @param deltaSeconds 초단위 델타 시간값입니다.
	 */
	virtual void Tick(float deltaSeconds) = 0;


	/**
	 * @brief 다음 씬을 설정합니다.
	 * 
	 * @param nextScene 설정할 다음 씬의 포인터입니다.
	 */
	void SetNextScene(IScene* nextScene) { nextScene_ = nextScene; }


	/**
	 * @brief 다음 씬을 얻습니다.
	 * 
	 * @return 다음 씬의 포인터를 반환합니다.
	 */
	IScene* GetNextScene() { return nextScene_; }


	/**
	 * @brief 씬 활성화 여부를 확인합니다.
	 * 
	 * @return 씬이 활성화되어 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsActive() const { return bIsActive_; }


	/**
	 * @brief 씬 활성화 여부를 설정합니다.
	 * 
	 * @param bIsActive 설정할 씬 활성화 여부입니다.
	 */
	void SetActive(bool bIsActive) { bIsActive_ = bIsActive; }


protected:
	/**
	 * @brief 씬에 연결된 다음 씬입니다.
	 */
	IScene* nextScene_ = nullptr;


	/**
	 * @brief 씬이 활성화 되었는지 확인합니다.
	 */
	bool bIsActive_ = false;


	/**
	 * @brief 씬 내의 업데이트 해야 할 게임 오브젝트 목록입니다.
	 */
	std::vector<IGameObject*> updateObjects_;


	/**
	 * @brief 씬 내의 렌더링 해야 할 게임 오브젝트 목록입니다.
	 */
	std::vector<IGameObject*> renderObjects_;
};