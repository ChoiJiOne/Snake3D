#pragma once

#include <vector>
#include <string>
#include <cstdarg>
#include <windows.h>


/**
 * @brief 표준 문자열에 대한 헬퍼 기능을 수행합니다.
 *
 * @note 이 클래스의 메서드와 멤버 변수는 모두 정적(static) 형식입니다.
 */
class StringHelper
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
	static inline std::vector<std::string> Split(const std::string& text, const std::string& delimiter)
	{
		std::vector<std::string> tokens;
		std::size_t position = 0ULL;
		std::string remain = text;

		while ((position = remain.find(delimiter)) != std::string::npos)
		{
			tokens.push_back(remain.substr(0, position));
			remain.erase(0, position + delimiter.length());
		}

		tokens.push_back(remain);

		return tokens;
	}


	/**
	 * @brief 특정 문자열을 기준으로 텍스트를 분리합니다.
	 *
	 * @param text 분리할 대상 문자열입니다.
	 * @param delimiter 분리를 위한 기준 문자열입니다.
	 *
	 * @return 분리된 문자열을 담고 있는 벡터(std::vector)입니다.
	 */
	static inline std::vector<std::wstring> Split(const std::wstring& text, const std::wstring& delimiter)
	{
		std::vector<std::wstring> tokens;
		std::size_t position = 0ULL;
		std::wstring remain = text;

		while ((position = remain.find(delimiter)) != std::string::npos)
		{
			tokens.push_back(remain.substr(0, position));
			remain.erase(0, position + delimiter.length());
		}

		tokens.push_back(remain);

		return tokens;
	}


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
	static inline std::string Format(const char* format, ...)
	{
		static char buffer[MAX_BUFFER_SIZE];

		va_list args;
		va_start(args, format);
		int32_t size = vsnprintf(buffer, MAX_BUFFER_SIZE, format, args);
		va_end(args);

		return std::string(buffer, size);
	}


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
	static inline std::wstring Format(const wchar_t* format, ...)
	{
		static wchar_t buffer[MAX_BUFFER_SIZE];

		va_list args;
		va_start(args, format);
		int32_t size = _vsnwprintf_s(buffer, MAX_BUFFER_SIZE, format, args);
		va_end(args);

		return std::wstring(buffer, size);
	}


	/**
	 * @brief UTF-8 문자열을 UTF-16 문자열로 변환합니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar
	 *
	 * @param string 변환할 문자열입니다.
	 *
	 * @return 변환된 UTF-16 문자열을 반환합니다.
	 */
	static inline std::wstring Convert(const std::string& string)
	{
		static wchar_t buffer[MAX_BUFFER_SIZE];

		if (!MultiByteToWideChar(CP_UTF8, 0, string.c_str(), -1, buffer, MAX_BUFFER_SIZE))
		{
			buffer[0] = L'\0';
		}

		return std::wstring(buffer);
	}


	/**
	 * @brief UTF-16 문자열을 UTF-8 문자열로 변환합니다.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte
	 *
	 * @param string 변환할 문자열입니다.
	 *
	 * @return 변환된 UTF-8 문자열을 반환합니다.
	 */
	static inline std::string Convert(const std::wstring& string)
	{
		static char buffer[MAX_BUFFER_SIZE];

		if (!WideCharToMultiByte(CP_UTF8, 0, &string[0], -1, buffer, MAX_BUFFER_SIZE, nullptr, nullptr))
		{
			buffer[0] = L'\0';
		}

		return std::string(buffer);
	}


private:
	/**
	 * @brief 문자열 버퍼의 최대 크기입니다.
	 */
	static const uint32_t MAX_BUFFER_SIZE = 1024;
};