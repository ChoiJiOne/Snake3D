#pragma once

#include "StringHelper.h"


/**
 * @brief Ÿ���� ���� ������ �� ���� �����ڸ� ������� ���ϵ��� �����մϴ�.
 *
 * @note �� ��ũ�θ� ������� �ʴ� Ŭ������ �ݵ�� ��������� ���� �����ڿ� ���� �����ڸ� �����ؾ� �մϴ�.
 *
 * @param TYPE ���� ������ �� ���� �����ڸ� ������ Ÿ���Դϴ�.
 */
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TYPE)\
TYPE(TYPE&&) = delete;\
TYPE(const TYPE&) = delete;\
TYPE& operator=(TYPE&&) = delete;\
TYPE& operator=(const TYPE&) = delete;
#endif


/**
 * @brief Ÿ���� ����Ʈ �����ڿ� �ƹ� ���۵� �������� �ʴ� ���� �Ҹ��ڸ� �����մϴ�.
 *
 * @param TYPE ����Ʈ �����ڿ� ���� �Ҹ��ڸ� ������ Ÿ���Դϴ�.
 */
#ifndef DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR
#define DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(TYPE)\
TYPE() = default;\
virtual ~TYPE() {}
#endif


/**
 * @brief �򰡽��� ������ �˻��մϴ�.
 *
 * @note
 * - ����Ű� ������ �극��ũ ����Ʈ�� �ɸ��ϴ�.
 * - ����Ű� ������ ũ���� ���� ������ �����մϴ�.
 *
 * @param EXP �˻��� �򰡽��Դϴ�.
 * @param MESSAGE �򰡽��� �������� ���� ��� ǥ���� �޽����Դϴ�.
 */
#if defined(DEBUG)
#ifndef ASSERT
#define ASSERT(EXP, MESSAGE)\
	{\
		if (!(EXP))\
		{\
			OutputDebugStringA(StringHelper::Format("\nAssertion Checkpoint Failed!\nFILE : %s, LINE : %d, EXP : %s, MESSAGE : %s\n", __FILE__, __LINE__, #EXP, MESSAGE).c_str());\
			__debugbreak();\
			ExitProcess(-1);\
		}\
	}
#endif
#elif defined(RELEASE) 
#ifndef ASSERT
#define ASSERT(EXP, MESSAGE)\
	{\
		if (!(EXP))\
		{\
			OutputDebugStringA(StringHelper::Format("\nAssertion Checkpoint Failed!\nFILE : %s, LINE : %d, EXP : %s, MESSAGE : %s\n", __FILE__, __LINE__, #EXP, MESSAGE).c_str());\
			__debugbreak();\
		}\
	}
#endif
#else // defined(SHIPPING)
#ifndef ASSERT
#define ASSERT(EXP, MESSAGE)
#endif
#endif