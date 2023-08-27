#pragma once

#include <d3d11.h>
#include <unordered_map>

#include "Utils/Macro.h"

#include "Manager/IManager.h"

class Window;


/**
 * @brief 렌더링 처러를 수행하는 매니저입니다.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(RenderManager);


	/**
	 * @brief 렌더링 처리를 수행하는 메니저를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 렌더링 대상이 되는 윈도우를 설정합니다.
	 *
	 * @param window 렌더링 대상이 되는 윈도우의 포인터입니다.
	 */
	void SetRenderTargetWindow(Window* window);


	/**
	 * @brief 현재 렌더링 대상이 되는 윈도우의 포인터 값을 얻습니다.
	 * 
	 * @return 렌더링 대상이 되는 윈도우의 포인터 값을 반환합니다.
	 */
	Window* GetRenderTargetWindow();


	/**
	 * @brief 파이프라인의 뷰 포트를 설정합니다.
	 *
	 * @param topLeftX 뷰 포트 왼쪽 상단의 X좌표입니다.
	 * @param topLeftY 뷰 포트 왼쪽 상단의 Y좌표입니다.
	 * @param width 뷰 포트의 가로 크기입니다.
	 * @param height 뷰 포트의 세로 크기입니다.
	 * @param minDepth 뷰 포트의 최소 깊이입니다. 기본 값은 0.0 입니다.
	 * @param maxDepth 뷰 포트의 최대 깊이입니다. 기본 값은 1.0 입니다.
	 */
	void SetViewport(float topLeftX, float topLeftY, float width, float height, float minDepth = 0.0f, float maxDepth = 1.0f);


	/**
	 * @brief 디바이스를 얻습니다.
	 *
	 * @return 디바이스의 포인터를 반환합니다.
	 */
	ID3D11Device* GetDevice() { return device_; }


	/**
	 * @brief 파이프라인 상태를 설정하고 렌더링 명령을 생성하는 데 사용할 (즉시) 컨텍스트를 반환합니다.
	 *
	 * @return 컨텍스트의 포인터를 반환합니다.
	 */
	ID3D11DeviceContext* GetContext() { return context_; }


	/**
	 * @brief 프레임 렌더링을 시작하고 백버퍼를 초기화합니다.
	 *
	 * @param red 색상 버퍼의 초기화 할 색상 중 R값입니다.
	 * @param green 색상 버퍼의 초기화 할 색상 중 G값입니다.
	 * @param blue 색상 버퍼의 초기화 할 색상 중 B값입니다.
	 * @param alpha 색상 버퍼의 초기화 할 색상 중 A값입니다.
	 * @param depth 깊이 버퍼의 초기화 할 값입니다. 기본 값은 1.0 입니다
	 * @param stencil 스텐실 버퍼의 초기화 할 값입니다. 기본 값은 0입니다.
	 */
	void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief 프레임 렌더링을 종료하고 백버퍼와 프론트 버퍼를 스왑합니다.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present
	 *
	 * @param bIsVsync 수직 동기화 여부를 확인합니다. 기본적으로 수직 동기화 처리합니다.
	 *
	 * @throws 백 버퍼와 프론트 버퍼의 교환에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void EndFrame(bool bIsVsync = true);


	/**
	 * @brief 깊이-스텐실 모드를 설정합니다.
	 *
	 * @param bIsEnableZBuffer Z 버퍼 활성화 여부입니다.
	 */
	void SetDepthStencilMode(bool bIsEnableZBuffer);


	/**
	 * @brief 블랜딩 모드를 설정합니다.
	 *
	 * @param bIsEnableAlphaBlend 알파 블랜딩 활성화 여부입니다.
	 */
	void SetBlendMode(bool bIsEnableAlphaBlend);


	/**
	 * @brief 레스터라이저 모드를 설정합니다.
	 * 
	 * @param bIsEnableFillMode 채움 모드 활성화 여부입니다.
	 * @param bIsEnableClipDepth 깊이값 클리핑 활성화 여부입니다.
	 */
	void SetRasterizerMode(bool bIsEnableFillMode, bool bIsEnableClipDepth);


