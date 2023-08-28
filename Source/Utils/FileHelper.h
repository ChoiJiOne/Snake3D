#pragma once

#include <shlwapi.h>

#include "Utils/Macro.h"


/**
 * @brief 파일 처리에 대한 핼퍼 기능을 수행합니다.
 *
 * @note 이 클래스는 멤버 함수 모두가 정적인 정적(static) 클래스입니다.
 */
class FileHelper
{
public:
	/**
	 * @brief 파일을 읽고 버퍼에 저장합니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 *
	 * @param path 파일의 경로입니다.
	 * @param outBuffer 읽은 파일을 저장할 버퍼입니다.
	 */
	static inline void ReadBufferFromFile(const std::string& path, std::vector<uint8_t>& outBuffer)
	{
		HANDLE fileHandle = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
		ASSERT((fileHandle != INVALID_HANDLE_VALUE), "failed to create file");

		DWORD fileSize = GetFileSize(fileHandle, nullptr);

		outBuffer.resize(fileSize);
		DWORD bytesRead;

		ASSERT(ReadFile(fileHandle, &outBuffer[0], fileSize, &bytesRead, nullptr), "failed read file...");
		ASSERT(CloseHandle(fileHandle), "failed to close file...");
	}


	/**
	 * @brief 파일을 읽고 버퍼에 저장합니다.
	 *
	 * @param path 파일의 경로입니다.
	 * @param outBuffer 읽은 파일을 저장할 버퍼입니다.
	 */
	static inline void ReadBufferFromFile(const std::wstring& path, std::vector<uint8_t>& outBuffer)
	{
		HANDLE fileHandle = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
		ASSERT((fileHandle != INVALID_HANDLE_VALUE), "failed to create file...");

		DWORD fileSize = GetFileSize(fileHandle, nullptr);

		outBuffer.resize(fileSize);
		DWORD bytesRead;

		ASSERT(ReadFile(fileHandle, &outBuffer[0], fileSize, &bytesRead, nullptr), "failed read file...");
		ASSERT(CloseHandle(fileHandle), "failed to close file...");
	}


	/**
	 * @brief 버퍼를 파일에 씁니다.
	 *
	 * @param path 파일의 경로입니다.
	 * @param buffer 파일에 쓸 버퍼입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 */
	static inline void WriteBufferFromFile(const std::string& path, const std::vector<uint8_t>& buffer)
	{
		HANDLE fileHandle = CreateFileA(path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		ASSERT((fileHandle != INVALID_HANDLE_VALUE), "failed to create file...");

		DWORD bytesWrite;

		ASSERT(WriteFile(fileHandle, &buffer[0], static_cast<DWORD>(buffer.size()), &bytesWrite, nullptr), "failed to write file...");
		ASSERT(CloseHandle(fileHandle), "failed to close file...");
	}


	/**
	 * @brief 버퍼를 파일에 씁니다.
	 * 
	 * @param path 파일의 경로입니다.
	 * @param buffer 파일에 쓸 버퍼입니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew
	 */
	static inline void WriteBufferFromFile(const std::wstring& path, const std::vector<uint8_t>& buffer)
	{
		HANDLE fileHandle = CreateFileW(path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		ASSERT((fileHandle != INVALID_HANDLE_VALUE), "failed to create file...");

		DWORD bytesWrite;

		ASSERT(WriteFile(fileHandle, &buffer[0], static_cast<DWORD>(buffer.size()), &bytesWrite, nullptr), "failed to write file...");
		ASSERT(CloseHandle(fileHandle), "failed to close file...");
	}


	/**
	 * @brief 경로가 유효한 디렉토리인지 검사합니다.
	 * 
	 * @param directoryPath 디렉토리인지 검사할 경로입니다.
	 *
	 * @return 경로가 유효한 디렉토리라면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectorya
	 */
	static inline bool IsValidDirectory(const std::string& directoryPath)
	{
		return PathIsDirectoryA(directoryPath.c_str());
	}


	/**
	 * @brief 경로가 유효한 디렉토리인지 검사합니다.
	 * 
	 * @param directoryPath 디렉토리인지 검사할 경로입니다.
	 *
	 * @return 경로가 유효한 디렉토리라면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectoryw
	 */
	static inline bool IsValidDirectory(const std::wstring& directoryPath)
	{
		return PathIsDirectoryW(directoryPath.c_str());
	}
};