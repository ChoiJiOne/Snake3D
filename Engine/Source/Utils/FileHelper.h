#pragma once

#include <shlwapi.h>

#include "Utils/Macro.h"


/**
 * @brief ���� ó���� ���� ���� ����� �����մϴ�.
 *
 * @note �� Ŭ������ ��� �Լ� ��ΰ� ������ ����(static) Ŭ�����Դϴ�.
 */
class FileHelper
{
public:
	/**
	 * @brief ������ �а� ���ۿ� �����մϴ�.
	 * 
	 * @param path ������ ����Դϴ�.
	 * @param outBuffer ���� ������ ������ �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
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
	 * @brief ������ �а� ���ۿ� �����մϴ�.
	 * 
	 * @param path ������ ����Դϴ�.
	 * @param outBuffer ���� ������ ������ �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilew
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
	 * @brief ���۸� ���Ͽ� ���ϴ�.
	 *
	 * @param path ������ ����Դϴ�.
	 * @param buffer ���Ͽ� �� �����Դϴ�.
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
	 * @brief ���۸� ���Ͽ� ���ϴ�.
	 * 
	 * @param path ������ ����Դϴ�.
	 * @param buffer ���Ͽ� �� �����Դϴ�.
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
	 * @brief ��ΰ� ��ȿ�� ���丮���� �˻��մϴ�.
	 * 
	 * @param directoryPath ���丮���� �˻��� ����Դϴ�.
	 *
	 * @return ��ΰ� ��ȿ�� ���丮��� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectorya
	 */
	static inline bool IsValidDirectory(const std::string& directoryPath)
	{
		return PathIsDirectoryA(directoryPath.c_str());
	}


	/**
	 * @brief ��ΰ� ��ȿ�� ���丮���� �˻��մϴ�.
	 * 
	 * @param directoryPath ���丮���� �˻��� ����Դϴ�.
	 *
	 * @return ��ΰ� ��ȿ�� ���丮��� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathisdirectoryw
	 */
	static inline bool IsValidDirectory(const std::wstring& directoryPath)
	{
		return PathIsDirectoryW(directoryPath.c_str());
	}


	/**
	 * @brief ������ ��ȿ���� �˻��մϴ�.
	 * 
	 * @param filePath ��ȿ���� �˻��� ���� ����Դϴ�.
	 *
	 * @return ������ ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsa
	 */
	static inline bool IsValidFile(const std::string& filePath)
	{
		return PathFileExistsA(filePath.c_str());
	}


	/**
	 * @brief ������ ��ȿ���� �˻��մϴ�.
	 * 
	 * @param filePath ��ȿ���� �˻��� ���� ����Դϴ�.
	 *
	 * @return ������ ��ȿ�ϴٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfileexistsw
	 */
	static inline bool IsValidFile(const std::wstring& filePath)
	{
		return PathFileExistsW(filePath.c_str());
	}

	
	/**
	 * @brief ��ο��� ���� �̸��� ������ ��θ� ����ϴ�.
	 * 
	 * @param path ���� �̸��� ������ ��θ� ���� ��ü ����Դϴ�.
	 * 
	 * @return ���� �̸��� ������ ��θ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "D:/AAA/BBB/" �Դϴ�.
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
	 * @brief ��ο��� ���� �̸��� ������ ��θ� ����ϴ�.
	 *
	 * @param path ���� �̸��� ������ ��θ� ���� ��ü ����Դϴ�.
	 * 
	 * @return ���� �̸��� ������ ��θ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "D:/AAA/BBB/" �Դϴ�.
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
	 * @brief ��ü ���� ��ο��� ���̽� ��θ� �����մϴ�.
	 * 
	 * @param path ���̽� ��θ� ������ ��ü ���� ����Դϴ�.
	 * 
	 * @return ���̽� ��ΰ� ������ ���� ��θ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "CCC.a" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "CCC.a" �Դϴ�.
	 */
	static inline std::string RemoveBasePath(const std::string& path)
	{
		return std::string(PathFindFileNameA(path.c_str()));
	}


	/**
	 * @brief ��ü ���� ��ο��� ���̽� ��θ� �����մϴ�.
	 *
	 * @param path ���̽� ��θ� ������ ��ü ���� ����Դϴ�.
	 * 
	 * @return ���̽� ��ΰ� ������ ���� ��θ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "CCC.a" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "CCC.a" �Դϴ�.
	 */
	static inline std::wstring RemoveBasePath(const std::wstring& path)
	{
		return std::wstring(PathFindFileNameW(path.c_str()));
	}


	/**
	 * @brief ��ü ���� ��ο��� ���� Ȯ���ڸ� ����ϴ�.
	 * 
	 * @param path ���� Ȯ���ڸ� ���� ��ü ���� ����Դϴ�.
	 * 
	 * @return ��ü ���� ����� ���� Ȯ���ڸ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� ".a" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� ".a" �Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensiona
	 */
	static inline std::string GetFileExtension(const std::string& path)
	{
		return std::string(PathFindExtensionA(path.c_str()));
	}


	/**
	 * @brief ��ü ���� ��ο��� ���� Ȯ���ڸ� ����ϴ�.
	 *
	 * @param path ���� Ȯ���ڸ� ���� ��ü ���� ����Դϴ�.
	 *
	 * @return ��ü ���� ����� ���� Ȯ���ڸ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� ".a" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� ".a" �Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-pathfindextensionw
	 */
	static inline std::wstring GetFileExtension(const std::wstring& path)
	{
		return std::wstring(PathFindExtensionW(path.c_str()));
	}


	/**
	 * @brief ��ü ���� ��ο��� ���� Ȯ���ڸ� �����մϴ�.
	 * 
	 * @param path ���� Ȯ���ڸ� ������ ��ü ���� ����Դϴ�.
	 * 
	 * @return ���� Ȯ���ڰ� ������ ��ü ���� ��θ� ��ȯ�մϴ�.
	 * 
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\CCC" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "D:/AAA/BBB/CCC" �Դϴ�.
	 */
	static inline std::string RemoveExtension(const std::string& path)
	{
		return path.substr(0, path.rfind("."));
	}


	/**
	 * @brief ��ü ���� ��ο��� ���� Ȯ���ڸ� �����մϴ�.
	 *
	 * @param path ���� Ȯ���ڸ� ������ ��ü ���� ����Դϴ�.
	 *
	 * @return ���� Ȯ���ڰ� ������ ��ü ���� ��θ� ��ȯ�մϴ�.
	 *
	 * @example
	 * - ���� ��ΰ� "D:\\AAA\\BBB\\CCC.a"���, ��ȯ�ϴ� ���� "D:\\AAA\\BBB\\CCC" �Դϴ�.
	 * - ���� ��ΰ� "D:/AAA/BBB/CCC.a"���, ��ȯ�ϴ� ���� "D:/AAA/BBB/CCC" �Դϴ�.
	 */
	static inline std::wstring RemoveExtension(const std::wstring& path)
	{
		return path.substr(0, path.rfind(L"."));
	}
};