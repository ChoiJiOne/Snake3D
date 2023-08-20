#pragma once

#include <d3d11.h>
#include <string>

#include "Core/Macro.h"
#include "Core/MathHelper.h"


/**
 * @brief HLSL�� �ϴ��� �����ϴ� ���̴��� �������̽��Դϴ�.
 * 
 * @note ���̴��� �ݵ�� �� �������̽��� ��ӹ޾ƾ� �մϴ�.
 */
class IShader
{
public:
	/**
	 * @brief HLSL�� �ϴ��� �����ϴ� ���̴� �������̽��� ����Ʈ �������Դϴ�.
	 * 
	 * @note �ʱ�ȭ�� �ϱ� ���ؼ��� �ݵ�� ���� Ŭ������ Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	IShader() = default;


	/**
	 * @brief HLSL�� �ϴ��� �����ϴ� ���̴� �������̽��� ���� �Ҹ����Դϴ�.
	 * 
	 * @note ���̴� �� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� ���� Ŭ������ Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~IShader() {}


	/**
	 * @brief HLSL�� �ϴ��� �����ϴ� ���̴� �������̽��� ���� ������ �� ���� ������ ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IShader);


	/**
	 * @brief HLSL�� �ϴ��� �����ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 * 
	 * @note ���� Ŭ�������� �� �޼��带 �޵�� ���� �� �����ؾ� �մϴ�.
	 */
	virtual void Initialize() = 0;


	/**
	 * @brief HLSL�� �ϴ��� �����ϴ� ���̴��� �����մϴ�.
	 * 
	 * @note ���� Ŭ�������� �� �޼��带 �޵�� ���� �� �����ؾ� �մϴ�.
	 */
	virtual void Release() = 0;


protected:
	/**
	 * @brief HLSL ���̴� ������ �������մϴ�.
	 *
	 * @param path ���̴� ������ ����Դϴ�.
	 * @param entryPoint ���̴��� ���� ����Դϴ�.
	 * @param shaderModel ���̴��� ���Դϴ�.
	 * @param outBlob �����ϵ� ���̴��Դϴ�.
	 *
	 * @return �����ϵ� ����� HRESULT ������ ��ȯ�մϴ�. �����Ͽ� �����ϸ� S_OK, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
	 */
	static HRESULT CompileShaderFromFile(const std::wstring& path, const std::string& entryPoint, const std::string& shaderModel, ID3DBlob** outBlob);


	/**
	 * @brief ���ؽ� ���̴��� �������ϰ� �����մϴ�.
	 * 
	 * @param device ���̴� ���ҽ� ������ ����� D3D11 ����̽��Դϴ�.
	 * @param path ���ؽ� ���̴��� ����Դϴ�.
	 */
	void CreateVertexShader(ID3D11Device* device, const std::wstring& path);


	/**
	 * @brief �ȼ� ���̴��� �������ϰ� �����մϴ�.
	 * 
	 * @param device ���̴� ���ҽ� ������ ����� D3D11 ����̽��Դϴ�.
	 * @param path �ȼ� ���̴��� ����Դϴ�.
	 */
	void CreatePixelShader(ID3D11Device* device, const std::wstring& path);


	/**
	 * @brief �Է� ����� �ܰ迡 ���� ���ҽ��� �����մϴ�.
	 * 
	 * @param device �Է� ����� �ܰ迡 ���� ���ҽ��� ������ �� ����� D3D11 ����̽��Դϴ�.
	 * @param inputLayout �Է� ����� �ܰ迡 ���� ����Դϴ�.
	 */
	void CreateInputLayout(ID3D11Device* device, const std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayout);


	/**
	 * @brief ���������ο��� ����� ���̳��� ���� ���۸� �����մϴ�.
	 *
	 * @param device ���۸� ������ �� ����� D3D11 ����̽��Դϴ�.
	 * @param vertices ���̳��� ������ �������Դϴ�.
	 * @param vertexByteSize ���̳��� ������ ����Ʈ ũ���Դϴ�.
	 * @param vertexCount ���̳��� ������ ���Դϴ�.
	 * @param outVertexBuffer ������ ���� �����Դϴ�.
	 */
	void CreateDynamicVertexBuffer(ID3D11Device* device, const void* vertices, uint32_t vertexByteSize, uint32_t vertexCount, ID3D11Buffer** outVertexBuffer);


	/**
	 * @brief ���������ο��� ����� �ε��� ���۸� �����մϴ�.
	 *
	 * @param device ���۸� ������ �� ����� D3D11 ����̽��Դϴ�.
	 * @param indices �ε��� ���۸� ������ �� ������ �ε��� ����Դϴ�.
	 * @param outIndexBuffer ������ �ε��� �����Դϴ�.
	 */
	void CreateIndexBuffer(ID3D11Device* Device, const std::vector<uint32_t>& indices, ID3D11Buffer** outIndexBuffer);


	/**
	 * @brief ���̳��� ��� ���۸� �����մϴ�.
	 * 
	 * @param device ��� ���� ������ �� ����� D3D11 ����̽��Դϴ�.
	 * @param bufferByteWidth ��� ������ ũ���Դϴ�.
	 * @param outConstantBuffer ������ ��� �����Դϴ�.
	 */
	void CreateDynamicConstantBuffer(ID3D11Device* device, uint32_t bufferByteWidth, ID3D11Buffer** outConstantBuffer);


protected:
	/**
	 * @brief ���̴��� �ʱ�ȭ�� ���� �ִ��� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief �����ϵ� ���ؽ� ���̴��� ����Ʈ �ڵ��Դϴ�.
	 */
	ID3DBlob* vertexShaderBuffer_ = nullptr;


	/**
	 * @brief ���ؽ� ���̴� �ܰ踦 �����ϴ� ���� ���α׷�(���ؽ� ���̴�)�� �����մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11vertexshader
	 */
	ID3D11VertexShader* vertexShader_ = nullptr;


	/**
	 * @brief �����ϵ� �ȼ� ���̴��� ����Ʈ �ڵ��Դϴ�.
	 */
	ID3DBlob* pixelShaderBuffer_ = nullptr;


	/**
	 * @brief �ȼ� ���̴� �ܰ踦 �����ϴ� ���� ���α׷�(�ȼ� ���̴�)�� �����մϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11pixelshader
	 */
	ID3D11PixelShader* pixelShader_ = nullptr;


	/**
	 * @brief �޸𸮿� ��ġ�� ���ؽ� �����͸� �׷��� ������������ �Է� ����� �ܰ迡 �����ϴ� ����� ���� �����Դϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11inputlayout
	 */
	ID3D11InputLayout* inputLayout_ = nullptr;
};