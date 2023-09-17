#pragma once

#include "GameObject/Light.h"


/**
 * @brief ������ ������Ʈ�Դϴ�.
 */
class DirectionalLight : public Light
{
public:
	/**
	 * @brief ������ ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	DirectionalLight() = default;


	/**
	 * @brief ������ ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ������ ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~DirectionalLight();


	/**
	 * @brief ������ ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(DirectionalLight);


	/**
	 * @brief �������� �ʱ�ȭ�մϴ�.
	 * 
	 * @param ambient �������� Ambient ����Դϴ�.
	 * @param diffuse �������� Diffuse ����Դϴ�.
	 * @param specular �������� Specular ����Դϴ�.
	 * @param direction �������� �����Դϴ�.
	 */
	void Initialize(const glm::vec4& ambient, const glm::vec4& diffuse, const glm::vec4& specular, const glm::vec3& direction);


	/**
	 * @brief ������ ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ������ ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ������ ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ Ambient ��Ҹ� ����ϴ�.
	 *
	 * @return ������ Ambient ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetAmbient() const { return ambient_; }


	/**
	 * @brief ������ Ambient ��Ҹ� �����մϴ�.
	 *
	 * @param ambient ������ ������ Ambient ����Դϴ�.
	 */
	void SetAmbient(const glm::vec4& ambient) { ambient_ = ambient; }


	/**
	 * @brief ������ Diffuse ��Ҹ� ����ϴ�.
	 *
	 * @return ������ Diffuse ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief ������ Diffuse ��Ҹ� �����մϴ�.
	 *
	 * @param diffuse ������ ������ Diffuse ����Դϴ�.
	 */
	void SetDiffuse(const glm::vec4& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief ������ Specular ��Ҹ� ����ϴ�.
	 *
	 * @return ������ Specular ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetSpecular() const { return specular_; }


	/**
	 * @brief ������ Specular ��Ҹ� �����մϴ�.
	 *
	 * @param specular ������ ������ Specular ����Դϴ�.
	 */
	void SetSpecular(const glm::vec4& specular) { specular_ = specular; }


	/**
	 * @brief ������ ������ ����ϴ�.
	 * 
	 * @return ������ ������ ��ȯ�մϴ�.
	 */
	glm::vec3 GetDirection() const { return direction_; }


	/**
	 * @brief ������ ������ �����մϴ�.
	 * 
	 * @param direction ������ ������ �����Դϴ�.
	 */
	void SetDirection(const glm::vec3& direction) { direction_ = direction; }


private:
	/**
	 * @brief ������ Ambient ����Դϴ�.
	 */
	glm::vec4 ambient_;


	/**
	 * @brief ������ Diffuse ����Դϴ�.
	 */
	glm::vec4 diffuse_;


	/**
	 * @brief ������ Specular ����Դϴ�.
	 */
	glm::vec4 specular_;


	/**
	 * @brief ������ �����Դϴ�.
	 */
	glm::vec3 direction_;
};