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
};