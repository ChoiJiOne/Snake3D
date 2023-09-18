#pragma once

#include "GameObject/Light.h"


/**
 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ�Դϴ�.
 */
class SpotLight : public Light
{
public:
	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	SpotLight() = default;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ����Ʈ ����Ʈ(Spot Light) ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~SpotLight();


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpotLight);


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� �ʱ�ȭ�մϴ�.
	 * 
	 * @note ���� ������ 60�й��Դϴ�.
	 * 
	 * @param position ����Ʈ ����Ʈ(Spot Light)�� ��ġ�Դϴ�.
	 * @param direction ����Ʈ ����Ʈ(Spot Light)�� �����Դϴ�.
	 * @param innerCutOff ����Ʈ ����Ʈ(Spot Light)�� ���� �� ���� �����Դϴ�.
	 * @param outerCutOff ����Ʈ ����Ʈ(Spot Light)�� �ܺ� �� ���� �����Դϴ�.
	 * @param ambient ����Ʈ ����Ʈ(Spot Light)�� Ambient ����Դϴ�.
	 * @param diffuse ����Ʈ ����Ʈ(Spot Light)�� Diffuse ����Դϴ�.
	 * @param specular ����Ʈ ����Ʈ(Spot Light)�� Specular ����Դϴ�.
	 * @param constant ����Ʈ ����Ʈ(Spot Light) ������ ������Դϴ�.
	 * @param linear ����Ʈ ����Ʈ(Spot Light) ������ �������Դϴ�.
	 * @param quadratic ����Ʈ ����Ʈ(Spot Light) ������ �������Դϴ�.
	 */
	void Initialize(
		const glm::vec3& position,
		const glm::vec3& direction,
		float innerCutOff,
		float outerCutOff,
		const glm::vec4& ambient,
		const glm::vec4& diffuse,
		const glm::vec4& specular,
		float constant,
		float linear,
		float quadratic
	);


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ��ġ�� ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light)�� ��ġ�� ��ȯ�մϴ�.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ��ġ�� �����մϴ�.
	 *
	 * @param position ������ ����Ʈ ����Ʈ(Spot Light)�� ��ġ�Դϴ�.
	 */
	void SetPosition(const glm::vec3& position) { position_ = position; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ������ ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light)�� ������ ��ȯ�մϴ�.
	 */
	glm::vec3 GetDirection() const { return direction_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ������ �����մϴ�.
	 *
	 * @param direction ������ ����Ʈ ����Ʈ(Spot Light)�� ��ġ�Դϴ�.
	 */
	void SetDirection(const glm::vec3& direction) { direction_ = direction; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ���� �� ���� ������ ����ϴ�.
	 * 
	 * @return ����Ʈ ����Ʈ(Spot Light)�� ���� �� ���� ������ ��ȯ�մϴ�.
	 */
	float GetInnerCutOff() const { return innerCutOff_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ���� �� ���� ������ �����մϴ�.
	 * 
	 * @param innerCutOff ������ ����Ʈ ����Ʈ(Spot Light) ���� �� ���� �����Դϴ�.
	 */
	void SetInnerCutOff(float innerCutOff) { innerCutOff_ = innerCutOff; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� �ܺ� �� ���� ������ ����ϴ�.
	 * 
	 * @return ����Ʈ ����Ʈ(Spot Light)�� �ܺ� �� ���� ������ ��ȯ�մϴ�.
	 */
	float GetOuterCutOff() const { return outerCutOff_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� �ܺ� �� ���� ������ �����մϴ�.
	 * 
	 * @param outerCutOff ������ ����Ʈ ����Ʈ(Spot Light) �ܺ� �� ���� �����Դϴ�.
	 */
	void SetOuterCutOff(float outerCutOff) { outerCutOff_ = outerCutOff; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Ambient ��Ҹ� ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light)�� Ambient ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetAmbient() const { return ambient_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Ambient ��Ҹ� �����մϴ�.
	 *
	 * @param ambient ������ ����Ʈ ����Ʈ(Spot Light)�� Ambient ����Դϴ�.
	 */
	void SetAmbient(const glm::vec4& ambient) { ambient_ = ambient; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Diffuse ��Ҹ� ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light)�� Diffuse ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Diffuse ��Ҹ� �����մϴ�.
	 *
	 * @param diffuse ������ ����Ʈ ����Ʈ(Spot Light)�� Diffuse ����Դϴ�.
	 */
	void SetDiffuse(const glm::vec4& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Specular ��Ҹ� ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light)�� Specular ��Ҹ� ��ȯ�մϴ�.
	 */
	glm::vec4 GetSpecular() const { return specular_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Specular ��Ҹ� �����մϴ�.
	 *
	 * @param specular ������ ����Ʈ ����Ʈ(Spot Light)�� Specular ����Դϴ�.
	 */
	void SetSpecular(const glm::vec4& specular) { specular_ = specular; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ ������� ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light) ������ ������� ��ȯ�մϴ�.
	 */
	float GetConstant() const { return constant_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ ������� �����մϴ�.
	 *
	 * @param constant ������ ����Ʈ ����Ʈ(Spot Light) ������ ������Դϴ�.
	 */
	void SetConstant(float constant) { constant_ = constant; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ �������� ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light) ������ �������� ��ȯ�մϴ�.
	 */
	float GetLinear() const { return linear_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ �������� �����մϴ�.
	 *
	 * @param linear ������ ����Ʈ ����Ʈ(Spot Light) ������ �������Դϴ�.
	 */
	void SetLinear(float linear) { linear_ = linear; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ ������ ����ϴ�.
	 *
	 * @return ����Ʈ ����Ʈ(Spot Light) ������ ������ ��ȯ�մϴ�.
	 */
	float GetQuadratic() const { return quadratic_; }


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ �������� �����մϴ�.
	 *
	 * @param quadratic ������ ����Ʈ ����Ʈ(Spot Light) ������ �������Դϴ�.
	 */
	void SetQuadratic(float quadratic) { quadratic_ = quadratic; }


private:
	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� �����Դϴ�.
	 */
	glm::vec3 direction_;


	/**
	 * @brief ����Ʈ ����Ʈ ������ �� ���� �����Դϴ�.
	 */
	float innerCutOff_ = 0.0f;


	/**
	 * @brief ����Ʈ ����Ʈ �ܺ��� �� ���� �����Դϴ�.
	 */
	float outerCutOff_ = 0.0f;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Ambient ����Դϴ�.
	 */
	glm::vec4 ambient_;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Diffuse ����Դϴ�.
	 */
	glm::vec4 diffuse_;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light)�� Specular ����Դϴ�.
	 */
	glm::vec4 specular_;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ ������Դϴ�.
	 */
	float constant_;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ �������Դϴ�.
	 */
	float linear_;


	/**
	 * @brief ����Ʈ ����Ʈ(Spot Light) ������ �������Դϴ�.
	 */
	float quadratic_;
};