#pragma once

#include "Resource/IResource.h"

#include "Vector/Vector.h"


/**
 * @brief 색상 메터리얼입니다.
 */
class ColorMaterial : public IResource
{
public:
	/**
	 * @brief 색상 메터리얼의 기본 생성자입니다.
	 * 
	 * @note 이때, 설정되는 색상은 검정색입니다.
	 */
	ColorMaterial() : color_(0.0f, 0.0f, 0.0f, 1.0f) {}


	/**
	 * @brief 색상 메터리얼의 생성자입니다.
	 * 
	 * @param color 메터리얼의 색상입니다.
	 */
	ColorMaterial(const Vector4f& color) 
		: color_(color) 
	{
		bIsInitialized_ = true;
	}


	/**
	 * @brief 색상 메터리얼의 생성자입니다.
	 *
	 * @param r 메터리얼의 색상의 R값 입니다.
	 * @param g 메터리얼의 색상의 G값 입니다.
	 * @param b 메터리얼의 색상의 B값 입니다.
	 * @param a 메터리얼의 색상의 A값 입니다. 기본값은 1.0f입니다.
	 */
	ColorMaterial(float r, float g, float b, float a = 1.0f) 
		: color_(r, g, b, a)
	{
		bIsInitialized_ = true;
	}


	/**
	 * @brief 색상 메터리얼의 가상 소멸자입니다.
	 */
	virtual ~ColorMaterial();


	/**
	 * @brief 색상 메터리얼의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorMaterial);


	/**
	 * @brief 색상 메터리얼의 색상을 설정합니다.
	 * 
	 * @param color 설정할 색상입니다.
	 */
	void SetColor(const Vector4f& color) 
	{ 
		color_ = color;
		bIsInitialized_ = true;
	}


	/**
	 * @brief 색상 메터리얼의 색상을 얻습니다.
	 * 
	 * @return 색상 메터리얼의 색상을 반환합니다.
	 */
	Vector4f GetColor() { return color_; }


	/**
	 * @brief 색상 메터리얼의 리소스를 정리합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 메터리얼의 색상입니다.
	 */
	Vector4f color_;
};