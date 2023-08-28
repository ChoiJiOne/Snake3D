#pragma once

#include <d3d11.h>
#include <memory>
#include <unordered_map>

#include "Utils/Macro.h"

#include "Manager/IManager.h"

#include "Shader/IShader.h"

class Camera3D;
class Window;
class TTFont;
class Model;


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


	/**
	 * @brief ���� ������ ����� �Ǵ� �������� ������ ���� ����ϴ�.
	 * 
	 * @return ������ ����� �Ǵ� �������� ������ ���� ��ȯ�մϴ�.
	 */
	Window* GetRenderTargetWindow();


	/**
	 * @brief ������������ �� ��Ʈ�� �����մϴ�.
	 *
	 * @param topLeftX �� ��Ʈ ���� ����� X��ǥ�Դϴ�.
	 * @param topLeftY �� ��Ʈ ���� ����� Y��ǥ�Դϴ�.
	 * @param width �� ��Ʈ�� ���� ũ���Դϴ�.
	 * @param height �� ��Ʈ�� ���� ũ���Դϴ�.
	 * @param minDepth �� ��Ʈ�� �ּ� �����Դϴ�. �⺻ ���� 0.0 �Դϴ�.
	 * @param maxDepth �� ��Ʈ�� �ִ� �����Դϴ�. �⺻ ���� 1.0 �Դϴ�.
	 */
	void SetViewport(float topLeftX, float topLeftY, float width, float height, float minDepth = 0.0f, float maxDepth = 1.0f);


	/**
	 * @brief ������������ ������ �� ��Ʈ�� �����մϴ�.
	 * 
	 * @param minDepth �� ��Ʈ�� �ּ� �����Դϴ�. �⺻ ���� 0.0 �Դϴ�.
	 * @param maxDepth �� ��Ʈ�� �ִ� �����Դϴ�. �⺻ ���� 1.0 �Դϴ�.
	 */
	void SetWindowViewport(float minDepth = 0.0f, float maxDepth = 1.0f);


	/**
	 * @brief ����̽��� ����ϴ�.
	 *
	 * @return ����̽��� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11Device* GetDevice() { return device_; }


	/**
	 * @brief ���������� ���¸� �����ϰ� ������ ����� �����ϴ� �� ����� (���) ���ؽ�Ʈ�� ��ȯ�մϴ�.
	 *
	 * @return ���ؽ�Ʈ�� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11DeviceContext* GetContext() { return context_; }


	/**
	 * @brief ������ �������� �����ϰ� ����۸� �ʱ�ȭ�մϴ�.
	 *
	 * @param red ���� ������ �ʱ�ȭ �� ���� �� R���Դϴ�.
	 * @param green ���� ������ �ʱ�ȭ �� ���� �� G���Դϴ�.
	 * @param blue ���� ������ �ʱ�ȭ �� ���� �� B���Դϴ�.
	 * @param alpha ���� ������ �ʱ�ȭ �� ���� �� A���Դϴ�.
	 * @param depth ���� ������ �ʱ�ȭ �� ���Դϴ�. �⺻ ���� 1.0 �Դϴ�
	 * @param stencil ���ٽ� ������ �ʱ�ȭ �� ���Դϴ�. �⺻ ���� 0�Դϴ�.
	 */
	void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief ������ �������� �����ϰ� ����ۿ� ����Ʈ ���۸� �����մϴ�.
	 *
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present
	 *
	 * @param bIsVsync ���� ����ȭ ���θ� Ȯ���մϴ�. �⺻������ ���� ����ȭ ó���մϴ�.
	 *
	 * @throws �� ���ۿ� ����Ʈ ������ ��ȯ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void EndFrame(bool bIsVsync = true);


	/**
	 * @brief ����-���ٽ� ��带 �����մϴ�.
	 *
	 * @param bIsEnableZBuffer Z ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetDepthStencilMode(bool bIsEnableZBuffer);


	/**
	 * @brief ���� ��带 �����մϴ�.
	 *
	 * @param bIsEnableAlphaBlend ���� ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetBlendMode(bool bIsEnableAlphaBlend);


	/**
	 * @brief �����Ͷ����� ��带 �����մϴ�.
	 * 
	 * @param bIsEnableFillMode ä�� ��� Ȱ��ȭ �����Դϴ�.
	 * @param bIsEnableClipDepth ���̰� Ŭ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetRasterizerMode(bool bIsEnableFillMode, bool bIsEnableClipDepth);


	/**
	 * @brief 2D ���� ����ۿ� �������մϴ�.
	 *
	 * @param startPosition 2D ��ǥ�� ���� �� ���� ���Դϴ�.
	 * @param endPosition 2D ��ǥ�� ���� �� �� ���Դϴ�.
	 * @param color 2D ���� �����Դϴ�.
	 */
	void DrawLine2D(const Vector2f& startPosition, const Vector2f& endPosition, const Vector4f& color);


	/**
	 * @brief 2D �ﰢ���� ����ۿ� �������մϴ�.
	 *
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param color 2D �ﰢ���� �����Դϴ�.
	 */
	void DrawTriangle2D(const Vector2f& fromPosition, const Vector2f& byPosition, const Vector2f& toPosition, const Vector4f& color);


	/**
	 * @brief 2D ���̾������� �ﰢ���� ����ۿ� �������մϴ�.
	 *
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param color 2D �ﰢ���� �����Դϴ�.
	 */
	void DrawWireframeTriangle2D(const Vector2f& fromPosition, const Vector2f& byPosition, const Vector2f& toPosition, const Vector4f& color);


	/**
	 * @brief 2D �簢���� ����ۿ� �������մϴ�.
	 *
	 * @param leftTopPosition 2D ��ǥ�� ���� ���� ��� ��ǥ�Դϴ�.
	 * @param rightBottomPosition 2D ��ǥ�� ���� ������ �ϴ� ��ǥ�Դϴ�.
	 * @param color 2D �簢���� �����Դϴ�.
	 */
	void DrawRect2D(const Vector2f& leftTopPosition, const Vector2f& rightBottomPosition, const Vector4f& color);


	/**
	 * @brief 2D ���̾� ������ �簢���� ����ۿ� �������մϴ�.
	 *
	 * @param leftTopPosition 2D ��ǥ�� ���� ���� ��� ��ǥ�Դϴ�.
	 * @param rightBottomPosition 2D ��ǥ�� ���� ������ �ϴ� ��ǥ�Դϴ�.
	 * @param color 2D �簢���� �����Դϴ�.
	 */
	void DrawWireframeRect2D(const Vector2f& leftTopPosition, const Vector2f& rightBottomPosition, const Vector4f& color);


	/**
	 * @brief 2D �ؽ�Ʈ�� ����ۿ� �������մϴ�.
	 *
	 * @param font �ؽ�Ʈ�� �������� �� ������ ��Ʈ�Դϴ�.
	 * @param text �������� �ؽ�Ʈ�Դϴ�.
	 * @param center 2D ��ǥ�� ���� �ؽ�Ʈ �߽� ��ǥ�Դϴ�.
	 * @param color �ؽ�Ʈ�� �����Դϴ�.
	 */
	void DrawText2D(TTFont* font, const std::wstring& text, const Vector2f& center, const Vector4f& color);


	/**
	 * @brief 3D ���� ����ۿ� �������մϴ�.
	 *
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param startPosition ���� ���� 3D �� ���� ���Դϴ�.
	 * @param endPosition ���� ���� 3D �� �� ���Դϴ�.
	 * @param color 3D ���� �����Դϴ�.
	 */
	void DrawLine3D(Camera3D* camera, const Vector3f& startPosition, const Vector3f& endPosition, const Vector4f& color);


	/**
	 * @brief 3D ���� ����ۿ� �������մϴ�.
	 * 
	 * @param world ���� ���� ����Դϴ�.
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param model �������� ���Դϴ�.
	 */
	void DrawModel3D(const Matrix4x4f& world, Camera3D* camera, Model* model);


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


	/**
	 * @brief ���� ���ٽ� ���¸� �����մϴ�.
	 *
	 * @param depthStencilState ������ ���� ���ٽ� ���¸� ������ �������Դϴ�.
	 * @param bIsEnableDepth ���� ���� Ȱ��ȭ �����Դϴ�.
	 * @param bIsEnableStencil ���ٽ� ���� Ȱ��ȭ �����Դϴ�.
	 *
	 * @return ���� ���ٽ� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateDepthStencilState(ID3D11DepthStencilState** depthStencilState, bool bIsEnableDepth, bool bIsEnableStencil);


	/**
	 * @brief ������ ���� ���� ���¸� �����մϴ�.
	 *
	 * @param blendState ������ ���� ���¸� ������ �������Դϴ�.
	 * @param bIsEnable ���� ���� Ȱ��ȭ �����Դϴ�.
	 *
	 * @return ���� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateBlendState(ID3D11BlendState** blendState, bool bIsEnable);


	/**
	 * @brief �����Ͷ����� ���¸� �����մϴ�.
	 *
	 * @param rasterizerState ������ �����Ͷ����� ���¸� ������ �������Դϴ�.
	 * @param bIsEnableCull �ø��� ���� �����Դϴ�.
	 * @param bIsEnableFill ������ �� ä�� ��� ���� �����Դϴ�.
	 * @param bIsEnableClipDepth ���� �� Ŭ���� Ȱ��ȭ ���� �����Դϴ�.
	 *
	 * @return �����Ͷ����� ���� ���� ����� ��ȯ�մϴ�. �����ߴٸ� S_OK, �׷��� �ʴٸ� �� �̿��� ���� ��ȯ�մϴ�.
	 */
	HRESULT CreateRasterizerState(ID3D11RasterizerState** rasterizerState, bool bIsEnableCull, bool bIsEnableFill, bool bIsEnableClipDepth);


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
	D3D_FEATURE_LEVEL featureLevel_ = D3D_FEATURE_LEVEL_11_0;


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
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilview
	 */
	ID3D11DepthStencilView* depthStencilView_ = nullptr;


	/**
	 * @brief ������ �� ����� ���� ���ٽ� �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilstate
	 */
	std::unordered_map<std::string, ID3D11DepthStencilState*> depthStencilStates_;


	/**
	 * @brief ������ �� ����� ���� �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nn-d3d11-id3d11blendstate
	 */
	std::unordered_map<std::string, ID3D11BlendState*> blendStates_;


	/**
	 * @brief ������ �� ����� �����Ͷ����� �����Դϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11rasterizerstate
	 */
	std::unordered_map<std::string, ID3D11RasterizerState*> rasterizerStates_;


	/**
	 * @brief ���� �Ŵ������� �����ϴ� ���̴��Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<IShader>> shaders_;
};