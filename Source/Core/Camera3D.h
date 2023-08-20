#pragma once

#include "Matrix/Matrix.h"

#include "Vector/Vector.h"


/**
 * @brief 3D 카메라 클래스입니다.
 */
class Camera3D
{
public:
	/**
	 * @brief 3D 카메라 클래스의 기본 생성자입니다.
	 * 
	 * @note 초기화를 수행하기 위해서는 반드시 Initialize 메서드를 호출해야 합니다.
	 */
	Camera3D() = default;


	/**
	 * @brief 3D 카메라 클래스의 가상 소멸자입니다.
	 */
	virtual ~Camera3D();


	/**
	 * @brief 카메라를 초기화합니다.
	 * 
	 * @param eyePosition 카메라의 월드 상 위치입니다.
	 * @param focusPosition 카메라가 바라보고 있는 위치입니다.
	 * @param upDirection 카메라의 위 방향입니다.
	 * @param fovRadians 하향식 보기 필드 각도(라디안)입니다.
	 * @param aspectRatio 뷰 공간의 X:Y 비율입니다.
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다. 0보다 커야 합니다.
	 */
	void Initialzie(
		const Vector3f& eyePosition,
		const Vector3f& focusPosition,
		const Vector3f& upDirection,
		float fovRadians,
		float aspectRatio,
		float nearZ,
		float farZ
	);


	/**
	 * @brief 카메라의 월드 상 위치를 설정합니다.
	 * 
	 * @param eyePosition 설정할 카메라의 월드 상 위치입니다.
	 */
	void SetEyePosition(const Vector3f& eyePosition) 
	{ 
		eyePosition_ = eyePosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief 카메라가 바라보고 있는 위치를 설정합니다.
	 * 
	 * @param focusPosition 설정할 카메라가 바라보고 있는 위치입니다.
	 */
	void SetFocusPosition(const Vector3f& focusPosition) 
	{ 
		focusPosition_ = focusPosition; 
		UpdateViewMatrix();
	}


	/**
	 * @brief 카메라의 위 방향을 설정합니다.
	 * 
	 * @param upDirection 설정할 카메라의 위 방향입니다.
	 */
	void SetUpDirection(const Vector3f& upDirection) 
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
	

	/**
	 * @brief 카메라가 바라보고 있는 위치를 얻습니다.
	 */


	/**
	 * @brief 카메라의 위 방향을 얻습니다.
	 */

	/**
	 * @brief 하향식 보기 필드 각도(라디안) 값을 얻습니다.
	 */


	/**
	 * @brief 뷰 공간 X:Y의 가로 세로 비율 값을 얻습니다.
	 */


	/**
	 * @brief 가까운 클리핑 평면까지의 거리 값을 얻습니다.
	 */


	/**
	 * @brief 원거리 클리핑 평면까지의 거리 값을 얻습니다.
	 */


	/**
	 * @brief 시야 행렬을 얻습니다.
	 * 
	 * @return 시야 행렬을 반환합니다.
	 */
	Matrix4x4f GetViewMatrix() { return viewMatrix_; }


	/**
	 * @brief 투영 행렬을 얻습니다.
	 * 
	 * @return 투영 행렬을 반환합니다.
	 */
	Matrix4x4f GetProjectionMatrix() { return projectionMatrix_; }

	
private:
	/**
	 * @brief 시야 행렬을 업데이트합니다.
	 */
	void UpdateViewMatrix();


	/**
	 * @brief 투영 행렬을 업데이트합니다.
	 */
	void UpdateProjectionMatrix();


private:
	/**
	 * @brief 카메라의 월드 상 위치입니다.
	 */
	Vector3f eyePosition_;


	/**
	 * @brief 카메라가 바라보고 있는 위치입니다.
	 */
	Vector3f focusPosition_;


	/**
	 * @brief 카메라의 위 방향입니다.
	 */
	Vector3f upDirection_;


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
	Matrix4x4f viewMatrix_;


	/**
	 * @brief 투영 행렬입니다.
	 * 
	 * @note 직교 투영행렬이 아닌 원근 투영 행렬입니다.
	 */
	Matrix4x4f projectionMatrix_;
};