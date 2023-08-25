#pragma once

#include "Utils/Macro.h"

#include <string>
#include <windows.h>


/**
 * @brief 게임 내 윈도우 창을 생성하고 관리합니다.
 */
class Window
{
public:
	/**
	 * @brief 게임 내 윈도우 창을 생성하고 관리하는 클래스의 기본 생성자입니다.
	 *
	 * @note 반드시 클래스 내부 요소를 초기화하는 메서드를 호출해야 합니다.
	 */
	explicit Window() = default;


	/**
	 * @brief 게임 내 윈도우 창을 생성하고 관리하는 클래스의 가상 소멸자입니다.
	 */
	virtual ~Window();


	/**
	 * @brief 게임 내 윈도우 창을 생성하고 관리하는 클래스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * @brief 윈도우 창을 생성합니다.
	 *
	 * @param title 윈도우 창의 타이틀입니다.
	 * @param screenX 스크린 상의 윈도우 창의 왼쪽 상단 좌표의 X값입니다.
	 * @param screenY 스크린 상의 윈도우 창의 왼쪽 상단 좌표의 Y값입니다.
	 * @param clientWidth 윈도우 창의 클라이언트 가로 크기입니다.
	 * @param clientHeight 윈도우 창의 클라이언트 세로 크기입니다.
	 */
	void Create(
		const std::wstring & title,
		const int32_t & screenX,
		const int32_t & screenY,
		const int32_t & clientWidth,
		const int32_t & clientHeight
	);


	/**
	 * @brief 윈도우 핸들 값을 얻습니다.
	 *
	 * @return 윈도우 핸들 값을 반환합니다.
	 */
	HWND GetHandle() const { return windowHandle_; }


	/**
	 * @brief 윈도우 클라이언트의 크기값을 얻습니다.
	 *
	 * @param outClientWidth 윈도우 클라이언트의 가로 크기입니다.
	 * @param outClientHeight 윈도우 클라이언트의 세로 크기입니다.
	 */
	void GetClientSize(uint32_t & outClientWidth, uint32_t & outClientHeight);


	/**
	 * @brief 시스템에 윈도우 클래스를 등록합니다.
	 *
	 * @param wndProc 윈도우 이벤트의 프로시저입니다.
	 * @param windowClassName 시스템에 등록할 윈도우 클래스의 이름입니다.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/ns-winuser-wndclassexa
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-registerclassexw
	 */
	static void RegisterWindowClass(WNDPROC wndProc, const std::wstring& windowClassName);


	/**
	 * @brief 윈도우 클래스의 등록을 해제합니다.
	 */
	static void UnregisterWindowClass();


private:
	/**
	 * @brief 원하는 클라이언트 크기를 기준으로 필요한 창 크기를 얻습니다.
	 *
	 * @param clientWidth 기준이 되는 클라이언트의 위치와 크기입니다.
	 * @param clientHeight 기준이 되는 클라이언트의 위치와 크기입니다.
	 * @param windowStype 윈도우의 스타일입니다.
	 * @param windowWidth[out] 클라이언트와 스타일을 고려하여 계산된 윈도우의 가로 크기입니다.
	 * @param windowHeight[out] 클라이언트와 스타일을 고려하여 계산된 윈도우의 세로 크기입니다.
	 */
	static void GetWindowSizeFromClient(
		const int32_t& clientWidth,
		const int32_t& clientHeight,
		const DWORD& windowStyle,
		int32_t& outWindowWidth,
		int32_t& outWindowHeight
	);


private:
	/**
	 * @brief 인스턴스에 대한 핸들입니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/winmain--the-application-entry-point
	 */
	static HINSTANCE hMainInstance_;


	/**
	 * @brief 윈도우 클래스가 등록 되었는지 확인합니다.
	 */
	static bool bIsRegisterWindowClass_;


	/**
	 * @brief 윈도우 클래스의 이름입니다.
	 *
	 * @note 최대 길이는 256입니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/ns-winuser-wndclassexw
	 */
	static std::wstring windowClassName_;


	/**
	 * @brief 윈도우 클래스의 ATOM(Access TO Memory)입니다.
	 *
	 * @see https://stackoverflow.com/questions/10525511/what-is-the-atom-data-type
	 */
	static ATOM windowClassAtom_;


	/**
	 * @brief 윈도우 창의 핸들입니다.
	 */
	HWND windowHandle_ = nullptr;
};