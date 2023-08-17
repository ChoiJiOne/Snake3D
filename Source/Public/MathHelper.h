#pragma once

#include <cstdint>
#include <limits>

#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

#include "Matrix/Matrix2x2.h"
#include "Matrix/Matrix3x3.h"
#include "Matrix/Matrix4x4.h"


/**
 * @brief float 타입의 파이(π) 값입니다.
 */
const float PI_F = 3.1415926535F;


/**
 * @brief double 타입의 파이(π) 값입니다.
 */
const double PI_D = 3.1415926535897931;


/**
 * @brief float 타입의 타입의 엡실론(ε) 값입니다.
 */
const float EPSILON_F = std::numeric_limits<float>::epsilon();


/**
 * @brief double 타입의 엡실론(ε) 값입니다.
 */
const double EPSILON_D = std::numeric_limits<double>::epsilon();


/**
 * @brief float 타입의 무한대 값입니다.
 */
const float INFINITY_F = std::numeric_limits<float>::infinity();


/**
 * @brief double 타입의 무한대 값입니다.
 */
const double INFINITY_D = std::numeric_limits<double>::infinity();


/**
 * @brief float 타입의 음의 무한대 값입니다.
 */
const float NINFINITY_F = -std::numeric_limits<float>::infinity();


/**
 * @brief double 타입의 음의 무한대 값입니다.
 */
const double NINFINITY_D = -std::numeric_limits<double>::infinity();


/**
 * @brief int 타입의 2차원 벡터입니다.
 */
using Vector2i = Vector2<int32_t>;


/**
 * @brief float 타입의 2차원 벡터입니다.
 */
using Vector2f = Vector2<float>;


/**
 * @brief int 타입의 3차원 벡터입니다.
 */
using Vector3i = Vector3<int32_t>;


/**
 * @brief float 타입의 3차원 벡터입니다.
 */
using Vector3f = Vector3<float>;


/**
 * @brief int 타입의 4차원 벡터입니다.
 */
using Vector4i = Vector4<int32_t>;


/**
 * @brief float 타입의 4차원 벡터입니다.
 */
using Vector4f = Vector4<float>;


/**
 * @brief int 타입의 2x2 행렬입니다.
 */
using Matrix2x2i = Matrix2x2<int32_t>;


/**
 * @brief float 타입의 2x2 행렬입니다.
 */
using Matrix2x2f = Matrix2x2<float>;


/**
 * @brief int 타입의 3x3 행렬입니다.
 */
using Matrix3x3i = Matrix3x3<int32_t>;


/**
 * @brief float 타입의 3x3 행렬입니다.
 */
using Matrix3x3f = Matrix3x3<float>;


/**
 * @brief int 타입의 4x4 행렬입니다.
 */
using Matrix4x4i = Matrix4x4<int32_t>;


/**
 * @brief float 타입의 4x4 행렬입니다.
 */
using Matrix4x4f = Matrix4x4<float>;


/**
 * @brief 수학 관련 헬퍼 기능을 수행합니다.
 * 
 * @note 이 클래스의 메서드와 멤버 변수는 모두 정적(static) 형식입니다.
 */
class MathHelper
{
public:
	/**
	 * @brief 라디안 각을 육십분법 각으로 변환합니다.
	 *
	 * @param radian 변환할 라디안 각입니다.
	 *
	 * @return 변환된 육십분법 각입니다.
	 */
	static inline float ToDegree(float radian)
	{
		return (radian * 180.0f) / PI_F;
	}


	/**
	 * @brief 라디안 각을 육십분법 각으로 변환합니다.
	 *
	 * @param radian 변환할 라디안 각입니다.
	 *
	 * @return 변환된 육십분법 각입니다.
	 */
	static inline double ToDegree(double radian)
	{
		return (radian * 180.0) / PI_D;
	}


	/**
	 * @brief 육십분법 각을 라디안 각으로 변환합니다.
	 *
	 * @param degree 변환할 육십분법 각입니다.
	 *
	 * @return 변환된 라디안 각입니다.
	 */
	static inline float ToRadian(float degree)
	{
		return (degree * PI_F) / 180.0f;
	}


