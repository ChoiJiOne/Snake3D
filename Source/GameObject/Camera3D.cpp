#include "GameObject/Camera3D.h"

#include "Utility/Assertion.h"

#include <glm/gtc/matrix_transform.hpp>

Camera3D::~Camera3D()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Camera3D::Initialize(const glm::vec3& eyePosition, const glm::vec3& focusPosition, const glm::vec3& upDirection, float fovRadians, float aspectRatio, float nearZ, float farZ)
{
	ASSERT(!bIsInitialized_, "already initialize 3d camera object...");

	eyePosition_ = eyePosition;
	focusPosition_ = focusPosition;
	upDirection_ = upDirection;
	fov_ = fovRadians;
	aspectRatio_ = aspectRatio;
	nearZ_ = nearZ;
	farZ_ = farZ;

	UpdateViewMatrix();
	UpdateProjectionMatrix();

	bIsInitialized_ = true;
}

void Camera3D::Update(float deltaSeconds)
{
	// 여기서는 아무 동작도 수행하지 않습니다.
}

void Camera3D::Render()
{
	// 여기서는 아무 동작도 수행하지 않습니다.
}

void Camera3D::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}

void Camera3D::UpdateViewMatrix()
{
	viewMatrix_ = glm::lookAt(eyePosition_, focusPosition_, upDirection_);
}

void Camera3D::UpdateProjectionMatrix()
{
	projectionMatrix_ = glm::perspective(glm::radians(fov_), aspectRatio_, nearZ_, farZ_);
}