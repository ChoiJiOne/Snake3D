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
 * @brief ���� ���� ���� ����� �����մϴ�.
 * 
 * @note �� Ŭ������ �޼���� ��� ������ ��� ����(static) �����Դϴ�.
 */
class MathHelper
{
public:
	/**
	 * @brief ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 *
	 * @param radian ��ȯ�� ���� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	static inline float ToDegree(float radian)
	{
		return (radian * 180.0f) / PI_F;
	}


	/**
	 * @brief ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 *
	 * @param radian ��ȯ�� ���� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	static inline double ToDegree(double radian)
	{
		return (radian * 180.0) / PI_D;
	}


	/**
	 * @brief ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
	 *
	 * @param degree ��ȯ�� ���ʺй� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���� ���Դϴ�.
	 */
	static inline float ToRadian(float degree)
	{
		return (degree * PI_F) / 180.0f;
	}


	/**
	 * @brief ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
	 *
	 * @param degree ��ȯ�� ���ʺй� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���� ���Դϴ�.
	 */
	static inline double ToRadian(double degree)
	{
		return (degree * PI_D) / 180.0;
	}


	/**
	 * @brief 0�� �Ѿ��� ����� ������ Ȯ���մϴ�.
	 *
	 * @param value 0�� �Ѿ��� ������� Ȯ���� ���Դϴ�.
	 * @param epsilon ���Ƿ� ���Դϴ�.
	 *
	 * @return ���Ƿ� ������ �۴ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static inline bool IsNearZero(const float& value, const float& epsilon = EPSILON_F)
	{
		return (fabs(value) <= epsilon);
	}


	/**
	 * @brief 0�� �Ѿ��� ����� ������ Ȯ���մϴ�.
	 *
	 * @param value 0�� �Ѿ��� ������� Ȯ���� ���Դϴ�.
	 * @param epsilon ���Ƿ� ���Դϴ�.
	 *
	 * @return ���Ƿ� ������ �۴ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static inline bool IsNearZero(const double& value, const double& epsilon = EPSILON_D)
	{
		return (fabs(value) <= epsilon);
	}


	/**
	 * @brief �� ������ ����(Dot) ������ �����մϴ�.
	 * 
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 * 
	 * @return �� ������ ���� ��(��Į�� ��)�� ��ȯ�մϴ�.
	 */
	static int32_t Dot(const Vector2i& lhs, const Vector2i& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y);
	}


	/**
	 * @brief �� ������ ����(Dot) ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� ��(��Į�� ��)�� ��ȯ�մϴ�.
	 */
	static float Dot(const Vector2f& lhs, const Vector2f& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y);
	}


	/**
	 * @brief �� ������ ����(Dot) ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� ��(��Į�� ��)�� ��ȯ�մϴ�.
	 */
	static int32_t Dot(const Vector3i& lhs, const Vector3i& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
	}


	/**
	 * @brief �� ������ ����(Dot) ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� ��(��Į�� ��)�� ��ȯ�մϴ�.
	 */
	static float Dot(const Vector3f& lhs, const Vector3f& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
	}


	/**
	 * @brief �� ������ ����(Dot) ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� ��(��Į�� ��)�� ��ȯ�մϴ�.
	 */
	static int32_t Dot(const Vector4i& lhs, const Vector4i& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
	}


	/**
	 * @brief �� ������ ����(Dot) ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� ��(��Į�� ��)�� ��ȯ�մϴ�.
	 */
	static float Dot(const Vector4f& lhs, const Vector4f& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
	}


	/**
	 * @brief �� ������ ����(Cross) ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� ��(���� ��)�� ��ȯ�մϴ�.
	 */
	static Vector3f Cross(const Vector3f& lhs, const Vector3f& rhs)
	{
		return Vector3f(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}


	/**
	 * @brief ���� ũ���� ���� ���� ����ϴ�.
	 * 
	 * @param v ũ���� ���� ���� ���� �����Դϴ�.
	 * 
	 * @return ���� ũ���� ���� ���� ��ȯ�մϴ�.
	 */
	static int32_t LengthSquare(const Vector2i& v)
	{
		return (v.x * v.x + v.y * v.y);
	}


	/**
	 * @brief ���� ũ���� ���� ���� ����ϴ�.
	 *
	 * @param v ũ���� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ���� ���� ���� ��ȯ�մϴ�.
	 */
	static float LengthSquare(const Vector2f& v)
	{
		return (v.x * v.x + v.y * v.y);
	}


	/**
	 * @brief ���� ũ���� ���� ���� ����ϴ�.
	 *
	 * @param v ũ���� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ���� ���� ���� ��ȯ�մϴ�.
	 */
	static int32_t LengthSquare(const Vector3i& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}


	/**
	 * @brief ���� ũ���� ���� ���� ����ϴ�.
	 *
	 * @param v ũ���� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ���� ���� ���� ��ȯ�մϴ�.
	 */
	static float LengthSquare(const Vector3f& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}


	/**
	 * @brief ���� ũ���� ���� ���� ����ϴ�.
	 *
	 * @param v ũ���� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ���� ���� ���� ��ȯ�մϴ�.
	 */
	static int32_t LengthSquare(const Vector4i& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	
	/**
	 * @brief ���� ũ���� ���� ���� ����ϴ�.
	 *
	 * @param v ũ���� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ���� ���� ���� ��ȯ�մϴ�.
	 */
	static float LengthSquare(const Vector4f& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}


	/**
	 * @brief ���� ũ�� ���� ����ϴ�.
	 *
	 * @param v ũ�� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static float Length(const Vector2f& v)
	{
		return std::sqrt(LengthSquare(v));
	}


	/**
	 * @brief ���� ũ�� ���� ����ϴ�.
	 *
	 * @param v ũ�� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static float Length(const Vector3f& v)
	{
		return std::sqrt(LengthSquare(v));
	}


	/**
	 * @brief ���� ũ�� ���� ����ϴ�.
	 *
	 * @param v ũ�� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	static float Length(const Vector4f& v)
	{
		return std::sqrt(LengthSquare(v));
	}


	/**
	 * @brief ���͸� ����ȭ�մϴ�.
	 * 
	 * @param v ����ȭ�� �����Դϴ�.
	 * 
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	static Vector2f Normalize(const Vector2f& v)
	{
		float length = Length(v);

		return Vector2f(v.x / length, v.y / length);
	}


	/**
	 * @brief ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ�� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	static Vector3f Normalize(const Vector3f& v)
	{
		float length = Length(v);

		return Vector3f(v.x / length, v.y / length, v.z / length);
	}


	/**
	 * @brief ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ�� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	static Vector4f Normalize(const Vector4f& v)
	{
		float length = Length(v);

		return Vector4f(v.x / length, v.y / length, v.z / length, v.w / length);
	}


	/**
	 * @brief ������ �����¸�ŭ�� ��ȯ ����� ��ȯ�մϴ�.
	 * 
	 * @param xoffset x�� �������� �̵��� �������Դϴ�.
	 * @param yoffset y�� �������� �̵��� �������Դϴ�.
	 * @param zoffset z�� �������� �̵��� �������Դϴ�.
	 * 
	 * @return (xoffset, yoffset, zoffet) ��ŭ �̵��� ��ȯ ����� ��ȯ�մϴ�.
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
	 * @brief x, y, z �࿡ ���� ������ �����ϴ� ����� ��ȯ�մϴ�.
	 * 
	 * @param xscale x�� �������� ������ ���� ���Դϴ�.
	 * @param yscale y�� �������� ������ ���� ���Դϴ�.
	 * @param zscale z�� �������� ������ ���� ���Դϴ�.
	 * 
	 * @return ������ �����ϴ� ����� ��ȯ�մϴ�.
	 */
	static inline Matrix4x4f ScalingMatrix(float xscale, float yscale, float zscale)
	{
		return Matrix4x4f(
			xscale,   0.0f,   0.0f, 0.0f,
			  0.0f, yscale,   0.0f, 0.0f,
			  0.0f,   0.0f, zscale, 0.0f,
			  0.0f,   0.0f,   0.0f, 1.0f
		);
	}
	

	/**
	 * @brief x�� �������� ȸ����Ű�� ȸ�� ����� ��ȯ�մϴ�.
	 * 
	 * @param radians x�� �������� ȸ�� ��ų ���� �����Դϴ�.
	 * 
	 * @return x�� �������� ȸ�� ��ų ȸ�� ����� ��ȯ�մϴ�.
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
	 * @brief y�� �������� ȸ����Ű�� ȸ�� ����� ��ȯ�մϴ�.
	 *
	 * @param radians y�� �������� ȸ�� ��ų ���� �����Դϴ�.
	 *
	 * @return y�� �������� ȸ�� ��ų ȸ�� ����� ��ȯ�մϴ�.
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
	 * @brief z�� �������� ȸ����Ű�� ȸ�� ����� ��ȯ�մϴ�.
	 *
	 * @param radians z�� �������� ȸ�� ��ų ���� �����Դϴ�.
	 *
	 * @return z�� �������� ȸ�� ��ų ȸ�� ����� ��ȯ�մϴ�.
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


	/**
	 * @brief �þ� ����� �����մϴ�.
	 *
	 * @note ��ǥ �ý����� �޼� ��ǥ���Դϴ�.
	 *
	 * @param eyePosition ���� ���� �þ� ��ġ�Դϴ�.
	 * @param focusPosition ���� ���� ���� ��ġ�Դϴ�.
	 * @param worldUpDirection ���� ���� ���� �����Դϴ�.
	 *
	 * @return �޼� ��ǥ�� ������ �þ� ����� ��ȯ�մϴ�.
	 * 
	 * @see https://learnopengl.com/Getting-started/Camera
	 */
	static inline Matrix4x4f LookAtMatrix(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& worldUpDirection)
	{
		Vector3f eyeDirection = focusPosition - eyePosition;
		eyeDirection = Normalize(eyeDirection);

		Vector3f rightDirection = Cross(worldUpDirection, eyeDirection);
		rightDirection = Normalize(rightDirection);

		Vector3f upDirection = Cross(eyeDirection, rightDirection);
		upDirection = Normalize(upDirection);

		float px = -Dot(eyePosition, rightDirection);
		float py = -Dot(eyePosition, upDirection);
		float pz = -Dot(eyePosition, eyeDirection);

		return Matrix4x4f(
			rightDirection.x,  upDirection.x, eyeDirection.x, 0.0f,
			rightDirection.y,  upDirection.y, eyeDirection.y, 0.0f,
			rightDirection.z,  upDirection.z, eyeDirection.z, 0.0f,
		                  px,             py,             pz, 1.0f
		);
	}


	/**
	 * @brief ���� ���� ����� �����մϴ�.
	 * 
	 * @note ��ǥ �ý����� �޼� ��ǥ���Դϴ�.
	 * 
	 * @param viewWidth ����� Ŭ���� ��鿡 �ִ� frustum�� �ʺ��Դϴ�.
	 * @param viewHeight ����� Ŭ���� ��鿡 �ִ� frustum�� �����Դϴ�.
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�.
	 * 
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline Matrix4x4f OrthographicMatrix(float viewWidth, float viewHeight, float nearZ, float farZ)
	{
		float range = 1.0f / (farZ - nearZ);

		return Matrix4x4f(
			2.0f / viewWidth,               0.0f,          0.0f, 0.0f,
			            0.0f, 2.0f / viewHeight,           0.0f, 0.0f,
		            	0.0f,              0.0f,          range, 0.0f,
			            0.0f,              0.0f, -range * nearZ, 1.0f
		);
	}


	/**
	 * @brief ���� ���� ����� �����մϴ�.
	 * 
	 * @note ��ǥ �ý����� �޼� ��ǥ���Դϴ�.
	 * 
	 * @param fovRadians ����� ���� �ʵ� ����(����)�Դϴ�.
	 * @param aspectRatio �� ���� X:Y�� ���� ���� �����Դϴ�.
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * 
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	static inline Matrix4x4f ProjectionMatrix(float fovRadians, float aspectRatio, float nearZ, float farZ)
	{
		float halfFov = fovRadians * 0.5f;
		float sinFov = sin(halfFov);
		float cosFov = cos(halfFov);

		float height = cosFov / sinFov;
		float width = height / aspectRatio;
		float range = farZ / (farZ - nearZ);

		return Matrix4x4f(
			width,   0.0f,           0.0f, 0.0f,
			 0.0f, height,           0.0f, 0.0f,
			 0.0f,   0.0f,          range, 1.0f,
			 0.0f,   0.0f, -range * nearZ, 0.0f
		);
	}
};