	/**
	 * @brief 육십분법 각을 라디안 각으로 변환합니다.
	 *
	 * @param degree 변환할 육십분법 각입니다.
	 *
	 * @return 변환된 라디안 각입니다.
	 */
	static inline double ToRadian(double degree)
	{
		return (degree * PI_D) / 180.0;
	}


	/**
	 * @brief 0에 한없이 가까운 값인지 확인합니다.
	 *
	 * @param value 0에 한없이 가까운지 확인할 값입니다.
	 * @param epsilon 엡실론 값입니다.
	 *
	 * @return 엡실론 값보다 작다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static inline bool IsNearZero(const float& value, const float& epsilon = EPSILON_F)
	{
		return (fabs(value) <= epsilon);
	}


	/**
	 * @brief 0에 한없이 가까운 값인지 확인합니다.
	 *
	 * @param value 0에 한없이 가까운지 확인할 값입니다.
	 * @param epsilon 엡실론 값입니다.
	 *
	 * @return 엡실론 값보다 작다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static inline bool IsNearZero(const double& value, const double& epsilon = EPSILON_D)
	{
		return (fabs(value) <= epsilon);
	}


	/**
	 * @brief 지정된 오프셋만큼의 변환 행렬을 반환합니다.
	 * 
	 * @param xoffset x축 기준으로 이동할 오프셋입니다.
	 * @param yoffset y축 기준으로 이동할 오프셋입니다.
	 * @param zoffset z축 기준으로 이동할 오프셋입니다.
	 * 
	 * @return (xoffset, yoffset, zoffet) 만큼 이동할 변환 행렬을 반환합니다.
	 */
	static inline Matrix4x4f TranslationMatrix(float xoffset, float yoffset, float zoffset)
	{
		return Matrix4x4f(
			   1.0f,    0.0f,    0.0f, 0.0f,
			   0.0f,    1.0f,    0.0f, 0.0f,
			   0.0f,    0.0f,    1.0f, 0.0f,
			xoffset, yoffset, zoffset, 1.0f
		);
	}


	/**
	 * @brief x축 기준으로 회전시키는 회전 행렬을 반환합니다.
	 * 
	 * @param radians x축 기준으로 회전 시킬 라디안 각도입니다.
	 * 
	 * @return x축 기준으로 회전 시킬 회전 행렬을 반환합니다.
	 */
	static inline Matrix4x4f RotationXMatrix(float radians)
	{
		float sinAngle = sin(radians);
		float cosAngle = cos(radians);

		return Matrix4x4f(
			1.0f,      0.0f,     0.0f, 0.0f,
			0.0f,  cosAngle, sinAngle, 0.0f,
			0.0f, -sinAngle, cosAngle, 0.0f,
			0.0f,      0.0f,     0.0f, 1.0f
		);
	}


	/**
	 * @brief y축 기준으로 회전시키는 회전 행렬을 반환합니다.
	 *
	 * @param radians y축 기준으로 회전 시킬 라디안 각도입니다.
	 *
	 * @return y축 기준으로 회전 시킬 회전 행렬을 반환합니다.
	 */
	static inline Matrix4x4f RotationYMatrix(float radians)
	{
		float sinAngle = sin(radians);
		float cosAngle = cos(radians);

		return Matrix4x4f(
			cosAngle, 0.0f, -sinAngle, 0.0f,
			    0.0f, 1.0f,      0.0f, 0.0f,
			sinAngle, 0.0f,  cosAngle, 0.0f,
			    0.0f, 0.0f,      0.0f, 1.0f
		);
	}


	/**
	 * @brief z축 기준으로 회전시키는 회전 행렬을 반환합니다.
	 *
	 * @param radians z축 기준으로 회전 시킬 라디안 각도입니다.
	 *
	 * @return z축 기준으로 회전 시킬 회전 행렬을 반환합니다.
	 */
	static inline Matrix4x4f RotationZMatrix(float radians)
	{
		float sinAngle = sin(radians);
		float cosAngle = cos(radians);

		return Matrix4x4f(
			 cosAngle, sinAngle, 0.0f, 0.0f,
			-sinAngle, cosAngle, 0.0f, 0.0f,
			     0.0f,     0.0f, 1.0f, 0.0f,
			     0.0f,     0.0f, 0.0f, 1.0f
		);
	}
};