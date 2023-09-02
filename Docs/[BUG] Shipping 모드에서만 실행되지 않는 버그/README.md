# [BUG] Shipping 모드에서만 실행되지 않는 버그

이 문서는 Shipping 모드에서만 실행되지 않는 버그와 그 버그를 수정한 방법에 대한 문서입니다.
<br><br>


## 상황

우연히 `RunGame.bat`를 이용해서 `Shipping` 모드를 실행했는데([RunGame.bat 사용법](../[USAGE]%20RunGame.bat%20사용법/README.md) 참조), 크래시 덤프 파일을 생성하면서 프로그램이 종료되는 문제를 발견했습니다.
<br><br>


## 문제 발생 원인 찾기

문제가 발생한 지점은 셰이더 부분의 상수 버퍼를 업데이트하는 마지막 부분에서 디버거에 브레이크가 결렸습니다.

```
// 상수 버퍼를 업데이트하는 지점...
D3D11_MAPPED_SUBRESOURCE mappedResource;
HRESULT_ASSERT(context->Map(primitiveShapeVertexBuffer_[signature], 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update primitive shape vertex buffer...");
{
    VertexPosition* vertexBufferPtr = reinterpret_cast<VertexPosition*>(mappedResource.pData);

    std::memcpy(
        vertexBufferPtr,
        reinterpret_cast<const void*>(&primitiveShapeVertex_[signature][0]),
        primitiveShapeVertex_[signature].size() * static_cast<size_t>(VertexPosition::GetStride())
    );

    context->Unmap(primitiveShapeVertexBuffer_[signature], 0);
}
```

하지만, 문제를 인식한 시점에서 `Shipping` 모드는 최적화를 수행하므로, 디버거에 브레이크가 걸리더라도 내부 변수에 대한 정보를 확인할 수 없었습니다. 그래서 최적화 옵션을 전부 비활성화 한 상태에서 `Shipping` 모드를 실행했는데도 디버거에 브레이크가 걸렸습니다. 그 상태에서 브레이크가 걸린 지점은 `RenderManager`의 `BeginFrame`입니다. 

```
void RenderManager::BeginFrame(float red, float green, float blue, float alpha, float depth, uint8_t stencil)
{
	context_->OMSetRenderTargets(1, &renderTargetView_, depthStencilView_);

	float colorRGBA[4] = { red, green, blue, alpha };
	context_->ClearRenderTargetView(renderTargetView_, colorRGBA);
	context_->ClearDepthStencilView(depthStencilView_, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, depth, stencil);
}
```

디버그 창에서 확인한 결과 `renderTargetView_`와 `depthStencilView_`가 nullptr이였습니다. 즉, 이전에 초기화하는 시점에서 렌더 타겟 뷰와 깊이 스텐실 뷰 생성에 실패한 것이였습니다.
그래서, 렌더 타겟 뷰와 깊이 스텐실 뷰를 생성하는 부분에 브레이크 포인트를 걸고 확인해보았습니다.

```
void RenderManager::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");
	ASSERT(renderTargetWindow_ != nullptr, "you have to set render target window...");

	CreateDeviceAndContext();
	CreateSwapChain();
	CreateRenderTargetView(); // 이부분이 렌더 타겟 뷰 생성하는 곳
	CreateDepthStencilView(); // 이부분이 깊이 스텐실 뷰 생성하는 곳

    ...

	bIsInitialized_ = true;
}
```

확인 결과 `CreateRenderTargetView` 에서 생성 실패를 하는데, 디버깅 중 이상한 현상을 발견했습니다. 이상하게 매크로로 감싸져 있는 부분을 건너 뛰는 느낌이 들었습니다.

```
void RenderManager::CreateRenderTargetView()
{
	SAFE_RELEASE(renderTargetView_);

	ID3D11Texture2D* backBuffer = nullptr;
	HRESULT_ASSERT(swapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer)), "failed to get back buffer resource...");
	HRESULT_ASSERT(device_->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView_), "failed to create render target view...");

	SAFE_RELEASE(backBuffer);
}
```

그런데, 건너 뛰는 느낌을 받기 전 `swapChain_` 변수를 확인해본 결과 nullptr값이 들어있었습니다. 이는 이전에 `CreateSwapChain` 호출에 실패했다는 것입니다. 따라서, `CreateSwapChain` 부분에 브레이크 포인트를 걸고 다시 분석해보았습니다.

```
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
```

