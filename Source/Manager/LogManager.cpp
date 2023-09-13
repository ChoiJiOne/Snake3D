#include "LogManager.h"

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