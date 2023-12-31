#pragma once

#include <array>

#include "Resource/Shader.h"

#include "Utility/Vertex.h"


/**
 * @brief 선, 삼각형, 사각형 등 기본 도형을 렌더링하는 셰이더입니다.
 * 
 * @note 기본 도형 중 2D 도형을 렌더링할 때의 좌표계는 다음과 같습니다.
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
class GeometryShader : public Shader
{
public:
	/**
	 * @brief 기본 도형을 렌더링하는 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	GeometryShader() = default;


	/**
	 * @brief 기본 도형을 렌더링하는 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더의 내부 리소스를 할당 해제하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~GeometryShader();


	/**
	 * @brief 기본 도형을 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GeometryShader);


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
	 * @brief 화면에 3D 선을 그립니다.
	 * 
	 * @param view 시야 행렬입니다.
	 * @param projection 원근 투영 행렬입니다.
	 * @param fromPosition 월드 상 3D 선의 시작 점입니다.
	 * @param toPosition 월드 상 3D 선의 끝 점입니다.
	 * @param color 3D 선의 색상입니다.
	 */
	void DrawLine3D(
		const glm::mat4& view, 
		const glm::mat4& projection, 
		const glm::vec3& fromPosition, 
		const glm::vec3& toPosition, 
		const glm::vec4& color
	);


	/**
	 * @brief 화면에 2D 선을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param fromPosition 스크린 상 2D 선의 시작 점입니다.
	 * @param toPosition 스크린 상 2D 선의 끝 점입니다.
	 * @param color 2D 선의 색상입니다.
	 */
	void DrawLine2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec2& toPosition, const glm::vec4& color);


	/**
	 * @brief 화면에 2D 삼각형을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param color 2D 삼각형의 색상입니다.
	 */
	void DrawTriangle2D(
		const glm::mat4& projection, 
		const glm::vec2& fromPosition, 
		const glm::vec2& byPosition,
		const glm::vec2& toPosition, 
		const glm::vec4& color
	);


	/**
	 * @brief 화면에 2D 삼각형을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param fromColor 2D 좌표계 상 삼각형 시작 점의 색상입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param byColor 2D 좌표계 상 삼각형 중간 점의 색상입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param toColor 2D 좌표계 상 삼각형 끝 점의 색상입니다.
	 */
	void DrawTriangle2D(
		const glm::mat4& projection,
		const glm::vec2& fromPosition,
		const glm::vec4& fromColor,
		const glm::vec2& byPosition,
		const glm::vec4& byColor,
		const glm::vec2& toPosition,
		const glm::vec4& toColor
	);


	/**
	 * @brief 화면에 2D 와이어 프레임 삼각형을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param color 2D 삼각형의 색상입니다.
	 */
	void DrawWireframeTriangle2D(
		const glm::mat4 & projection,
		const glm::vec2 & fromPosition,
		const glm::vec2 & byPosition,
		const glm::vec2 & toPosition,
		const glm::vec4 & color
	);


	/**
	 * @brief 화면에 2D 와이어 프레임 삼각형을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param fromPosition 2D 좌표계 상의 삼각형 시작 점입니다.
	 * @param fromColor 2D 좌표계 상 삼각형 시작 점의 색상입니다.
	 * @param byPosition 2D 좌표계 상의 삼각형 중간 점입니다.
	 * @param byColor 2D 좌표계 상 삼각형 중간 점의 색상입니다.
	 * @param toPosition 2D 좌표계 상의 삼각형 끝 점입니다.
	 * @param toColor 2D 좌표계 상 삼각형 끝 점의 색상입니다.
	 */
	void DrawWireframeTriangle2D(
		const glm::mat4& projection,
		const glm::vec2& fromPosition,
		const glm::vec4& fromColor,
		const glm::vec2& byPosition,
		const glm::vec4& byColor,
		const glm::vec2& toPosition,
		const glm::vec4& toColor
	);


	/**
	 * @brief 화면에 2D 사각형을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param center 2D 사각형의 중심 좌표입니다.
	 * @param width 2D 사각형의 가로 크기입니다.
	 * @param heigt 2D 사각형의 세로 크기입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void DrawRectangle2D(const glm::mat4& projection, const glm::vec2& center, float width, float height, const glm::vec4& color);


	/**
	 * @brief 화면에 2D 사각형을 그립니다.
	 * 
	 * @param projection 직교 투영 행렬입니다.
	 * @param leftTopPosition 2D 사각형의 왼쪽 상단 좌표입니다.
	 * @param rightBottomPosition 2D 사각형의 오른쪽 하단 좌표입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void DrawRectangle2D(
		const glm::mat4& projection, 
		const glm::vec2& leftTopPosition, 
		const glm::vec2& rightBottomPosition, 
		const glm::vec4& color
	);


	/**
	 * @brief 화면에 2D 와이어 프레임 사각형을 그립니다.
	 *
	 * @param projection 직교 투영 행렬입니다.
	 * @param center 2D 사각형의 중심 좌표입니다.
	 * @param width 2D 사각형의 가로 크기입니다.
	 * @param heigt 2D 사각형의 세로 크기입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void DrawWireframeRectangle2D(
		const glm::mat4& projection, 
		const glm::vec2& center, 
		float width, 
		float height, 
		const glm::vec4& color
	);


	/**
	 * @brief 화면에 2D 와이어 프레임 사각형을 그립니다.
	 *
	 * @param projection 직교 투영 행렬입니다.
	 * @param leftTopPosition 2D 사각형의 왼쪽 상단 좌표입니다.
	 * @param rightBottomPosition 2D 사각형의 오른쪽 하단 좌표입니다.
	 * @param color 2D 사각형의 색상입니다.
	 */
	void DrawWireframeRectangle2D(
		const glm::mat4& projection, 
		const glm::vec2& leftTopPosition, 
		const glm::vec2& rightBottomPosition, 
		const glm::vec4& color
	);


private:
	/**
	 * @brief 기본 도형을 그리기 위한 모드를 나타내는 열거형입니다.
	 */
	enum class ERenderMode : int32_t
	{
		LineStrip = 0x0003,
		Triangle  = 0x0004,
	};


	/**
	 * @brief 버텍스 버퍼를 업데이트합니다.
	 */
	void UpdateVertexBuffer();


	/**
	 * @brief 기본 도형을 화면에 그립니다.
	 * 
	 * @param view 시야 행렬입니다. 2D의 경우 단위 행렬로 설정해야 합니다.
	 * @param projection 투영 행렬입니다. 2D의 경우 직교 투영 행렬로 설정해야 합니다.
	 * @param renderMode 기본 도형을 그리기 위한 렌더링 모드입니다.
	 * @param vertexCount 기본 도형의 정점 수입니다.
	 */
	void DrawGeometry(const glm::mat4& view, const glm::mat4& projection, const ERenderMode& renderMode, int32_t vertexCount);


private:
	/**
	 * @brief 도형 정점 목록의 최대 크기입니다.
	 */
	static const int32_t MAX_VERTEX_SIZE = 6;


	/**
	 * @brief 도형의 정점 목록입니다.
	 */
	std::array<VertexPositionColor, MAX_VERTEX_SIZE> vertices_;


	/**
	 * @brief 정점 버퍼의 오브젝트입니다.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief 정점 버퍼 목록의 오브젝트입니다.
	 */
	uint32_t vertexArrayObject_ = 0;
};