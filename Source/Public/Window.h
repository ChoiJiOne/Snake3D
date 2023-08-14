#pragma once

#include "Macro.h"

#include <string>
#include <windows.h>


/**
 * @brief ���� �� ������ â�� �����ϰ� �����մϴ�.
 */
class Window
{
public:
	/**
	 * @brief �ý��ۿ� ������ Ŭ������ ����մϴ�.
	 *
	 * @param wndProc ������ �̺�Ʈ�� ���ν����Դϴ�.
	 * @param windowClassName �ý��ۿ� ����� ������ Ŭ������ �̸��Դϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/ns-winuser-wndclassexa
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/nf-winuser-registerclassexw
	 */
	static void RegisterWindowClass(WNDPROC wndProc, const std::wstring& windowClassName);


	/**
	 * @brief ������ Ŭ������ ����� �����մϴ�.
	 */
	static void UnregisterWindowClass();


private:
	/**
	 * @brief �ν��Ͻ��� ���� �ڵ��Դϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/winmain--the-application-entry-point
	 */
	static HINSTANCE hMainInstance_;


	/**
	 * @brief ������ Ŭ������ ��� �Ǿ����� Ȯ���մϴ�.
	 */
	static bool bIsRegisterWindowClass_;


	/**
	 * @brief ������ Ŭ������ �̸��Դϴ�.
	 *
	 * @note �ִ� ���̴� 256�Դϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/winuser/ns-winuser-wndclassexw
	 */
	static std::wstring windowClassName_;


	/**
	 * @brief ������ Ŭ������ ATOM(Access TO Memory)�Դϴ�.
	 *
	 * @see https://stackoverflow.com/questions/10525511/what-is-the-atom-data-type
	 */
	static ATOM windowClassAtom_;
};