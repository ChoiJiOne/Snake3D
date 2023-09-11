#pragma once

#include <string>


/**
 * @brief ���� �� ���丮 ���� Ȯ�� ����� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ������ �޼���� ��� ����(static) Ÿ���Դϴ�.
 */
class FileSystem
{
public:
	/**
	 * @brief ���� Ȥ�� ���丮 ��ΰ� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param path ���� Ȥ�� ���丮 ����Դϴ�.
	 *
	 * @return ���� Ȥ�� ���丮�� ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsValidPath(const std::string& path);


	/**
	 * @brief ���� Ȥ�� ���丮 ��ΰ� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param path ���� Ȥ�� ���丮 ����Դϴ�.
	 *
	 * @return ���� Ȥ�� ���丮�� ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsValidPath(const std::wstring& path);


	/**
	 * @brief ��ΰ� ���� ������� Ȯ���մϴ�.
	 *
	 * @param path ���� ������� Ȯ���� ��ü ����Դϴ�.
	 *
	 * @return ��ΰ� ���� ��ζ�� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsFilePath(const std::string& path);


	/**
	 * @brief ��ΰ� ���� ������� Ȯ���մϴ�.
	 *
	 * @param path ���� ������� Ȯ���� ��ü ����Դϴ�.
	 *
	 * @return ��ΰ� ���� ��ζ�� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsFilePath(const std::wstring& path);
};