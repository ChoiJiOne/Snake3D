#pragma once

#include <d3d11.h>

#include "Utils/Macro.h"


/**
 * @brief �޽� Ŭ�����Դϴ�.
 */
class Mesh
{
public:
	/**
	 * @brief �޽� Ŭ������ �⺻ �������Դϴ�.
	 * 
	 * @note �ʱ�ȭ�� �����ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Mesh() = default;


	/**
	 * @brief �޽� Ŭ������ ���� �Ҹ����Դϴ�.
	 * 
	 * @note ������ �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Mesh();


	/**
	 * @brief �޽� Ŭ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Mesh);


	/**
	 * @brief �޽� Ŭ������ �ʱ�ȭ�մϴ�.
	 * 
	 * @param verticesPtr ���ؽ� ������ �������Դϴ�.
	 * @param vertexStride ���ؽ� ������ ���� ũ���Դϴ�.
	 * @param vertexCount ���ؽ� ������ ���Դϴ�.
	 * @param indicesPtr �ε��� ������ �������Դϴ�.
	 * @param indexCount �ε��� ������ ���Դϴ�.
	 */
	void Initialize(const void* verticesPtr, uint32_t vertexStride, uint32_t vertexCount, const void* indicesPtr, uint32_t indexCount);

	
	/**
	 * @brief �޽� Ŭ������ �����մϴ�.
	 */
	void Release();


	/**
	 * @brief ���ؽ� ���� �������̽��� �����͸� ����ϴ�.
	 * 
	 * @return ���ؽ� ���� �������̽��� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11Buffer* GetVertexBufferPtr() { return vertexBuffer_; }


	/**
	 * @brief �ε��� ���� �������̽��� �����͸� ����ϴ�.
	 * 
	 * @return �ε��� ���� �������̽��� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11Buffer* GetIndexBufferPtr() { return indexBuffer_; }


	/**
	 * @brief ���ؽ� ������ ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return ���ؽ� ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	uint32_t GetVertexStride() { return vertexStride_; }


	/**
	 * @brief ���ؽ� ������ ���� ����ϴ�.
	 * 
	 * @return ���ؽ� ������ ���� ��ȯ�մϴ�.
	 */
	uint32_t GetVertexCount() { return vertexCount_; }


	/**
	 * @brief �ε��� ������ ���� ����ϴ�.
	 * 
	 * @return �ε��� ������ ���� ��ȯ�մϴ�.
	 */
	uint32_t GetIndexCount() { return indexCount_; }
	

private:
	/**
	 * @brief �޽� Ŭ������ �ʱ�ȭ�ߴ��� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief ������ �޸��� ���� ���ҽ��� �׼��� ������ ���ؽ� ���� �������̽��Դϴ�. 
	 */
	ID3D11Buffer* vertexBuffer_ = nullptr;


	/**
	 * @brief ������ �޸��� ���� ���ҽ��� �׼��� ������ ���ؽ� �ε��� �������̽��Դϴ�. 
	 */
	ID3D11Buffer* indexBuffer_ = nullptr;


	/**
	 * @brief ���ؽ� ������ ũ�� �����Դϴ�.
	 */
	uint32_t vertexStride_ = 0;


	/**
	 * @brief ���ؽ� ������ ���Դϴ�.
	 */
	uint32_t vertexCount_ = 0;


	/**
	 * @brief �ε��� ������ ���Դϴ�.
	 */
	uint32_t indexCount_ = 0;
};