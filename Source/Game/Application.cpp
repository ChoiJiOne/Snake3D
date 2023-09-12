#include <iostream>
#include <windows.h>

#include "Utility/CommandLine.h"
#include "Utility/String.h"
#include "Utility/Macro.h"
#include "Utility/MinidumpWriter.h"

int32_t main(int32_t argc, char* argv[])
{
	CommandLine::Parse(argc, argv);
	MinidumpWriter::RegisterUnhandledExceptionFilter();
	
	MinidumpWriter::UnregisterUnhandledExceptionFilter();
	return 0;
}