#include <array>

#include "Core/RenderManager.h"
#include "Core/Window.h"

void RenderManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");
	ASSERT(renderTargetWindow_ != nullptr, "you have to set render target window...");

	CreateDeviceAndContext();
	CreateSwapChain();
	CreateRenderTargetView();
	CreateDepthStencilView();

	HRESULT_ASSERT(CreateDepthStencilState(&depthStencilStates_["EnableZ"], true, true), "failed to create enable z depth stencil state...");
	HRESULT_ASSERT(CreateDepthStencilState(&depthStencilStates_["DisableZ"], false, true), "failed to create disable z depth stencil state...");

	HRESULT_ASSERT(CreateBlendState(&blendStates_["Alpha"], true), "failed to create alpha blend state...");

	HRESULT_ASSERT(CreateRasterizerState(&rasterizerStates_["DepthClipEnableFill"], false, true, true), "failed to create DepthClipEnableFill mode rasterizer state...");
	HRESULT_ASSERT(CreateRasterizerState(&rasterizerStates_["DepthClipDisableFill"], false, true, false), "failed to create DepthClipDisableFill mode rasterizer state...");
	HRESULT_ASSERT(CreateRasterizerState(&rasterizerStates_["DepthClipEnableWireframe"], false, false, true), "failed to create DepthClipEnableWireframe mode rasterizer state...");
	HRESULT_ASSERT(CreateRasterizerState(&rasterizerStates_["DepthClipDisableWireframe"], false, false, false), "failed to create DepthClipDisableWireframe mode rasterizer state...");

	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	for (auto& rasterizerState : rasterizerStates_)
	{
		SAFE_RELEASE(rasterizerState.second);
	}

	for (auto& blendState : blendStates_)
	{
		SAFE_RELEASE(blendState.second);
	}

	for (auto& depthStencilState : depthStencilStates_)
	{
		SAFE_RELEASE(depthStencilState.second);
	}

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

Window* RenderManager::GetRenderTargetWindow()
{
	return renderTargetWindow_;
}

void RenderManager::SetViewport(float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth)
{
	D3D11_VIEWPORT viewport = {};

	viewport.TopLeftX = topLeftX;
	viewport.TopLeftY = topLeftY;
	viewport.Width = width;
	viewport.Height = height;
	viewport.MinDepth = minDepth;
	viewport.MaxDepth = maxDepth;

	context_->RSSetViewports(1, &viewport);
}

void RenderManager::BeginFrame(float red, float green, float blue, float alpha, float depth, uint8_t stencil)
{
	context_->OMSetRenderTargets(1, &renderTargetView_, depthStencilView_);

	float colorRGBA[4] = { red, green, blue, alpha };
	context_->ClearRenderTargetView(renderTargetView_, colorRGBA);
	context_->ClearDepthStencilView(depthStencilView_, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, depth, stencil);
}

void RenderManager::EndFrame(bool bIsVsync)
{
	HRESULT_ASSERT(swapChain_->Present(static_cast<uint32_t>(bIsVsync), 0), "failed to swap back buffer and front buffer...");
}

void RenderManager::SetDepthStencilMode(bool bIsEnableZBuffer)
{
	ID3D11DepthStencilState* depthStencilState = bIsEnableZBuffer ? depthStencilStates_["EnableZ"] : depthStencilStates_["DisableZ"];

	context_->OMSetDepthStencilState(depthStencilState, 1);
}

void RenderManager::SetBlendMode(bool bIsEnableAlphaBlend)
{
	ID3D11BlendState* blendState = bIsEnableAlphaBlend ? blendStates_["Alpha"] : nullptr;

	context_->OMSetBlendState(blendState, nullptr, 0xFFFFFFFF);
}

void RenderManager::SetRasterizerMode(bool bIsEnableFillMode, bool bIsEnableClipDepth)
{
	ID3D11RasterizerState* rasterizerState = nullptr;

	if (bIsEnableFillMode)
	{
		rasterizerState = (bIsEnableClipDepth ? rasterizerStates_["DepthClipEnableFill"] : rasterizerStates_["DepthClipDisableFill"]);
	}
	else
	{
		rasterizerState = (bIsEnableClipDepth ? rasterizerStates_["DepthClipEnableWireframe"] : rasterizerStates_["DepthClipDisableWireframe"]);
	}

	context_->RSSetState(rasterizerState);
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

void RenderManager::CreateRenderTargetView()
{
	SAFE_RELEASE(renderTargetView_);

	ID3D11Texture2D* backBuffer = nullptr;
	HRESULT_ASSERT(swapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer)), "failed to get back buffer resource...");
	HRESULT_ASSERT(device_->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView_), "failed to create render target view...");

	SAFE_RELEASE(backBuffer);
}

