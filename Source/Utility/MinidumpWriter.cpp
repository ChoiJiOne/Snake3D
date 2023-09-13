#include "Utility/MinidumpWriter.h"
#include "Utility/CommandLine.h"
#include "Utility/Logging.h"
#include "Utility/String.h"

#include "Manager/LogManager.h"

#include <windows.h>
#include <dbghelp.h>
#include <string>

LPTOP_LEVEL_EXCEPTION_FILTER topLevelExceptionFilter;

LONG WINAPI DetectApplicationCrash(EXCEPTION_POINTERS* exceptionPtr);
void GenerateMinidumpFile(const std::wstring& minidumpFilename, EXCEPTION_POINTERS* exceptionPtr);

void MinidumpWriter::RegisterUnhandledExceptionFilter()
{
	topLevelExceptionFilter = SetUnhandledExceptionFilter(DetectApplicationCrash);
}

void MinidumpWriter::UnregisterUnhandledExceptionFilter()
{
	SetUnhandledExceptionFilter(topLevelExceptionFilter);
}

LONG WINAPI DetectApplicationCrash(EXCEPTION_POINTERS* exceptionPtr)
{
	SYSTEMTIME currentSystemTime;
	GetLocalTime(&currentSystemTime);

	std::string logFilePath = String::Format(
		"%sWindows-%d-%d-%d-%d-%d-%d.txt",
		CommandLine::GetValue("Crash").c_str(),
		static_cast<int32_t>(currentSystemTime.wYear),
		static_cast<int32_t>(currentSystemTime.wMonth),
		static_cast<int32_t>(currentSystemTime.wDay),
		static_cast<int32_t>(currentSystemTime.wHour),
		static_cast<int32_t>(currentSystemTime.wMinute),
		static_cast<int32_t>(currentSystemTime.wSecond)
	);
	LogManager::Get().ExportOutputLogToPath(logFilePath);

	std::wstring minidumpFilePath = String::Format(
		L"%sWindows-%d-%d-%d-%d-%d-%d.dmp",
		String::Convert(CommandLine::GetValue("Crash")).c_str(),
		static_cast<int32_t>(currentSystemTime.wYear),
		static_cast<int32_t>(currentSystemTime.wMonth),
		static_cast<int32_t>(currentSystemTime.wDay),
		static_cast<int32_t>(currentSystemTime.wHour),
		static_cast<int32_t>(currentSystemTime.wMinute),
		static_cast<int32_t>(currentSystemTime.wSecond)
	);
	GenerateMinidumpFile(minidumpFilePath, exceptionPtr);

	return EXCEPTION_EXECUTE_HANDLER;
}

void GenerateMinidumpFile(const std::wstring& minidumpFilename, EXCEPTION_POINTERS* exceptionPtr)
{
	HANDLE minidumpFileHandle = CreateFileW(
		minidumpFilename.c_str(),
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr
	);

	if (minidumpFileHandle == INVALID_HANDLE_VALUE)
	{
		return;
	}

	_MINIDUMP_EXCEPTION_INFORMATION exception;
	exception.ThreadId = GetCurrentThreadId();
	exception.ExceptionPointers = exceptionPtr;
	exception.ClientPointers = FALSE;

	bool bIsGeneratedDump_ = MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		minidumpFileHandle,
		MiniDumpWithFullMemory,
		&exception,
		nullptr,
		nullptr
	);

	CloseHandle(minidumpFileHandle);
}