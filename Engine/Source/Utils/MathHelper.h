#pragma once

#include <cstdint>
#include <cmath>
#include <random>
#include <limits>

#include "Vector/Vector.h"

#include "Matrix/Matrix.h"


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
 * @brief 수학 관련 헬퍼 기능을 수행합니다.
 * 
 * @note 이 클래스의 메서드와 멤버 변수는 모두 정적(static) 형식입니다.
 */
class MathHelper
{
public:
	/**
	 * @brief 두 값 중 큰 값을 반환합니다.
	 * 
	 * @param lhs 두 값 중 좌측 값입니다.
	 * @param rhs 두 값 중 우측 값입니다.
	 * 
	 * @return 두 값 중 큰 값을 반환합니다.
	 */
	template <typename T>
	static inline T Max(const T& lhs, const T& rhs)
	{
		return (lhs < rhs ? rhs : lhs);
	}


	/**
	 * @brief 두 값 중 작은 값을 반환합니다.
	 *
	 * @param lhs 두 값 중 좌측 값입니다.
	 * @param rhs 두 값 중 우측 값입니다.
	 *
	 * @return 두 값 중 작은 값을 반환합니다.
	 */
	template <typename T>
	static inline T Min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}


	/**
	 * @brief 특정 값을 [lower, uppper] 범위로 자릅니다.
	 * 
	 * @param value 범위를 자를 특정 값입니다.
	 * @param lower 범위의 최소값입니다.
	 * @param upper 범위의 최대값입니다.
	 * 
	 * @return [lower, uppper] 범위로 절단된 값을 반환합니다.
	 */
	template <typename T>
	static inline T Clamp(const T& value, const T& lower, const T& upper)
	{
		return Min(upper, Max(lower, value));
	}


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
	 * @brief 두 백터의 내적(Dot) 연산을 수행합니다.
	 * 
	 * @param lhs 내적의 왼쪽 피연산자입니다.
	 * @param rhs 내적의 오른쪽 피연산자입니다.
	 * 
	 * @return 두 벡터의 내적 값(스칼라 값)을 반환합니다.
	 */
	static int32_t Dot(const Vector2i& lhs, const Vector2i& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y);
	}


	/**
	 * @brief 두 백터의 내적(Dot) 연산을 수행합니다.
	 *
	 * @param lhs 내적의 왼쪽 피연산자입니다.
	 * @param rhs 내적의 오른쪽 피연산자입니다.
	 *
	 * @return 두 벡터의 내적 값(스칼라 값)을 반환합니다.
	 */
	static float Dot(const Vector2f& lhs, const Vector2f& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y);
	}


	/**
	 * @brief 두 백터의 내적(Dot) 연산을 수행합니다.
	 *
	 * @param lhs 내적의 왼쪽 피연산자입니다.
	 * @param rhs 내적의 오른쪽 피연산자입니다.
	 *
	 * @return 두 벡터의 내적 값(스칼라 값)을 반환합니다.
	 */
	static int32_t Dot(const Vector3i& lhs, const Vector3i& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
	}


	/**
	 * @brief 두 백터의 내적(Dot) 연산을 수행합니다.
	 *
	 * @param lhs 내적의 왼쪽 피연산자입니다.
	 * @param rhs 내적의 오른쪽 피연산자입니다.
	 *
	 * @return 두 벡터의 내적 값(스칼라 값)을 반환합니다.
	 */
	static float Dot(const Vector3f& lhs, const Vector3f& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
	}


	/**
	 * @brief 두 백터의 내적(Dot) 연산을 수행합니다.
	 *
	 * @param lhs 내적의 왼쪽 피연산자입니다.
	 * @param rhs 내적의 오른쪽 피연산자입니다.
	 *
	 * @return 두 벡터의 내적 값(스칼라 값)을 반환합니다.
	 */
	static int32_t Dot(const Vector4i& lhs, const Vector4i& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
	}


	/**
	 * @brief 두 백터의 내적(Dot) 연산을 수행합니다.
	 *
	 * @param lhs 내적의 왼쪽 피연산자입니다.
	 * @param rhs 내적의 오른쪽 피연산자입니다.
	 *
	 * @return 두 벡터의 내적 값(스칼라 값)을 반환합니다.
	 */
	static float Dot(const Vector4f& lhs, const Vector4f& rhs)
	{
		return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w);
	}


	/**
	 * @brief 두 벡터의 외적(Cross) 연산을 수행합니다.
	 *
	 * @param lhs 외적의 왼쪽 피연산자입니다.
	 * @param rhs 외적의 오른쪽 피연산자입니다.
	 *
	 * @return 두 벡터의 외적 값(벡터 값)을 반환합니다.
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
	 * @brief 벡터 크기의 제곱 값을 얻습니다.
	 * 
	 * @param v 크기의 제곱 값을 얻을 벡터입니다.
	 * 
	 * @return 벡터 크기의 제곱 값을 반환합니다.
	 */
	static int32_t LengthSquare(const Vector2i& v)
	{
		return (v.x * v.x + v.y * v.y);
	}


	/**
	 * @brief 벡터 크기의 제곱 값을 얻습니다.
	 *
	 * @param v 크기의 제곱 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기의 제곱 값을 반환합니다.
	 */
	static float LengthSquare(const Vector2f& v)
	{
		return (v.x * v.x + v.y * v.y);
	}


	/**
	 * @brief 벡터 크기의 제곱 값을 얻습니다.
	 *
	 * @param v 크기의 제곱 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기의 제곱 값을 반환합니다.
	 */
	static int32_t LengthSquare(const Vector3i& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}


	/**
	 * @brief 벡터 크기의 제곱 값을 얻습니다.
	 *
	 * @param v 크기의 제곱 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기의 제곱 값을 반환합니다.
	 */
	static float LengthSquare(const Vector3f& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}


	/**
	 * @brief 벡터 크기의 제곱 값을 얻습니다.
	 *
	 * @param v 크기의 제곱 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기의 제곱 값을 반환합니다.
	 */
	static int32_t LengthSquare(const Vector4i& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	
	/**
	 * @brief 벡터 크기의 제곱 값을 얻습니다.
	 *
	 * @param v 크기의 제곱 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기의 제곱 값을 반환합니다.
	 */
	static float LengthSquare(const Vector4f& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}


	/**
	 * @brief 벡터 크기 값을 얻습니다.
	 *
	 * @param v 크기 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기 값을 반환합니다.
	 */
	static float Length(const Vector2f& v)
	{
		return std::sqrt(LengthSquare(v));
	}


	/**
	 * @brief 벡터 크기 값을 얻습니다.
	 *
	 * @param v 크기 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기 값을 반환합니다.
	 */
	static float Length(const Vector3f& v)
	{
		return std::sqrt(LengthSquare(v));
	}


	/**
	 * @brief 벡터 크기 값을 얻습니다.
	 *
	 * @param v 크기 값을 얻을 벡터입니다.
	 *
	 * @return 벡터 크기 값을 반환합니다.
	 */
	static float Length(const Vector4f& v)
	{
		return std::sqrt(LengthSquare(v));
	}


	/**
	 * @brief 벡터를 정규화합니다.
	 * 
	 * @param v 정규화할 벡터입니다.
	 * 
	 * @return 정규화된 벡터를 반환합니다.
	 */
	static Vector2f Normalize(const Vector2f& v)
	{
		float length = Length(v);

		return Vector2f(v.x / length, v.y / length);
	}


	/**
	 * @brief 벡터를 정규화합니다.
	 *
	 * @param v 정규화할 벡터입니다.
	 *
	 * @return 정규화된 벡터를 반환합니다.
	 */
	static Vector3f Normalize(const Vector3f& v)
	{
		float length = Length(v);

		return Vector3f(v.x / length, v.y / length, v.z / length);
	}


	/**
	 * @brief 벡터를 정규화합니다.
	 *
	 * @param v 정규화할 벡터입니다.
	 *
	 * @return 정규화된 벡터를 반환합니다.
	 */
	static Vector4f Normalize(const Vector4f& v)
	{
		float length = Length(v);

		return Vector4f(v.x / length, v.y / length, v.z / length, v.w / length);
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
	 * @brief x, y, z 축에 따라 배율을 조정하는 행렬을 반환합니다.
	 * 
	 * @param xscale x축 기준으로 조정할 배율 값입니다.
	 * @param yscale y축 기준으로 조정할 배율 값입니다.
	 * @param zscale z축 기준으로 조정할 배율 값입니다.
	 * 
	 * @return 배율을 조정하는 행렬을 반환합니다.
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


	/**
	 * @brief 시야 행렬을 생성합니다.
	 *
	 * @note 좌표 시스템은 왼손 좌표계입니다.
	 *
	 * @param eyePosition 월드 상의 시야 위치입니다.
	 * @param focusPosition 월드 상의 초점 위치입니다.
	 * @param worldUpDirection 월드 상의 위쪽 방향입니다.
	 *
	 * @return 왼손 좌표계 기준의 시야 행렬을 반환합니다.
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
	 * @brief 직교 투영 행렬을 생성합니다.
	 * 
	 * @note 좌표 시스템은 왼손 좌표계입니다.
	 * 
	 * @param viewWidth 가까운 클리핑 평면에 있는 frustum의 너비입니다.
	 * @param viewHeight 가까운 클리핑 평면에 있는 frustum의 높이입니다.
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다.
	 * 
	 * @return 직교 투영 행렬을 반환합니다.
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
	 * @brief 원근 투영 행렬을 생성합니다.
	 * 
	 * @note 좌표 시스템은 왼손 좌표계입니다.
	 * 
	 * @param fovRadians 하향식 보기 필드 각도(라디안)입니다.
	 * @param aspectRatio 뷰 공간 X:Y의 가로 세로 비율입니다.
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 * 
	 * @return 원근 투영 행렬을 반환합니다.
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


	/**
	 * @brief 임의의 정수를 생성합니다.
	 *
	 * @param minValue 생성할 난수 범위의 최솟값입니다.
	 * @param maxValue 생성할 난수 범위의 최댓값입니다.
	 *
	 * @return 생성된 임의의 정수를 반환합니다.
	 */
	static inline int32_t GenerateRandomInt(int32_t minValue, int32_t maxValue)
	{
		std::random_device randomDevice;
		std::mt19937 generator(randomDevice());
		std::uniform_int_distribution<int32_t> distribution(std::min<int32_t>(minValue, maxValue), std::max<int32_t>(minValue, maxValue));

		return distribution(generator);
	}


	/**
	 * @brief 임의의 실수를 생성합니다.
	 *
	 * @param minValue 생성할 난수 범위의 최솟값입니다.
	 * @param maxValue 생성할 난수 범위의 최댓값입니다.
	 *
	 * @return 생성된 임의의 실수를 반환합니다.
	 */
	static inline float GenerateRandomFloat(float minValue, float maxValue)
	{
		std::random_device randomDevice;
		std::mt19937 generator(randomDevice());
		std::uniform_real_distribution<float> distribution(std::min<float>(minValue, maxValue), std::max<float>(minValue, maxValue));

		return distribution(generator);
	}
};