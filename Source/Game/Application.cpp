#include <iostream>
#include <windows.h>

#include "Manager/LogManager.h"
#include "Manager/RenderManager.h"

#include "Utility/Assertion.h"
#include "Utility/CommandLine.h"
#include "Utility/String.h"
#include "Utility/Logging.h"
#include "Utility/Macro.h"
#include "Utility/MinidumpWriter.h"

int32_t main(int32_t argc, char* argv[])
{
	CommandLine::Parse(argc, argv);
	MinidumpWriter::RegisterUnhandledExceptionFilter();

	LogManager::Get().Initialize();
	RenderManager::Get().Initialize();

	RenderManager::Get().Release();
	LogManager::Get().Release();

	MinidumpWriter::UnregisterUnhandledExceptionFilter();
	return 0;
}