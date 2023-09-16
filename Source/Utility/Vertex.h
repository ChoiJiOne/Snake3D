#pragma once

#include <glm/glm.hpp>


/**
 * @brief 위치 정보를 가진 정점입니다.
 */
struct VertexPosition
{
	/**
	 * @brief 위치 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPosition() : position_(0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 */
	VertexPosition(const glm::vec3& position) : position_(position) {}


	/**
	 * @brief 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param x 정점 위치의 x값입니다.
	 * @param y 정점 위치의 y값입니다.
	 * @param z 정점 위치의 z값입니다.
	 */
	VertexPosition(float x, float y, float z) : position_(x, y, z) {}


	/**
	 * @brief 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPosition(VertexPosition&& instance) noexcept
		: position_(instance.position_) {}


	/**
	 * @brief 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPosition(const VertexPosition& instance) noexcept
		: position_(instance.position_) {}


	/**
	 * @brief 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPosition& operator=(VertexPosition&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;

		return *this;
	}


	/**
	 * @brief 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPosition& operator=(const VertexPosition& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPosition);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	glm::vec3 position_;
};


/**
 * @brief 위치와 색상 정보를 가진 정점입니다.
 */
struct VertexPositionColor
{
	/**
	 * @brief 위치와 색상 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionColor()
		: position_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 위치와 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param color 정점의 색상 정보입니다.
	 */
	VertexPositionColor(const glm::vec3& position, const glm::vec4& color)
		: position_(position), color_(color) {}


	/**
	 * @brief 위치와 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param x 정점 위치의 x값입니다.
	 * @param y 정점 위치의 y값입니다.
	 * @param z 정점 위치의 z값입니다.
	 * @param r 정점 색상의 R값입니다.
	 * @param g 정점 색상의 G값입니다.
	 * @param b 정점 색상의 B값입니다.
	 * @param a 정점 색상의 A값입니다.
	 */
	VertexPositionColor(
		float x, float y, float z,
		float r, float g, float b, float a
	) : position_(x, y, z), color_(r, g, b, a) {}


	/**
	 * @brief 위치와 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionColor(VertexPositionColor&& instance) noexcept
		: position_(instance.position_),
		color_(instance.color_) {}


	/**
	 * @brief 위치와 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionColor(const VertexPositionColor& instance) noexcept
		: position_(instance.position_),
		color_(instance.color_) {}


	/**
	 * @brief 위치와 색상 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionColor& operator=(VertexPositionColor&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief 위치와 색상 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionColor& operator=(const VertexPositionColor& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionColor);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 정점의 색상입니다.
	 */
	glm::vec4 color_;
};