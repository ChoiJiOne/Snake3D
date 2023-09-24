#include "Game/MovableCamera.h"

MovableCamera::~MovableCamera()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void MovableCamera::Initialize(const glm::vec3& eyePosition, float fovRadians, float aspectRatio, float nearZ, float farZ)
{
	glm::vec3 focusPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 upDirection = glm::vec3(0.0f, 1.0f, 0.0f);

	Camera3D::Initialize(eyePosition, focusPosition, upDirection, fovRadians, aspectRatio, nearZ, farZ);
}

void MovableCamera::Update(float deltaSeconds)
{
}

void MovableCamera::Render()
{
}

void MovableCamera::Release()
{
	Camera3D::Release();
}