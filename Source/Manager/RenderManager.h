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


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


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
};