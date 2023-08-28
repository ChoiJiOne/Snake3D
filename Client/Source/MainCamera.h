#pragma once

#include <memory>

#include "Game/IGameObject.h"

#include "Vector/Vector.h"

class Camera3D;


/**
 * @brief 게임 내 메인 카메라입니다.
 */
class MainCamera : public IGameObject
{
public:
	/**
	 * @brief 메인 카메라 오브젝트의 디폴트 생성자입니다.
	 * 
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다. 
	 */
	MainCamera() = default;


	/**
	 * @brief 메인 카메라 오브젝트의 가상 소멸자입니다.
	 * 
	 * @note 메인 카메라 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~MainCamera();


	/**
	 * @brief 메인 카메라 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(MainCamera);


	/**
	 * @brief 메인 카메라 오브젝트를 초기화합니다.
	 * 
	 * @param eyePosition 카메라의 월드 상 위치입니다.
	 * @param focusPosition 카메라가 바라보고 있는 위치입니다.
	 * @param upDirection 카메라의 위 방향입니다.
	 */
	void Initialize(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& upDirection);


	/**
	 * @brief 메인 카메라 오브젝트를 업데이트합니다.
	 * 
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 메인 카메라 오브젝트를 화면에 그립니다.
	 * 
	 * @note 메인 카메라는 렌더링을 수행하지 않습니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 메인 카메라 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 3D 카메라의 포인터를 얻습니다.
	 * 
	 * @return 3D 카메라의 포인터를 반환합니다.
	 */
	Camera3D* GetCamera3D() { return camera_.get(); }


private:
	/**
	 * @brief 3D 카메라입니다.
	 */
	std::unique_ptr<Camera3D> camera_ = nullptr;
};