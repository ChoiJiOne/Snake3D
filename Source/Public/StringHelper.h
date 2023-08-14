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


	/**
	 * @brief ����ȭ�� ���ڿ��� ��ȯ�մϴ�.
	 *
	 * @note
	 * - �� �޼���� snprintf�� ���� �Լ��� ��ü�ϱ� ���� ���Դϴ�.
	 * - ���ڿ��� ���̴� �ִ� 1024 �Դϴ�.
	 *
	 * @param format ���� ���ڿ��Դϴ�.
	 * @param ... ���ڿ��� ���Ŀ� �����ϴ� ���������Դϴ�.
	 *
	 * @return ����ȭ�� ǥ�� ���ڿ��� ��ȯ�մϴ�.
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
	 * @brief ����ȭ�� ���ڿ��� ��ȯ�մϴ�.
	 *
	 * @note
	 * - �� �޼���� snprintf�� ���� �Լ��� ��ü�ϱ� ���� ���Դϴ�.
	 * - ���ڿ��� ���̴� �ִ� 1024 �Դϴ�.
	 *
	 * @param format ���� ���ڿ��Դϴ�.
	 * @param ... ���ڿ��� ���Ŀ� �����ϴ� ���������Դϴ�.
	 *
	 * @return ����ȭ�� ǥ�� ���ڿ��� ��ȯ�մϴ�.
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


private:
	/**
	 * @brief ���ڿ� ������ �ִ� ũ���Դϴ�.
	 */
	static const uint32_t MAX_BUFFER_SIZE = 1024;
};