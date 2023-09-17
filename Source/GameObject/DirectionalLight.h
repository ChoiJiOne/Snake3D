#pragma once

#include "GameObject/Light.h"


/**
 * @brief ������(Directional Light) ������Ʈ�Դϴ�.
 */
class DirectionalLight : public Light
{
public:
	/**
	 * @brief ������(Directional Light) ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	DirectionalLight() = default;


	/**
	 * @brief ������(Directional Light) ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ������(Directional Light) ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~DirectionalLight();


	/**
	 * @brief ������(Directional Light) ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(DirectionalLight);


	/**
	 * @brief ������(Directional Light)�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param ambient ������(Directional Light)�� Ambient ����Դϴ�.
	 * @param diffuse ������(Directional Light)�� Diffuse ����Դϴ�.
	 * @param specular ������(Directional Light)�� Specular ����Դϴ�.
	 * @param direction ������(Directional Light)�� �����Դϴ�.
	 */
	void Initialize(const glm::vec4& ambient, const glm::vec4& diffuse, const glm::vec4& specular, const glm::vec3& direction);


	/**
	 * @brief ������(Directional Light) ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ������(Directional Light) ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ������(Directional Light) ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������(Directional Light)�� Ambient ��Ҹ� ����ϴ�.
	 *
	 * @return ������(Directional Light)�� Ambient ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetAmbient() const { return ambient_; }


	/**
	 * @brief ������(Directional Light)�� Ambient ��Ҹ� �����մϴ�.
	 *
	 * @param ambient ������ ������(Directional Light)�� Ambient ����Դϴ�.
	 */
	void SetAmbient(const glm::vec4& ambient) { ambient_ = ambient; }


	/**
	 * @brief ������(Directional Light)�� Diffuse ��Ҹ� ����ϴ�.
	 *
	 * @return ������(Directional Light)�� Diffuse ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief ������(Directional Light)�� Diffuse ��Ҹ� �����մϴ�.
	 *
	 * @param diffuse ������ ������(Directional Light)�� Diffuse ����Դϴ�.
	 */
	void SetDiffuse(const glm::vec4& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief ������(Directional Light)�� Specular ��Ҹ� ����ϴ�.
	 *
	 * @return ������(Directional Light)�� Specular ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetSpecular() const { return specular_; }


	/**
	 * @brief ������(Directional Light)�� Specular ��Ҹ� �����մϴ�.
	 *
	 * @param specular ������ ������(Directional Light)�� Specular ����Դϴ�.
	 */
	void SetSpecular(const glm::vec4& specular) { specular_ = specular; }


	/**
	 * @brief ������(Directional Light)�� ������ ����ϴ�.
	 * 
	 * @return ������(Directional Light)�� ������ ��ȯ�մϴ�.
	 */
	glm::vec3 GetDirection() const { return direction_; }


	/**
	 * @brief ������(Directional Light)�� ������ �����մϴ�.
	 * 
	 * @param direction ������ ������(Directional Light)�� �����Դϴ�.
	 */
	void SetDirection(const glm::vec3& direction) { direction_ = direction; }


private:
	/**
	 * @brief ������(Directional Light)�� Ambient ����Դϴ�.
	 */
	glm::vec4 ambient_;


	/**
	 * @brief ������(Directional Light)�� Diffuse ����Դϴ�.
	 */
	glm::vec4 diffuse_;


	/**
	 * @brief ������(Directional Light)�� Specular ����Դϴ�.
	 */
	glm::vec4 specular_;


	/**
	 * @brief ������(Directional Light)�� �����Դϴ�.
	 */
	glm::vec3 direction_;
};