#include "Game/MovableCamera.h"

#include "Manager/InputManager.h"

#include "Utility/Logging.h"

#include <glm/gtc/matrix_transform.hpp>

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

	rotateRadius_ = glm::sqrt(eyePosition.x * eyePosition.x + eyePosition.z * eyePosition.z);

	Camera3D::Initialize(eyePosition, focusPosition, upDirection, fovRadians, aspectRatio, nearZ, farZ);
}

void MovableCamera::Update(float deltaSeconds)
{
	InputManager& inputManager = InputManager::Get();

	float rotateRadians = 0.0f;

	EPressState state = EPressState::None;

	state = inputManager.GetKeyPressState(EKeyCode::KEY_A); // 양의 방향
	if (state == EPressState::Pressed || state == EPressState::Held)
	{
		rotateRadians -= deltaSeconds;
	}

	state = inputManager.GetKeyPressState(EKeyCode::KEY_D); // 음의 방향
	if (state == EPressState::Pressed || state == EPressState::Held)
	{
		rotateRadians += deltaSeconds;
	}

	// ZX 평명 기준 회전
	glm::mat3 rotateMatrix = glm::mat3(glm::rotate(glm::mat4(1.0f), rotateRadians, glm::vec3(0.0f, 1.0f, 0.0f)));

	eyePosition_ = rotateMatrix * eyePosition_;
	SetEyePosition(eyePosition_);
}

void MovableCamera::Render()
{
}

void MovableCamera::Release()
{
	Camera3D::Release();
}