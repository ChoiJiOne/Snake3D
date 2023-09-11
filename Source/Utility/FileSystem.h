#pragma once

#include <string>


/**
 * @brief 파일 및 디렉토리 관련 확장 기능을 수행합니다.
 * 
 * @note 이 클래스의 멤버 변수와 메서드는 모두 정적(static) 타입입니다.
 */
class FileSystem
{
public:
	/**
	 * @brief 파일 혹은 디렉토리 경로가 유효한지 확인합니다.
	 *
	 * @param path 파일 혹은 디렉토리 경로입니다.
	 *
	 * @return 파일 혹은 디렉토리가 유효하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsValidPath(const std::string& path);


	/**
	 * @brief 파일 혹은 디렉토리 경로가 유효한지 확인합니다.
	 *
	 * @param path 파일 혹은 디렉토리 경로입니다.
	 *
	 * @return 파일 혹은 디렉토리가 유효하다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsValidPath(const std::wstring& path);


	/**
	 * @brief 경로가 파일 경로인지 확인합니다.
	 *
	 * @param path 파일 경로인지 확인할 전체 경로입니다.
	 *
	 * @return 경로가 파일 경로라면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsFilePath(const std::string& path);


	/**
	 * @brief 경로가 파일 경로인지 확인합니다.
	 *
	 * @param path 파일 경로인지 확인할 전체 경로입니다.
	 *
	 * @return 경로가 파일 경로라면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsFilePath(const std::wstring& path);


	/**
	 * @brief 경로가 디렉토리 경로인지 확인합니다.
	 *
	 * @param path 디렉토리 경로인지 확인할 전체 경로입니다.
	 *
	 * @return 경로가 디렉토리 경로라면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsDirectoryPath(const std::string& path);


	/**
	 * @brief 경로가 디렉토리 경로인지 확인합니다.
	 *
	 * @param path 디렉토리 경로인지 확인할 전체 경로입니다.
	 *
	 * @return 경로가 디렉토리 경로라면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsDirectoryPath(const std::wstring& path);


	/**
	 * @brief 경로에서 파일이나 디렉토리 이름을 제외한 경로를 얻습니다.
	 *
	 * @param path 파일이나 디렉토리 경로입니다.
	 *
	 * @return 파일이나 디렉토리 이름을 제외한 경로를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "D:\\AAA\\BBB\\" 입니다.
	 * - 디렉토리 경로가 "D:\\AAA\\BBB\\CCC"라면, 반환하는 값은 "D:\\AAA\\BBB\\" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "D:/AAA/BBB/" 입니다.
	 * - 디렉토리 경로가 "D:/AAA/BBB/CCC"라면, 반환하는 값은 "D:/AAA/BBB/" 입니다.
	 */
	static std::string GetBasePath(const std::string& path);


	/**
	 * @brief 경로에서 파일이나 디렉토리 이름을 제외한 경로를 얻습니다.
	 *
	 * @param path 파일이나 디렉토리 경로입니다.
	 *
	 * @return 파일이나 디렉토리 이름을 제외한 경로를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "D:\\AAA\\BBB\\" 입니다.
	 * - 디렉토리 경로가 "D:\\AAA\\BBB\\CCC"라면, 반환하는 값은 "D:\\AAA\\BBB\\" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "D:/AAA/BBB/" 입니다.
	 * - 디렉토리 경로가 "D:/AAA/BBB/CCC"라면, 반환하는 값은 "D:/AAA/BBB/" 입니다.
	 */
	static std::wstring GetBasePath(const std::wstring& path);


	/**
	 * @brief 전체 파일이나 디렉토리 경로에서 베이스 경로를 삭제합니다.
	 *
	 * @param path 베이스 경로를 삭제할 전체 파일이나 디렉토리 경로입니다.
	 *
	 * @return 베이스 경로가 삭제된 파일 경로를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * - 디렉토리 경로가 "D:\\AAA\\BBB\\CCC"라면, 반환하는 값은 "CCC" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC"라면, 반환하는 값은 "CCC" 입니다.
	 */
	static std::string RemoveBasePath(const std::string& path);


	/**
	 * @brief 전체 파일이나 디렉토리 경로에서 베이스 경로를 삭제합니다.
	 *
	 * @param path 베이스 경로를 삭제할 전체 파일이나 디렉토리 경로입니다.
	 *
	 * @return 베이스 경로가 삭제된 파일 경로를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * - 디렉토리 경로가 "D:\\AAA\\BBB\\CCC"라면, 반환하는 값은 "CCC" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC"라면, 반환하는 값은 "CCC" 입니다.
	 */
	static std::wstring RemoveBasePath(const std::wstring& path);


	/**
	 * @brief 전체 파일 경로에서 파일 확장자를 얻습니다.
	 *
	 * @param path 파일 확장자를 얻을 전체 파일 경로입니다.
	 *
	 * @return 전체 파일 경로의 파일 확장자를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "a" 입니다.
	 */
	static std::string GetFileExtension(const std::string& path);


	/**
	 * @brief 전체 파일 경로에서 파일 확장자를 얻습니다.
	 *
	 * @param path 파일 확장자를 얻을 전체 파일 경로입니다.
	 *
	 * @return 전체 파일 경로의 파일 확장자를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "a" 입니다.
	 */
	static std::wstring GetFileExtension(const std::wstring& path);
};