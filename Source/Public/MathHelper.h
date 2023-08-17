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
 * @brief float Ÿ���� ����(��) ���Դϴ�.
 */
const float PI_F = 3.1415926535F;


/**
 * @brief double Ÿ���� ����(��) ���Դϴ�.
 */
const double PI_D = 3.1415926535897931;


/**
 * @brief float Ÿ���� Ÿ���� ���Ƿ�(��) ���Դϴ�.
 */
const float EPSILON_F = std::numeric_limits<float>::epsilon();


/**
 * @brief double Ÿ���� ���Ƿ�(��) ���Դϴ�.
 */
const double EPSILON_D = std::numeric_limits<double>::epsilon();


/**
 * @brief float Ÿ���� ���Ѵ� ���Դϴ�.
 */
const float INFINITY_F = std::numeric_limits<float>::infinity();


/**
 * @brief double Ÿ���� ���Ѵ� ���Դϴ�.
 */
const double INFINITY_D = std::numeric_limits<double>::infinity();


/**
 * @brief float Ÿ���� ���� ���Ѵ� ���Դϴ�.
 */
const float NINFINITY_F = -std::numeric_limits<float>::infinity();


/**
 * @brief double Ÿ���� ���� ���Ѵ� ���Դϴ�.
 */
const double NINFINITY_D = -std::numeric_limits<double>::infinity();


/**
 * @brief int Ÿ���� 2���� �����Դϴ�.
 */
using Vector2i = Vector2<int32_t>;


/**
 * @brief float Ÿ���� 2���� �����Դϴ�.
 */
using Vector2f = Vector2<float>;


/**
 * @brief int Ÿ���� 3���� �����Դϴ�.
 */
using Vector3i = Vector3<int32_t>;


/**
 * @brief float Ÿ���� 3���� �����Դϴ�.
 */
using Vector3f = Vector3<float>;


/**
 * @brief int Ÿ���� 4���� �����Դϴ�.
 */
using Vector4i = Vector4<int32_t>;


/**
 * @brief float Ÿ���� 4���� �����Դϴ�.
 */
using Vector4f = Vector4<float>;


/**
 * @brief int Ÿ���� 2x2 ����Դϴ�.
 */
using Matrix2x2i = Matrix2x2<int32_t>;


/**
 * @brief float Ÿ���� 2x2 ����Դϴ�.
 */
using Matrix2x2f = Matrix2x2<float>;


/**
 * @brief int Ÿ���� 3x3 ����Դϴ�.
 */
using Matrix3x3i = Matrix3x3<int32_t>;


/**
 * @brief float Ÿ���� 3x3 ����Դϴ�.
 */
using Matrix3x3f = Matrix3x3<float>;


/**
 * @brief int Ÿ���� 4x4 ����Դϴ�.
 */
using Matrix4x4i = Matrix4x4<int32_t>;


/**
 * @brief float Ÿ���� 4x4 ����Դϴ�.
 */
using Matrix4x4f = Matrix4x4<float>;


/**
 * @brief ���� ���� ���� ����� �����մϴ�.
 * 
 * @note �� Ŭ������ �޼���� ��� ������ ��� ����(static) �����Դϴ�.
 */
class MathHelper
{
public:
};