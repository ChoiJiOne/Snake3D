#pragma once

#include <cstdint>
#include <random>


/**
 * @brief ���� ���� ����� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ������ �޼���� ��� ����(static) Ÿ���Դϴ�.
 */
class Random
{
public:
	/**
	 * @brief ������ ������ �����մϴ�.
	 *
	 * @param minValue ������ ���� ������ �ּڰ��Դϴ�.
	 * @param maxValue ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return ������ ������ ������ ��ȯ�մϴ�.
	 */
	static int32_t GenerateRandomInt(int32_t minValue, int32_t maxValue);


	/**
	 * @brief ������ �Ǽ��� �����մϴ�.
	 *
	 * @param minValue ������ ���� ������ �ּڰ��Դϴ�.
	 * @param maxValue ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return ������ ������ �Ǽ��� ��ȯ�մϴ�.
	 */
	static float GenerateRandomFloat(float minValue, float maxValue);
};