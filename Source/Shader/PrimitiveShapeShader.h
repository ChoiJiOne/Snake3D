#pragma once

#include <vector>
#include <unordered_map>

#include "Core/Vertex.h"

#include "Shader/IShader.h"

class Camera3D;


/**
 * @brief 점, 선, 삼각형, 사각형과 같은 기본 도형을 렌더링하는 셰이더입니다.
 * 
 * @note 
 * - 이 셰이더 클래스는 Model이나 Mesh를 인자로 받지 않습니다.
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
class PrimitiveShapeShader : public IShader
{
public:
	/**
	 * @brief 매 프레임 변경되는 상수 버퍼입니다.
	 */
	struct EveryFrameBuffer
	{
		Matrix4x4f view;
		Matrix4x4f projection;
	};


	/**
	 * @brief 기본 도형의 색상 상수 버퍼입니다.
	 */
	struct ShapeColorBuffer
	{
		Vector4f color;
	};


public:
	/**
	 * @brief 점, 선, 삼각형, 사각형과 같은 기본 도형을 렌더링하는 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 초기화를 하기 위해서는 반드시 Initialize 메서드를 호출해야 합니다.
	 */
	PrimitiveShapeShader() = default;


	/**
	 * @brief 점, 선, 삼각형, 사각형과 같은 기본 도형을 렌더링하는 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더 내 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~PrimitiveShapeShader();


	/**
	 * @brief 점, 선, 삼각형, 사각형과 같은 기본 도형을 렌더링하는 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(PrimitiveShapeShader);


	/**
	 * @brief 점, 선, 삼각형, 사각형과 같은 기본 도형을 렌더링하는 셰이더를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 점, 선, 삼각형, 사각형과 같은 기본 도형을 렌더링하는 셰이더를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 2D 선을 백버퍼에 렌더링합니다.
	 * 
	 * @param startPosition 윈도우 상의 2D 선 시작 점입니다.
	 * @param endPosition 윈도우 상의 2D 선 끝 점입니다.
	 * @param color 2D 선의 색상입니다.
	 */
	void DrawLine2D(const Vector2f& startPosition, const Vector2f& endPosition, const Vector4f& color);


	/**
	 * @brief 3D 선을 백버퍼에 렌더링합니다.
	 * 
	 * @param camera 월드 상의 카메라입니다.
	 * @param startPosition 월드 상의 3D 선 시작 점입니다.
	 * @param endPosition 월드 상의 3D 선 끝 점입니다.
	 * @param color 3D 선의 색상입니다.
	 */
	void DrawLine3D(Camera3D* camera, const Vector3f& startPosition, const Vector3f& endPosition, const Vector4f& color);


private:
	/**
	 * @brief 선을 렌더링하기 위한 리소스를 구성합니다.
	 * 
	 * @param device 선에 대응하는 버퍼를 생성하기 위한 D3D11 디바이스입니다.
	 */
	void ConstructResourceForLine(ID3D11Device* device);


private:
	/**
	 * @brief 비정형 메모리인 버퍼 리소스 중 상수 버퍼에 액세스하기 위한 인터페이스입니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;


	/**
	 * @brief 비정형 메모리인 버퍼 리소스 중 상수 버퍼에 액세스하기 위한 인터페이스입니다.
	 *
	 * @see https://learn.microsoft.com/ko-kr/windows/win32/api/d3d11/nn-d3d11-id3d11buffer
	 */
	ID3D11Buffer* shapeColorBuffer_ = nullptr;


	/**
	 * @brief 기본 도형의 정점 목록입니다.
	 */
	std::unordered_map<std::string, std::vector<VertexPosition>> primitiveShapeVertex_;


	/**
	 * @brief 기본 도형의 정점 버퍼입니다.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> primitiveShapeVertexBuffer_;


	/**
	 * @brief 기본 도형의 인덱스 목록입니다.
	 */
	std::unordered_map<std::string, std::vector<uint32_t>> primitiveShapeIndex_;


	/**
	 * @brief 기본 도형의 인덱스 버퍼입니다.
	 */
	std::unordered_map<std::string, ID3D11Buffer*> primitiveShapeIndexBuffer_;
};