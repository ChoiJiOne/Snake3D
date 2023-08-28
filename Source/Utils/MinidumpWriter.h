#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <string>


/**
 * @brief ���α׷� ���� �� �߻��� ũ���ø� ������� �̴� ���� ������ �����մϴ�.
 *
 * @note �� Ŭ������ ��� ��� ���� �� �Լ��� ������ ���� Ŭ�����Դϴ�.
 */
class MinidumpWriter
{
public:
	/**
	 * @brief �̴� ���� ������ ����� ��θ� �����մϴ�.
	 *
	 * @param minidumpPath ������ �̴� ���� ������ ����Դϴ�.
	 */
	static void SetMinidumpPath(const std::wstring& minidumpPath)
	{
		minidumpPath_ = minidumpPath;
	}


	/**
	 * @brief �̴� ���� ������ �����ߴ��� Ȯ���մϴ�.
	 *
	 * @return �̴� ���� ������ ������ ���� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsGeneratedDump() { return bIsGeneratedDump_; }


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


	/**
	 * @brief ���ø����̼��� ũ���ð� �����ϰ�, ũ���� ������ �ݽ����� ����մϴ�.
	 *
	 * @param exceptionPtr ���� ������ ���� ������ ���Դϴ�.
	 *
	 * @return SEH�� ���� ���� ���� EXCEPTION_EXECUTE_HANDLER�� ��ȯ�մϴ�.
	 */
	static LONG WINAPI DetectApplicationCrash(EXCEPTION_POINTERS* exceptionPtr);


private:
	/**
	 * @brief �̴� ���� ������ �����մϴ�.
	 *
	 * @param minidumpFilename ũ���� ���� ������ �̸��Դϴ�.
	 * @param exceptionPtr ���� ������ ���� ������ ���Դϴ�.
	 */
	static void GenerateMinidumpFile(const std::wstring& minidumpFilename, EXCEPTION_POINTERS* exceptionPtr);


private:
	/**
	 * @brief �̴� ���� ������ ����� ����Դϴ�.
	 */
	static std::wstring minidumpPath_;


	/**
	 * @brief ���� ���� ������ ���� �����Դϴ�.
	 */
	static bool bIsGeneratedDump_;


	/**
	 * @brief �ֻ��� ���� ó���⸦ ����ϱ� ���� �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter
	 */
	static LPTOP_LEVEL_EXCEPTION_FILTER topLevelExceptionFilter_;
};