#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <string>


/**
 * @brief 프로그램 실행 중 발생한 크래시를 기반으로 미니 덤프 파일을 생성합니다.
 *
 * @note 이 클래스는 모든 멤버 변수 및 함수가 정적인 정적 클래스입니다.
 */
class MinidumpWriter
{
public:
	/**
	 * @brief 미니 덤프 파일이 저장될 경로를 설정합니다.
	 *
	 * @param minidumpPath 설정할 미니 덤프 파일의 경로입니다.
	 */
	static void SetMinidumpPath(const std::wstring& minidumpPath)
	{
		minidumpPath_ = minidumpPath;
	}


	/**
	 * @brief 미니 덤프 파일을 생성했는지 확인합니다.
	 *
	 * @return 미니 덤프 파일을 생성한 적이 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsGeneratedDump() { return bIsGeneratedDump_; }


	/**
	 * @brief 애플리케이션의 크래시가 감지하고, 크래시 덤프와 콜스택을 기록합니다.
	 *
	 * @param exceptionPtr 예외 정보에 대한 포인터 값입니다.
	 *
	 * @return SEH의 예외 필터 값인 EXCEPTION_EXECUTE_HANDLER를 반환합니다.
	 */
	static LONG WINAPI DetectApplicationCrash(EXCEPTION_POINTERS* exceptionPtr);


private:
	/**
	 * @brief 미니 덤프 파일을 생성합니다.
	 *
	 * @param minidumpFilename 크래시 덤프 파일의 이름입니다.
	 * @param exceptionPtr 예외 정보에 대한 포인터 값입니다.
	 */
	static void GenerateMinidumpFile(const std::wstring& minidumpFilename, EXCEPTION_POINTERS* exceptionPtr);


private:
	/**
	 * @brief 미니 덤프 파일이 저장될 경로입니다.
	 */
	static std::wstring minidumpPath_;


	/**
	 * @brief 덤프 파일 생성의 성공 여부입니다.
	 */
	static bool bIsGeneratedDump_;
};