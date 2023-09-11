#pragma once

#include "Utility/String.h"


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
 * @brief Ÿ���� �̱������� �����մϴ�.
 *
 * @param TYPE �̱������� ������ Ÿ���Դϴ�.
 */
#ifndef SINGLETON
#define SINGLETON(TYPE)\
TYPE(TYPE&&) = delete;\
TYPE(const TYPE&) = delete;\
TYPE& operator=(TYPE&&) = delete;\
TYPE& operator=(const TYPE&) = delete;\
static TYPE& Get()\
{\
	static TYPE instance;\
	return instance;\
}
#endif


/**
 * @brief �򰡽��� �˻��մϴ�.
 *
 * @note
 * - ����Ű� ������ �극��ũ ����Ʈ�� �ɸ��ϴ�.
 * - ����Ű� ������ ũ���� ���� ������ �����մϴ�.
 *
 * @param EXP �˻��� �򰡽��Դϴ�.
 */
#if defined(DEBUG)
#ifndef CHECK
#define CHECK(EXP)\
	{\
		if (!(EXP))\
		{\
			__debugbreak();\
			ExitProcess(-1);\
		}\
	}
#endif
#else // defined(RELEASE) or defined(SHIPPING)
#ifndef CHECK
#define CHECK(EXP)\
	{\
		if (!(EXP))\
		{\
			__debugbreak();\
		}\
	}
#endif
#endif