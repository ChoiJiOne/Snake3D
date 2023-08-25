#pragma once

#include <memory>
#include <vector>

#include "Utils/Macro.h"
#include "Utils/Vertex.h"

class Mesh;
class ColorMaterial;


/**
 * @brief �޽ÿ� ���͸���(����)�� ������ �� Ŭ�����Դϴ�.
 */
class Model
{
public:
	/**
	 * @brief �� Ŭ������ �⺻ �������Դϴ�.
	 * 
	 * @note �ʱ�ȭ�� �����ϱ� ���ؼ��� �ݵ�� Set~ �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Model() = default;


	/**
	 * @brief �� Ŭ������ ���� �Ҹ����Դϴ�.
	 * 
	 * @note ������ �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Model();


	/**
	 * @brief �� Ŭ������ ���� �����ڿ� ���� �����ڸ� ���������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Model);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 * 
	 * @param vertices �� �޽��� ���� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPosition>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� ������ ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionColor>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� �ؽ�ó ��ġ�� ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� �븻(����) ���͸� ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionNormal>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� �븻(����) ����, �ؽ�ó ��ġ�� ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionNormalUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� �븻(����) ����, ������ ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionNormalColor>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� ����, �ؽ�ó ��ġ�� ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionColorUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 *
	 * @param vertices �� �޽��� ��ġ�� �븻(����) ����, ����, �ؽ�ó ��ġ�� ������ ���ؽ��� ����Դϴ�.
	 * @param indices �� �޽��� �ε��� ����Դϴ�.
	 */
	void SetMesh(const std::vector<VertexPositionNormalColorUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ���� ���� ���͸����� �����մϴ�.
	 * 
	 * @param color �� ���͸����� �����Դϴ�.
	 */
	void SetColorMaterial(const Vector4f & color);


	/**
	 * @brief �� Ŭ������ �����մϴ�.
	 */
	void Release();


	/**
	 * @brief �� �޽��� ������ ��ġ ������ ������ �ִ��� Ȯ���մϴ�.
	 * 
	 * @return ������ �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HavePosition() { return bHavePositionInVertex_; }
	 
	 
	/**
	 * @brief �� �޽��� ������ �븻(����) ���� ������ ������ �ִ��� Ȯ���մϴ�.
	 * 
	 * @return ������ �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveNormal() { return bHaveNormalInVertex_; }


	/**
	 * @brief �� �޽��� ������ ���� ������ ������ �ִ��� Ȯ���մϴ�.
	 * 
	 * @return ������ �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveColor() { return bHaveColorInVertex_; }


	/**
	 * @brief �� �޽��� ������ �ؽ�ó ��ġ ������ ������ �ִ��� Ȯ���մϴ�.
	 * 
	 * @return ������ �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveUV() { return bHaveUVInVertex_; }


	/**
	 * @brief ���� �÷� ���͸����� ������ �ִ��� Ȯ���մϴ�.
	 * 
	 * @return ���� ���͸����� ������ �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveColorMaterial() { return material_ != nullptr; }

	
	/**
	 * @brief ���� �޽ø� ����ϴ�.
	 * 
	 * @return ���� �޽� �����͸� ��ȯ�մϴ�.
	 */
	Mesh* GetMesh() { return mesh_.get(); }


	/**
	 * @brief ���� ���� ���͸����� ����ϴ�.
	 * 
	 * @return ���� ���� ���͸��� �����͸� ��ȯ�մϴ�.
	 */
	ColorMaterial* GetColorMaterial() { return material_.get(); }


private:
	/**
	 * @brief ���� �޽ø� �����մϴ�.
	 * 
	 * @param verticesPtr ���ؽ� ������ �������Դϴ�.
	 * @param vertexStride ���ؽ� ������ ���� ũ���Դϴ�.
	 * @param vertexCount ���ؽ� ������ ���Դϴ�.
	 * @param indicesPtr �ε��� ������ �������Դϴ�.
	 * @param indexCount �ε��� ������ ���Դϴ�.
	 */
	void SetMesh(const void* verticesPtr, uint32_t vertexStride, uint32_t vertexCount, const void* indicesPtr, uint32_t indexCount);


private:
	/**
	 * @brief ������ ��ġ ������ ������ �ִ��� Ȯ���մϴ�.
	 */
	bool bHavePositionInVertex_ = false;


	/**
	 * @brief ������ �븻(����) ���� ������ ������ �ִ��� Ȯ���մϴ�.
	 */
	bool bHaveNormalInVertex_ = false;


	/**
	 * @brief ������ ���� ������ ������ �ִ��� Ȯ���մϴ�.
	 */
	bool bHaveColorInVertex_ = false;


	/**
	 * @brief ������ �ؽ�ó ��ġ ������ ������ �ִ��� Ȯ���մϴ�.
	 */
	bool bHaveUVInVertex_ = false;


	/**
	 * @brief ���� �޽��Դϴ�.
	 */
	std::unique_ptr<Mesh> mesh_ = nullptr;


	/**
	 * @brief ���� ���� ���͸����Դϴ�.
	 */
	std::unique_ptr<ColorMaterial> material_ = nullptr;
};