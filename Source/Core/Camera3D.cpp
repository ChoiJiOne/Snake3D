#include "Camera3D.h"

#include "Core/MathHelper.h"

Camera3D::~Camera3D()
{
}

void Camera3D::Initialzie(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& upDirection, float fovRadians, float aspectRatio, float nearZ, float farZ)
{
}

void Camera3D::UpdateViewMatrix()
{
	viewMatrix_ = MathHelper::LookAtMatrix(eyePosition_, focusPosition_, upDirection_);
}

void Camera3D::UpdateProjectionMatrix()
{
	projectionMatrix_ = MathHelper::ProjectionMatrix(fov_, aspectRatio_, nearZ_, farZ_);
}