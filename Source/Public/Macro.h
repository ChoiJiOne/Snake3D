#pragma once

#include "StringHelper.h"


/**
 * @brief 타입의 복사 생성자 및 대입 연산자를 사용하지 못하도록 삭제합니다.
 *
 * @note 이 매크로를 사용하지 않는 클래스는 반드시 명시적으로 대입 연산자와 복사 생성자를 정의해야 합니다.
 *
 * @param TYPE 복사 생성자 및 대입 연산자를 삭제할 타입입니다.
 */
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TYPE)\
TYPE(TYPE&&) = delete;\
TYPE(const TYPE&) = delete;\
TYPE& operator=(TYPE&&) = delete;\
TYPE& operator=(const TYPE&) = delete;
#endif


/**
 * @brief 평가식이 참인지 검사합니다.
 *
 * @note
 * - 디버거가 있으면 브레이크 포인트가 걸립니다.
 * - 디버거가 없으면 크래시 덤프 파일을 생성합니다.
 *
 * @param EXP 검사할 평가식입니다.
 * @param MESSAGE 평가식을 만족하지 못할 경우 표시할 메시지입니다.
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