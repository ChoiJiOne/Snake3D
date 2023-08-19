#pragma once

#include "Vector/Vector.h"


/**
 * @brief ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPosition
{
	/**
	 * @brief ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPosition() : position_(0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief ��ġ ������ ���� ������ �������Դϴ�.
	 * 
	 * @param position ������ ��ġ �����Դϴ�.
	 */
	VertexPosition(const Vector3f& position) : position_(position) {}


	/**
	 * @brief ��ġ ������ ���� ������ �������Դϴ�.
	 * 
	 * @param x ���� ��ġ�� x���Դϴ�.
	 * @param y ���� ��ġ�� y���Դϴ�.
	 * @param z ���� ��ġ�� z���Դϴ�.
	 */
	VertexPosition(float x, float y, float z) : position_(x, y, z) {}


	/**
	 * @brief ��ġ ������ ���� ������ �������Դϴ�.
	 * 
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPosition(VertexPosition&& instance) noexcept
		: position_(instance.position_) {}


	/**
	 * @brief ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPosition(const VertexPosition& instance) noexcept
		: position_(instance.position_) {}


	/**
	 * @brief ��ġ ������ ���� ������ ���� �������Դϴ�.
	 * 
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPosition& operator=(VertexPosition&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;

		return *this;
	}


	/**
	 * @brief ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPosition& operator=(const VertexPosition& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 * 
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPosition);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;
};


/**
 * @brief ��ġ�� ���� ������ ���� �����Դϴ�.
 */
struct VertexPositionColor
{
	/**
	 * @brief ��ġ�� ���� ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionColor() 
		: position_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param color ������ ���� �����Դϴ�.
	 */
	VertexPositionColor(const Vector3f& position, const Vector4f& color) 
		: position_(position), color_(color) {}


	/**
	 * @brief ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param x ���� ��ġ�� x���Դϴ�.
	 * @param y ���� ��ġ�� y���Դϴ�.
	 * @param z ���� ��ġ�� z���Դϴ�.
	 * @param r ���� ������ R���Դϴ�.
	 * @param g ���� ������ G���Դϴ�.
	 * @param b ���� ������ B���Դϴ�.
	 * @param a ���� ������ A���Դϴ�.
	 */
	VertexPositionColor(
		float x, float y, float z,
		float r, float g, float b, float a
	) : position_(x, y, z), color_(r, g, b, a) {}


	/**
	 * @brief ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColor(VertexPositionColor&& instance) noexcept
		: position_(instance.position_), 
		  color_(instance.color_) {}


	/**
	 * @brief ��ġ�� ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColor(const VertexPositionColor& instance) noexcept
		: position_(instance.position_),
		color_(instance.color_) {}


	/**
	 * @brief ��ġ�� ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColor& operator=(VertexPositionColor&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief ��ġ�� ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColor& operator=(const VertexPositionColor& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionColor);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	Vector4f color_;
};


/**
 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionUV
{
	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionUV()
		: position_(0.0f, 0.0f, 0.0f), uv_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param uv ������ �ؽ�ó ��ġ �����Դϴ�.
	 */
	VertexPositionUV(const Vector3f& position, const Vector2f& uv)
		: position_(position), uv_(uv) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param x ���� ��ġ�� x���Դϴ�.
	 * @param y ���� ��ġ�� y���Դϴ�.
	 * @param z ���� ��ġ�� z���Դϴ�.
	 * @param u ���� �ؽ�ó ��ġ�� u���Դϴ�.
	 * @param v ���� �ؽ�ó ��ġ�� v���Դϴ�.
	 */
	VertexPositionUV(
		float x, float y, float z, 
		float u, float v
	) : position_(x, y, z), uv_(u, v) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionUV(VertexPositionUV&& instance) noexcept
		: position_(instance.position_),
		  uv_(instance.uv_) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionUV(const VertexPositionUV& instance) noexcept
		: position_(instance.position_),
		  uv_(instance.uv_) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionUV& operator=(VertexPositionUV&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionUV& operator=(const VertexPositionUV& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionUV);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;


	/**
	 * @brief �ؽ�ó�� ��ġ�Դϴ�.
	 */
	Vector2f uv_;
};


/**
 * @brief ��ġ�� �븻(����) ���� ������ ���� �����Դϴ�.
 */
struct VertexPositionNormal
{
	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionNormal()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param normal ������ �븻(����) ���� �����Դϴ�.
	 */
	VertexPositionNormal(const Vector3f& position, const Vector3f& normal)
		: position_(position), normal_(normal) {}


	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param px ���� ��ġ�� x���Դϴ�.
	 * @param py ���� ��ġ�� y���Դϴ�.
	 * @param pz ���� ��ġ�� z���Դϴ�.
	 * @param nx ���� �븻(����) ������ x���Դϴ�.
	 * @param ny ���� �븻(����) ������ y���Դϴ�.
	 * @param nz ���� �븻(����) ������ z���Դϴ�.
	 */
	VertexPositionNormal(
		float px, float py, float pz,
		float nx, float ny, float nz
	) : position_(px, py, pz), normal_(nx, ny, nz) {}


	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormal(VertexPositionNormal&& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_) {}


	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormal(const VertexPositionNormal& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_) {}


	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionNormal& operator=(VertexPositionNormal&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;

		return *this;
	}


