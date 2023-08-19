#pragma once

#include <d3d11.h>
#include <string>

#include "Core/Macro.h"
#include "Core/MathHelper.h"


/**
 * @brief 렌더링을 수행하는 셰이더입니다.
 * 
 * @note 이 셰이더 클래스는 HLSL 셰이더와 일대일 대응합니다.
 */
class Shader
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


public:
	/**
	 * @brief 색상 효과만 렌더링하는 셰이더의 디폴트 생성자입니다.
	 * 
	 * @note 초기화를 하기 위해서는 반드시 Initialize 메서드를 호출해야 합니다.
	 */
	Shader() = default;


	/**
	 * @brief 색상 효과만 렌더링하는 셰이더의 가상 소멸자입니다.
	 * 
	 * @note 셰이더 내 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Shader();


	/**
	 * @brief 색상 효과만 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


	/**
	 * @brief 색상 효과만 렌더링하는 셰이더를 초기화합니다.
	 * 
	 * @param vertexShaderPath HLSL 버텍스 셰이더의 경로입니다.
	 * @param pixelShaderPath HLSL 픽셀 셰이더의 경로입니다.
	 */
	void Initialize(const std::wstring& vertexShaderPath, const std::wstring& pixelShaderPath);


	/**
	 * @brief 색상 효과만 렌더링하는 셰이더를 할당 해제합니다.
	 */
	void Release();


	/**
	 * @brief 색상 효과를 렌더링 파이프라인에 바인딩합니다.
	 */
	void Bind();


private:
	/**
	 * @brief HLSL 셰이더 파일을 컴파일합니다.
	 * 
	 * @param path 셰이더 파일의 경로입니다.
	 * @param entryPoint 셰이더의 진입 경로입니다.
	 * @param shaderModel 셰이더의 모델입니다.
	 * @param outBlob 컴파일된 셰이더입니다.
	 * 
	 * @return 컴파일된 결과를 HRESULT 값으로 반환합니다. 컴파일에 성공하면 S_OK, 그렇지 않으면 그 외의 값을 반환합니다.
	 */
	static HRESULT CompileShaderFromFile(const std::wstring& path, const std::string& entryPoint, const std::string& shaderModel, ID3DBlob** outBlob);


private:
	/**
	 * @brief 셰이더가 초기화된 적이 있는지 확인합니다.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief 컴파일된 버텍스 셰이더의 바이트 코드입니다.
	 */
	ID3DBlob* vertexShaderBuffer_ = nullptr;


	/**
	 * @brief 버텍스 셰이더 단계를 제어하는 실행 프로그램(버텍스 셰이더)을 관리합니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11vertexshader
	 */
	ID3D11VertexShader* vertexShader_ = nullptr;


	/**
	 * @brief 컴파일된 픽셀 셰이더의 바이트 코드입니다.
	 */
	ID3DBlob* pixelShaderBuffer_ = nullptr;


	/**
	 * @brief 픽셀 셰이더 단계를 제어하는 실행 프로그램(픽셀 셰이더)을 관리합니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11pixelshader
	 */
	ID3D11PixelShader* pixelShader_ = nullptr;


	/**
	 * @brief 메모리에 배치된 버텍스 데이터를 그래픽 파이프라인의 입력 어셈블러 단계에 공급하는 방법에 대한 정의입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11inputlayout
	 */
	ID3D11InputLayout* inputLayout_ = nullptr;


	/**
	 * @brief 비정형 메모리인 버퍼 리소스 중 상수 버퍼에 액세스하기 위한 인터페이스입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;
};