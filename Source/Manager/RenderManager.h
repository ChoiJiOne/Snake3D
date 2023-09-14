#pragma once

#include <cstdint>

#include "Manager/IManager.h"

class Window;


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
	void Initialize(Window* renderTargetWindow, bool bEnableVsync = false);


	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 프레임 렌더링을 시작합니다.
	 * 
	 * @param red 색상 버퍼의 R 값입니다.
	 * @param green 색상 버퍼의 G 값입니다.
	 * @param blue 색상 버퍼의 B 값입니다.
	 * @param alpha 색상 버퍼의 A 값입니다.
	 * @param depth 깊이 버퍼의 초기화 값입니다.
	 * @param stencil 스텐실 버퍼의 초기화 값입니다.
	 */
	void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief 프레임 렌더링을 종료하고 백버퍼와 프론트버퍼를 스왑합니다.
	 */
	void EndFrame();


private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


private:
	/**
	 * @brief 렌더링 대상이 되는 윈도우입니다.
	 */
	Window* renderTargetWindow_ = nullptr;


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