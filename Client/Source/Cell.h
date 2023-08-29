#pragma once

#include "Vector/Vector.h"


/**
 * @brief 그리드(격자)의 한 조각입니다.
 */
class Cell
{
public:
	/**
	 * @brief 그리드 한 조각의 상태입니다.
	 * 
	 * @note
	 * - 그리드의 한 조각이 GRAY(회색) 상태이면, 뱀이 그냥 지나갈 수 있는 상태입니다.
	 * - 그리드의 한 조각이 GREEN(회색) 상태일 때, 뱀이 지나가면 크기가 커집니다.
	 * - 그리드의 한 조각이 RED(빨강색) 상태일 때, 뱀이 지나가면 게임이 종료됩니다.
	 */
	enum class EState : int32_t
	{
		GRAY  = 0x00,
		GREEN = 0x01,
		RED   = 0x02,
	};


public:
	/**
	 * @brief 그리드 한 조각 상태의 생성자입니다.
	 */
	Cell() : state_(EState::GRAY), transform_(0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 그리드 한 조각 상태의 생성자입니다.
	 * 
	 * @param state 그리드 한 조각의 상태입니다.
	 * @param transform 그리드 한 조각의 변환될 위치 값입니다.
	 */
	Cell(const EState& state, const Vector3f& transform)
		: state_(state)
		, transform_(transform) {}


	/**
	 * @brief 그리드 한 조각 상태의 복사 생성자입니다.
	 * 
	 * @param instance 복사할 인스턴스입니다.
	 */
	Cell(Cell&& instance) noexcept
		: state_(instance.state_)
		, transform_(instance.transform_) {}


	/**
	 * @brief 그리드 한 조각 상태의 복사 생성자입니다.
	 *
	 * @param instance 복사할 인스턴스입니다.
	 */
	Cell(const Cell& instance) noexcept
		: state_(instance.state_)
		, transform_(instance.transform_) {}


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

		state_ = instance.state_;
		transform_ = instance.transform_;

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

		state_ = instance.state_;
		transform_ = instance.transform_;

		return *this;
	}


	/**
	 * @brief 현재 그리드 한 조각 상태에 맞는 컬러값을 얻습니다.
	 * 
	 * @return 현재 그리드 한 조각 상태에 맞는 컬러값을 반환합니다.
	 */
	Vector4f GetStateColor() const
	{
		Vector4f color;

		switch (state_)
		{
		case EState::GRAY:
			color = Vector4f(0.5f, 0.5f, 0.5f, 1.0f);
			break;

		case EState::GREEN:
			color = Vector4f(0.0f, 1.0f, 0.0f, 1.0f);
			break;

		case EState::RED:
			color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);
			break;

		default:
			color = Vector4f(1.0f, 1.0f, 1.0f, 1.0f);
			break;
		}

		return color;
	}


	/**
	 * @brief 현재 그리드 한 조각 상태를 얻습니다.
	 * 
	 * @return 현재 그리드 한 조각 상태를 반환합니다.
	 */
	EState GetState() const { return state_; }


	/**
	 * @brief 현재 그리드 한 조각 상태를 설정합니다.
	 * 
	 * @param state 설정할 그리드 한 조각 상태입니다.
	 */
	void SetState(const EState& state) { state_ = state; }


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


private:
	/**
	 * @brief 현재 그리드 한 조각의 상태입니다.
	 */
	EState state_ = EState::GRAY;


	/**
	 * @brief 현재 그리드 한 조각의 변환될 위치 값입니다.
	 */
	Vector3f transform_;
};