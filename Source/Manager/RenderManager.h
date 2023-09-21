#pragma once

#include <cstdint>

#include <glm/glm.hpp>

#include "Manager/IManager.h"

// 오브젝트
class Camera3D;
class Light;

// 리소스
class CubeMap;
class Material;
class Mesh;
class Model;
class Shader;

// 유틸리티
class Window;


/**
 * @brief 렌더링 처리를 수행하는 매니저입니다.
 * 
 * @note 이 클래스는 싱글턴 클래스입니다.
 */
class RenderManager : public IManager
{
public:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(RenderManager);


	/**
	 * @brief 렌더링 처리를 수행하는 매니저를 초기화합니다.
	 * 
	 * @param renderTargetWindow 렌더링 대상이 되는 윈도우입니다.
	 */
	void Initialize(Window* renderTargetWindow);


	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 프레임 렌더링을 시작합니다.
	 * 
	 * @param red 색상 버퍼의 R 값입니다.
	 * @param green 색상 버퍼의 G 값입니다.
	 * @param blue 색상 버퍼의 B 값입니다.
	 * @param alpha 색상 버퍼의 A 값입니다.
	 * @param depth 깊이 버퍼의 초기화 값입니다.
	 * @param stencil 스텐실 버퍼의 초기화 값입니다.
	 */
	void BeginFrame(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief 프레임 렌더링을 종료하고 백버퍼와 프론트버퍼를 스왑합니다.
	 */
	void EndFrame();


	/**
	 * @brief 수직 동기화 여부를 설정합니다.
	 *
	 * @param bIsEnable 수직 동기화 여부입니다.
	 */
	void SetVsyncMode(bool bIsEnable);


	/**
	 * @brief 깊이 테스트를 활성화 여부를 설정합니다.
	 * 
	 * @param bIsEnable 깊이 테스트 활성화 여부입니다.
	 */
	void SetDepthMode(bool bIsEnable);


	/**
	 * @brief 알파 블랜딩을 활성화합니다.
	 * 
	 * @param bIsEnable 알파 블랜딩 활성화 여부입니다.
	 */
	void SetAlphaBlend(bool bIsEnable);


	/**
	 * @brief 뷰포트를 설정합니다.
	 * 
	 * @param x 뷰포트 사각형의 왼쪽 상단 x좌표입니다.
	 * @param y 뷰포트 사각형의 왼쪽 상단 y좌표입니다.
	 * @param width 뷰포트 사각형의 가로 크기입니다.
	 * @param height 뷰포트 사각형의 세로 크기입니다.
	 */
	void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height);


	/**
	 * @brief 렌더링 대상 윈도우 크기의 뷰포트를 설정합니다.
	 */
	void SetRenderTargetWindowViewport();
	

	/**
	 * @brief 렌더링 대상의 윈도우 크기를 얻습니다.
	 * 
	 * @param outWidth[out] 렌더링 대상의 윈도우 가로 크기입니다.
	 * @param outHeight[out] 렌더링 대상의 윈도우 세로 크기입니다.
	 */
	void GetRenderTargetWindowSize(int32_t& outWidth, int32_t& outHeight);


	/**
	 * @brief 렌더링 대상의 윈도우 가로:세로 비율값을 얻습니다.
	 * 
	 * @return 렌더링 대상의 윈도우 가로:세로 비율값을 반환합니다.
	 */
	float GetRenderTargetWindowAspectRatio();


	/**
	 * @brief 2D 선을 화면에 그립니다.
	 *
	 * @param fromPosition 2D 스크린 상 선의 시작 점입니다.
	 * @param toPosition 2D 스크린 상 선의 끝 점입니다.
	 * @param color 2D 선의 색상입니다.
	 */
	void RenderLine2D(const glm::vec2& fromPosition, const glm::vec2& toPosition, const glm::vec4& color);