void RenderManager::CreateDepthStencilView()
{
	SAFE_RELEASE(depthStencilView_);
	SAFE_RELEASE(depthStencilBuffer_);

	uint32_t clientWidth = 0;
	uint32_t clientHeight = 0;
	renderTargetWindow_->GetClientSize(clientWidth, clientHeight);

	D3D11_TEXTURE2D_DESC depthStencilBufferDesc = {};

	depthStencilBufferDesc.Width = static_cast<uint32_t>(clientWidth);
	depthStencilBufferDesc.Height = static_cast<uint32_t>(clientHeight);
	depthStencilBufferDesc.MipLevels = 1;
	depthStencilBufferDesc.ArraySize = 1;
	depthStencilBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilBufferDesc.SampleDesc.Count = 1;
	depthStencilBufferDesc.SampleDesc.Quality = 0;
	depthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilBufferDesc.CPUAccessFlags = 0;
	depthStencilBufferDesc.MiscFlags = 0;

	HRESULT_ASSERT(device_->CreateTexture2D(&depthStencilBufferDesc, nullptr, &depthStencilBuffer_), "failed to create depth stencil buffer...");

	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	HRESULT_ASSERT(device_->CreateDepthStencilView(depthStencilBuffer_, &depthStencilViewDesc, &depthStencilView_), "failed to create depth stencil view...");
}

HRESULT RenderManager::CreateDepthStencilState(ID3D11DepthStencilState** depthStencilState, bool bIsEnableDepth, bool bIsEnableStencil)
{
	D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc = {};

	depthStencilStateDesc.DepthEnable = static_cast<BOOL>(bIsEnableDepth);
	depthStencilStateDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilStateDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilStateDesc.StencilEnable = static_cast<BOOL>(bIsEnableStencil);
	depthStencilStateDesc.StencilReadMask = 0xFF;
	depthStencilStateDesc.StencilWriteMask = 0xFF;

	depthStencilStateDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilStateDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilStateDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilStateDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	depthStencilStateDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilStateDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilStateDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilStateDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	return device_->CreateDepthStencilState(&depthStencilStateDesc, depthStencilState);
}

HRESULT RenderManager::CreateBlendState(ID3D11BlendState** blendState, bool bIsEnable)
{
	D3D11_BLEND_DESC blendStateDesc = {};

	blendStateDesc.RenderTarget[0].BlendEnable = static_cast<BOOL>(bIsEnable);
	blendStateDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendStateDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendStateDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendStateDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendStateDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendStateDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendStateDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	return device_->CreateBlendState(&blendStateDesc, blendState);
}

HRESULT RenderManager::CreateRasterizerState(ID3D11RasterizerState** rasterizerState, bool bIsEnableCull, bool bIsEnableFill, bool bIsEnableClipDepth)
{
	D3D11_RASTERIZER_DESC rasterizerDesc = {};

	rasterizerDesc.AntialiasedLineEnable = static_cast<BOOL>(false);
	rasterizerDesc.CullMode = (bIsEnableCull ? D3D11_CULL_BACK : D3D11_CULL_NONE);
	rasterizerDesc.DepthBias = 0;
	rasterizerDesc.DepthBiasClamp = 0.0f;
	rasterizerDesc.DepthClipEnable = static_cast<BOOL>(bIsEnableClipDepth);
	rasterizerDesc.FillMode = (bIsEnableFill ? D3D11_FILL_SOLID : D3D11_FILL_WIREFRAME);
	rasterizerDesc.FrontCounterClockwise = static_cast<BOOL>(false);
	rasterizerDesc.MultisampleEnable = static_cast<BOOL>(false);
	rasterizerDesc.ScissorEnable = static_cast<BOOL>(false);
	rasterizerDesc.SlopeScaledDepthBias = 0.0f;

	return device_->CreateRasterizerState(&rasterizerDesc, rasterizerState);
}
