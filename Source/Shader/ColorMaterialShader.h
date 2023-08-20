#pragma once

#include "Shader/IShader.h"

class Model;
class Camera3D;


/**
 * @brief 색상 메터리얼을 렌더링하는 셰이더입니다.
 *
 * @note 이 셰이더 클래스는 HLSL 셰이더와 일대일 대응합니다.
 */
class ColorMaterialShader : public IShader
{
public:
	/**
	 * @brief 매 프레임 변경되는 상수 버퍼입니다.
	 */
	struct EveryFrameBuffer
	{
		Matrix4x4f world;
		Matrix4x4f view;
		Matrix4x4f projection;
	};


	/**
	 * @brief 색상 메터리얼 상수 버퍼입니다.
	 */
	struct ColorMaterialBuffer
	{
		Vector4f color;
	};


public:
	/**
	 * @brief 색상 메터리얼을 렌더링하는 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 초기화를 하기 위해서는 반드시 Initialize 메서드를 호출해야 합니다.
	 */
	ColorMaterialShader() = default;


	/**
	 * @brief 색상 메터리얼을 렌더링하는 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더 내 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~ColorMaterialShader();


	/**
	 * @brief 색상 메터리얼을 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorMaterialShader);


	/**
	 * @brief 색상 메터리얼을 렌더링하는 셰이더를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 색상 메터리얼을 렌더링하는 셰이더를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 셰이더를 파이프라인에 바인딩하여 모델을 백버퍼에 그립니다.
	 *
	 * @param world 모델의 월드 행렬입니다.
	 * @param camera 월드 상의 카메라입니다.
	 * @param model 렌더링할 모델입니다.
	 */
	void Draw(const Matrix4x4f& world, Camera3D* camera, Model* model);


private:
	/**
	 * @brief 비정형 메모리인 버퍼 리소스 중 상수 버퍼에 액세스하기 위한 인터페이스입니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;


	/**
	 * @brief 비정형 메모리인 버퍼 리소스 중 상수 버퍼에 액세스하기 위한 인터페이스입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* colorMaterialBuffer_ = nullptr;
};