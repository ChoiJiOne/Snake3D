#pragma once

#include "GameObject/Light.h"


/**
 * @brief 스포트 라이트(Spot Light) 오브젝트입니다.
 */
class SpotLight : public Light
{
public:
	/**
	 * @brief 스포트 라이트(Spot Light) 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	SpotLight() = default;


	/**
	 * @brief 스포트 라이트(Spot Light) 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 스포트 라이트(Spot Light) 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~SpotLight();


	/**
	 * @brief 스포트 라이트(Spot Light) 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpotLight);


	/**
	 * @brief 스포트 라이트(Spot Light)을 초기화합니다.
	 * 
	 * @note 각도 단위는 60분법입니다.
	 * 
	 * @param position 스포트 라이트(Spot Light)의 위치입니다.
	 * @param direction 스포트 라이트(Spot Light)의 방향입니다.
	 * @param innerCutOff 스포트 라이트(Spot Light)의 내부 컷 오프 각도입니다.
	 * @param outerCutOff 스포트 라이트(Spot Light)의 외부 컷 오프 각도입니다.
	 * @param ambient 스포트 라이트(Spot Light)의 Ambient 요소입니다.
	 * @param diffuse 스포트 라이트(Spot Light)의 Diffuse 요소입니다.
	 * @param specular 스포트 라이트(Spot Light)의 Specular 요소입니다.
	 * @param constant 스포트 라이트(Spot Light) 감쇠의 상수항입니다.
	 * @param linear 스포트 라이트(Spot Light) 감쇠의 일차항입니다.
	 * @param quadratic 스포트 라이트(Spot Light) 감쇠의 이차항입니다.
	 */
	void Initialize(
		const glm::vec3& position,
		const glm::vec3& direction,
		float innerCutOff,
		float outerCutOff,
		const glm::vec3& ambient,
		const glm::vec3& diffuse,
		const glm::vec3& specular,
		float constant,
		float linear,
		float quadratic
	);


	/**
	 * @brief 스포트 라이트(Spot Light) 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 스포트 라이트(Spot Light) 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 스포트 라이트(Spot Light) 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 스포트 라이트(Spot Light)의 위치를 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light)의 위치를 반환합니다.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 위치를 설정합니다.
	 *
	 * @param position 설정할 스포트 라이트(Spot Light)의 위치입니다.
	 */
	void SetPosition(const glm::vec3& position) { position_ = position; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 방향을 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light)의 방향을 반환합니다.
	 */
	glm::vec3 GetDirection() const { return direction_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 방향을 설정합니다.
	 *
	 * @param direction 설정할 스포트 라이트(Spot Light)의 위치입니다.
	 */
	void SetDirection(const glm::vec3& direction) { direction_ = direction; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 내부 컷 오프 각도를 얻습니다.
	 * 
	 * @return 스포트 라이트(Spot Light)의 내부 컷 오프 각도를 반환합니다.
	 */
	float GetInnerCutOff() const { return innerCutOff_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 내부 컷 오프 각도를 설정합니다.
	 * 
	 * @param innerCutOff 설정할 스포트 라이트(Spot Light) 내부 컷 오프 각도입니다.
	 */
	void SetInnerCutOff(float innerCutOff) { innerCutOff_ = innerCutOff; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 외부 컷 오프 각도를 얻습니다.
	 * 
	 * @return 스포트 라이트(Spot Light)의 외부 컷 오프 각도를 반환합니다.
	 */
	float GetOuterCutOff() const { return outerCutOff_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 외부 컷 오프 각도를 설정합니다.
	 * 
	 * @param outerCutOff 설정할 스포트 라이트(Spot Light) 외부 컷 오프 각도입니다.
	 */
	void SetOuterCutOff(float outerCutOff) { outerCutOff_ = outerCutOff; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 Ambient 요소를 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light)의 Ambient 요소를 반환합니다.
	 */
	glm::vec3 GetAmbient() const { return ambient_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 Ambient 요소를 설정합니다.
	 *
	 * @param ambient 설정할 스포트 라이트(Spot Light)의 Ambient 요소입니다.
	 */
	void SetAmbient(const glm::vec3& ambient) { ambient_ = ambient; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 Diffuse 요소를 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light)의 Diffuse 요소를 반환합니다.
	 */
	glm::vec3 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 Diffuse 요소를 설정합니다.
	 *
	 * @param diffuse 설정할 스포트 라이트(Spot Light)의 Diffuse 요소입니다.
	 */
	void SetDiffuse(const glm::vec3& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 Specular 요소를 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light)의 Specular 요소를 반환합니다.
	 */
	glm::vec3 GetSpecular() const { return specular_; }


	/**
	 * @brief 스포트 라이트(Spot Light)의 Specular 요소를 설정합니다.
	 *
	 * @param specular 설정할 스포트 라이트(Spot Light)의 Specular 요소입니다.
	 */
	void SetSpecular(const glm::vec3& specular) { specular_ = specular; }


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 상수항을 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light) 감쇠의 상수항을 반환합니다.
	 */
	float GetConstant() const { return constant_; }


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 상수항을 설정합니다.
	 *
	 * @param constant 설정할 스포트 라이트(Spot Light) 감쇠의 상수항입니다.
	 */
	void SetConstant(float constant) { constant_ = constant; }


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 일차항을 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light) 감쇠의 일차항을 반환합니다.
	 */
	float GetLinear() const { return linear_; }


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 일차항을 설정합니다.
	 *
	 * @param linear 설정할 스포트 라이트(Spot Light) 감쇠의 일차항입니다.
	 */
	void SetLinear(float linear) { linear_ = linear; }


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 이차항 얻습니다.
	 *
	 * @return 스포트 라이트(Spot Light) 감쇠의 이차항 반환합니다.
	 */
	float GetQuadratic() const { return quadratic_; }


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 이차항을 설정합니다.
	 *
	 * @param quadratic 설정할 스포트 라이트(Spot Light) 감쇠의 이차항입니다.
	 */
	void SetQuadratic(float quadratic) { quadratic_ = quadratic; }


private:
	/**
	 * @brief 스포트 라이트(Spot Light)의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 스포트 라이트(Spot Light)의 방향입니다.
	 */
	glm::vec3 direction_;


	/**
	 * @brief 스포트 라이트 내부의 컷 오프 각도입니다.
	 */
	float innerCutOff_ = 0.0f;


	/**
	 * @brief 스포트 라이트 외부의 컷 오프 각도입니다.
	 */
	float outerCutOff_ = 0.0f;


	/**
	 * @brief 스포트 라이트(Spot Light)의 Ambient 요소입니다.
	 */
	glm::vec3 ambient_;


	/**
	 * @brief 스포트 라이트(Spot Light)의 Diffuse 요소입니다.
	 */
	glm::vec3 diffuse_;


	/**
	 * @brief 스포트 라이트(Spot Light)의 Specular 요소입니다.
	 */
	glm::vec3 specular_;


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 상수항입니다.
	 */
	float constant_;


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 일차항입니다.
	 */
	float linear_;


	/**
	 * @brief 스포트 라이트(Spot Light) 감쇠의 이차항입니다.
	 */
	float quadratic_;
};