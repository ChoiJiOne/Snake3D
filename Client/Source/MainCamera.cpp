#include "MainCamera.h"

#include "Manager/RenderManager.h"

#include "Utils/Camera3D.h"
#include "Utils/MathHelper.h"
#include "Utils/Window.h"

MainCamera::~MainCamera()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void MainCamera::Initialize(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& upDirection)
{
	ASSERT(!bIsInitialized_, "already initialize main camera object...");

	uint32_t clientWidth = 0;
	uint32_t clientHeight = 0;
	RenderManager::Get().GetRenderTargetWindow()->GetClientSize(clientWidth, clientHeight);

	float fov = PI_F / 4.0f;
	float aspectRatio = static_cast<float>(clientWidth) / static_cast<float>(clientHeight);
	float nearZ = 0.01f;
	float farZ = 1000.0f;

	camera_ = std::make_unique<Camera3D>();
	camera_->Initialzie(eyePosition, focusPosition, upDirection, fov, aspectRatio, nearZ, farZ);

	bIsInitialized_ = true;
}

void MainCamera::Update(float deltaSeconds)
{
	// 이 게임에서의 메인 카메라는 움직이지 않습니다.
}

void MainCamera::Render()
{
	// 이 게임에서의 메인 카메라는 렌더링하지 않습니다.
}

void MainCamera::Release()
{
	ASSERT(bIsInitialized_, "you have to initialize main camera object...");

	camera_.reset();

	bIsInitialized_ = false;
}
