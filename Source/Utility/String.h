#pragma once

#include <vector>
#include <string>
#include <cstdarg>


/**
 * @brief ǥ�� ���ڿ� ����� Ȯ�� ����� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ������ �޼���� ��� ����(static) Ÿ���Դϴ�.
 */
class String
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
	std::vector<std::string> Split(const std::string& text, const std::string& delimiter);


	/**
	 * @brief Ư�� ���ڿ��� �������� �ؽ�Ʈ�� �и��մϴ�.
	 *
	 * @param text �и��� ��� ���ڿ��Դϴ�.
	 * @param delimiter �и��� ���� ���� ���ڿ��Դϴ�.
	 *
	 * @return �и��� ���ڿ��� ��� �ִ� ����(std::vector)�Դϴ�.
	 */
	std::vector<std::wstring> Split(const std::wstring& text, const std::wstring& delimiter);
};