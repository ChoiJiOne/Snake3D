#pragma once

#include "Utility/Macro.h"


/**
 * @brief 게임 오브젝트 인터페이스입니다.
 *
 * @note 월드에 배치되는 게임 내 오브젝트는 반드시 이 클래스를 상속받아야 합니다.
 */
class IGameObject
{
public:
	/**
	 * @brief 게임 오브젝트 인터페이스의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	IGameObject() = default;


	/**
	 * @brief 게임 오브젝트 인터페이스의 가상 소멸자입니다.
	 *
	 * @note 게임 오브젝트 인터페이스의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~IGameObject() {}


	/**
	 * @brief 게임 오브젝트 인터페이스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IGameObject);


	/**
	 * @brief 게임 오브젝트를 업데이트합니다.
	 *
	 * @note 게임 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) = 0;


	/**
	 * @brief 게임 오브젝트를 화면에 그립니다.
	 *
	 * @note 게임 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Render() = 0;


	/**
	 * @brief 게임 오브젝트 내의 리소스를 할당 해제합니다.
	 *
	 * @note 게임 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Release() = 0;


protected:
	/**
	 * @brief 게임 오브젝트가 초기화되었는지 확인합니다.
	 */
	bool bIsInitialized_ = false;
};