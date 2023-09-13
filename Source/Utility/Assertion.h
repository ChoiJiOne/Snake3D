#pragma once

#include <windows.h>

#include "Utility/String.h"
#include "Utility/Logging.h"


/**
 * @brief �򰡽��� ������ �˻��մϴ�.
 *
 * @note
 * - ����Ű� ������ �극��ũ ����Ʈ�� �ɸ��ϴ�.
 * - ����Ű� ������ ũ���� ���� ������ �����մϴ�.
 * - DEBUG ��忡���� BREAK�� �ɸ� ��� ��� ���μ����� ����˴ϴ�.
 * - RELEASE ��忡���� BREAK�� �ɸ� ��� �극��ũ�� �ɸ��� ���� ������ ������ �� �ֽ��ϴ�.
 * - SHIPPING ��忡���� �˻����� �ʽ��ϴ�.
 *
 * @param EXPRESSION �˻��� �򰡽��Դϴ�.
 * @param ... �򰡽��� �������� ���� ��� ǥ���� ���� ���� ��� �޽����Դϴ�.
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