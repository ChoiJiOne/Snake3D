#pragma once

#include <glm/glm.hpp>

#include "Resource/IResource.h"


/**
 * @brief ��ü�� �����Դϴ�.
 */
class Material : public IResource
{
public:
	/**
	 * @brief ������ ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Material() = default;


	/**
	 * @brief ������ ���� �Ҹ����Դϴ�.
	 *
	 * @note ���� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Material();


	/**
	 * @brief ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Material);


	/**
	 * @brief ���� ���ҽ��� �ʱ�ȭ�մϴ�.
	 * 
	 * @param ambient ������ Ambient (�ֺ���) ����Դϴ�.
	 * @param diffuse ������ Diffuse (�л걤) ����Դϴ�.
	 * @param specular ������ Specular (�ݻ籤) ����Դϴ�.
	 * @param power ������ Specular Power (�ݻ� ����) ����Դϴ�.
	 */
	void Initialize(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, float power);


	/**
	 * @brief ���� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ Ambient (�ֺ���) ��Ҹ� ����ϴ�.
	 * 
	 * @return ������ Ambient (�ֺ���) ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec3 GetAmbient() const { return ambient_; }


	/**
	 * @brief ������ Ambient (�ֺ���) ��Ҹ� �����մϴ�.
	 * 
	 * @param ambient ������ ������ Ambient (�ֺ���) ����Դϴ�.
	 */
	void SetAmbient(const glm::vec3& ambient) { ambient_ = ambient; }


	/**
	 * @brief ������ Diffuse (�л걤) ��Ҹ� ����ϴ�.
	 * 
	 * @return ������ Diffuse (�л걤) ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec3 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief ������ Diffuse (�л걤) ��Ҹ� �����մϴ�.
	 * 
	 * @param diffuse ������ ������ Diffuse (�л걤) ����Դϴ�.
	 */
	void SetDiffuse(const glm::vec3& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief ������ Specular (�ݻ籤) ��Ҹ� ����ϴ�.
	 * 
	 * @return ������ Specular (�ݻ籤) ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec3 GetSpecular() const { return specular_; }


	/**
	 * @brief ������ Specular (�ݻ籤) ��Ҹ� �����մϴ�.
	 * 
	 * @param specular ������ ������ Specular (�ݻ籤) ����Դϴ�.
	 */
	void SetSpecular(const glm::vec3& specular) { specular_ = specular; }


	/**
	 * @brief ������ Specular Power (�ݻ� ����) ��Ҹ� ����ϴ�.
	 * 
	 * @return ������ Specular Power (�ݻ� ����) ��Ҹ� ��ȯ�մϴ�.
	 */
	float GetSpecularPower() const { return specularPower_; }
	

	/**
	 * @brief ������ Specular Power (�ݻ� ����) ��Ҹ� �����մϴ�.
	 * 
	 * @param power ������ ������ Specular Power (�ݻ� ����) ����Դϴ�.
	 */
	void SetSpecularPower(float power) { specularPower_ = power; }


private:
	/**
	 * @brief ������ Ambient (�ֺ���) ����Դϴ�.
	 */
	glm::vec3 ambient_;


	/**
	 * @brief ������ Diffuse (�л걤) ����Դϴ�.
	 */
	glm::vec3 diffuse_;


	/**
	 * @brief ������ Specular (�ݻ籤) ����Դϴ�.
	 */
	glm::vec3 specular_;


	/**
	 * @brief ������ Specular Power (�ݻ� ����) ����Դϴ�.
	 */
	float specularPower_ = 0.0f;
};