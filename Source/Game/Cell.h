#pragma once

#include "Vector/Vector.h"


/**
 * @brief 그리드(격자)의 한 조각입니다.
 */
class Cell
{
public:
	/**
	 * @brief 그리드 한 조각 상태의 생성자입니다.
	 */
	Cell() : transform_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 1.0f) {}


	/**
	 * @brief 그리드 한 조각 상태의 생성자입니다.
	 * 
	 * @param transform 그리드 한 조각의 변환될 위치 값입니다.
	 * @param color 그리드 한 조각의 색상입니다.
	 */
	Cell(const Vector3f& transform, const Vector4f& color)
		: transform_(transform)
		, color_(color) {}


	/**
	 * @brief 그리드 한 조각 상태의 복사 생성자입니다.
	 * 
	 * @param instance 복사할 인스턴스입니다.
	 */
	Cell(Cell&& instance) noexcept
		: transform_(instance.transform_)
		, color_(instance.color_) {}


	/**
	 * @brief 그리드 한 조각 상태의 복사 생성자입니다.
	 *
	 * @param instance 복사할 인스턴스입니다.
	 */
	Cell(const Cell& instance) noexcept
		: transform_(instance.transform_)
		, color_(instance.color_) {}


	/**
	 * @brief 그리드 한 조각 상태의 대입 연산자입니다.
	 * 
	 * @param instance 대입 연산을 통해 복사할 인스턴스입니다.
	 * 
	 * @return 복사한 인스턴스의 참조자를 반환합니다.
	 */
	Cell& operator=(Cell&& instance) noexcept
	{
		if (this == &instance) return *this;

		transform_ = instance.transform_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief 그리드 한 조각 상태의 대입 연산자입니다.
	 *
	 * @param instance 대입 연산을 통해 복사할 인스턴스입니다.
	 *
	 * @return 복사한 인스턴스의 참조자를 반환합니다.
	 */
	Cell& operator=(const Cell& instance) noexcept
	{
		if (this == &instance) return *this;

		transform_ = instance.transform_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief 현재 그리드 한 조각의 변환될 위치값을 얻습니다.
	 * 
	 * @return 현재 그리드 한 조각의 변환될 위치값을 반환합니다.
	 */
	Vector3f GetTransform() const { return transform_; }


	/**
	 * @brief 현재 그리드 한 조각의 변환될 위치값을 설정합니다.
	 * 
	 * @param transform 설정할 그리드 한 조각의 변환될 위치값입니다.
	 */
	void SetTransform(const Vector3f& transform) { transform_ = transform; }


	/**
	 * @brief 현재 그리드 한 조각 상태를 얻습니다.
	 *
	 * @return 현재 그리드 한 조각 상태를 반환합니다.
	 */
	Vector4f GetColor() const { return color_; }


	/**
	 * @brief 현재 그리드 한 조각 상태를 설정합니다.
	 *
	 * @param state 설정할 그리드 한 조각 상태입니다.
	 */
	void SetColor(const Vector4f& color) { color_ = color; }


private:
	/**
	 * @brief 현재 그리드 한 조각의 변환될 위치 값입니다.
	 */
	Vector3f transform_;


	/**
	 * @brief 현재 그리드 한 조각의 색상입니다.
	 */
	Vector4f color_;
};