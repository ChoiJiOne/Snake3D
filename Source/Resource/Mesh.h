#pragma once

#include <vector>

#include "Resource/IResource.h"

#include "Utility/Vertex.h"


/**
 * @brief �޽� Ŭ�����Դϴ�.
 */
class Mesh : public IResource
{
public:
	/**
	 * @brief �޽��� ����Ʈ �������Դϴ�.
	 * 
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Mesh() = default;


	/**
	 * @brief �޽��� ���� �Ҹ����Դϴ�.
	 * 
	 * @note �޽� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Mesh();


	/**
	 * @brief �޽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Mesh);


	/**
	 * @brief ������ �ε����� ������� �޽ø� �����մϴ�.
	 * 
	 * @param vertices �޽ø� ������ ���� ����Դϴ�.
	 * @param indices �޽ø� ������ �ε��� ����Դϴ�.
	 */
	void Initialize(const std::vector<VertexPosition>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief ������ �ε����� ������� �޽ø� �����մϴ�.
	 *
	 * @param vertices �޽ø� ������ ���� ����Դϴ�.
	 * @param indices �޽ø� ������ �ε��� ����Դϴ�.
	 */
	void Initialize(const std::vector<VertexPositionNormal>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief �޽� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief �޽��� ������ ��ġ�� �����ߴ��� Ȯ���մϴ�.
	 * 
	 * @return �޽��� ������ ��ġ�� �����ϰ� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HavePosition() const { return bHavePosition_; }


	/**
	 * @brief �޽��� ������ �븻(����) ���͸� �����ߴ��� Ȯ���մϴ�.
	 * 
	 * @return �޽��� ������ �븻(����) ���͸� �����ϰ� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveNormal() const { return bHaveNormal_; }


	/**
	 * @brief �޽��� ������ ������ �����ߴ��� Ȯ���մϴ�. 
	 * 
	 * @return �޽��� ������ ������ �����ϰ� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveColor() const { return bHaveColor_; }


	/**
	 * @brief �޽��� ������ �ؽ�ó ��ǥ�� �����ߴ��� Ȯ���մϴ�.
	 * 
	 * @return �޽��� ������ �ؽ�ó ��ǥ�� �����ϰ� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool HaveTextureCoordinate() const { return bHaveTextureCoordinate_; }


	/**
	 * @brief �޽� ������ �ε��� ī��Ʈ ���� ����ϴ�.
	 * 
	 * @return �޽� ������ �ε��� ī��Ʈ ���� ��ȯ�մϴ�.
	 */
	uint32_t GetIndexCount() const { return indexCount_; }


	/**
	 * @brief �޽� ������ �ε����� ���ؽ� ��� ������Ʈ ID�� ����ϴ�.
	 * 
	 * @return ������ �ε����� ���ؽ� ��� ������Ʈ ID�� ��ȯ�մϴ�.
	 */
	uint32_t GetVertexArrayObject() const { return vertexArrayObject_; }


private:
	/**
	 * @brief �޽��� ������ ��ġ�� �����ߴ��� Ȯ���մϴ�.
	 */
	bool bHavePosition_ = false;


	/**
	 * @brief �޽��� ������ �븻(����) ���͸� �����ߴ��� Ȯ���մϴ�.
	 */
	bool bHaveNormal_ = false;


	/**
	 * @brief �޽��� ������ ������ �����ߴ��� Ȯ���մϴ�.
	 */
	bool bHaveColor_ = false;


	/**
	 * @brief �޽��� ������ �ؽ�ó ��ǥ�� �����ߴ��� Ȯ���մϴ�.
	 */
	bool bHaveTextureCoordinate_ = false;


	/**
	 * @brief ������ �ε��� ī��Ʈ�Դϴ�.
	 */
	uint32_t indexCount_ = 0;


	/**
	 * @brief ������ ���ؽ� ���� ID�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ������ �ε��� ���� ID�Դϴ�.
	 */
	uint32_t indexBufferObject_ = 0;


	/**
	 * @brief ������ ���ؽ� ��� ID�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;
};