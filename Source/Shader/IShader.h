#pragma once

#include <d3d11.h>
#include <string>

#include "Core/Macro.h"
#include "Core/MathHelper.h"


/**
 * @brief HLSL과 일대일 대응하는 셰이더의 인터페이스입니다.
 * 
 * @note 셰이더는 반드시 이 인터페이스를 상속받아야 합니다.
 */
class IShader
{
public:
	/**
	 * @brief HLSL과 일대일 대응하는 셰이더 인터페이스의 디폴트 생성자입니다.
	 * 
	 * @note 초기화를 하기 위해서는 반드시 하위 클래스의 Initialize 메서드를 호출해야 합니다.
	 */
	IShader() = default;


	/**
	 * @brief HLSL과 일대일 대응하는 셰이더 인터페이스의 가상 소멸자입니다.
	 * 
	 * @note 셰이더 내 리소스를 할당 해제하기 위해서는 반드시 하위 클래스의 Release 메서드를 호출해야 합니다.
	 */
	virtual ~IShader() {}


	/**
	 * @brief HLSL과 일대일 대응하는 셰이더 인터페이스의 복사 생성자 및 대입 연산자 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IShader);


	/**
	 * @brief HLSL과 일대일 대응하는 셰이더를 초기화합니다.
	 * 
	 * @note 하위 클래스에서 이 메서드를 받드시 선언 및 구현해야 합니다.
	 */
	virtual void Initialize() = 0;


	/**
	 * @brief HLSL과 일대일 대응하는 셰이더를 해제합니다.
	 * 
	 * @note 하위 클래스에서 이 메서드를 받드시 선언 및 구현해야 합니다.
	 */
	virtual void Release() = 0;


protected:
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


	/**
	 * @brief 버텍스 셰이더를 컴파일하고 생성합니다.
	 * 
	 * @param device 셰이더 리소스 생성에 사용할 D3D11 디바이스입니다.
	 * @param path 버텍스 셰이더의 경로입니다.
	 */
	void CreateVertexShader(ID3D11Device* device, const std::wstring& path);


	/**
	 * @brief 픽셀 셰이더를 컴파일하고 생성합니다.
	 * 
	 * @param device 셰이더 리소스 생성에 사용할 D3D11 디바이스입니다.
	 * @param path 픽셀 셰이더의 경로입니다.
	 */
	void CreatePixelShader(ID3D11Device* device, const std::wstring& path);


	/**
	 * @brief 입력 어셈블러 단계에 대한 리소스를 생성합니다.
	 * 
	 * @param device 입력 어셈블러 단계에 대한 리소스를 생성할 때 사용할 D3D11 디바이스입니다.
	 * @param inputLayout 입력 어셈블러 단계에 대한 목록입니다.
	 */
	void CreateInputLayout(ID3D11Device* device, const std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayout);


	/**
	 * @brief 다이나믹 상수 버퍼를 생성합니다.
	 * 
	 * @param device 상수 버퍼 생성할 때 사용할 D3D11 디바이스입니다.
	 * @param bufferByteWidth 상수 버퍼의 크기입니다.
	 * @param outConstantBuffer 생성된 상수 버퍼입니다.
	 */
	void CreateDynamicConstantBuffer(ID3D11Device* device, uint32_t bufferByteWidth, ID3D11Buffer** outConstantBuffer);


protected:
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
};