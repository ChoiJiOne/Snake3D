#pragma once

#include "Utils/FileHelper.h"

// @third party code - BEGIN
#include <json/json.hpp>
// @third party code - END


/**
 * @brief nlohmann ���ӽ����̽��� �����ϱ� ���� �����Դϴ�.
 */
using json = nlohmann::json;


/**
 * @brief Json ���� ���� ����� �����մϴ�.
 *
 * @note �� Ŭ������ �޼���� ��� ������ ��� ����(static) �����Դϴ�.
 */
class JsonHelper
{
public:
	/**
	 * @brief json ������ �ε��մϴ�.
	 *
	 * @param path json ������ ����Դϴ�.
	 *
	 * @return json ��ü�� ��ȯ�մϴ�.
	 */
	static inline json LoadJsonFromFile(const std::string& path)
	{
		ASSERT(FileHelper::IsValidFile(path), "invalid json file...");

		std::vector<uint8_t> jsonBuffer;
		FileHelper::ReadBufferFromFile(path, jsonBuffer);

		return json::parse(jsonBuffer);
	}


	/**
	 * @brief json ������ �ε��մϴ�.
	 *
	 * @param path json ������ ����Դϴ�.
	 *
	 * @return json ��ü�� ��ȯ�մϴ�.
	 */
	static inline json LoadJsonFromFile(const std::wstring& path)
	{
		ASSERT(FileHelper::IsValidFile(path), "invalid json file...");

		std::vector<uint8_t> jsonBuffer;
		FileHelper::ReadBufferFromFile(path, jsonBuffer);

		return json::parse(jsonBuffer);
	}
};