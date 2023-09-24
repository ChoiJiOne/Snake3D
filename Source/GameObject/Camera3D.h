#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief 3D ī�޶� ������Ʈ�Դϴ�.
 */
class Camera3D : public IGameObject
{
public:
	/**
	 * @brief 3D ī�޶� ������Ʈ�� ����Ʈ �������Դϴ�.
	 * 
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Camera3D() = default;


	/**
	 * @brief 3D ī�޶� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 * 
	 * @note 3D ī�޶� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Camera3D();


	/**
	 * @brief 3D ī�޶� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Camera3D);


	/**
	 * @brief 3D ī�޶� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param eyePosition ī�޶��� ���� �� ��ġ�Դϴ�.
	 * @param focusPosition ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 * @param upDirection ī�޶��� �� �����Դϴ�.
	 * @param fovRadians ����� ���� �ʵ� ����(����)�Դϴ�.
	 * @param aspectRatio �� ������ X:Y �����Դϴ�.
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	virtual void Initialize(
		const glm::vec3& eyePosition,
		const glm::vec3& focusPosition,
		const glm::vec3& upDirection,
		float fovRadians,
		float aspectRatio,
		float nearZ,
		float farZ
	);


	/**
	 * @brief 3D ī�޶� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 3D ī�޶� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief 3D ī�޶� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ī�޶��� ���� �� ��ġ�� �����մϴ�.
	 *
	 * @param eyePosition ������ ī�޶��� ���� �� ��ġ�Դϴ�.
	 */
	void SetEyePosition(const glm::vec3& eyePosition)
	{
		eyePosition_ = eyePosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�� �����մϴ�.
	 *
	 * @param focusPosition ������ ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 */
	void SetFocusPosition(const glm::vec3& focusPosition)
	{
		focusPosition_ = focusPosition;
		UpdateViewMatrix();
	}


	/**
	 * @brief ī�޶��� �� ������ �����մϴ�.
	 *
	 * @param upDirection ������ ī�޶��� �� �����Դϴ�.
	 */
	void SetUpDirection(const glm::vec3& upDirection)
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
	glm::vec3 GetEyePosition() { return eyePosition_; }


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�� ����ϴ�.
	 *
	 * @return ī�޶� �ٶ󺸰� �ִ� ��ġ�� ��ȯ�մϴ�.
	 */
	glm::vec3 GetFocusPosition() { return focusPosition_; }


	/**
	 * @brief ī�޶��� �� ������ ����ϴ�.
	 *
	 * @return ī�޶��� �� ������ ��ȯ�մϴ�.
	 */
	glm::vec3 GetUpDirection() { return upDirection_; }


	/**
	 * @brief ����� ���� �ʵ� ����(����) ���� ����ϴ�.
	 *
	 * @return ����� ���� �ʵ� ����(����) ���� ��ȯ�մϴ�.
	 */
	float GetFovRadians() { return fov_; }


	/**
	 * @brief �� ���� X:Y�� ���� ���� ���� ���� ����ϴ�.
	 *
	 * @return �� ���� X:Y�� ���� ���� ���� ���� ��ȯ�մϴ�.
	 */
	float GetAspectRatio() { return aspectRatio_; }


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ� ���� ����ϴ�.
	 *
	 * @return ����� Ŭ���� �������� �Ÿ� ���� ��ȯ�մϴ�.
	 */
	float GetNearZ() { return nearZ_; }


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ� ���� ����ϴ�.
	 *
	 * @return ���Ÿ� Ŭ���� �������� �Ÿ� ���� ��ȯ�մϴ�.
	 */
	float GetFarZ() { return farZ_; }


	/**
	 * @brief �þ� ����� ����ϴ�.
	 *
	 * @return �þ� ����� ��ȯ�մϴ�.
	 */
	glm::mat4 GetViewMatrix() { return viewMatrix_; }


	/**
	 * @brief ���� ����� ����ϴ�.
	 *
	 * @return ���� ����� ��ȯ�մϴ�.
	 */
	glm::mat4 GetProjectionMatrix() { return projectionMatrix_; }


protected:
	/**
	 * @brief �þ� ����� ������Ʈ�մϴ�.
	 */
	void UpdateViewMatrix();


	/**
	 * @brief ���� ����� ������Ʈ�մϴ�.
	 */
	void UpdateProjectionMatrix();


protected:
	/**
	 * @brief ī�޶��� ���� �� ��ġ�Դϴ�.
	 */
	glm::vec3 eyePosition_;


	/**
	 * @brief ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 */
	glm::vec3 focusPosition_;


	/**
	 * @brief ī�޶��� �� �����Դϴ�.
	 */
	glm::vec3 upDirection_;


	/**
	 * @brief ����� ���� �ʵ� ����(����)�Դϴ�.
	 */
	float fov_ = 0.0f;


	/**
	 * @brief �� ���� X:Y�� ���� ���� �����Դϴ�.
	 */
	float aspectRatio_ = 0.0f;


	/**
	 * @brief ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	float nearZ_ = 0.0f;


	/**
	 * @brief ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	float farZ_ = 0.0f;


	/**
	 * @brief �� ����Դϴ�.
	 */
	glm::mat4 viewMatrix_;


	/**
	 * @brief ���� ����Դϴ�.
	 *
	 * @note ���� ��������� �ƴ� ���� ���� ����Դϴ�.
	 */
	glm::mat4 projectionMatrix_;
};