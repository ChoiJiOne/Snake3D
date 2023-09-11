#pragma once

#include "Utility/String.h"


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
 * @brief 타입의 디폴트 생성자와 아무 동작도 수행하지 않는 가상 소멸자를 선언합니다.
 *
 * @param TYPE 디폴트 생성자와 가상 소멸자를 생성할 타입입니다.
 */
#ifndef DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR
#define DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(TYPE)\
TYPE() = default;\
virtual ~TYPE() {}
#endif


/**
 * @brief 타입을 싱글턴으로 설정합니다.
 *
 * @param TYPE 싱글턴으로 설정할 타입입니다.
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
 * @brief 평가식을 검사합니다.
 *
 * @note
 * - 디버거가 있으면 브레이크 포인트가 걸립니다.
 * - 디버거가 없으면 크래시 덤프 파일을 생성합니다.
 *
 * @param EXP 검사할 평가식입니다.
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