#pragma once

#include <glm/glm.hpp>


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
	VertexPosition(const glm::vec3& position) : position_(position) {}


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
	glm::vec3 position_;
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
	VertexPositionColor(const glm::vec3& position, const glm::vec4& color)
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
	glm::vec3 position_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	glm::vec4 color_;
};


/**
 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionTexture
{
	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionTexture()
		: position_(0.0f, 0.0f, 0.0f), textureCoordinate_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param textureCoordinate ������ �ؽ�ó ��ġ �����Դϴ�.
	 */
	VertexPositionTexture(const glm::vec3& position, const glm::vec2& textureCoordinate)
		: position_(position), textureCoordinate_(textureCoordinate) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param x ���� ��ġ�� x���Դϴ�.
	 * @param y ���� ��ġ�� y���Դϴ�.
	 * @param z ���� ��ġ�� z���Դϴ�.
	 * @param s ���� �ؽ�ó ��ġ�� s���Դϴ�.
	 * @param t ���� �ؽ�ó ��ġ�� t���Դϴ�.
	 */
	VertexPositionTexture(
		float x, float y, float z,
		float s, float t
	) : position_(x, y, z), textureCoordinate_(s, t) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionTexture(VertexPositionTexture&& instance) noexcept
		: position_(instance.position_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionTexture(const VertexPositionTexture& instance) noexcept
		: position_(instance.position_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionTexture& operator=(VertexPositionTexture&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief ��ġ�� �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionTexture& operator=(const VertexPositionTexture& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionTexture);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief �ؽ�ó�� ��ġ�Դϴ�.
	 */
	glm::vec2 textureCoordinate_;
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
	VertexPositionNormal(const glm::vec3& position, const glm::vec3& normal)
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
	glm::vec3 position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	glm::vec3 normal_;
};


/**
 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionNormalTexture
{
	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionNormalTexture()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), textureCoordinate_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param normal ������ �븻(����) ���� �����Դϴ�.
	 * @param textureCoordinate ������ �ؽ�ó ��ġ �����Դϴ�.
	 */
	VertexPositionNormalTexture(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& textureCoordinate)
		: position_(position), normal_(normal), textureCoordinate_(textureCoordinate) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param px ���� ��ġ�� x���Դϴ�.
	 * @param py ���� ��ġ�� y���Դϴ�.
	 * @param pz ���� ��ġ�� z���Դϴ�.
	 * @param nx ���� �븻(����) ������ x���Դϴ�.
	 * @param ny ���� �븻(����) ������ y���Դϴ�.
	 * @param nz ���� �븻(����) ������ z���Դϴ�.
	 * @param s �ؽ�ó ��ġ�� s���Դϴ�.
	 * @param t �ؽ�ó ��ġ�� t���Դϴ�.
	 */
	VertexPositionNormalTexture(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float s, float t
	) : position_(px, py, pz), normal_(nx, ny, nz), textureCoordinate_(s, t) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalTexture(VertexPositionNormalTexture&& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalTexture(const VertexPositionNormalTexture& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ��ġ, �븻(����) ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormalTexture);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	glm::vec3 normal_;


	/**
	 * @brief �ؽ�ó�� ��ġ�Դϴ�.
	 */
	glm::vec2 textureCoordinate_;
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
	VertexPositionNormalColor(const glm::vec3& position, const glm::vec3& normal, const glm::vec4& color)
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
	glm::vec3 position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	glm::vec3 normal_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	glm::vec4 color_;
};


/**
 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionColorTexture
{
	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionColorTexture()
		: position_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f), textureCoordinate_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param color ������ ���� �����Դϴ�.
	 * @param textureCoordinate ������ �ؽ�ó ��ġ �����Դϴ�.
	 */
	VertexPositionColorTexture(const glm::vec3& position, const glm::vec4& color, const glm::vec2& textureCoordinate)
		: position_(position), color_(color), textureCoordinate_(textureCoordinate) {}


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
	 * @param s ���� �ؽ�ó ��ġ�� s���Դϴ�.
	 * @param t ���� �ؽ�ó ��ġ�� t���Դϴ�.
	 */
	VertexPositionColorTexture(
		float px, float py, float pz,
		float r, float g, float b, float a,
		float s, float t
	) : position_(px, py, pz), color_(r, g, b, a), textureCoordinate_(s, t) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColorTexture(VertexPositionColorTexture&& instance) noexcept
		: position_(instance.position_),
		color_(instance.color_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionColorTexture(const VertexPositionColorTexture& instance) noexcept
		: position_(instance.position_),
		color_(instance.color_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColorTexture& operator=(VertexPositionColorTexture&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief ��ġ, ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionColorTexture& operator=(const VertexPositionColorTexture& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		color_ = instance.color_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionColorTexture);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	glm::vec4 color_;


	/**
	 * @brief ������ �ؽ�ó ��ġ�Դϴ�.
	 */
	glm::vec2 textureCoordinate_;
};


/**
 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� �����Դϴ�.
 */
struct VertexPositionNormalColorTexture
{
	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ �⺻ �������Դϴ�.
	 */
	VertexPositionNormalColorTexture()
		: position_(0.0f, 0.0f, 0.0f), normal_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 0.0f), textureCoordinate_(0.0f, 0.0f) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param position ������ ��ġ �����Դϴ�.
	 * @param normal ������ �븻(����) ���� �����Դϴ�.
	 * @param color ������ ���� �����Դϴ�.
	 * @param textureCoordinate ������ �ؽ�ó �����Դϴ�.
	 */
	VertexPositionNormalColorTexture(const glm::vec3& position, const glm::vec3& normal, const glm::vec4& color, const glm::vec2& textureCoordinate)
		: position_(position), normal_(normal), color_(color), textureCoordinate_(textureCoordinate) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
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
	 * @param s ���� �ؽ�ó ��ġ�� s ���Դϴ�.
	 * @param t ���� �ؽ�ó ��ġ�� t ���Դϴ�.
	 */
	VertexPositionNormalColorTexture(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float r, float g, float b, float a,
		float s, float t
	) : position_(px, py, pz), normal_(nx, ny, nz), color_(r, g, b, a), textureCoordinate_(s, t) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalColorTexture(VertexPositionNormalColorTexture&& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_),
		color_(instance.color_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 */
	VertexPositionNormalColorTexture(const VertexPositionNormalColorTexture& instance) noexcept
		: position_(instance.position_),
		normal_(instance.normal_),
		color_(instance.color_),
		textureCoordinate_(instance.textureCoordinate_) {}


	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionNormalColorTexture& operator=(VertexPositionNormalColorTexture&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		color_ = instance.color_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief ��ġ, �븻(����) ����, ����, �ؽ�ó ��ġ ������ ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	VertexPositionNormalColorTexture& operator=(const VertexPositionNormalColorTexture& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		color_ = instance.color_;
		textureCoordinate_ = instance.textureCoordinate_;

		return *this;
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionNormalColorTexture);
	}


	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief �븻(����) �����Դϴ�.
	 */
	glm::vec3 normal_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	glm::vec4 color_;


	/**
	 * @brief ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	glm::vec2 textureCoordinate_;
};