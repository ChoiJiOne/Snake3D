#pragma once

#include <string>
#include <unordered_map>


/**
 * @brief Ŀ�ǵ� ������ �Ľ��ϰ� ���ڸ� �����մϴ�.
 *
 * @note �� Ŭ������ ��� ������ �޼��� ��� ����(static) Ÿ���Դϴ�.
 */
class CommandLine
{
public:
	/**
	 * @brief Ŀ�ǵ� ������ �Ľ��մϴ�.
	 *
	 * @param cmdLine �Ľ��� ��ü Ŀ�ǵ� ���� ���ڿ��Դϴ�.
	 */
	static void Parse(const std::wstring& cmdLine);


	/**
	 * @brief Ŀ�ǵ� ���� ������ �ɼ��� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param option ��ȿ���� Ȯ���� �ɼ��Դϴ�.
	 *
	 * @return �ɼ��� ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsValidOption(const std::wstring& option);


	/**
	 * @brief Ŀ�ǵ� ���� ������ Ű ���� ��ȿ���� Ȯ���մϴ�.
	 *
	 * @param key ��ȿ���� Ȯ���� Ű ���Դϴ�.
	 *
	 * @return Ű ���� ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsValidKey(const std::wstring& key);


	/**
	 * @brief Ŀ�ǵ� ���� ������ Ű ���� �����ϴ� ���� ����ϴ�.
	 *
	 * @param key Ŀ�ǵ� ���� ���� ��ȿ�� Ű ���Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ���� ��ȯ�մϴ�. �̶� Ű ���� ��ȿ���� ������ �� ���ڿ��� ��ȯ�մϴ�.
	 */
	static std::wstring GetValue(const std::wstring& key);


private:
	/**
	 * @brief ����� ������ �����Դϴ�.
	 *
	 * @note
	 * - NONE�� �������� �ʴ� �����Դϴ�.
	 * - OPTION�� ����� ���ڰ� "-<option>" �����Դϴ�.
	 * - KEYVALUE�� ����� ���ڰ� "<key>=<value>" �����Դϴ�.
	 */
	enum class EArgumentType
	{
		NONE     = 0x00,
		OPTION   = 0x01,
		KEYVALUE = 0x02,
	};


private:
	/**
	 * @brief Ŀ�ǵ� ���� �� ���ڰ� ���� ǥ���� ���ϰ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param arg ������ �˻��� Ŀ�ǵ� ���� �� �����Դϴ�.
	 * @param pattern ���� ��ġ Ȯ���� ���� ���� ǥ���� �����Դϴ�.
	 *
	 * @return Ŀ�ǵ� ���� �� ���ڰ� ���ϰ� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool CheckArgPatternMatch(const std::wstring& arg, const std::wstring& pattern);


	/**
	 * @brief Ŀ�ǵ� ���� �� ������ ������ ����ϴ�.
	 *
	 * @param ������ ���� Ŀ�ǵ� ���� �� �����Դϴ�.
	 *
	 * @return Ŀ�ǵ� ���� �� ������ ���� �������� ��ȯ�մϴ�.
	 */
	static EArgumentType GetArgType(const std::wstring& arg);


	/**
	 * @brief ����� ���ڸ� �Ľ��մϴ�.
	 *
	 * @note ����� ���ڰ� ��ȿ���� ������ �ƹ� ���۵� �������� �ʽ��ϴ�.
	 *
	 * @param arg �Ľ��� ����� �����Դϴ�.
	 */
	static void ParseArg(const std::wstring& arg);


private:
	/**
	 * @brief ���� ���� ����Դϴ�.
	 */
	static std::wstring executePath_;


	/**
	 * @brief Ŀ�ǵ� ���� ���� �ɼǵ��Դϴ�.
	 *
	 * @note �ɼ��� Ŀ�ǵ� ���� ���� "-<optiont>"�� ���� �����Դϴ�.
	 */
	static std::vector<std::wstring> options_;


	/**
	 * @brief Ŀ�ǵ� ���� ���� Ű-�� ���Դϴ�.
	 *
	 * @note Ű-�� ���� Ŀ�ǵ� ���� ���� "<key>=<value>"�� ���� �����Դϴ�.
	 */
	static std::unordered_map<std::wstring, std::wstring> keyValues_;


	/**
	 * @brief ����� ������ ���� ǥ���� �����Դϴ�.
	 */
	static std::unordered_map<EArgumentType, std::wstring> argPatterns_;
};