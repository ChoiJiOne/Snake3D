#pragma once

#include "Vector/Vector.h"


/**
 * @brief ���� ���͸����Դϴ�.
 */
class ColorMaterial
{
public:
	/**
	 * @brief ���� ���͸����� �⺻ �������Դϴ�.
	 * 
	 * @note �̶�, �����Ǵ� ������ �������Դϴ�.
	 */
	ColorMaterial() : color_(0.0f, 0.0f, 0.0f, 1.0f) {}


	/**
	 * @brief ���� ���͸����� �������Դϴ�.
	 * 
	 * @param color ���͸����� �����Դϴ�.
	 */
	ColorMaterial(const Vector4f& color) : color_(color) {}


	/**
	 * @brief ���� ���͸����� �������Դϴ�.
	 *
	 * @param r ���͸����� ������ R�� �Դϴ�.
	 * @param g ���͸����� ������ G�� �Դϴ�.
	 * @param b ���͸����� ������ B�� �Դϴ�.
	 * @param a ���͸����� ������ A�� �Դϴ�. �⺻���� 1.0f�Դϴ�.
	 */
	ColorMaterial(float r, float g, float b, float a = 1.0f) : color_(r, g, b, a) {}


	/**
	 * @brief ���� ���͸����� ���� �������Դϴ�.
	 * 
	 * @param instance ������ ���� ���͸��� �ν��Ͻ��Դϴ�.
	 */
	ColorMaterial(ColorMaterial&& instance) noexcept : color_(instance.color_) {}


	/**
	 * @brief ���� ���͸����� ���� �������Դϴ�.
	 * 
	 * @param instance ������ ���� ���͸��� �ν��Ͻ��Դϴ�.
	 */
	ColorMaterial(const ColorMaterial& instance) noexcept : color_(instance.color_) {}


	/**
	 * @brief ���� ���͸����� ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������ ������ ���� ���͸��� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ���� ���͸��� ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	ColorMaterial& operator=(ColorMaterial&& instance) noexcept
	{
		if (this == &instance) return *this;

		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief ���� ���͸����� ���� �������Դϴ�.
	 *
	 * @param instance ���� ������ ������ ���� ���͸��� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ���� ���͸��� ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	ColorMaterial& operator=(const ColorMaterial& instance) noexcept
	{
		if (this == &instance) return *this;

		color_ = instance.color_;

		return *this;
	}


	/**
	 * @brief ���� ���͸����� ������ �����մϴ�.
	 * 
	 * @param color ������ �����Դϴ�.
	 */
	void SetColor(const Vector4f& color) { color_ = color; }


	/**
	 * @brief ���� ���͸����� ������ ����ϴ�.
	 * 
	 * @return ���� ���͸����� ������ ��ȯ�մϴ�.
	 */
	Vector4f GetColor() { return color_; }


private:
	/**
	 * @brief ���͸����� �����Դϴ�.
	 */
	Vector4f color_;
};