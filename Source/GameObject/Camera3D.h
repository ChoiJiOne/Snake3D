#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief 3D 카메라 오브젝트입니다.
 */
class Camera3D : public IGameObject
{
public:
	/**
	 * @brief 3D 카메라 오브젝트의 디폴트 생성자입니다.
	 * 
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Camera3D() = default;


	/**
	 * @brief 3D 카메라 오브젝트의 가상 소멸자입니다.
	 * 
	 * @note 3D 카메라 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Camera3D();


	/**
	 * @brief 3D 카메라 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Camera3D);


	/**
	 * @brief 3D 카메라 오브젝트를 초기화합니다.
	 * 
	 * @param eyePosition 카메라의 월드 상 위치입니다.
	 * @param focusPosition 카메라가 바라보고 있는 위치입니다.
	 * @param upDirection 카메라의 위 방향입니다.
	 * @param fovRadians 하향식 보기 필드 각도(라디안)입니다.
	 * @param aspectRatio 뷰 공간의 X:Y 비율입니다.
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	void Initialize(
		const glm::vec3& eyePosition,
		const glm::vec3& focusPosition,
		const glm::vec3& upDirection,
		float fovRadians,
		float aspectRatio,
		float nearZ,
		float farZ
	);


	/**
	 * @brief 3D 카메라 오브젝트를 업데이트합니다.
	 *
	 * @note 3D 카메라 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 3D 카메라 오브젝트를 화면에 그립니다.
	 *
	 * @note 3D 카메라 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 3D 카메라 오브젝트 내의 리소스를 할당 해제합니다.
	 *
	 * @note 3D 카메라 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 카메라의 월드 상 위치를 설정합니다.
	 *
	 * @param eyePosition 설정할 카메라의 월드 상 위치입니다.
	 */
	void SetEyePosition(const glm::vec3& eyePosition)
	{
		eyePosition_ = eyePosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief 카메라가 바라보고 있는 위치를 설정합니다.
	 *
	 * @param focusPosition 설정할 카메라가 바라보고 있는 위치입니다.
	 */
	void SetFocusPosition(const glm::vec3& focusPosition)
	{
		focusPosition_ = focusPosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief 카메라의 위 방향을 설정합니다.
	 *
	 * @param upDirection 설정할 카메라의 위 방향입니다.
	 */
	void SetUpDirection(const glm::vec3& upDirection)
	{
		upDirection_ = upDirection;
		UpdateViewMatrix();
	}


	/**
	 * @brief 하향식 보기 필드 각도(라디안)를 설정합니다.
	 *
	 * @param fovRadians 설정할 필드 각도(라디안) 입니다.
	 */
	void SetFov(float fovRadians)
	{
		fov_ = fovRadians;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율을 설정합니다.
	 *
	 * @param aspectRatio 설정할 뷰 공간의 가로 세로 비율입니다.
	 */
	void SetAspectRation(float aspectRatio)
	{
		aspectRatio_ = aspectRatio;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 가까운 클리핑 평면까지의 거리를 설정합니다.
	 *
	 * @param nearZ 설정할 가까운 클리핑 평면까지의 거리입니다.
	 */
	void SetNearZ(float nearZ)
	{
		nearZ_ = nearZ;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 원거리 클리핑 평면까지의 거리를 설정합니다.
	 *
	 * @param farZ 설정할 원거리 클리핑 평면까지의 거리입니다.
	 */
	void SetFarZ(float farZ)
	{
		farZ_ = farZ;
		UpdateProjectionMatrix();
	}


	/**
	 * @brief 카메라의 월드 상 위치를 얻습니다.
	 *
	 * @return 카메라의 월드 상 위치를 반환합니다.
	 */
	glm::vec3 GetEyePosition() { return eyePosition_; }


	/**
	 * @brief 카메라가 바라보고 있는 위치를 얻습니다.
	 *
	 * @return 카메라가 바라보고 있는 위치를 반환합니다.
	 */
	glm::vec3 GetFocusPosition() { return focusPosition_; }


	/**
	 * @brief 카메라의 위 방향을 얻습니다.
	 *
	 * @return 카메라의 위 방향을 반환합니다.
	 */
	glm::vec3 GetUpDirection() { return upDirection_; }


	/**
	 * @brief 하향식 보기 필드 각도(라디안) 값을 얻습니다.
	 *
	 * @return 하향식 보기 필드 각도(라디안) 값을 반환합니다.
	 */
	float GetFovRadians() { return fov_; }


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율 값을 얻습니다.
	 *
	 * @return 뷰 공간 X:Y의 가로 세로 비율 값을 반환합니다.
	 */
	float GetAspectRatio() { return aspectRatio_; }


	/**
	 * @brief 가까운 클리핑 평면까지의 거리 값을 얻습니다.
	 *
	 * @return 가까운 클리핑 평면까지의 거리 값을 반환합니다.
	 */
	float GetNearZ() { return nearZ_; }


	/**
	 * @brief 원거리 클리핑 평면까지의 거리 값을 얻습니다.
	 *
	 * @return 원거리 클리핑 평면까지의 거리 값을 반환합니다.
	 */
	float GetFarZ() { return farZ_; }


	/**
	 * @brief 시야 행렬을 얻습니다.
	 *
	 * @return 시야 행렬을 반환합니다.
	 */
	glm::mat4 GetViewMatrix() { return viewMatrix_; }


	/**
	 * @brief 투영 행렬을 얻습니다.
	 *
	 * @return 투영 행렬을 반환합니다.
	 */
	glm::mat4 GetProjectionMatrix() { return projectionMatrix_; }


protected:
	/**
	 * @brief 시야 행렬을 업데이트합니다.
	 */
	void UpdateViewMatrix();


	/**
	 * @brief 투영 행렬을 업데이트합니다.
	 */
	void UpdateProjectionMatrix();


protected:
	/**
	 * @brief 카메라의 월드 상 위치입니다.
	 */
	glm::vec3 eyePosition_;


	/**
	 * @brief 카메라가 바라보고 있는 위치입니다.
	 */
	glm::vec3 focusPosition_;


	/**
	 * @brief 카메라의 위 방향입니다.
	 */
	glm::vec3 upDirection_;


	/**
	 * @brief 하향식 보기 필드 각도(라디안)입니다.
	 */
	float fov_;


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율입니다.
	 */
	float aspectRatio_;


	/**
	 * @brief 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	float nearZ_;


	/**
	 * @brief 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	float farZ_;


	/**
	 * @brief 뷰 행렬입니다.
	 */
	glm::mat4 viewMatrix_;


	/**
	 * @brief 투영 행렬입니다.
	 *
	 * @note 직교 투영행렬이 아닌 원근 투영 행렬입니다.
	 */
	glm::mat4 projectionMatrix_;
};