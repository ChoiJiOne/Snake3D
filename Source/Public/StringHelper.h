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
};