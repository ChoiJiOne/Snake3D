#pragma once

#include "Matrix/Matrix.h"

#include "Vector/Vector.h"


/**
 * @brief 3D ī�޶� Ŭ�����Դϴ�.
 */
class Camera3D
{
public:
	/**
	 * @brief 3D ī�޶� Ŭ������ �⺻ �������Դϴ�.
	 * 
	 * @note �ʱ�ȭ�� �����ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Camera3D() = default;


	/**
	 * @brief 3D ī�޶� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Camera3D();


	/**
	 * @brief ī�޶� �ʱ�ȭ�մϴ�.
	 * 
	 * @param eyePosition ī�޶��� ���� �� ��ġ�Դϴ�.
	 * @param focusPosition ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 * @param upDirection ī�޶��� �� �����Դϴ�.
	 * @param fovRadians ����� ���� �ʵ� ����(����)�Դϴ�.
	 * @param aspectRatio �� ������ X:Y �����Դϴ�.
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
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
	 * @brief ī�޶��� ���� �� ��ġ�� �����մϴ�.
	 * 
	 * @param eyePosition ������ ī�޶��� ���� �� ��ġ�Դϴ�.
	 */
	void SetEyePosition(const Vector3f& eyePosition) 
	{ 
		eyePosition_ = eyePosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�� �����մϴ�.
	 * 
	 * @param focusPosition ������ ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 */
	void SetFocusPosition(const Vector3f& focusPosition) 
	{ 
		focusPosition_ = focusPosition; 
		UpdateViewMatrix();
	}


	/**
	 * @brief ī�޶��� �� ������ �����մϴ�.
	 * 
	 * @param upDirection ������ ī�޶��� �� �����Դϴ�.
	 */
	void SetUpDirection(const Vector3f& upDirection) 
	{ 
		upDirection_ = upDirection; 
		UpdateViewMatrix();
	}


	/**
	 * @brief ����� ���� �ʵ� ����(����)�� �����մϴ�.
	 * 
	 * @param fovRadians ������ �ʵ� ����(����) �Դϴ�.
	 */
	void SetFov(float fovRadians) 
	{ 
		fov_ = fovRadians; 
		UpdateProjectionMatrix();
	}


	/**
	 * @brief �� ���� X:Y�� ���� ���� ������ �����մϴ�.
	 * 
	 * @param aspectRatio ������ �� ������ ���� ���� �����Դϴ�.
	 */
	void SetAspectRation(float aspectRatio) 
	{ 
		aspectRatio_ = aspectRatio; 
		UpdateProjectionMatrix();
	}


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ��� �����մϴ�.
	 * 
	 * @param nearZ ������ ����� Ŭ���� �������� �Ÿ��Դϴ�.
	 */
	void SetNearZ(float nearZ) 
	{ 
		nearZ_ = nearZ; 
		UpdateProjectionMatrix();
	}


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ��� �����մϴ�.
	 * 
	 * @param farZ ������ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�.
	 */
	void SetFarZ(float farZ) 
	{ 
		farZ_ = farZ; 
		UpdateProjectionMatrix();
	}


	/**
	 * @brief ī�޶��� ���� �� ��ġ�� ����ϴ�.
	 * 
	 * @return ī�޶��� ���� �� ��ġ�� ��ȯ�մϴ�.
	 */
	

	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�� ����ϴ�.
	 */


	/**
	 * @brief ī�޶��� �� ������ ����ϴ�.
	 */

	/**
	 * @brief ����� ���� �ʵ� ����(����) ���� ����ϴ�.
	 */


	/**
	 * @brief �� ���� X:Y�� ���� ���� ���� ���� ����ϴ�.
	 */


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ� ���� ����ϴ�.
	 */


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ� ���� ����ϴ�.
	 */


	/**
	 * @brief �þ� ����� ����ϴ�.
	 * 
	 * @return �þ� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4f GetViewMatrix() { return viewMatrix_; }


	/**
	 * @brief ���� ����� ����ϴ�.
	 * 
	 * @return ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4f GetProjectionMatrix() { return projectionMatrix_; }

	
private:
	/**
	 * @brief �þ� ����� ������Ʈ�մϴ�.
	 */
	void UpdateViewMatrix();


	/**
	 * @brief ���� ����� ������Ʈ�մϴ�.
	 */
	void UpdateProjectionMatrix();


private:
	/**
	 * @brief ī�޶��� ���� �� ��ġ�Դϴ�.
	 */
	Vector3f eyePosition_;


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 */
	Vector3f focusPosition_;


	/**
	 * @brief ī�޶��� �� �����Դϴ�.
	 */
	Vector3f upDirection_;


	/**
	 * @brief ����� ���� �ʵ� ����(����)�Դϴ�.
	 */
	float fov_;


	/**
	 * @brief �� ���� X:Y�� ���� ���� �����Դϴ�.
	 */
	float aspectRatio_;


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	float nearZ_;


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	float farZ_;


	/**
	 * @brief �� ����Դϴ�.
	 */
	Matrix4x4f viewMatrix_;


	/**
	 * @brief ���� ����Դϴ�.
	 * 
	 * @note ���� ��������� �ƴ� ���� ���� ����Դϴ�.
	 */
	Matrix4x4f projectionMatrix_;
};