	/**
	 * @brief 2D 삼각형을 화면에 그립니다.
	 * 
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param color 2D 삼각형의 색상입니다.
	 */
	void RenderTriangle2D(const glm::vec2& fromPosition, const glm::vec2& byPosition, const glm::vec2& toPosition, const glm::vec4& color);


	/**
	 * @brief 2D 삼각형을 화면에 그립니다.
	 * 
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param fromColor 2D 좌표계 상 삼각형 시작 점의 색상입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param byColor 2D 좌표계 상 삼각형 중간 점의 색상입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param toColor 2D 좌표계 상 삼각형 끝 점의 색상입니다.
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
	 * @brief 2D 와이어 프레임 삼각형을 화면에 그립니다.
	 *
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param color 2D 삼각형의 색상입니다.
	 */
	void RenderWireframeTriangle2D(const glm::vec2& fromPosition, const glm::vec2& byPosition, const glm::vec2& toPosition, const glm::vec4& color);
	

	/**
	 * @brief 2D 와이어 프레임 삼각형을 화면에 그립니다.
	 *
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param fromColor 2D 좌표계 상 삼각형 시작 점의 색상입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param byColor 2D 좌표계 상 삼각형 중간 점의 색상입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param toColor 2D 좌표계 상 삼각형 끝 점의 색상입니다.
	 */
	void RenderWireframeTriangle2D(
		const glm::vec2& fromPosition,
		const glm::vec4& fromColor,
		const glm::vec2& byPosition,
		const glm::vec4& byColor,
		const glm::vec2& toPosition,
		const glm::vec4& toColor
	);


	/**
	 * @brief 2D 사각형을 화면에 그립니다.
	 * 
	 * @param center 2D 사각형의 중심 좌표입니다.
	 * @param rectWidth 2D 사각형의 가로 크기입니다.
	 * @param rectHeight 2D 사각형의 세로 크기입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void RenderRectangle2D(const glm::vec2& center, float rectWidth, float rectHeight, const glm::vec4& color);


	/**
	 * @brief 2D 사각형을 화면에 그립니다.
	 *
	 * @param projection 투영 행렬입니다.
	 * @param leftTopPosition 2D 사각형의 왼쪽 상단 좌표입니다.
	 * @param rightBottomPosition 2D 사각형의 오른쪽 하단 좌표입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void RenderRectangle2D(const glm::vec2& leftTopPosition, const glm::vec2& rightBottomPosition, const glm::vec4& color);


	/**
	 * @brief 2D 와이어 프레임 사각형을 화면에 그립니다.
	 *
	 * @param center 2D 사각형의 중심 좌표입니다.
	 * @param rectWidth 2D 사각형의 가로 크기입니다.
	 * @param rectHeight 2D 사각형의 세로 크기입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void RenderWireframeRectangle2D(const glm::vec2& center, float rectWidth, float rectHeight, const glm::vec4& color);
		

	/**
	 * @brief 3D 선을 화면에 그립니다.
	 * 
	 * @param camera 월드 상의 카메라입니다.
	 * @param fromPosition 월드 상 3D 선의 시작 점입니다.
	 * @param toPosition 월드 상 3D 선의 끝 점입니다.
	 * @param color 3D 선의 색상입니다.
	 */
	void RenderLine3D(Camera3D* camera, const glm::vec3& fromPosition, const glm::vec3& toPosition, const glm::vec4& color);

	
	/**
	 * @brief 3D 모델을 백버퍼에 렌더링합니다.
	 * 
	 * @param world 모델의 월드 행렬입니다.
	 * @param camera 월드 상의 카메라입니다.
	 * @param model 렌더링할 모델입니다.
	 * @param light 모델이 영향을 받을 라이트입니다.
	 */
	void RenderModel3D(const glm::mat4& world, Camera3D* camera, Model* model, Light* light);

	
	/**
	 * @brief 큐브맵을 백버퍼에 렌더링합니다.
	 * 
	 * @param camera 월드 상의 카메라입니다.
	 * @param cubeMap 큐브맵 리소스입니다.
	 */
	void RenderCubeMap(Camera3D* camera, CubeMap* cubeMap);


