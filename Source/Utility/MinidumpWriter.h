#pragma once


/**
 * @brief 프로그램 실행 중 발생한 크래시를 기반으로 미니 덤프 파일을 생성합니다.
 *
 * @note 이 클래스는 모든 메서드가 정적인 정적 클래스입니다.
 */
class MinidumpWriter
{
public:
	/**
	 * @brief 애플리케이션이 프로세스의 각 스레드에 대한 최상위 예외 처리기를 등록합니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter
	 */
	static void RegisterUnhandledExceptionFilter();


	/**
	 * @brief 애플리케이션이 프로세스의 각 스레드에 대한 최상위 예외 처리기 등록을 해제합니다.
	 */
	static void UnregisterUnhandledExceptionFilter();
};