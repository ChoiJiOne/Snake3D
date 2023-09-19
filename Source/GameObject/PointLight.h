#pragma once

#include "GameObject/Light.h"


/**
 * @brief ����(Point Light) ������Ʈ�Դϴ�.
 */
class PointLight : public Light
{
public:
	/**
	 * @brief ����(Point Light) ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	PointLight() = default;


	/**
	 * @brief ����(Point Light) ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ����(Point Light) ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~PointLight();


	/**
	 * @brief ����(Point Light) ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PointLight);


	/**
	 * @brief ����(Point Light)�� �ʱ�ȭ�մϴ�.
	 *
	 * @param position ����(Point Light)�� ��ġ�Դϴ�.
	 * @param ambient ����(Point Light)�� Ambient ����Դϴ�.
	 * @param diffuse ����(Point Light)�� Diffuse ����Դϴ�.
	 * @param specular ����(Point Light)�� Specular ����Դϴ�.
	 * @param constant ����(Point Light) ������ ������Դϴ�.
	 * @param linear ����(Point Light) ������ �������Դϴ�.
	 * @param quadratic ����(Point Light) ������ �������Դϴ�.
	 */
	void Initialize(
		const glm::vec3& position,
		const glm::vec3& ambient, 
		const glm::vec3& diffuse, 
		const glm::vec3& specular, 
		float constant,
		float linear,
		float quadratic
	);


	/**
	 * @brief ����(Point Light) ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ����(Point Light) ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ����(Point Light) ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ����(Point Light)�� ��ġ�� ����ϴ�.
	 * 
	 * @return ����(Point Light)�� ��ġ�� ��ȯ�մϴ�.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief ����(Point Light)�� ��ġ�� �����մϴ�.
	 * 
	 * @param position ������ ����(Point Light)�� ��ġ�Դϴ�.
	 */
	void SetPosition(const glm::vec3& position) { position_ = position; }


	/**
	 * @brief ����(Point Light)�� Ambient ��Ҹ� ����ϴ�.
	 *
	 * @return ����(Point Light)�� Ambient ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec3 GetAmbient() const { return ambient_; }


	/**
	 * @brief ����(Point Light)�� Ambient ��Ҹ� �����մϴ�.
	 *
	 * @param ambient ������ ����(Point Light)�� Ambient ����Դϴ�.
	 */
	void SetAmbient(const glm::vec3& ambient) { ambient_ = ambient; }


	/**
	 * @brief ����(Point Light)�� Diffuse ��Ҹ� ����ϴ�.
	 *
	 * @return ����(Point Light)�� Diffuse ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec3 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief ����(Point Light)�� Diffuse ��Ҹ� �����մϴ�.
	 *
	 * @param diffuse ������ ����(Point Light)�� Diffuse ����Դϴ�.
	 */
	void SetDiffuse(const glm::vec3& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief ����(Point Light)�� Specular ��Ҹ� ����ϴ�.
	 *
	 * @return ����(Point Light)�� Specular ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec3 GetSpecular() const { return specular_; }


	/**
	 * @brief ����(Point Light)�� Specular ��Ҹ� �����մϴ�.
	 *
	 * @param specular ������ ����(Point Light)�� Specular ����Դϴ�.
	 */
	void SetSpecular(const glm::vec3& specular) { specular_ = specular; }


	/**
	 * @brief ����(Point Light) ������ ������� ����ϴ�.
	 * 
	 * @return ����(Point Light) ������ ������� ��ȯ�մϴ�.
	 */
	float GetConstant() const { return constant_; }


	/**
	 * @brief ����(Point Light) ������ ������� �����մϴ�.
	 * 
	 * @param constant ������ ����(Point Light) ������ ������Դϴ�.
	 */
	void SetConstant(float constant) { constant_ = constant; }


	/**
	 * @brief ����(Point Light) ������ �������� ����ϴ�.
	 * 
	 * @return ����(Point Light) ������ �������� ��ȯ�մϴ�.
	 */
	float GetLinear() const { return linear_; }


	/**
	 * @brief ����(Point Light) ������ �������� �����մϴ�.
	 * 
	 * @param linear ������ ����(Point Light) ������ �������Դϴ�.
	 */
	void SetLinear(float linear) { linear_ = linear; }

		
	/**
	 * @brief ����(Point Light) ������ ������ ����ϴ�.
	 * 
	 * @return ����(Point Light) ������ ������ ��ȯ�մϴ�.
	 */
	float GetQuadratic() const { return quadratic_; }


	/**
	 * @brief ����(Point Light) ������ �������� �����մϴ�.
	 * 
	 * @param quadratic ������ ����(Point Light) ������ �������Դϴ�.
	 */
	void SetQuadratic(float quadratic) { quadratic_ = quadratic; }


private:
	/**
	 * @brief ����(Point Light)�� ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief ����(Point Light)�� Ambient ����Դϴ�.
	 */
	glm::vec3 ambient_;


	/**
	 * @brief ����(Point Light)�� Diffuse ����Դϴ�.
	 */
	glm::vec3 diffuse_;


	/**
	 * @brief ����(Point Light)�� Specular ����Դϴ�.
	 */
	glm::vec3 specular_;


	/**
	 * @brief ����(Point Light) ������ ������Դϴ�.
	 */
	float constant_;

	
	/**
	 * @brief ����(Point Light) ������ �������Դϴ�.
	 */
	float linear_;


	/**
	 * @brief ����(Point Light) ������ �������Դϴ�.
	 */
	float quadratic_;
};