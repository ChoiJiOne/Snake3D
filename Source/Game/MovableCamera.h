#pragma once

#include "GameObject/Camera3D.h"


/**
 * @brief 움직일 수 있는 카메라 오브젝트입니다.
 */
class MovableCamera : public Camera3D
{
public:
	/**
	 * @brief 움직일 수 있는 카메라 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	MovableCamera() = default;


	/**
	 * @brief 움직일 수 있는 카메라 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 움직일 수 있는 카메라 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~MovableCamera();


	/**
	 * @brief 움직일 수 있는 카메라 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(MovableCamera);


	/**
	 * @brief 움직일 수 있는 카메라 오브젝트를 초기화합니다.
	 * 
	 * @note 움직일 수 있는 카메라는 항상 원점을 바라보고 있습니다.
	 *
	 * @param eyePosition 카메라의 월드 상 위치입니다.
	 * @param fovRadians 하향식 보기 필드 각도(라디안)입니다.
	 * @param aspectRatio 뷰 공간의 X:Y 비율입니다.
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	void Initialize(const glm::vec3& eyePosition, float fovRadians, float aspectRatio, float nearZ, float farZ);


	/**
	 * @brief 움직일 수 있는 카메라 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 움직일 수 있는 카메라 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 움직일 수 있는 카메라 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;
};