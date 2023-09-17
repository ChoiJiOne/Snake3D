#pragma once

#include "Resource/IResource.h"

class Material;
class Mesh;


/**
 * @brief 메시와 재질을 포함한 모델입니다.
 */
class Model : public IResource
{
public:
	/**
	 * @brief 모델 클래스의 기본 생성자입니다.
	 *
	 * @note 초기화를 수행하기 위해서는 반드시 초기화 메서드를 호출해야 합니다.
	 */
	Model() = default;


	/**
	 * @brief 모델 클래스의 가상 소멸자입니다.
	 *
	 * @note 해제를 수행하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Model();


	/**
	 * @brief 모델 클래스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Model);


	/**
	 * @brief 메시와 재질로 모델을 구성합니다.
	 * 
	 * @param mesh 모델의 메시입니다.
	 * @param material 모델의 재질입니다.
	 */
	void Initialize(Mesh* mesh, Material* material);


	/**
	 * @brief 모델 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 모델의 메실를 얻습니다.
	 * 
	 * @return 모델의 메시 포인터 값을 반환합니다.
	 */
	Mesh* GetMesh() { return mesh_; }


	/**
	 * @brief 모델의 재질을 얻습니다.
	 * 
	 * @return 모델의 재질 포인터 값을 반환합니다.
	 */
	Material* GetMaterial() { return material_; }


private:
	/**
	 * @brief 모델의 메시입니다.
	 */
	Mesh* mesh_ = nullptr;


	/**
	 * @brief 모델의 재질입니다.
	 */
	Material* material_ = nullptr;
};