#pragma once

#include <cstdint>

#include <glm/glm.hpp>

#include "Manager/IManager.h"

// ������Ʈ
class Camera3D;
class Light;

// ���ҽ�
class CubeMap;
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
	 * @brief ���� ������ Ȱ��ȭ�մϴ�.
	 * 
	 * @param bIsEnable ���� ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetAlphaBlend(bool bIsEnable);


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
	 * @brief 2D ���� ȭ�鿡 �׸��ϴ�.
	 *
	 * @param fromPosition 2D ��ũ�� �� ���� ���� ���Դϴ�.
	 * @param toPosition 2D ��ũ�� �� ���� �� ���Դϴ�.
	 * @param color 2D ���� �����Դϴ�.
	 */
	void RenderLine2D(const glm::vec2& fromPosition, const glm::vec2& toPosition, const glm::vec4& color);


	/**
	 * @brief 2D �ﰢ���� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param color 2D �ﰢ���� �����Դϴ�.
	 */
	void RenderTriangle2D(const glm::vec2& fromPosition, const glm::vec2& byPosition, const glm::vec2& toPosition, const glm::vec4& color);


	/**
	 * @brief 2D �ﰢ���� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param fromColor 2D ��ǥ�� �� �ﰢ�� ���� ���� �����Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param byColor 2D ��ǥ�� �� �ﰢ�� �߰� ���� �����Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param toColor 2D ��ǥ�� �� �ﰢ�� �� ���� �����Դϴ�.
	 */
	void RenderTriangle2D(
		const glm::vec2& fromPosition,
		const glm::vec4& fromColor,
		const glm::vec2& byPosition,
		const glm::vec4& byColor,
		const glm::vec2& toPosition,
		const glm::vec4& toColor
	);
	

	/**
	 * @brief 3D ���� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param fromPosition ���� �� 3D ���� ���� ���Դϴ�.
	 * @param toPosition ���� �� 3D ���� �� ���Դϴ�.
	 * @param color 3D ���� �����Դϴ�.
	 */
	void RenderLine3D(Camera3D* camera, const glm::vec3& fromPosition, const glm::vec3& toPosition, const glm::vec4& color);

	
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
	 * @brief ť����� ����ۿ� �������մϴ�.
	 * 
	 * @param camera ���� ���� ī�޶��Դϴ�.
	 * @param cubeMap ť��� ���ҽ��Դϴ�.
	 */
	void RenderCubeMap(Camera3D* camera, CubeMap* cubeMap);


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
	 * @brief ť��ʿ� �����ϴ� ���� ���ۿ� ���� ��� ������Ʈ�� �����մϴ�.
	 */
	void CreateCubeMapVertexArray();


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
	 * @brief ����Ʈ ���μ��� ȿ���� ����ߴ��� Ȯ���մϴ�.
	 */
	bool bIsUsePostProcessing_ = false;


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


	/**
	 * @brief ��ũ�� ���ؽ��� ī��Ʈ�Դϴ�.
	 */
	uint32_t screenVertexCount_ = 0;


	/**
	 * @brief ť����� ���ؽ� ���� ID�Դϴ�.
	 */
	uint32_t cubeMapVertexBuffer_ = 0;


	/**
	 * @brief ť��� ���ؽ� �迭�� ID�Դϴ�.
	 */
	uint32_t cubeMapVertexArray_ = 0;


	/**
	 * @brief ť��� ���ؽ��� ī��Ʈ�Դϴ�.
	 */
	uint32_t cubeMapVertexCount_ = 0;
};