	/**
	 * @brief 프레임 버퍼에 흐리기 효과를 부여합니다.
	 * 
	 * @note 흐리기 효과의 가중치는 0에 가까워질 수록 더욱 흐려지고, 0에 멀어질수록 흐려짐이 약합니다.
	 * 
	 * @param bias 0.0f 보다 큰 흐리기 효과의 가중치입니다.
	 */
	void BlurEffect(float bias);


	/**
	 * @brief 프레임 버퍼에 색상 가중치 효과를 부여합니다.
	 * 
	 * @param redBias RGB 중 R값의 가중치입니다.
	 * @param greenBias RGB 중 G값의 가중치입니다.
	 * @param blueBias RGB 중 B값의 가중치입니다.
	 */
	void ColorEffect(float redBias, float greenBias, float blueBias);


	/**
	 * @brief 프레임 버퍼의 색상을 전부 뒤집는 효과를 부여합니다.
	 */
	void InversionEffect();


	/**
	 * @brief 프레임 버퍼에 그레이 스케일 효과를 부여합니다.
	 */
	void GrayScaleEffect();
	

private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(RenderManager);


	/**
	 * @brief 스크린에 대응하는 정점 버퍼와 정점 목록 오브젝트를 생성합니다.
	 */
	void CreateScreenVertexArray();


	/**
	 * @brief 큐브맵에 대응하는 정점 버퍼와 정점 목록 오브젝트를 생성합니다.
	 */
	void CreateCubeMapVertexArray();


	/**
	 * @brief 렌더 타겟 프레임 버퍼를 생성합니다.
	 */
	void CreateRenderTargetFramebuffer();


	/**
	 * @brief 화면에 포스트 프로세싱 효과를 부여합니다.
	 */
	void EffectPostProcessing();


private:
	/**
	 * @brief 렌더링 대상이 되는 윈도우입니다.
	 */
	Window* renderTargetWindow_ = nullptr;


	/**
	 * @brief 수직 동기화 활성화 여부입니다.
	 */
	bool bEnableVsync_ = true;

	
	/**
	 * @brief 포스트 프로세싱 효과를 사용했는지 확인합니다.
	 */
	bool bIsUsePostProcessing_ = false;


	/**
	 * @brief OpenGL의 주 버전입니다.
	 */
	const int32_t majorVersion_ = 4;


	/**
	 * @brief OpenGL의 부 버전입니다.
	 */
	const int32_t minorVersion_ = 5;


	/**
	 * @brief 렌더 타겟 프레임 버퍼입니다.
	 */
	uint32_t renderTargetFrameBuffer_ = 0;


	/**
	 * @brief 렌더 타겟 컬러 버퍼입니다.
	 */
	uint32_t renderTargetColorBuffer_ = 0;


	/**
	 * @brief 렌더 타겟 깊이-스텐실 버퍼입니다.
	 */
	uint32_t renderTargetDepthStencilBuffer_ = 0;


	/**
	 * @brief 스크린 버텍스 버퍼의 ID 입니다.
	 */
	uint32_t screenVertexBuffer_ = 0;


	/**
	 * @brief 스크린 버텍스 배열의 ID 입니다.
	 */
	uint32_t screenVertexArray_ = 0;


	/**
	 * @brief 스크린 버텍스의 카운트입니다.
	 */
	uint32_t screenVertexCount_ = 0;


	/**
	 * @brief 큐브맵의 버텍스 버퍼 ID입니다.
	 */
	uint32_t cubeMapVertexBuffer_ = 0;


	/**
	 * @brief 큐브맵 버텍스 배열의 ID입니다.
	 */
	uint32_t cubeMapVertexArray_ = 0;


	/**
	 * @brief 큐브맵 버텍스의 카운트입니다.
	 */
	uint32_t cubeMapVertexCount_ = 0;
};