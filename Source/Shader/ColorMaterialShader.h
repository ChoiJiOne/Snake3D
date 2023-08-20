#pragma once

#include "Shader/IShader.h"

class Model;
class Camera3D;


/**
 * @brief ���� ���͸����� �������ϴ� ���̴��Դϴ�.
 *
 * @note �� ���̴� Ŭ������ HLSL ���̴��� �ϴ��� �����մϴ�.
 */
class ColorMaterialShader : public IShader
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


	/**
	 * @brief ���� ���͸��� ��� �����Դϴ�.
	 */
	struct ColorMaterialBuffer
	{
		Vector4f color;
	};


public:
	/**
	 * @brief ���� ���͸����� �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note �ʱ�ȭ�� �ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	ColorMaterialShader() = default;


	/**
	 * @brief ���� ���͸����� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴� �� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~ColorMaterialShader();


	/**
	 * @brief ���� ���͸����� �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorMaterialShader);


	/**
	 * @brief ���� ���͸����� �������ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief ���� ���͸����� �������ϴ� ���̴��� �����մϴ�.
	 */
	virtual void Release() override;


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
	 * @brief ������ �޸��� ���� ���ҽ� �� ��� ���ۿ� �׼����ϱ� ���� �������̽��Դϴ�.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;


	/**
	 * @brief ������ �޸��� ���� ���ҽ� �� ��� ���ۿ� �׼����ϱ� ���� �������̽��Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* colorMaterialBuffer_ = nullptr;
};