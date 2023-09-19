#pragma once

#include "GameObject/Light.h"


/**
 * @brief 점광(Point Light) 오브젝트입니다.
 */
class PointLight : public Light
{
public:
	/**
	 * @brief 점광(Point Light) 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	PointLight() = default;


	/**
	 * @brief 점광(Point Light) 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 점광(Point Light) 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~PointLight();


	/**
	 * @brief 점광(Point Light) 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(PointLight);


	/**
	 * @brief 점광(Point Light)을 초기화합니다.
	 *
	 * @param position 점광(Point Light)의 위치입니다.
	 * @param ambient 점광(Point Light)의 Ambient 요소입니다.
	 * @param diffuse 점광(Point Light)의 Diffuse 요소입니다.
	 * @param specular 점광(Point Light)의 Specular 요소입니다.
	 * @param constant 점광(Point Light) 감쇠의 상수항입니다.
	 * @param linear 점광(Point Light) 감쇠의 일차항입니다.
	 * @param quadratic 점광(Point Light) 감쇠의 이차항입니다.
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
	 * @brief 점광(Point Light) 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 점광(Point Light) 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 점광(Point Light) 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 점광(Point Light)의 위치를 얻습니다.
	 * 
	 * @return 점광(Point Light)의 위치를 반환합니다.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief 점광(Point Light)의 위치를 설정합니다.
	 * 
	 * @param position 설정할 점광(Point Light)의 위치입니다.
	 */
	void SetPosition(const glm::vec3& position) { position_ = position; }


	/**
	 * @brief 점광(Point Light)의 Ambient 요소를 얻습니다.
	 *
	 * @return 점광(Point Light)의 Ambient 요소를 반환합니다.
	 */
	glm::vec3 GetAmbient() const { return ambient_; }


	/**
	 * @brief 점광(Point Light)의 Ambient 요소를 설정합니다.
	 *
	 * @param ambient 설정할 점광(Point Light)의 Ambient 요소입니다.
	 */
	void SetAmbient(const glm::vec3& ambient) { ambient_ = ambient; }


	/**
	 * @brief 점광(Point Light)의 Diffuse 요소를 얻습니다.
	 *
	 * @return 점광(Point Light)의 Diffuse 요소를 반환합니다.
	 */
	glm::vec3 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief 점광(Point Light)의 Diffuse 요소를 설정합니다.
	 *
	 * @param diffuse 설정할 점광(Point Light)의 Diffuse 요소입니다.
	 */
	void SetDiffuse(const glm::vec3& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief 점광(Point Light)의 Specular 요소를 얻습니다.
	 *
	 * @return 점광(Point Light)의 Specular 요소를 반환합니다.
	 */
	glm::vec3 GetSpecular() const { return specular_; }


	/**
	 * @brief 점광(Point Light)의 Specular 요소를 설정합니다.
	 *
	 * @param specular 설정할 점광(Point Light)의 Specular 요소입니다.
	 */
	void SetSpecular(const glm::vec3& specular) { specular_ = specular; }


	/**
	 * @brief 점광(Point Light) 감쇠의 상수항을 얻습니다.
	 * 
	 * @return 점광(Point Light) 감쇠의 상수항을 반환합니다.
	 */
	float GetConstant() const { return constant_; }


	/**
	 * @brief 점광(Point Light) 감쇠의 상수항을 설정합니다.
	 * 
	 * @param constant 설정할 점광(Point Light) 감쇠의 상수항입니다.
	 */
	void SetConstant(float constant) { constant_ = constant; }


	/**
	 * @brief 점광(Point Light) 감쇠의 일차항을 얻습니다.
	 * 
	 * @return 점광(Point Light) 감쇠의 일차항을 반환합니다.
	 */
	float GetLinear() const { return linear_; }


	/**
	 * @brief 점광(Point Light) 감쇠의 일차항을 설정합니다.
	 * 
	 * @param linear 설정할 점광(Point Light) 감쇠의 일차항입니다.
	 */
	void SetLinear(float linear) { linear_ = linear; }

		
	/**
	 * @brief 점광(Point Light) 감쇠의 이차항 얻습니다.
	 * 
	 * @return 점광(Point Light) 감쇠의 이차항 반환합니다.
	 */
	float GetQuadratic() const { return quadratic_; }


	/**
	 * @brief 점광(Point Light) 감쇠의 이차항을 설정합니다.
	 * 
	 * @param quadratic 설정할 점광(Point Light) 감쇠의 이차항입니다.
	 */
	void SetQuadratic(float quadratic) { quadratic_ = quadratic; }


private:
	/**
	 * @brief 점광(Point Light)의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 점광(Point Light)의 Ambient 요소입니다.
	 */
	glm::vec3 ambient_;


	/**
	 * @brief 점광(Point Light)의 Diffuse 요소입니다.
	 */
	glm::vec3 diffuse_;


	/**
	 * @brief 점광(Point Light)의 Specular 요소입니다.
	 */
	glm::vec3 specular_;


	/**
	 * @brief 점광(Point Light) 감쇠의 상수항입니다.
	 */
	float constant_;

	
	/**
	 * @brief 점광(Point Light) 감쇠의 일차항입니다.
	 */
	float linear_;


	/**
	 * @brief 점광(Point Light) 감쇠의 이차항입니다.
	 */
	float quadratic_;
};