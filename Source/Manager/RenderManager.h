#pragma once

#include <cstdint>

#include <glm/glm.hpp>

#include "Manager/IManager.h"

// ������Ʈ
class Camera3D;
class Light;

// ���ҽ�
class Material;
class Mesh;
class Model;
class Shader;

// ��ƿ��Ƽ
class Window;


/**
 * @brief ������ ó���� �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱��� Ŭ�����Դϴ�.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(RenderManager);


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�մϴ�.
	 * 
	 * @param renderTargetWindow ������ ����� �Ǵ� �������Դϴ�.
	 */
	void Initialize(Window* renderTargetWindow);


	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ �������� �����մϴ�.
	 * 
	 * @param red ���� ������ R ���Դϴ�.
	 * @param green ���� ������ G ���Դϴ�.
	 * @param blue ���� ������ B ���Դϴ�.
	 * @param alpha ���� ������ A ���Դϴ�.
	 * @param depth ���� ������ �ʱ�ȭ ���Դϴ�.
	 * @param stencil ���ٽ� ������ �ʱ�ȭ ���Դϴ�.
	 */
	void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief ������ �������� �����ϰ� ����ۿ� ����Ʈ���۸� �����մϴ�.
	 */
	void EndFrame();


	/**
	 * @brief ���� ����ȭ ���θ� �����մϴ�.
	 *
	 * @param bIsEnable ���� ����ȭ �����Դϴ�.
	 */
	void SetVsyncMode(bool bIsEnable);


	/**
	 * @brief ���� �׽�Ʈ�� Ȱ��ȭ ���θ� �����մϴ�.
	 * 
	 * @param bIsEnable ���� �׽�Ʈ Ȱ��ȭ �����Դϴ�.
	 */
	void SetDepthMode(bool bIsEnable);


	/**
	 * @brief ����Ʈ�� �����մϴ�.
	 * 
	 * @param x ����Ʈ �簢���� ���� ��� x��ǥ�Դϴ�.
	 * @param y ����Ʈ �簢���� ���� ��� y��ǥ�Դϴ�.
	 * @param width ����Ʈ �簢���� ���� ũ���Դϴ�.
	 * @param height ����Ʈ �簢���� ���� ũ���Դϴ�.
	 */
	void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height);


	/**
	 * @brief ������ ��� ������ ũ���� ����Ʈ�� �����մϴ�.
	 */
	void SetRenderTargetWindowViewport();
	

	/**
	 * @brief ������ ����� ������ ũ�⸦ ����ϴ�.
	 * 
	 * @param outWidth[out] ������ ����� ������ ���� ũ���Դϴ�.
	 * @param outHeight[out] ������ ����� ������ ���� ũ���Դϴ�.
	 */
	void GetRenderTargetWindowSize(int32_t& outWidth, int32_t& outHeight);


	/**
	 * @brief ������ ����� ������ ����:���� �������� ����ϴ�.
	 * 
	 * @return ������ ����� ������ ����:���� �������� ��ȯ�մϴ�.
	 */
	float GetRenderTargetWindowAspectRatio();


	/**
	 * @brief 3D ���� ����ۿ� �������մϴ�.
	 * 
	 * @param world ���� ���� ����Դϴ�.
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param model �������� ���Դϴ�.
	 * @param light ���� ������ ���� ����Ʈ�Դϴ�.
	 */
	void RenderModel3D(const glm::mat4& world, Camera3D* camera, Model* model, Light* light);


	/**
	 * @brief ������ ���ۿ� �帮�� ȿ���� �ο��մϴ�.
	 * 
	 * @note �帮�� ȿ���� ����ġ�� 0�� ������� ���� ���� �������, 0�� �־������� ������� ���մϴ�.
	 * 
	 * @param bias 0.0f ���� ū �帮�� ȿ���� ����ġ�Դϴ�.
	 */
	void BlurEffect(float bias);


	/**
	 * @brief ������ ���ۿ� ���� ����ġ ȿ���� �ο��մϴ�.
	 * 
	 * @param redBias RGB �� R���� ����ġ�Դϴ�.
	 * @param greenBias RGB �� G���� ����ġ�Դϴ�.
	 * @param blueBias RGB �� B���� ����ġ�Դϴ�.
	 */
	void ColorEffect(float redBias, float greenBias, float blueBias);


	/**
	 * @brief ������ ������ ������ ���� ������ ȿ���� �ο��մϴ�.
	 */
	void InversionEffect();


	/**
	 * @brief ������ ���ۿ� �׷��� ������ ȿ���� �ο��մϴ�.
	 */
	void GrayScaleEffect();
	

private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


	/**
	 * @brief ��ũ���� �����ϴ� ���� ���ۿ� ���� ��� ������Ʈ�� �����մϴ�.
	 */
	void CreateScreenVertexArray();


	/**
	 * @brief ���� Ÿ�� ������ ���۸� �����մϴ�.
	 */
	void CreateRenderTargetFramebuffer();


	/**
	 * @brief ȭ�鿡 ����Ʈ ���μ��� ȿ���� �ο��մϴ�.
	 */
	void EffectPostProcessing();


private:
	/**
	 * @brief ������ ����� �Ǵ� �������Դϴ�.
	 */
	Window* renderTargetWindow_ = nullptr;


	/**
	 * @brief ���� ����ȭ Ȱ��ȭ �����Դϴ�.
	 */
	bool bEnableVsync_ = true;


	/**
	 * @brief OpenGL�� �� �����Դϴ�.
	 */
	const int32_t majorVersion_ = 4;


	/**
	 * @brief OpenGL�� �� �����Դϴ�.
	 */
	const int32_t minorVersion_ = 5;


	/**
	 * @brief ���� Ÿ�� ������ �����Դϴ�.
	 */
	uint32_t renderTargetFrameBuffer_ = 0;


	/**
	 * @brief ���� Ÿ�� �÷� �����Դϴ�.
	 */
	uint32_t renderTargetColorBuffer_ = 0;


	/**
	 * @brief ���� Ÿ�� ����-���ٽ� �����Դϴ�.
	 */
	uint32_t renderTargetDepthStencilBuffer_ = 0;


	/**
	 * @brief ��ũ�� ���ؽ� ������ ID �Դϴ�.
	 */
	uint32_t screenVertexBuffer_ = 0;


	/**
	 * @brief ��ũ�� ���ؽ� �迭�� ID �Դϴ�.
	 */
	uint32_t screenVertexArray_ = 0;
};