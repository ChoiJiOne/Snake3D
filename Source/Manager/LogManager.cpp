#include "Manager/LogManager.h"

#include "Utility/FileSystem.h"
#include "Utility/Assertion.h"
#include "Utility/String.h"

#include <iostream>
#include <fstream>
#include <windows.h>

void LogManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize log manager...");

	bIsInitialized_ = true;
}

void LogManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}

void LogManager::OutputLogMessage(const ELevel& level, const char* message, ...)
{
	static const int32_t MAX_BUFFER_SIZE = 1024;
	static char buffer[MAX_BUFFER_SIZE];

	va_list args;
	va_start(args, message);
	int32_t size = vsnprintf(buffer, MAX_BUFFER_SIZE, message, args);
	va_end(args);

	std::string logMessage = std::string(buffer, size);

	OutputLogMessage(level, logMessage);
}

std::string LogManager::GetCurrentSystemTime() const
{
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);

	std::string currentSystemTime = String::Format(
		"%4d-%02d-%02d %02d:%02d:%02d",
		static_cast<int32_t>(systemTime.wYear),
		static_cast<int32_t>(systemTime.wMonth),
		static_cast<int32_t>(systemTime.wDay),
		static_cast<int32_t>(systemTime.wHour),
		static_cast<int32_t>(systemTime.wMinute),
		static_cast<int32_t>(systemTime.wSecond)
	);
	
	return currentSystemTime;
}

std::string LogManager::GetLogLevelString(const ELevel& level) const
{
	std::string logLevel;

	switch (level)
	{
	case ELevel::Info:
		logLevel = "INFO";
		break;

	case ELevel::Warn:
		logLevel = "WARN";
		break;

	case ELevel::Error:
		logLevel = "ERROR";
		break;

	case ELevel::Debug:
		logLevel = "DEBUG";
		break;

	default:
		logLevel = "UNDEFINED";
		break;
	}

	return logLevel;
}

void LogManager::OutputLogMessage(const ELevel& level, const std::string& message)
{
	std::string systime = GetCurrentSystemTime();
	std::string logLevel = GetLogLevelString(level);

	std::string outputMessage = String::Format("[%s][%s] %s\n", systime.c_str(), logLevel.c_str(), message.c_str());
	messageCahce_.push_back(outputMessage);
	
	switch (mode_)
	{
	case EMode::Console:
		std::cout << outputMessage;
		break;

	case EMode::WinDebug:
		OutputDebugStringA(outputMessage.c_str());
		break;

	default:
		break;
	}
}

void LogManager::ExportOutputLog(const std::string& path)
{
	std::string outputPath = path;
	if (!FileSystem::GetFileExtension(path).compare("txt"))
	{
		std::string filename = FileSystem::RemoveFileExtension(path);
		outputPath = filename + ".txt";
	}

	int32_t count = 0;
	while (FileSystem::IsValidPath(outputPath))
	{
		std::string filename = FileSystem::RemoveFileExtension(path);
		std::string extension = FileSystem::GetFileExtension(path);

		filename += std::to_string(count++);

		outputPath = filename + "." + extension;
	}

	std::string logMessage;
	for (const auto& message : messageCahce_)
	{
		logMessage += message;
	}

	std::ofstream outputLogFile(outputPath);
	if (outputLogFile.is_open())
	{
		outputLogFile << logMessage;
	}
	outputLogFile.close();
}