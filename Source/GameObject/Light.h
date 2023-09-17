#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief 라이트 오브젝트입니다.
 */
class Light : public IGameObject
{
public:
	/**
	 * @brief 라이트의 종류입니다.
	 */
	enum class EType : int32_t
	{
		None             = 0x00,
		DirectionalLight = 0x01,
		PointLight       = 0x02,
		SpotLight        = 0x03,
	};


public:
	/**
	 * @brief 라이트 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Light() = default;


	/**
	 * @brief 라이트 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 라이트 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Light();


	/**
	 * @brief 라이트 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Light);


	/**
	 * @brief 라이트 오브젝트를 업데이트합니다.
	 * 
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 라이트 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 라이트 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 라이트 타입을 얻습니다.
	 * 
	 * @return 라이트 타입을 반환합니다.
	 */
	EType GetType() const { return type_; }


protected:
	/**
	 * @brief 라이트의 타입입니다.
	 */
	EType type_ = EType::None;
};