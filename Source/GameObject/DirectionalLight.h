#pragma once

#include "GameObject/Light.h"


/**
 * @brief 직선광(Directional Light) 오브젝트입니다.
 */
class DirectionalLight : public Light
{
public:
	/**
	 * @brief 직선광(Directional Light) 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	DirectionalLight() = default;


	/**
	 * @brief 직선광(Directional Light) 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 직선광(Directional Light) 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~DirectionalLight();


	/**
	 * @brief 직선광(Directional Light) 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(DirectionalLight);


	/**
	 * @brief 직선광(Directional Light)을 초기화합니다.
	 * 
	 * @param ambient 직선광(Directional Light)의 Ambient 요소입니다.
	 * @param diffuse 직선광(Directional Light)의 Diffuse 요소입니다.
	 * @param specular 직선광(Directional Light)의 Specular 요소입니다.
	 * @param direction 직선광(Directional Light)의 방향입니다.
	 */
	void Initialize(const glm::vec4& ambient, const glm::vec4& diffuse, const glm::vec4& specular, const glm::vec3& direction);


	/**
	 * @brief 직선광(Directional Light) 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 직선광(Directional Light) 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 직선광(Directional Light) 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 직선광(Directional Light)의 Ambient 요소를 얻습니다.
	 *
	 * @return 직선광(Directional Light)의 Ambient 요소를 반환합니다.
	 */
	glm::vec4 GetAmbient() const { return ambient_; }


	/**
	 * @brief 직선광(Directional Light)의 Ambient 요소를 설정합니다.
	 *
	 * @param ambient 설정할 직선광(Directional Light)의 Ambient 요소입니다.
	 */
	void SetAmbient(const glm::vec4& ambient) { ambient_ = ambient; }


	/**
	 * @brief 직선광(Directional Light)의 Diffuse 요소를 얻습니다.
	 *
	 * @return 직선광(Directional Light)의 Diffuse 요소를 반환합니다.
	 */
	glm::vec4 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief 직선광(Directional Light)의 Diffuse 요소를 설정합니다.
	 *
	 * @param diffuse 설정할 직선광(Directional Light)의 Diffuse 요소입니다.
	 */
	void SetDiffuse(const glm::vec4& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief 직선광(Directional Light)의 Specular 요소를 얻습니다.
	 *
	 * @return 직선광(Directional Light)의 Specular 요소를 반환합니다.
	 */
	glm::vec4 GetSpecular() const { return specular_; }


	/**
	 * @brief 직선광(Directional Light)의 Specular 요소를 설정합니다.
	 *
	 * @param specular 설정할 직선광(Directional Light)의 Specular 요소입니다.
	 */
	void SetSpecular(const glm::vec4& specular) { specular_ = specular; }


	/**
	 * @brief 직선광(Directional Light)의 방향을 얻습니다.
	 * 
	 * @return 직선광(Directional Light)의 방향을 반환합니다.
	 */
	glm::vec3 GetDirection() const { return direction_; }


	/**
	 * @brief 직선광(Directional Light)의 방향을 설정합니다.
	 * 
	 * @param direction 설정할 직선광(Directional Light)의 방향입니다.
	 */
	void SetDirection(const glm::vec3& direction) { direction_ = direction; }


private:
	/**
	 * @brief 직선광(Directional Light)의 Ambient 요소입니다.
	 */
	glm::vec4 ambient_;


	/**
	 * @brief 직선광(Directional Light)의 Diffuse 요소입니다.
	 */
	glm::vec4 diffuse_;


	/**
	 * @brief 직선광(Directional Light)의 Specular 요소입니다.
	 */
	glm::vec4 specular_;


	/**
	 * @brief 직선광(Directional Light)의 방향입니다.
	 */
	glm::vec3 direction_;
};