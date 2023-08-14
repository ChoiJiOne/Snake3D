#pragma once

#include <vector>
#include <string>
#include <cstdarg>
#include <windows.h>


/**
 * @brief ǥ�� ���ڿ��� ���� ���� ����� �����մϴ�.
 *
 * @note �� Ŭ������ �޼���� ��� ������ ��� ����(static) �����Դϴ�.
 */
class StringHelper
{
public:
	/**
	 * @brief Ư�� ���ڿ��� �������� �ؽ�Ʈ�� �и��մϴ�.
	 *
	 * @param text �и��� ��� ���ڿ��Դϴ�.
	 * @param delimiter �и��� ���� ���� ���ڿ��Դϴ�.
	 *
	 * @return �и��� ���ڿ��� ��� �ִ� ����(std::vector)�� ��ȯ�մϴ�.
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
	 * @brief Ư�� ���ڿ��� �������� �ؽ�Ʈ�� �и��մϴ�.
	 *
	 * @param text �и��� ��� ���ڿ��Դϴ�.
	 * @param delimiter �и��� ���� ���� ���ڿ��Դϴ�.
	 *
	 * @return �и��� ���ڿ��� ��� �ִ� ����(std::vector)�Դϴ�.
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