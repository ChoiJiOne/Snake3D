#pragma once

#include <d3d11.h>
#include <string>

#include "Core/Macro.h"
#include "Core/MathHelper.h"

class Model;
class Mesh;
class Camera3D;


/**
 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��Դϴ�.
 * 
 * @note 
 * - �� ���̴� Ŭ������ HLSL ���̴��� �ϴ��� �����մϴ�.
 * - �� ���̴��� �޽ô� ������ ���� �������� ������ �־�� �մϴ�.
 */
class ColorPassShader
{
public:
	/**
	 * @brief �� ������ ����Ǵ� ��� �����Դϴ�.
	 */
	struct EveryFrameBuffer
	{
		Matrix4x4f world;
		Matrix4x4f view;
		Matrix4x4f projection;
	};


public:
	/**
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 * 
	 * @note �ʱ�ȭ�� �ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	ColorPassShader() = default;


	/**
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 * 
	 * @note ���̴� �� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~ColorPassShader();


	/**
	 * @brief ���Է����� ���� ���� ������ �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorPassShader);


	/**
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� �����մϴ�.
	 */
	void Release();


	/**
	 * @brief ���̴��� ���������ο� ���ε��Ͽ� ���� ����ۿ� �׸��ϴ�.
	 * 
	 * @param world ���� ���� ����Դϴ�.
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param model �������� ���Դϴ�.
	 */
	void Draw(const Matrix4x4f& world, Camera3D* camera, Model* model);

	
private:
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


private:
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


	/**
	 * @brief ������ �޸��� ���� ���ҽ� �� ��� ���ۿ� �׼����ϱ� ���� �������̽��Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;
};