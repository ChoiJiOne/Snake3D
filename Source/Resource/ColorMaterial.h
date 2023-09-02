#pragma once

#include "Resource/IResource.h"

#include "Vector/Vector.h"


/**
 * @brief ���� ���͸����Դϴ�.
 */
class ColorMaterial : public IResource
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
	ColorMaterial(const Vector4f& color) 
		: color_(color) 
	{
		bIsInitialized_ = true;
	}


	/**
	 * @brief ���� ���͸����� �������Դϴ�.
	 *
	 * @param r ���͸����� ������ R�� �Դϴ�.
	 * @param g ���͸����� ������ G�� �Դϴ�.
	 * @param b ���͸����� ������ B�� �Դϴ�.
	 * @param a ���͸����� ������ A�� �Դϴ�. �⺻���� 1.0f�Դϴ�.
	 */
	ColorMaterial(float r, float g, float b, float a = 1.0f) 
		: color_(r, g, b, a)
	{
		bIsInitialized_ = true;
	}


	/**
	 * @brief ���� ���͸����� ���� �Ҹ����Դϴ�.
	 */
	virtual ~ColorMaterial();


	/**
	 * @brief ���� ���͸����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorMaterial);


	/**
	 * @brief ���� ���͸����� ������ �����մϴ�.
	 * 
	 * @param color ������ �����Դϴ�.
	 */
	void SetColor(const Vector4f& color) 
	{ 
		color_ = color;
		bIsInitialized_ = true;
	}


	/**
	 * @brief ���� ���͸����� ������ ����ϴ�.
	 * 
	 * @return ���� ���͸����� ������ ��ȯ�մϴ�.
	 */
	Vector4f GetColor() { return color_; }


	/**
	 * @brief ���� ���͸����� ���ҽ��� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ���͸����� �����Դϴ�.
	 */
	Vector4f color_;
};