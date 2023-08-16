#pragma once

#include <d3d11.h>

#include "Macro.h"
#include "IManager.h"

class Window;


/**
 * @brief ������ ó���� �����ϴ� �Ŵ����Դϴ�.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(RenderManager);


	/**
	 * @brief ������ ó���� �����ϴ� �޴����� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ ����� �Ǵ� �����츦 �����մϴ�.
	 *
	 * @param window ������ ����� �Ǵ� �������� �������Դϴ�.
	 */
	void SetRenderTargetWindow(Window* window);


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


	/**
	 * @brief ����̽��� ���ؽ�Ʈ�� �����մϴ�.
	 */
	void CreateDeviceAndContext();


	/**
	 * @brief ���� ü���� �����մϴ�.
	 */
	void CreateSwapChain();


	/**
	 * @brief ���� Ÿ�� �並 �����մϴ�.
	 */
	void CreateRenderTargetView();


	/**
	 * @brief ���� ���ٽ� �並 �����մϴ�.
	 */
	void CreateDepthStencilView();


private:
	/**
	 * @brief ������ ����� �Ǵ� �������Դϴ�.
	 */
	Window* renderTargetWindow_ = nullptr;


	/**
	 * @brief Direct3D ����̹� Ÿ���Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_driver_type
	 */
	D3D_DRIVER_TYPE driverType_ = D3D_DRIVER_TYPE_UNKNOWN;


	/**
	 * @brief Direct3D ��� �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_feature_level
	 */
	D3D_FEATURE_LEVEL featureLevel_;


	/**
	 * @brief ���ҽ��� ����� �� ���Ǵ� ���� ����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11device
	 */
	ID3D11Device* device_ = nullptr;


	/**
	 * @brief ������ ����� �����ϴ� ���ؽ�Ʈ�Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11devicecontext
	 */
	ID3D11DeviceContext* context_ = nullptr;


	/**
	 * @brief ������ �� �����͸� ��¿� ǥ���ϱ� ���� �����ϱ� ���� �ϳ� �̻��� ǥ���� �����մϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/dxgi/nn-dxgi-idxgiswapchain
	 */
	IDXGISwapChain* swapChain_ = nullptr;
	

	/**
	 * @brief ������ ���� ���� ������ ���� Ÿ�� ���� ���ҽ� �������̽��Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11rendertargetview
	 */
	ID3D11RenderTargetView* renderTargetView_ = nullptr;


	/**
	 * @brief ���� - ���ٽ� ������ �ؽ�ó �������̽��Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11texture2d
	 */
	ID3D11Texture2D* depthStencilBuffer_ = nullptr;


	/**
	 * @brief ���� - ���ٽ� �׽�Ʈ ���� ���� ������ �ؽ�ó ���ҽ� �������̽��Դϴ�.
	 */
	ID3D11DepthStencilView* depthStencilView_ = nullptr;
};