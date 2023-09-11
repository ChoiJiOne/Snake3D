#pragma once

#include <vector>
#include <string>
#include <cstdarg>


/**
 * @brief 표준 문자열 기반의 확장 기능을 제공합니다.
 * 
 * @note 이 클래스의 멤버 변수와 메서드는 모두 정적(static) 타입입니다.
 */
class String
{
public:
	/**
	 * @brief 특정 문자열을 기준으로 텍스트를 분리합니다.
	 *
	 * @param text 분리할 대상 문자열입니다.
	 * @param delimiter 분리를 위한 기준 문자열입니다.
	 *
	 * @return 분리된 문자열을 담고 있는 벡터(std::vector)를 반환합니다.
	 */
	static std::vector<std::string> Split(const std::string& text, const std::string& delimiter);


	/**
	 * @brief 특정 문자열을 기준으로 텍스트를 분리합니다.
	 *
	 * @param text 분리할 대상 문자열입니다.
	 * @param delimiter 분리를 위한 기준 문자열입니다.
	 *
	 * @return 분리된 문자열을 담고 있는 벡터(std::vector)입니다.
	 */
	static std::vector<std::wstring> Split(const std::wstring& text, const std::wstring& delimiter);


	/**
	 * @brief 형식화된 문자열을 반환합니다.
	 *
	 * @note
	 * - 이 메서드는 snprintf와 같은 함수를 대체하기 위한 것입니다.
	 * - 문자열의 길이는 최대 1024 입니다.
	 *
	 * @param format 형식 문자열입니다.
	 * @param ... 문자열의 형식에 대응하는 가변인자입니다.
	 *
	 * @return 형식화된 표준 문자열을 반환합니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l?view=msvc-170
	 */
	static std::string Format(const char* format, ...);


	/**
	 * @brief 형식화된 문자열을 반환합니다.
	 *
	 * @note
	 * - 이 메서드는 snprintf와 같은 함수를 대체하기 위한 것입니다.
	 * - 문자열의 길이는 최대 1024 입니다.
	 *
	 * @param format 형식 문자열입니다.
	 * @param ... 문자열의 형식에 대응하는 가변인자입니다.
	 *
	 * @return 형식화된 표준 문자열을 반환합니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l?view=msvc-170
	 */
	static std::wstring Format(const wchar_t* format, ...);


private:
	/**
	 * @brief 문자열 버퍼의 최대 크기입니다.
	 */
	static const uint32_t MAX_BUFFER_SIZE = 1024;


	/**
	 * @brief MBCS 문자열 버퍼입니다.
	 */
	static char mbcsBuffer_[MAX_BUFFER_SIZE];


	/**
	 * @brief WCS 문자열 버퍼입니다.
	 */
	static wchar_t wcsBuffer_[MAX_BUFFER_SIZE];
};