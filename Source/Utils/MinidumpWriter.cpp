#include "Utils/MinidumpWriter.h"
#include "Utils/StringHelper.h"

std::wstring MinidumpWriter::minidumpPath_;
bool MinidumpWriter::bIsGeneratedDump_ = false;

LONG MinidumpWriter::DetectApplicationCrash(EXCEPTION_POINTERS* exceptionPtr)
{
	SYSTEMTIME currentSystemTime;
	GetLocalTime(&currentSystemTime);

	std::wstring minidumpFilePath = StringHelper::Format(
		L"%sWindows-%d-%d-%d-%d-%d-%d.dmp",
		minidumpPath_.c_str(),
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

void MinidumpWriter::GenerateMinidumpFile(const std::wstring& minidumpFilename, EXCEPTION_POINTERS* exceptionPtr)
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
		bIsGeneratedDump_ = false;
		return;
	}

	_MINIDUMP_EXCEPTION_INFORMATION exception;
	exception.ThreadId = GetCurrentThreadId();
	exception.ExceptionPointers = exceptionPtr;
	exception.ClientPointers = FALSE;

	bIsGeneratedDump_ = MiniDumpWriteDump(
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