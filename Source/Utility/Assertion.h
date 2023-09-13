#pragma once

#include <windows.h>

#include "Utility/String.h"
#include "Utility/Logging.h"


/**
 * @brief 평가식이 참인지 검사합니다.
 *
 * @note
 * - 디버거가 있으면 브레이크 포인트가 걸립니다.
 * - 디버거가 없으면 크래시 덤프 파일을 생성합니다.
 * - DEBUG 모드에서는 BREAK가 걸릴 경우 즉시 프로세스가 종료됩니다.
 * - RELEASE 모드에서는 BREAK가 걸릴 경우 브레이크만 걸리고 다음 스텝을 진행할 수 있습니다.
 * - SHIPPING 모드에서는 검사하지 않습니다.
 *
 * @param EXPRESSION 검사할 평가식입니다.
 * @param ... 평가식을 만족하지 못할 경우 표시할 가변 인자 기반 메시지입니다.
 */
#if defined(DEBUG)
#ifndef ASSERT
#define ASSERT(EXPRESSION, ...)\
{\
	if (!(EXPRESSION))\
	{\
		LogManager::Get().OutputLogMessage(LogManager::ELevel::Error, "Assertion check point failed! FILE : %s, LINE : %d, EXPRESSION : %s", __FILE__, __LINE__, #EXPRESSION);\
		LogManager::Get().OutputLogMessage(LogManager::ELevel::Error, __VA_ARGS__);\
		__debugbreak();\
		ExitProcess(-1);\
	}\
}
#endif
#elif defined(RELEASE)
#define ASSERT(EXPRESSION, ...)\
{\
	if (!(EXPRESSION))\
	{\
		LogManager::Get().OutputLogMessage(LogManager::ELevel::Error, "Assertion check point failed! FILE : %s, LINE : %d, EXPRESSION : %s", __FILE__, __LINE__, #EXPRESSION);\
		LogManager::Get().OutputLogMessage(LogManager::ELevel::Error, __VA_ARGS__);\
		__debugbreak();\
	}\
}
#else // defined(SHIPPING)
#ifndef ASSERT
#define ASSERT(EXPRESSION, ...) ((void)(EXPRESSION))
#endif
#endif