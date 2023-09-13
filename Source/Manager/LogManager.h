#pragma once

#include "Manager/IManager.h"


/**
 * @brief 로그를 기록하고 출력하는 매니저입니다.
 * 
 * @note 이 클래스는 싱글턴 클래스입니다.
 */
class LogManager : public IManager
{
public:
	/**
	 * @brief 로그 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(LogManager);


	/**
	 * @brief 로그 처리를 수행하는 매니저를 초기화합니다.
	 */
	void Initialize();


	/**
	 * @brief 로그 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(LogManager);
};
