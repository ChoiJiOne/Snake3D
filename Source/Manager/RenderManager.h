#pragma once

#include <cstdint>

#include "Manager/IManager.h"

typedef struct GLFWwindow GLFWwindow; // GLFWwindow를 사용하기 위한 전방 선언입니다.


/**
 * @brief 렌더링 처리를 수행하는 매니저입니다.
 * 
 * @note 이 클래스는 싱글턴 클래스입니다.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(RenderManager);


	/**
	 * @brief 렌더링 처리를 수행하는 매니저를 초기화합니다.
	 * 
	 * @param renderTargetWindow 렌더링 대상이 되는 윈도우입니다.
	 * @param bEnableVsync 수직 동기화 활성화 여부입니다.
	 */
	void Initialize(GLFWwindow* renderTargetWindow, bool bEnableVsync = false);


	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


private:
	/**
	 * @brief 렌더링 대상이 되는 윈도우입니다.
	 */
	GLFWwindow* renderTargetWindow_ = nullptr;


	/**
	 * @brief 수직 동기화 활성화 여부입니다.
	 */
	bool bEnableVsync_ = true;


	/**
	 * @brief OpenGL의 주 버전입니다.
	 */
	const int32_t majorVersion_ = 4;


	/**
	 * @brief OpenGL의 부 버전입니다.
	 */
	const int32_t minorVersion_ = 5;
};