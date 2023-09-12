#pragma once


/**
 * @brief ���α׷� ���� �� �߻��� ũ���ø� ������� �̴� ���� ������ �����մϴ�.
 *
 * @note �� Ŭ������ ��� �޼��尡 ������ ���� Ŭ�����Դϴ�.
 */
class MinidumpWriter
{
public:
	/**
	 * @brief ���ø����̼��� ���μ����� �� �����忡 ���� �ֻ��� ���� ó���⸦ ����մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter
	 */
	static void RegisterUnhandledExceptionFilter();


	/**
	 * @brief ���ø����̼��� ���μ����� �� �����忡 ���� �ֻ��� ���� ó���� ����� �����մϴ�.
	 */
	static void UnregisterUnhandledExceptionFilter();
};