private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


	/**
	 * @brief 디바이스와 컨텍스트를 생성합니다.
	 */
	void CreateDeviceAndContext();


	/**
	 * @brief 스왑 체인을 생성합니다.
	 */
	void CreateSwapChain();


	/**
	 * @brief 렌더 타겟 뷰를 생성합니다.
	 */
	void CreateRenderTargetView();


	/**
	 * @brief 깊이 스텐실 뷰를 생성합니다.
	 */
	void CreateDepthStencilView();


	/**
	 * @brief 깊이 스텐실 상태를 생성합니다.
	 *
	 * @param depthStencilState 생성한 깊이 스텐실 상태를 저장할 포인터입니다.
	 * @param bIsEnableDepth 깊이 버퍼 활성화 여부입니다.
	 * @param bIsEnableStencil 스텐실 버퍼 활성화 여부입니다.
	 *
	 * @return 깊이 스텐실 상태 생성 결과를 반환합니다. 성공했다면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateDepthStencilState(ID3D11DepthStencilState** depthStencilState, bool bIsEnableDepth, bool bIsEnableStencil);


	/**
	 * @brief 블랜딩을 위한 블랜드 상태를 생성합니다.
	 *
	 * @param blendState 생성한 블랜드 상태를 저장할 포인터입니다.
	 * @param bIsEnable 블랜드 상태 활성화 여부입니다.
	 *
	 * @return 블랜딩 상태 생성 결과를 반환합니다. 성공했다면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateBlendState(ID3D11BlendState** blendState, bool bIsEnable);


	/**
	 * @brief 레스터라이저 상태를 생성합니다.
	 *
	 * @param rasterizerState 생성한 레스터라이저 상태를 저장할 포인터입니다.
	 * @param bIsEnableCull 컬링을 수행 여부입니다.
	 * @param bIsEnableFill 렌더링 시 채움 모드 수행 여부입니다.
	 * @param bIsEnableClipDepth 깊이 값 클리핑 활성화 수행 여부입니다.
	 *
	 * @return 레스터라이저 상태 생성 결과를 반환합니다. 성공했다면 S_OK, 그렇지 않다면 그 이외의 값을 반환합니다.
	 */
	HRESULT CreateRasterizerState(ID3D11RasterizerState** rasterizerState, bool bIsEnableCull, bool bIsEnableFill, bool bIsEnableClipDepth);


private:
	/**
	 * @brief 렌더링 대상이 되는 윈도우입니다.
	 */
	Window* renderTargetWindow_ = nullptr;


	/**
	 * @brief Direct3D 드라이버 타입입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_driver_type
	 */
	D3D_DRIVER_TYPE driverType_ = D3D_DRIVER_TYPE_UNKNOWN;


	/**
	 * @brief Direct3D 기능 수준입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_feature_level
	 */
	D3D_FEATURE_LEVEL featureLevel_;


	/**
	 * @brief 리소스를 만드는 데 사용되는 가상 어뎁터입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11device
	 */
	ID3D11Device* device_ = nullptr;


	/**
	 * @brief 렌더링 명령을 생성하는 컨텍스트입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11devicecontext
	 */
	ID3D11DeviceContext* context_ = nullptr;


	/**
	 * @brief 렌더링 된 데이터를 출력에 표시하기 전에 저장하기 위한 하나 이상의 표면을 구현합니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain
	 */
	IDXGISwapChain* swapChain_ = nullptr;
	

	/**
	 * @brief 렌더링 동안 접근 가능한 렌더 타겟 서브 리소스 인터페이스입니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11rendertargetview
	 */
	ID3D11RenderTargetView* renderTargetView_ = nullptr;


	/**
	 * @brief 깊이 - 스텐실 버퍼의 텍스처 인터페이스입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11texture2d
	 */
	ID3D11Texture2D* depthStencilBuffer_ = nullptr;


	/**
	 * @brief 깊이 - 스텐실 테스트 동안 접근 가능한 텍스처 리소스 인터페이스입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilview
	 */
	ID3D11DepthStencilView* depthStencilView_ = nullptr;


	/**
	 * @brief 렌더링 시 사용할 깊이 스텐실 상태입니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilstate
	 */
	std::unordered_map<std::string, ID3D11DepthStencilState*> depthStencilStates_;


	/**
	 * @brief 렌더링 시 사용할 블랜딩 상태입니다.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11blendstate
	 */
	std::unordered_map<std::string, ID3D11BlendState*> blendStates_;


	/**
	 * @brief 렌더링 시 사용할 레스터라이저 상태입니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11rasterizerstate
	 */
	std::unordered_map<std::string, ID3D11RasterizerState*> rasterizerStates_;
};