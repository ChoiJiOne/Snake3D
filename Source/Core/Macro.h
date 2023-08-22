#pragma once

#include "Core/StringHelper.h"


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
#else // defined(RELEASE) or defined(SHIPPING)
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
#endif


/**
 * @brief HRESULT ���� ��ȿ���� �˻��մϴ�.
 *
 * @note
 * - ����Ű� ������ �극��ũ ����Ʈ�� �ɸ��ϴ�.
 * - ����Ű� ������ ũ���� ���� ������ �����մϴ�.
 *
 * @param HR �˻��� HRESULT ���Դϴ�.
 * @param MESSAGE HRESULT ���� S_OK�� �ƴ� ��� ǥ���� �޽����Դϴ�.
 */
#if defined(DEBUG)
#ifndef HRESULT_ASSERT
#define HRESULT_ASSERT(HR, MESSAGE)\
	{\
		if (((HRESULT)(HR)) < 0)\
		{\
			OutputDebugStringA(StringHelper::Format("\nHRESULT Assertion Checkpoint Failed!\nFILE : %s, LINE : %d, HR = 0x%08X, MESSAGE : %s\n", __FILE__, __LINE__, HR, MESSAGE).c_str());\
			__debugbreak();\
			ExitProcess(-1);\
		}\
	}
#endif
#else // defined(RELEASE) or defined(SHIPPING)
#ifndef HRESULT_ASSERT
#define HRESULT_ASSERT(HR, MESSAGE)\
	{\
		if (((HRESULT)(HR)) < 0)\
		{\
			OutputDebugStringA(StringHelper::Format("\nHRESULT Assertion Checkpoint Failed!\nFILE : %s, LINE : %d, HR = 0x%08X, MESSAGE : %s\n", __FILE__, __LINE__, HR, MESSAGE).c_str());\
			__debugbreak();\
		}\
	}
#endif
#endif


/**
 * @brief COM ���ҽ��� �Ҵ� �����մϴ�.
 *
 * @param X �Ҵ� ������ COM ���ҽ��Դϴ�.
 */
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(X)\
{\
	if((X))\
	{\
		(X)->Release();\
		(X) = nullptr;\
	}\
}
#endif