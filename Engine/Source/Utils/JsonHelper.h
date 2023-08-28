#pragma once

#include "Utils/FileHelper.h"

// @third party code - BEGIN
#include <json/json.hpp>
// @third party code - END


/**
 * @brief nlohmann 네임스페이스를 무시하기 위한 선언문입니다.
 */
using json = nlohmann::json;


/**
 * @brief Json 관련 헬퍼 기능을 수행합니다.
 *
 * @note 이 클래스의 메서드와 멤버 변수는 모두 정적(static) 형식입니다.
 */
class JsonHelper
{
public:
	/**
	 * @brief json 파일을 로딩합니다.
	 *
	 * @param path json 파일의 경로입니다.
	 *
	 * @return json 객체를 반환합니다.
	 */
	static inline json LoadJsonFromFile(const std::string& path)
	{
		ASSERT(FileHelper::IsValidFile(path), "invalid json file...");

		std::vector<uint8_t> jsonBuffer;
		FileHelper::ReadBufferFromFile(path, jsonBuffer);

		return json::parse(jsonBuffer);
	}
};