#pragma once

#include <array>

#include "Resource/Shader.h"

#include "Utility/Vertex.h"

struct Glyph;
class TTFont;


/**
 * @brief 글리프를 이용해서 텍스트를 렌더링하는 셰이더입니다.
 *
 * @note
 * - 삼각형의 방향은 오른손 기준 CCW입니다.
 * - 2차원 좌표계는 다음과 같습니다.
 * ┼────────────────────▶ +x
 * │
 * │
 * │
 * │
 * │
 * │
 * │
 * ▼
 * +y
 */
class GlyphShader : public Shader
{
public:
	/**
	 * @brief 글리프를 이용해서 텍스트를 렌더링하는 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	GlyphShader() = default;


	/**
	 * @brief 글리프를 이용해서 텍스트를 렌더링하는 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더의 내부 리소스를 할당 해제하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~GlyphShader();


	/**
	 * @brief 글리프를 이용해서 텍스트를 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GlyphShader);


	/**
	 * @brief GLSL 셰이더를 컴파일하고 셰이더 프로그램을 생성합니다.
	 *
	 * @param vsFile 버텍스 셰이더의 확장자(.vert)를 포함한 이름입니다.
	 * @param fsFile 프레그먼트 셰이더의 확장자(.frag)를 포함한 이름입니다.
	 */
	virtual void Initialize(const std::string& vsFile, const std::string& fsFile) override;


	/**
	 * @brief 셰이더 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 2D 텍스트를 백버퍼에 렌더링합니다.
	 *
	 * @param projection 직교 투영 행렬입니다.
	 * @param font 텍스트를 렌더링할 때 참조할 폰트입니다.
	 * @param text 렌더링할 텍스트입니다.
	 * @param center 2D 좌표계 상의 텍스트 중심 좌표입니다.
	 * @param color 텍스트의 RGB 색상입니다.
	 */
	void DrawText2D(const glm::mat4& projection, TTFont* font, const std::wstring& text, const glm::vec2& center, const glm::vec3& color);


private:
	/**
	 * @brief 글리프 정보를 이용해서 정버 버퍼를 업데이트합니다.
	 * 
	 * @param glyph 글리프입니다.
	 * @param glyphAtlasSize 글리프 아틀라스 크기입니다.
	 * @param position 2D 좌표계 상의 글리프 위치입니다.
	 */
	void UpdateGlyphVertexBuffer(const Glyph& glyph, float glyphAtlasSize, const glm::vec2& position);

	
private:
	/**
	 * @brief 버텍스 버퍼를 업데이트합니다.
	 */
	void UpdateVertexBuffer();


private:
	/**
	 * @brief 글리프 정점 목록의 최대 크기입니다.
	 */
	static const int32_t MAX_VERTEX_SIZE = 6;


	/**
	 * @brief 글리프 정점 목록입니다.
	 */
	std::array<VertexPositionTexture, MAX_VERTEX_SIZE> glyphVertices_;


	/**
	 * @brief 글리프 정점 버퍼의 오브젝트입니다.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief 글리프 정점 버퍼 목록의 오브젝트입니다.
	 */
	uint32_t vertexArrayObject_ = 0;
};