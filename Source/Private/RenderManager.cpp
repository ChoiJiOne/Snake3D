#include <array>

#include "RenderManager.h"
#include "Window.h"

void RenderManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");
	ASSERT(renderTargetWindow_ != nullptr, "you have to set render target window...");

	CreateDeviceAndContext();

	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	if (context_)
	{
		context_->ClearState();
	}

	SAFE_RELEASE(depthStencilView_);
	SAFE_RELEASE(depthStencilBuffer_);
	SAFE_RELEASE(renderTargetView_);
	SAFE_RELEASE(swapChain_);
	SAFE_RELEASE(context_);
	SAFE_RELEASE(device_);

	bIsInitialized_ = false;
}

void RenderManager::SetRenderTargetWindow(Window* window)
{
	ASSERT(window != nullptr, "render target window pointer is nullptr...");
	renderTargetWindow_ = window;
}

void RenderManager::CreateDeviceAndContext()
{
	uint32_t createDeviceFlags = 0;

#if defined(DEBUG) || defined(RELEASE)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	std::array<D3D_DRIVER_TYPE, 3> driverTypes =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};

	std::array<D3D_FEATURE_LEVEL, 6> featureLevels =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};

	HRESULT hr = S_OK;
	for (const auto& driverType : driverTypes)
	{
		driverType_ = driverType;

		hr = D3D11CreateDevice(
			nullptr,
			driverType_,
			nullptr,
			createDeviceFlags,
			&featureLevels[0],
			static_cast<UINT>(featureLevels.size()),
			D3D11_SDK_VERSION,
			&device_,
			&featureLevel_,
			&context_
		);

		if (SUCCEEDED(hr))
		{
			break;
		}
	}

	HRESULT_ASSERT(hr, "failed to create device and context...");
}