#pragma once

#include "Vector/Vector.h"


/**
 * @brief �׸���(����)�� �� �����Դϴ�.
 */
class Cell
{
public:
	/**
	 * @brief �׸��� �� ���� ������ �������Դϴ�.
	 */
	Cell() : transform_(0.0f, 0.0f, 0.0f), color_(0.0f, 0.0f, 0.0f, 1.0f) {}


	/**
	 * @brief �׸��� �� ���� ������ �������Դϴ�.
	 * 
	 * @param transform �׸��� �� ������ ��ȯ�� ��ġ ���Դϴ�.
	 * @param color �׸��� �� ������ �����Դϴ�.
	 */
	Cell(const Vector3f& transform, const Vector4f& color)
		: transform_(transform)
		, color_(color) {}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 * 
	 * @param instance ������ �ν��Ͻ��Դϴ�.
	 */
	Cell(Cell&& instance) noexcept
		: transform_(instance.transform_)
		, color_(instance.color_) {}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ �ν��Ͻ��Դϴ�.
	 */
	Cell(const Cell& instance) noexcept
		: transform_(instance.transform_)
		, color_(instance.color_) {}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������ ���� ������ �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Cell& operator=(Cell&& instance) noexcept
	{
		if (this == &instance) return *this;

		transform_ = instance.transform_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ���� ������ ���� ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Cell& operator=(const Cell& instance) noexcept
	{
		if (this == &instance) return *this;

		transform_ = instance.transform_;
		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief ���� �׸��� �� ������ ��ȯ�� ��ġ���� ����ϴ�.
	 * 
	 * @return ���� �׸��� �� ������ ��ȯ�� ��ġ���� ��ȯ�մϴ�.
	 */
	Vector3f GetTransform() const { return transform_; }


	/**
	 * @brief ���� �׸��� �� ������ ��ȯ�� ��ġ���� �����մϴ�.
	 * 
	 * @param transform ������ �׸��� �� ������ ��ȯ�� ��ġ���Դϴ�.
	 */
	void SetTransform(const Vector3f& transform) { transform_ = transform; }


	/**
	 * @brief ���� �׸��� �� ���� ���¸� ����ϴ�.
	 *
	 * @return ���� �׸��� �� ���� ���¸� ��ȯ�մϴ�.
	 */
	Vector4f GetColor() const { return color_; }


	/**
	 * @brief ���� �׸��� �� ���� ���¸� �����մϴ�.
	 *
	 * @param state ������ �׸��� �� ���� �����Դϴ�.
	 */
	void SetColor(const Vector4f& color) { color_ = color; }


private:
	/**
	 * @brief ���� �׸��� �� ������ ��ȯ�� ��ġ ���Դϴ�.
	 */
	Vector3f transform_;


	/**
	 * @brief ���� �׸��� �� ������ �����Դϴ�.
	 */
	Vector4f color_;
};