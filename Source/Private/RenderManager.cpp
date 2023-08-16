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

void RenderManager::CreateSwapChain()
{
	IDXGIDevice* device = nullptr;
	HRESULT_ASSERT(device_->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&device)), "failed to query dxgi device...");

	IDXGIAdapter* adapter = nullptr;
	HRESULT_ASSERT(device->GetAdapter(&adapter), "failed to get adapter from dxgi device...");

	IDXGIFactory* factory = nullptr;
	HRESULT_ASSERT(adapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory)), "failed to get dxgi factory...");

	SAFE_RELEASE(adapter);
	SAFE_RELEASE(device);

	uint32_t clientWidth = 0;
	uint32_t clientHeight = 0;
	renderTargetWindow_->GetClientSize(clientWidth, clientHeight);

	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	swapChainDesc.BufferCount = 2;
	swapChainDesc.BufferDesc.Width = static_cast<UINT>(clientWidth);
	swapChainDesc.BufferDesc.Height = static_cast<UINT>(clientHeight);
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = renderTargetWindow_->GetHandle();
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.Windowed = TRUE;

	HRESULT_ASSERT(factory->CreateSwapChain(device_, &swapChainDesc, &swapChain_), "failed to create swap chain...");
	HRESULT_ASSERT(factory->MakeWindowAssociation(renderTargetWindow_->GetHandle(), DXGI_MWA_NO_ALT_ENTER), "failed to set disable alt enter...");

	SAFE_RELEASE(factory);
}