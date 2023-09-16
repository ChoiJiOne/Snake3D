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


/**
 * @brief 위치와 텍스처 위치 정보를 가진 정점입니다.
 */
struct VertexPositionTexture
{
	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionTexture()
		: position_(0.0f, 0.0f, 0.0f), textureCoordinate_(0.0f, 0.0f) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param textureCoordinate 정점의 텍스처 위치 정보입니다.
	 */
	VertexPositionTexture(const glm::vec3& position, const glm::vec2& textureCoordinate)
		: position_(position), textureCoordinate_(textureCoordinate) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param x 정점 위치의 x값입니다.
	 * @param y 정점 위치의 y값입니다.
	 * @param z 정점 위치의 z값입니다.
	 * @param s 정점 텍스처 위치의 s값입니다.
	 * @param t 정점 텍스처 위치의 t값입니다.
	 */
	VertexPositionTexture(
		float x, float y, float z,
		float s, float t
	) : position_(x, y, z), textureCoordinate_(s, t) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionTexture(VertexPositionTexture&& instance) noexcept
		: position_(instance.position_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionTexture(const VertexPositionTexture& instance) noexcept
		: position_(instance.position_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionTexture& operator=(VertexPositionTexture&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionTexture& operator=(const VertexPositionTexture& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionTexture);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 텍스처의 위치입니다.
	 */
	glm::vec2 textureCoordinate_;
};


/**
 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점입니다.
 */
struct VertexPositionNormal
{
	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionNormal()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param normal 정점의 노말(법선) 정보 벡터입니다.
	 */
	VertexPositionNormal(const glm::vec3& position, const glm::vec3& normal)
		: position_(position), normal_(normal) {}


	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 생성자입니다.
	 *
	 * @param px 정점 위치의 x값입니다.
	 * @param py 정점 위치의 y값입니다.
	 * @param pz 정점 위치의 z값입니다.
	 * @param nx 정점 노말(법선) 벡터의 x값입니다.
	 * @param ny 정점 노말(법선) 벡터의 y값입니다.
	 * @param nz 정점 노말(법선) 벡터의 z값입니다.
	 */
	VertexPositionNormal(
		float px, float py, float pz,
		float nx, float ny, float nz
	) : position_(px, py, pz), normal_(nx, ny, nz) {}


	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormal(VertexPositionNormal&& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_) {}


	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormal(const VertexPositionNormal& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_) {}


	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormal& operator=(VertexPositionNormal&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;

		return *this;
	}


	/**
	 * @brief 위치와 노말(법선) 벡터 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormal& operator=(const VertexPositionNormal& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormal);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 노말(법선) 벡터입니다.
	 */
	glm::vec3 normal_;
};


/**
 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점입니다.
 */
struct VertexPositionNormalTexture
{
	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionNormalTexture()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), textureCoordinate_(0.0f, 0.0f) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param normal 정점의 노말(법선) 정보 벡터입니다.
	 * @param textureCoordinate 정점의 텍스처 위치 정보입니다.
	 */
	VertexPositionNormalTexture(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& textureCoordinate)
		: position_(position), normal_(normal), textureCoordinate_(textureCoordinate) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param px 정점 위치의 x값입니다.
	 * @param py 정점 위치의 y값입니다.
	 * @param pz 정점 위치의 z값입니다.
	 * @param nx 정점 노말(법선) 벡터의 x값입니다.
	 * @param ny 정점 노말(법선) 벡터의 y값입니다.
	 * @param nz 정점 노말(법선) 벡터의 z값입니다.
	 * @param s 텍스처 위치의 s값입니다.
	 * @param t 텍스처 위치의 t값입니다.
	 */
	VertexPositionNormalTexture(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float s, float t
	) : position_(px, py, pz), normal_(nx, ny, nz), textureCoordinate_(s, t) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormalTexture(VertexPositionNormalTexture&& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormalTexture(const VertexPositionNormalTexture& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormalTexture& operator=(VertexPositionNormalTexture&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormalTexture& operator=(const VertexPositionNormalTexture& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormalTexture);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 노말(법선) 벡터입니다.
	 */
	glm::vec3 normal_;


	/**
	 * @brief 텍스처의 위치입니다.
	 */
	glm::vec2 textureCoordinate_;
};