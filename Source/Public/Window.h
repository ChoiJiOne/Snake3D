#pragma once

#include "Macro.h"

#include <string>
#include <windows.h>


/**
 * @brief 게임 내 윈도우 창을 생성하고 관리합니다.
 */
class Window
{
public:
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
};