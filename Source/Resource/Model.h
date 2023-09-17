#pragma once

#include "Resource/IResource.h"

class Material;
class Mesh;


/**
 * @brief �޽ÿ� ������ ������ ���Դϴ�.
 */
class Model : public IResource
{
public:
	/**
	 * @brief �� Ŭ������ �⺻ �������Դϴ�.
	 *
	 * @note �ʱ�ȭ�� �����ϱ� ���ؼ��� �ݵ�� �ʱ�ȭ �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Model() = default;


	/**
	 * @brief �� Ŭ������ ���� �Ҹ����Դϴ�.
	 *
	 * @note ������ �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Model();


	/**
	 * @brief �� Ŭ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Model);


	/**
	 * @brief �޽ÿ� ������ ���� �����մϴ�.
	 * 
	 * @param mesh ���� �޽��Դϴ�.
	 * @param material ���� �����Դϴ�.
	 */
	void Initialize(Mesh* mesh, Material* material);


	/**
	 * @brief �� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���� �޽Ǹ� ����ϴ�.
	 * 
	 * @return ���� �޽� ������ ���� ��ȯ�մϴ�.
	 */
	Mesh* GetMesh() { return mesh_; }


	/**
	 * @brief ���� ������ ����ϴ�.
	 * 
	 * @return ���� ���� ������ ���� ��ȯ�մϴ�.
	 */
	Material* GetMaterial() { return material_; }


private:
	/**
	 * @brief ���� �޽��Դϴ�.
	 */
	Mesh* mesh_ = nullptr;


	/**
	 * @brief ���� �����Դϴ�.
	 */
	Material* material_ = nullptr;
};