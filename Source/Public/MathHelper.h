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
};