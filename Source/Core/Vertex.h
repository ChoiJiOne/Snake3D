#pragma once

#include "Vector/Vector.h"


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
	VertexPosition(const Vector3f& position) : position_(position) {}


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
	Vector3f position_;
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
	VertexPositionColor(const Vector3f& position, const Vector4f& color) 
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
	Vector3f position_;


	/**
	 * @brief 정점의 색상입니다.
	 */
	Vector4f color_;
};


/**
 * @brief 위치와 텍스처 위치 정보를 가진 정점입니다.
 */
struct VertexPositionUV
{
	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionUV()
		: position_(0.0f, 0.0f, 0.0f), uv_(0.0f, 0.0f) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param uv 정점의 텍스처 위치 정보입니다.
	 */
	VertexPositionUV(const Vector3f& position, const Vector2f& uv)
		: position_(position), uv_(uv) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param x 정점 위치의 x값입니다.
	 * @param y 정점 위치의 y값입니다.
	 * @param z 정점 위치의 z값입니다.
	 * @param u 정점 텍스처 위치의 u값입니다.
	 * @param v 정점 텍스처 위치의 v값입니다.
	 */
	VertexPositionUV(
		float x, float y, float z, 
		float u, float v
	) : position_(x, y, z), uv_(u, v) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionUV(VertexPositionUV&& instance) noexcept
		: position_(instance.position_),
		  uv_(instance.uv_) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionUV(const VertexPositionUV& instance) noexcept
		: position_(instance.position_),
		  uv_(instance.uv_) {}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionUV& operator=(VertexPositionUV&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 위치와 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionUV& operator=(const VertexPositionUV& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionUV);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	Vector3f position_;


	/**
	 * @brief 텍스처의 위치입니다.
	 */
	Vector2f uv_;
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
	VertexPositionNormal(const Vector3f& position, const Vector3f& normal)
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
	Vector3f position_;


	/**
	 * @brief 노말(법선) 벡터입니다.
	 */
	Vector3f normal_;
};



/**
 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점입니다.
 */
struct VertexPositionNormalUV
{
	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionNormalUV()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), uv_(0.0f, 0.0f) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param normal 정점의 노말(법선) 정보 벡터입니다.
	 * @param uv 정점의 텍스처 위치 정보입니다.
	 */
	VertexPositionNormalUV(const Vector3f& position, const Vector3f& normal, const Vector2f& uv)
		: position_(position), normal_(normal), uv_(uv) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param px 정점 위치의 x값입니다.
	 * @param py 정점 위치의 y값입니다.
	 * @param pz 정점 위치의 z값입니다.
	 * @param nx 정점 노말(법선) 벡터의 x값입니다.
	 * @param ny 정점 노말(법선) 벡터의 y값입니다.
	 * @param nz 정점 노말(법선) 벡터의 z값입니다.
	 * @param u 텍스처 위치의 u값입니다.
	 * @param v 텍스처 위치의 v값입니다.
	 */
	VertexPositionNormalUV(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float u, float v
	) : position_(px, py, pz), normal_(nx, ny, nz), uv_(u, v) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormalUV(VertexPositionNormalUV&& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  uv_(instance.uv_){}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormalUV(const VertexPositionNormalUV& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  uv_(instance.uv_) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormalUV& operator=(VertexPositionNormalUV&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 위치, 노말(법선) 벡터, 텍스처 위치 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormalUV& operator=(const VertexPositionNormalUV& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 바이트 보폭(stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormalUV);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	Vector3f position_;


	/**
	 * @brief 노말(법선) 벡터입니다.
	 */
	Vector3f normal_;


	/**
	 * @brief 텍스처의 위치입니다.
	 */
	Vector2f uv_;
};


/**
 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점입니다.
 */
struct VertexPositionNormalColor
{
	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionNormalColor()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치 정보입니다.
	 * @param normal 정점의 노말(법선) 정보 벡터입니다.
	 * @param color 정점의 색상 정보입니다.
	 */
	VertexPositionNormalColor(const Vector3f& position, const Vector3f& normal, const Vector4f& color)
		: position_(position), normal_(normal), color_(color) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param px 정점 위치의 x값입니다.
	 * @param py 정점 위치의 y값입니다.
	 * @param pz 정점 위치의 z값입니다.
	 * @param nx 정점 노말(법선) 벡터의 x값입니다.
	 * @param ny 정점 노말(법선) 벡터의 y값입니다.
	 * @param nz 정점 노말(법선) 벡터의 z값입니다.
	 * @param r 정점 색상의 R값입니다.
	 * @param g 정점 색상의 G값입니다.
	 * @param b 정점 색상의 B값입니다.
	 * @param a 정점 색상의 A값입니다.
	 */
	VertexPositionNormalColor(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float r, float g, float b, float a
	) : position_(px, py, pz), normal_(nx, ny, nz), color_(r, g, b, a) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormalColor(VertexPositionNormalColor&& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  color_(instance.color_) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점의 인스턴스입니다.
	 */
	VertexPositionNormalColor(const VertexPositionNormalColor& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  color_(instance.color_) {}


	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormalColor& operator=(VertexPositionNormalColor&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief 위치, 노말(법선) 벡터, 색상 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점의 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionNormalColor& operator=(const VertexPositionNormalColor& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
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
		return sizeof(VertexPositionNormalColor);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	Vector3f position_;


	/**
	 * @brief 노말(법선) 벡터입니다.
	 */
	Vector3f normal_;


	/**
	 * @brief 정점의 색상입니다.
	 */
	Vector4f color_;
};