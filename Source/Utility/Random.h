#pragma once

#include <cstdint>
#include <random>


/**
 * @brief 난수 관련 기능을 제공합니다.
 * 
 * @note 이 클래스의 멤버 변수와 메서드는 모두 정적(static) 타입입니다.
 */
class Random
{
public:
	/**
	 * @brief 임의의 정수를 생성합니다.
	 *
	 * @param minValue 생성할 난수 범위의 최솟값입니다.
	 * @param maxValue 생성할 난수 범위의 최댓값입니다.
	 *
	 * @return 생성된 임의의 정수를 반환합니다.
	 */
	static int32_t GenerateRandomInt(int32_t minValue, int32_t maxValue);


	/**
	 * @brief 임의의 실수를 생성합니다.
	 *
	 * @param minValue 생성할 난수 범위의 최솟값입니다.
	 * @param maxValue 생성할 난수 범위의 최댓값입니다.
	 *
	 * @return 생성된 임의의 실수를 반환합니다.
	 */
	static float GenerateRandomFloat(float minValue, float maxValue);
};