해당 부분에서 문제를 찾았습니다. `CreateSwapChain`에서는 `renderTargetWindow_` 라는 변수를 이용해서 윈도우 클라이언트의 크기를 가져오는 기능이 있는데, 여기에서 크기를 가져오는 데 실패해서 `clientWidth`와 `clientHeight`에 0값이 들어 있었고, 이로 인해서 `CreateSwapChain` 에서의 SwapChain 생성은 실패하는 것이였습니다. 그래서 `Window` 클래스의 `GetClientSize` 메서드 부분에 브레이크 포인트를 걸고 다시 분석했습니다.

```
void Window::GetClientSize(uint32_t& outClientWidth, uint32_t& outClientHeight)
{
	RECT clientRect = {};
	ASSERT(GetClientRect(windowHandle_, &clientRect), "failed to get client rect...");

	outClientWidth = clientRect.right - clientRect.left;
	outClientHeight = clientRect.bottom - clientRect.top;
}
```

여기에서 문제의 원인을 찾았습니다. 이 메서드를 호출할 때, 역시 `ASSERT` 매크로에 감싸져 있는 `GetClientRect` 함수는 호출되지 않았습니다. 결국 메크로가 문제였는데, Shipping 모드에서의 `ASSERT`와 `HRESULT_ASSERT` 정의는 다음과 같습니다.

```
...
#else // defined(SHIPPING)
#ifndef ASSERT
#define ASSERT(EXP, MESSAGE)
#endif
...
#else // defined(SHIPPING)
#ifndef HRESULT_ASSERT
#define HRESULT_ASSERT(EXP, MESSAGE)
#endif
```

Debug나 Release모드에서는 정의가 되어 있어 문제 없이 동작했지만, Shipping모드의 경우 내부 구현이 비어있어 EXP를 실행하지 않는데, 이는 함수를 호출하지 않아버리는 결과를 초래했습니다. 결국 Shipping 모드에서 동작하지 않은 이유는 매크로로 감싸져있는 함수는 호출되지 않아서 발생한 문제였습니다.
<br><br>


## 해결

매크로 구현을 다음과 같이 변경하니 이슈 없이 동작했습니다. 단순하게 Debug 모드와 그 외의 모드로 구분지었습니다.

```
#if defined(DEBUG)
#ifndef ASSERT
#define ASSERT(EXP, MESSAGE)\
	{\
		if (!(EXP))\
		{\
			OutputDebugStringA(StringHelper::Format("\nAssertion Checkpoint Failed!\nFILE : %s, LINE : %d, EXP : %s, MESSAGE : %s\n", __FILE__, __LINE__, #EXP, MESSAGE).c_str());\
			__debugbreak();\
			ExitProcess(-1);\
		}\
	}
#endif
#else // defined(RELEASE) or defined(SHIPPING)
#ifndef ASSERT
#define ASSERT(EXP, MESSAGE)\
	{\
		if (!(EXP))\
		{\
			OutputDebugStringA(StringHelper::Format("\nAssertion Checkpoint Failed!\nFILE : %s, LINE : %d, EXP : %s, MESSAGE : %s\n", __FILE__, __LINE__, #EXP, MESSAGE).c_str());\
			__debugbreak();\
		}\
	}
#endif
#endif

...

#if defined(DEBUG)
#ifndef HRESULT_ASSERT
#define HRESULT_ASSERT(HR, MESSAGE)\
	{\
		if (((HRESULT)(HR)) < 0)\
		{\
			OutputDebugStringA(StringHelper::Format("\nHRESULT Assertion Checkpoint Failed!\nFILE : %s, LINE : %d, HR = 0x%08X, MESSAGE : %s\n", __FILE__, __LINE__, HR, MESSAGE).c_str());\
			__debugbreak();\
			ExitProcess(-1);\
		}\
	}
#endif
#else // defined(RELEASE) or defined(SHIPPING)
#ifndef HRESULT_ASSERT
#define HRESULT_ASSERT(HR, MESSAGE)\
	{\
		if (((HRESULT)(HR)) < 0)\
		{\
			OutputDebugStringA(StringHelper::Format("\nHRESULT Assertion Checkpoint Failed!\nFILE : %s, LINE : %d, HR = 0x%08X, MESSAGE : %s\n", __FILE__, __LINE__, HR, MESSAGE).c_str());\
			__debugbreak();\
		}\
	}
#endif
#endif
```
<br><br>


## 버그 수정 커밋

[버그 수정 커밋](https://github.com/ChoiJiOne/Snake3D/commit/39fa7f1345969070ffb0c2053b225e0034fd23a3)의 해쉬 값은 39fa7f1345969070ffb0c2053b225e0034fd23a3 입니다.