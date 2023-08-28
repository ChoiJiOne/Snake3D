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


	/**
	 * @brief 파일이 유효한지 검사합니다.
	 * 
	 * @param filePath 유효한지 검사할 파일 경로입니다.
	 *
	 * @return 파일이 유효하다면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsa
	 */
	static inline bool IsValidFile(const std::string& filePath)
	{
		return PathFileExistsA(filePath.c_str());
	}


	/**
	 * @brief 파일이 유효한지 검사합니다.
	 * 
	 * @param filePath 유효한지 검사할 파일 경로입니다.
	 *
	 * @return 파일이 유효하다면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsw
	 */
	static inline bool IsValidFile(const std::wstring& filePath)
	{
		return PathFileExistsW(filePath.c_str());
	}

	
	/**
	 * @brief 경로에서 파일 이름을 제외한 경로를 얻습니다.
	 * 
	 * @param path 파일 이름을 제외한 경로를 얻을 전체 경로입니다.
	 * 
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "D:\\AAA\\BBB\\" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "D:/AAA/BBB/" 입니다.
	 * 
	 * @return 파일 이름을 제외한 경로를 반환합니다.
	 */
	static inline std::string GetBasePath(const std::string& path)
	{
		std::size_t lastSlash;

		if ((lastSlash = path.rfind('/')) != std::string::npos)
		{
			return path.substr(0, lastSlash + 1);
		}
		else if ((lastSlash = path.rfind('\\')) != std::string::npos)
		{
			return path.substr(0, lastSlash + 1);
		}
		else
		{
			return "";
		}
	}


	/**
	 * @brief 경로에서 파일 이름을 제외한 경로를 얻습니다.
	 *
	 * @param path 파일 이름을 제외한 경로를 얻을 전체 경로입니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "D:\\AAA\\BBB\\" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "D:/AAA/BBB/" 입니다.
	 *
	 * @return 파일 이름을 제외한 경로를 반환합니다.
	 */
	static inline std::wstring GetBasePath(const std::wstring& path)
	{
		std::size_t lastSlash;

		if ((lastSlash = path.rfind(L'/')) != std::wstring::npos)
		{
			return path.substr(0, lastSlash + 1);
		}
		else if ((lastSlash = path.rfind(L'\\')) != std::wstring::npos)
		{
			return path.substr(0, lastSlash + 1);
		}
		else
		{
			return L"";
		}
	}


	/**
	 * @brief 전체 파일 경로에서 베이스 경로를 삭제합니다.
	 * 
	 * @param path 베이스 경로를 삭제할 전체 파일 경로입니다.
	 * 
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * 
	 * @return 베이스 경로가 삭제된 파일 경로를 반환합니다.
	 */
	static inline std::string RemoveBasePath(const std::string& path)
	{
		return std::string(PathFindFileNameA(path.c_str()));
	}


	/**
	 * @brief 전체 파일 경로에서 베이스 경로를 삭제합니다.
	 *
	 * @param path 베이스 경로를 삭제할 전체 파일 경로입니다.
	 * 
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "CCC.a" 입니다.
	 *
	 * @return 베이스 경로가 삭제된 파일 경로를 반환합니다.
	 */
	static inline std::wstring RemoveBasePath(const std::wstring& path)
	{
		return std::wstring(PathFindFileNameW(path.c_str()));
	}


	/**
	 * @brief 전체 파일 경로에서 파일 확장자를 얻습니다.
	 * 
	 * @param path 파일 확장자를 얻을 전체 파일 경로입니다.
	 * 
	 * @return 전체 파일 경로의 파일 확장자를 반환합니다.
	 * 
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 ".a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 ".a" 입니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensiona
	 */
	static inline std::string GetFileExtension(const std::string& path)
	{
		return std::string(PathFindExtensionA(path.c_str()));
	}


	/**
	 * @brief 전체 파일 경로에서 파일 확장자를 얻습니다.
	 *
	 * @param path 파일 확장자를 얻을 전체 파일 경로입니다.
	 * 
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 ".a" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 ".a" 입니다.
	 *
	 * @return 전체 파일 경로의 파일 확장자를 반환합니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensionw
	 */
	static inline std::wstring GetFileExtension(const std::wstring& path)
	{
		return std::wstring(PathFindExtensionW(path.c_str()));
	}


	/**
	 * @brief 전체 파일 경로에서 파일 확장자를 삭제합니다.
	 * 
	 * @param path 파일 확장자를 삭제할 전체 파일 경로입니다.
	 * 
	 * @return 파일 확장자가 삭제된 전체 파일 경로를 반환합니다.
	 * 
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "D:\\AAA\\BBB\\CCC" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "D:/AAA/BBB/CCC" 입니다.
	 */
	static inline std::string RemoveExtension(const std::string& path)
	{
		return path.substr(0, path.rfind("."));
	}


	/**
	 * @brief 전체 파일 경로에서 파일 확장자를 삭제합니다.
	 *
	 * @param path 파일 확장자를 삭제할 전체 파일 경로입니다.
	 *
	 * @return 파일 확장자가 삭제된 전체 파일 경로를 반환합니다.
	 *
	 * @example
	 * - 파일 경로가 "D:\\AAA\\BBB\\CCC.a"라면, 반환하는 값은 "D:\\AAA\\BBB\\CCC" 입니다.
	 * - 파일 경로가 "D:/AAA/BBB/CCC.a"라면, 반환하는 값은 "D:/AAA/BBB/CCC" 입니다.
	 */
	static inline std::wstring RemoveExtension(const std::wstring& path)
	{
		return path.substr(0, path.rfind(L"."));
	}
};