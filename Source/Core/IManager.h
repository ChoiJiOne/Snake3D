#pragma once

#include "Core/Macro.h"


/**
 * @brief 매니저 인터페이스 입니다.
 *
 * @note 접두사로 매니저라고 명명된 클래스는 반드시 이 클래스를 상속받아야 합니다.
 */
class IManager
{
public:
	/**
	 * @brief 매니저 인터페이스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IManager);


	/**
	 * @brief 매니저 인터페이스를 초기화합니다.
	 *
	 * @note 반드시 이 메서드를 이용해서 초기화해야 합니다.
	 */
	virtual void Initialize() = 0;


	/**
	 * @brief 매니저 인터페이스를 해제합니다.
	 *
	 * @note 반드시 이 메서드를 이용해서 해제해야 합니다.
	 */
	virtual void Release() = 0;


protected:
	/**
	 * @brief 매니저 인터페이스의 디폴트 생성자와 가상 소멸자입니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(IManager);


protected:
	/**
	 * @brief 매니저 인터페이스가 초기화되었는지 확인합니다.
	 */
	bool bIsInitialized_ = false;
};