#pragma once

#include <string>

#include "GameObject/IGameObject.h"


class CubeMap; // 큐브맵 리소스를 사용하기 위한 전방 선언입니다.


/**
 * @brief 우주 배경 오브젝트입니다.
 */
class SpaceBackground : public IGameObject
{
public:
	/**
	 * @brief 우주 배경 오브젝트 인터페이스의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	SpaceBackground() = default;


	/**
	 * @brief 우주 배경 오브젝트 인터페이스의 가상 소멸자입니다.
	 *
	 * @note 우주 배경 오브젝트 인터페이스의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~SpaceBackground();


	/**
	 * @brief 우주 배경 오브젝트 인터페이스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpaceBackground);


	/**
	 * @brief 우주 배경 오브젝트를 초기화합니다.
	 * 
	 * @param cameraSignature 우주 배경 렌더링 시 참조할 카메라 오브젝트의 시그니처 값입니다.
	 */
	void Initialize(const std::string& cameraSignature);


	/**
	 * @brief 우주 배경 오브젝트를 업데이트합니다.
	 *
	 * @note 우주 배경 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 우주 배경 오브젝트를 화면에 그립니다.
	 *
	 * @note 우주 배경 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 우주 배경 오브젝트 내의 리소스를 할당 해제합니다.
	 *
	 * @note 우주 배경 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 큐브맵 리소스입니다.
	 */
	CubeMap* cubeMap_ = nullptr;


	/**
	 * @brief 큐브맵 렌더링에 참조할 카메라 오브젝트 시그니처 값입니다.
	 */
	std::string cameraSignature_;
};