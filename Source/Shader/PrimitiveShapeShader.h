#pragma once

#include <vector>
#include <unordered_map>

#include "Core/Vertex.h"

#include "Shader/IShader.h"

class Camera3D;


/**
 * @brief ��, ��, �ﰢ��, �簢���� ���� �⺻ ������ �������ϴ� ���̴��Դϴ�.
 * 
 * @note 
 * - �� ���̴� Ŭ������ Model�̳� Mesh�� ���ڷ� ���� �ʽ��ϴ�.
 * - �� ���̴����� ó���ϴ� 2D�� ��ǥ��� ������ �����ϴ�.
 *                y
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 * ����������������������������������������������������������������x
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 */
class PrimitiveShapeShader : public IShader
{
public:
	/**
	 * @brief �� ������ ����Ǵ� ��� �����Դϴ�.
	 */
	struct EveryFrameBuffer
	{
		Matrix4x4f view;
		Matrix4x4f projection;
	};


	/**
	 * @brief �⺻ ������ ���� ��� �����Դϴ�.
	 */
	struct ShapeColorBuffer
	{
		Vector4f color;
	};


public:
	/**
	 * @brief ��, ��, �ﰢ��, �簢���� ���� �⺻ ������ �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note �ʱ�ȭ�� �ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	PrimitiveShapeShader() = default;


	/**
	 * @brief ��, ��, �ﰢ��, �簢���� ���� �⺻ ������ �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴� �� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~PrimitiveShapeShader();


	/**
	 * @brief ��, ��, �ﰢ��, �簢���� ���� �⺻ ������ �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PrimitiveShapeShader);


	/**
	 * @brief ��, ��, �ﰢ��, �簢���� ���� �⺻ ������ �������ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief ��, ��, �ﰢ��, �簢���� ���� �⺻ ������ �������ϴ� ���̴��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief 3D ���� ����ۿ� �������մϴ�.
	 * 
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param startPosition ���� ���� 3D �� ���� ���Դϴ�.
	 * @param endPosition ���� ���� 3D �� �� ���Դϴ�.
	 * @param color 3D ���� �����Դϴ�.
	 */
	void DrawLine3D(Camera3D* camera, const Vector3f& startPosition, const Vector3f& endPosition, const Vector4f& color);


private:
	/**
	 * @brief ���� �������ϱ� ���� ���ҽ��� �����մϴ�.
	 * 
	 * @param device ���� �����ϴ� ���۸� �����ϱ� ���� D3D11 ����̽��Դϴ�.
	 */
	void ConstructResourceForLine(ID3D11Device* device);


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
	ID3D11Buffer* shapeColorBuffer_ = nullptr;


	/**
	 * @brief �⺻ ������ ���� ����Դϴ�.
	 */
	std::unordered_map<std::string, std::vector<VertexPosition>> primitiveShapeVertex_;


	/**
	 * @brief �⺻ ������ ���� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> primitiveShapeVertexBuffer_;


	/**
	 * @brief �⺻ ������ �ε��� ����Դϴ�.
	 */
	std::unordered_map<std::string, std::vector<uint32_t>> primitiveShapeIndex_;


	/**
	 * @brief �⺻ ������ �ε��� �����Դϴ�.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> primitiveShapeIndexBuffer_;
};