#pragma once

#include <d3d11.h>

#include "Macro.h"
#include "IManager.h"

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
	 */
	ID3D11DepthStencilView* depthStencilView_ = nullptr;
};