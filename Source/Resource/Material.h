#pragma once

#include <glm/glm.hpp>

#include "Resource/IResource.h"


/**
 * @brief 객체의 재질입니다.
 */
class Material : public IResource
{
public:
	/**
	 * @brief 재질의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Material() = default;


	/**
	 * @brief 재질의 가상 소멸자입니다.
	 *
	 * @note 재질 내부 리소스를 할당 해제하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Material();


	/**
	 * @brief 재질의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Material);


	/**
	 * @brief 재질 리소스를 초기화합니다.
	 * 
	 * @param ambient 재질의 Ambient (주변광) 요소입니다.
	 * @param diffuse 재질의 Diffuse (분산광) 요소입니다.
	 * @param specular 재질의 Specular (반사광) 요소입니다.
	 * @param power 재질의 Specular Power (반사 세기) 요소입니다.
	 */
	void Initialize(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, float power);


	/**
	 * @brief 재질 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 재질의 Ambient (주변광) 요소를 얻습니다.
	 * 
	 * @return 재질의 Ambient (주변광) 요소를 반환합니다.
	 */
	glm::vec3 GetAmbient() const { return ambient_; }


	/**
	 * @brief 재질의 Ambient (주변광) 요소를 설정합니다.
	 * 
	 * @param ambient 설정할 재질의 Ambient (주변광) 요소입니다.
	 */
	void SetAmbient(const glm::vec3& ambient) { ambient_ = ambient; }


	/**
	 * @brief 재질의 Diffuse (분산광) 요소를 얻습니다.
	 * 
	 * @return 재질의 Diffuse (분산광) 요소를 반환합니다.
	 */
	glm::vec3 GetDiffuse() const { return diffuse_; }


	/**
	 * @brief 재질의 Diffuse (분산광) 요소를 설정합니다.
	 * 
	 * @param diffuse 설정할 재질의 Diffuse (분산광) 요소입니다.
	 */
	void SetDiffuse(const glm::vec3& diffuse) { diffuse_ = diffuse; }


	/**
	 * @brief 재질의 Specular (반사광) 요소를 얻습니다.
	 * 
	 * @return 재질의 Specular (반사광) 요소를 반환합니다.
	 */
	glm::vec3 GetSpecular() const { return specular_; }


	/**
	 * @brief 재질의 Specular (반사광) 요소를 설정합니다.
	 * 
	 * @param specular 설정할 재질의 Specular (반사광) 요소입니다.
	 */
	void SetSpecular(const glm::vec3& specular) { specular_ = specular; }


	/**
	 * @brief 재질의 Specular Power (반사 세기) 요소를 얻습니다.
	 * 
	 * @return 재질의 Specular Power (반사 세기) 요소를 반환합니다.
	 */
	float GetSpecularPower() const { return specularPower_; }
	

	/**
	 * @brief 재질의 Specular Power (반사 세기) 요소를 설정합니다.
	 * 
	 * @param power 설정할 재질의 Specular Power (반사 세기) 요소입니다.
	 */
	void SetSpecularPower(float power) { specularPower_ = power; }


private:
	/**
	 * @brief 재질의 Ambient (주변광) 요소입니다.
	 */
	glm::vec3 ambient_;


	/**
	 * @brief 재질의 Diffuse (분산광) 요소입니다.
	 */
	glm::vec3 diffuse_;


	/**
	 * @brief 재질의 Specular (반사광) 요소입니다.
	 */
	glm::vec3 specular_;


	/**
	 * @brief 재질의 Specular Power (반사 세기) 요소입니다.
	 */
	float specularPower_ = 0.0f;
};