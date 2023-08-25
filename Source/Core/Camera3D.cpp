#include "Camera3D.h"

#include "Utils/MathHelper.h"

Camera3D::~Camera3D()
{
}

void Camera3D::Initialzie(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& upDirection, float fovRadians, float aspectRatio, float nearZ, float farZ)
{
	eyePosition_ = eyePosition;
	focusPosition_ = focusPosition;
	upDirection_ = upDirection;
	fov_ = fovRadians;
	aspectRatio_ = aspectRatio;
	nearZ_ = nearZ;
	farZ_ = farZ;

	UpdateViewMatrix();
	UpdateProjectionMatrix();
}

void Camera3D::UpdateViewMatrix()
{
	viewMatrix_ = MathHelper::LookAtMatrix(eyePosition_, focusPosition_, upDirection_);
}

void Camera3D::UpdateProjectionMatrix()
{
	projectionMatrix_ = MathHelper::ProjectionMatrix(fov_, aspectRatio_, nearZ_, farZ_);
}