	/**
	 * @brief ��ġ�� �븻(����) ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionNormal& operator=(const VertexPositionNormal& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormal);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	Vector3f normal_;
};



/**
 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionNormalUV
{
	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionNormalUV()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), uv_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param normal ������ �븻(����) ���� �����Դϴ�.
	 * @param uv ������ �ؽ�ó ��ġ �����Դϴ�.
	 */
	VertexPositionNormalUV(const Vector3f& position, const Vector3f& normal, const Vector2f& uv)
		: position_(position), normal_(normal), uv_(uv) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param px ���� ��ġ�� x���Դϴ�.
	 * @param py ���� ��ġ�� y���Դϴ�.
	 * @param pz ���� ��ġ�� z���Դϴ�.
	 * @param nx ���� �븻(����) ������ x���Դϴ�.
	 * @param ny ���� �븻(����) ������ y���Դϴ�.
	 * @param nz ���� �븻(����) ������ z���Դϴ�.
	 * @param u �ؽ�ó ��ġ�� u���Դϴ�.
	 * @param v �ؽ�ó ��ġ�� v���Դϴ�.
	 */
	VertexPositionNormalUV(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float u, float v
	) : position_(px, py, pz), normal_(nx, ny, nz), uv_(u, v) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalUV(VertexPositionNormalUV&& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  uv_(instance.uv_){}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalUV(const VertexPositionNormalUV& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  uv_(instance.uv_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormalUV);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	Vector3f normal_;


	/**
	 * @brief �ؽ�ó�� ��ġ�Դϴ�.
	 */
	Vector2f uv_;
};


/**
 * @brief ��ġ, �븻(����) ����, ���� ������ ���� �����Դϴ�.
 */
struct VertexPositionNormalColor
{
	/**
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionNormalColor()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param normal ������ �븻(����) ���� �����Դϴ�.
	 * @param color ������ ���� �����Դϴ�.
	 */
	VertexPositionNormalColor(const Vector3f& position, const Vector3f& normal, const Vector4f& color)
		: position_(position), normal_(normal), color_(color) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param px ���� ��ġ�� x���Դϴ�.
	 * @param py ���� ��ġ�� y���Դϴ�.
	 * @param pz ���� ��ġ�� z���Դϴ�.
	 * @param nx ���� �븻(����) ������ x���Դϴ�.
	 * @param ny ���� �븻(����) ������ y���Դϴ�.
	 * @param nz ���� �븻(����) ������ z���Դϴ�.
	 * @param r ���� ������ R���Դϴ�.
	 * @param g ���� ������ G���Դϴ�.
	 * @param b ���� ������ B���Դϴ�.
	 * @param a ���� ������ A���Դϴ�.
	 */
	VertexPositionNormalColor(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float r, float g, float b, float a
	) : position_(px, py, pz), normal_(nx, ny, nz), color_(r, g, b, a) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalColor(VertexPositionNormalColor&& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  color_(instance.color_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalColor(const VertexPositionNormalColor& instance) noexcept
		: position_(instance.position_),
		  normal_(instance.normal_),
		  color_(instance.color_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ��ġ, �븻(����) ����, ���� ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormalColor);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	Vector3f normal_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	Vector4f color_;
};


/**
 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionColorUV
{
	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionColorUV()
		: position_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f), uv_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param color ������ ���� �����Դϴ�.
	 * @param uv ������ �ؽ�ó ��ġ �����Դϴ�.
	 */
	VertexPositionColorUV(const Vector3f& position, const Vector4f& color, const Vector2f& uv)
		: position_(position), color_(color), uv_(uv) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param px ���� ��ġ�� x���Դϴ�.
	 * @param py ���� ��ġ�� y���Դϴ�.
	 * @param pz ���� ��ġ�� z���Դϴ�.
	 * @param r ���� ������ R���Դϴ�.
	 * @param g ���� ������ G���Դϴ�.
	 * @param b ���� ������ B���Դϴ�.
	 * @param a ���� ������ A���Դϴ�.
	 * @param u ���� �ؽ�ó ��ġ�� u���Դϴ�.
	 * @param v ���� �ؽ�ó ��ġ�� v���Դϴ�.
	 */
	VertexPositionColorUV(
		float px, float py, float pz,
		float r, float g, float b, float a,
		float u, float v
	) : position_(px, py, pz), color_(r, g, b, a), uv_(u, v) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColorUV(VertexPositionColorUV&& instance) noexcept
		: position_(instance.position_),
		  color_(instance.color_),
          uv_(instance.uv_) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColorUV(const VertexPositionColorUV& instance) noexcept
		: position_(instance.position_),
          color_(instance.color_),
		  uv_(instance.uv_) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColorUV& operator=(VertexPositionColorUV&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColorUV& operator=(const VertexPositionColorUV& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionColorUV);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vector3f position_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	Vector4f color_;


	/**
	 * @brief ������ �ؽ�ó ��ġ�Դϴ�.
	 */
	Vector2f uv_;
};