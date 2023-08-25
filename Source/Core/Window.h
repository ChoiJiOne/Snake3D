#pragma once

#include "Utils/Macro.h"

#include <string>
#include <windows.h>


/**
 * @brief ���� �� ������ â�� �����ϰ� �����մϴ�.
 */
class Window
{
public:
	/**
	 * @brief ���� �� ������ â�� �����ϰ� �����ϴ� Ŭ������ �⺻ �������Դϴ�.
	 *
	 * @note �ݵ�� Ŭ���� ���� ��Ҹ� �ʱ�ȭ�ϴ� �޼��带 ȣ���ؾ� �մϴ�.
	 */
	explicit Window() = default;


	/**
	 * @brief ���� �� ������ â�� �����ϰ� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Window();


	/**
	 * @brief ���� �� ������ â�� �����ϰ� �����ϴ� Ŭ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * @brief ������ â�� �����մϴ�.
	 *
	 * @param title ������ â�� Ÿ��Ʋ�Դϴ�.
	 * @param screenX ��ũ�� ���� ������ â�� ���� ��� ��ǥ�� X���Դϴ�.
	 * @param screenY ��ũ�� ���� ������ â�� ���� ��� ��ǥ�� Y���Դϴ�.
	 * @param clientWidth ������ â�� Ŭ���̾�Ʈ ���� ũ���Դϴ�.
	 * @param clientHeight ������ â�� Ŭ���̾�Ʈ ���� ũ���Դϴ�.
	 */
	void Create(
		const std::wstring & title,
		const int32_t & screenX,
		const int32_t & screenY,
		const int32_t & clientWidth,
		const int32_t & clientHeight
	);


	/**
	 * @brief ������ �ڵ� ���� ����ϴ�.
	 *
	 * @return ������ �ڵ� ���� ��ȯ�մϴ�.
	 */
	HWND GetHandle() const { return windowHandle_; }


	/**
	 * @brief ������ Ŭ���̾�Ʈ�� ũ�Ⱚ�� ����ϴ�.
	 *
	 * @param outClientWidth ������ Ŭ���̾�Ʈ�� ���� ũ���Դϴ�.
	 * @param outClientHeight ������ Ŭ���̾�Ʈ�� ���� ũ���Դϴ�.
	 */
	void GetClientSize(uint32_t & outClientWidth, uint32_t & outClientHeight);


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
	 * @brief ���ϴ� Ŭ���̾�Ʈ ũ�⸦ �������� �ʿ��� â ũ�⸦ ����ϴ�.
	 *
	 * @param clientWidth ������ �Ǵ� Ŭ���̾�Ʈ�� ��ġ�� ũ���Դϴ�.
	 * @param clientHeight ������ �Ǵ� Ŭ���̾�Ʈ�� ��ġ�� ũ���Դϴ�.
	 * @param windowStype �������� ��Ÿ���Դϴ�.
	 * @param windowWidth[out] Ŭ���̾�Ʈ�� ��Ÿ���� ����Ͽ� ���� �������� ���� ũ���Դϴ�.
	 * @param windowHeight[out] Ŭ���̾�Ʈ�� ��Ÿ���� ����Ͽ� ���� �������� ���� ũ���Դϴ�.
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


	/**
	 * @brief ������ â�� �ڵ��Դϴ�.
	 */
	HWND windowHandle_ = nullptr;
};