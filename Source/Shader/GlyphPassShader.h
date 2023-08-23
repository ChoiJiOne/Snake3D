#pragma once

#include "Core/Vertex.h"

#include "Shader/IShader.h"

struct Glyph;
class TTFont;


/**
 * @brief 글리프를 렌더링하는 셰이더입니다.
 * 
 * 
 * @note
 * - 이 셰이더에서 처리하는 2D의 좌표계는 다음과 같습니다.
 *                y
 *                ▲
 *                │
 *                │
 *                │
 *                │
 *                │
 *                │
 * ───────────────┼───────────────▶x
 *                │
 *                │
 *                │
 *                │
 *                │
 *                │
 */
class GlyphPassShader : public IShader
{
public:
	/**
	 * @brief 매 프레임 변경되는 상수 버퍼입니다.
	 */
	struct EveryFrameBuffer
	{
		Matrix4x4f projection;
	};


	/**
	 * @brief 텍스트의 색상 상수 버퍼입니다.
	 */
	struct TextColorBuffer
	{
		Vector4f color;
	};


public:
	/**
	 * @brief 글리프를 렌더링하는 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 초기화를 하기 위해서는 반드시 Initialize 메서드를 호출해야 합니다.
	 */
	GlyphPassShader() = default;


	/**
	 * @brief 글리프를 렌더링하는 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더 내 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~GlyphPassShader();


	/**
	 * @brief 글리프를 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GlyphPassShader);


	/**
	 * @brief 글리프를 렌더링하는 셰이더를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 글리프를 렌더링하는 셰이더를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 2D 텍스트를 백버퍼에 렌더링합니다.
	 * 
	 * @param font 텍스트를 렌더링할 때 참조할 폰트입니다.
	 * @param text 렌더링할 텍스트입니다.
	 * @param center 2D 좌표계 상의 텍스트 중심 좌표입니다.
	 * @param color 텍스트의 색상입니다.
	 */
	void DrawText2D(TTFont* font, const std::wstring& text, const Vector2f& center, const Vector4f& color);


private:
	/**
	 * @brief 윈도우 창에 대한 직교 투영 행렬을 얻습니다.
	 *
	 * @param nearZ 가까운 클리핑 평면까지의 거리입니다. 기본 값은 0.01f 입니다.
	 * @param farZ 원거리 클리핑 평면까지의 거리입니다. 기본 값은 100.0f 입니다.
	 *
	 * @return 윈도우 창에 대한 직교 투영 행렬을 반환합니다.
	 */
	Matrix4x4f GetWindowOrthographicMatrix(float nearZ = 0.01f, float farZ = 100.0f);


	/**
	 * @brief 정버 버퍼를 글리프에 맞게 업데이트합니다.
	 * 
	 * @param context 버퍼를 업데이트할 때 사용할 컨텍스트입니다.
	 * @param glyph 글리프입니다.
	 * @param glyphAtlasSize 글리프 텍스처 아틀라스의 크기입니다.
	 * @param position 2D 좌표계 상 글리프의 위치입니다.
	 */
	void UpdateGlyphVertexBuffer(ID3D11DeviceContext* context, const Glyph& glyph, float glyphAtlasSize, const Vector2f& position);


private:
	/**
	 * @brief 매 프레임 변경되는 셰이더 내의 상수 버퍼입니다.
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;


	/**
	 * @brief 텍스트 색상을 나타내는 셰이더 내의 상수 버퍼입니다.
	 */
	ID3D11Buffer* textColorBuffer_ = nullptr;


	/**
	 * @brief 텍스처 샘플링을 위한 샘플러 상태입니다.
	 */
	ID3D11SamplerState* linearSamplerState_ = nullptr;


	/**
	 * @brief 글리프의 정점 목록입니다.
	 */
	std::vector<VertexPositionUV> glyphVertex_;


	/**
	 * @brief 글리프의 정점 버퍼입니다.
	 */
	ID3D11Buffer* glyphVertexBuffer_ = nullptr;


	/**
	 * @brief 글리프의 인덱스 목록입니다.
	 */
	std::vector<uint32_t> glyphIndex_;


	/**
	 * @brief 글리프의 인덱스 버퍼입니다.
	 */
	ID3D11Buffer* glyphIndexBuffer_ = nullptr;
};