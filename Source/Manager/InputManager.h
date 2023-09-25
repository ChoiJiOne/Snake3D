#pragma once

#include "Manager/IManager.h"

class Window; // 윈도우 클래스를 사용하기 위한 전방 선언입니다.


/**
 * @brief 입력 처리를 수행하는 매니저입니다.
 * 
 * @note 이 클래스는 싱글턴입니다.
 */
class InputManager : public IManager
{
public:
	/**
	 * @brief 입력 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(InputManager);


	/**
	 * @brief 입력 처리를 수행하는 매니저를 초기화합니다.
	 *
	 * @param inputControlWindow 입력 처리 대상이 되는 윈도우입니다.
	 */
	void Initialize(Window* inputControlWindow);


	/**
	 * @brief 입력 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 입력 상태를 업데이트 합니다.
	 */
	void Tick();


private:
	/**
	 * @brief 입력 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(InputManager);


private:
	/**
	 * @brief 렌더링 대상이 되는 윈도우입니다.
	 */
	Window* inputControlWindow_ = nullptr;
};