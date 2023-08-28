#pragma once

#include "Shader/IShader.h"

class Model;
class Camera3D;


/**
 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��Դϴ�.
 * 
 * @note 
 * - �� ���̴� Ŭ������ HLSL ���̴��� �ϴ��� �����մϴ�.
 * - �� ���̴��� �޽ô� ������ ���� �������� ������ �־�� �մϴ�.
 */
class ColorPassShader : public IShader
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
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ColorPassShader);


	/**
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief �Է����� ���� ���� ������ �������ϴ� ���̴��� �����մϴ�.
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
};