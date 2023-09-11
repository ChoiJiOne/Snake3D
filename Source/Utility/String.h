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
	std::vector<std::string> Split(const std::string& text, const std::string& delimiter);


	/**
	 * @brief 특정 문자열을 기준으로 텍스트를 분리합니다.
	 *
	 * @param text 분리할 대상 문자열입니다.
	 * @param delimiter 분리를 위한 기준 문자열입니다.
	 *
	 * @return 분리된 문자열을 담고 있는 벡터(std::vector)입니다.
	 */
	std::vector<std::wstring> Split(const std::wstring& text, const std::wstring& delimiter);
};