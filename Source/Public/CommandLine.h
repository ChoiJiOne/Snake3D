#pragma once

#include <string>
#include <unordered_map>


/**
 * @brief 커맨드 라인을 파싱하고 인자를 관리합니다.
 *
 * @note 이 클래스의 멤버 변수와 메서드 모두 정적(static) 타입입니다.
 */
class CommandLine
{
public:
	/**
	 * @brief 커맨드 라인을 파싱합니다.
	 *
	 * @param cmdLine 파싱할 전체 커맨드 라인 문자열입니다.
	 */
	static void Parse(const std::wstring& cmdLine);


	/**
	 * @brief 커맨드 라인 내에서 옵션이 유효한지 확인합니다.
	 *
	 * @param option 유효한지 확인할 옵션입니다.
	 *
	 * @return 옵션이 유효하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsValidOption(const std::wstring& option);


	/**
	 * @brief 커맨드 라인 내에서 키 값이 유효한지 확인합니다.
	 *
	 * @param key 유효한지 확인할 키 값입니다.
	 *
	 * @return 키 값이 유효하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsValidKey(const std::wstring& key);


	/**
	 * @brief 커맨드 라인 내에서 키 값에 대응하는 값을 얻습니다.
	 *
	 * @param key 커맨드 라인 내에 유효한 키 값입니다.
	 *
	 * @return 키 값에 대응하는 값을 반환합니다. 이때 키 값이 유효하지 않으면 빈 문자열을 반환합니다.
	 */
	static std::wstring GetValue(const std::wstring& key);


private:
	/**
	 * @brief 명령행 인자의 형식입니다.
	 *
	 * @note
	 * - NONE은 지원하지 않는 인자입니다.
	 * - OPTION은 명령행 인자가 "-<option>" 형식입니다.
	 * - KEYVALUE는 명령행 인자가 "<key>=<value>" 형식입니다.
	 */
	enum class EArgumentType
	{
		NONE     = 0x00,
		OPTION   = 0x01,
		KEYVALUE = 0x02,
	};


private:
	/**
	 * @brief 커맨드 라인 내 인자가 정규 표현식 패턴과 일치하는지 확인합니다.
	 *
	 * @param arg 패턴을 검사할 커맨드 라인 내 인자입니다.
	 * @param pattern 패턴 일치 확인을 위한 정규 표현식 패턴입니다.
	 *
	 * @return 커맨드 라인 내 인자가 패턴과 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool CheckArgPatternMatch(const std::wstring& arg, const std::wstring& pattern);


	/**
	 * @brief 커맨드 라인 내 인자의 형식을 얻습니다.
	 *
	 * @param 형식을 얻을 커맨드 라인 내 인자입니다.
	 *
	 * @return 커맨드 라인 내 인자의 형식 열거형을 반환합니다.
	 */
	static EArgumentType GetArgType(const std::wstring& arg);


	/**
	 * @brief 명령행 인자를 파싱합니다.
	 *
	 * @note 명령행 인자가 유효하지 않으면 아무 동작도 수행하지 않습니다.
	 *
	 * @param arg 파싱할 명령행 인자입니다.
	 */
	static void ParseArg(const std::wstring& arg);


private:
	/**
	 * @brief 실행 파일 경로입니다.
	 */
	static std::wstring executePath_;


	/**
	 * @brief 커맨드 라인 내의 옵션들입니다.
	 *
	 * @note 옵션은 커맨드 라인 내에 "-<optiont>"와 같은 형태입니다.
	 */
	static std::vector<std::wstring> options_;


	/**
	 * @brief 커맨드 라인 내의 키-값 쌍입니다.
	 *
	 * @note 키-값 쌍은 커맨드 라인 내에 "<key>=<value>"와 같은 형태입니다.
	 */
	static std::unordered_map<std::wstring, std::wstring> keyValues_;


	/**
	 * @brief 명령행 인자의 정규 표현식 패턴입니다.
	 */
	static std::unordered_map<EArgumentType, std::wstring> argPatterns_;
};