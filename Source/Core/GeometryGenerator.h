#pragma once

#include <vector>

#include "Core/Vertex.h"

#include "Vector/Vector.h"


/**
 * @brief 버텍스와 인덱스 목록을 생성합니다.
 * 
 * @note 이 클래스는 모든 변수 및 멤버 변수가 정적인 정적(static) 클래스입니다.
 */
class GeometryGenerator
{
public:
	/**
	 * @brief 위치 좌표가 포함된 정점의 박스를 생성합니다.
	 *
	 * @param xsize 박스의 x 축 방향으로의 크기입니다.
	 * @param ysize 박스의 y 축 방향으로의 크기입니다.
	 * @param zsize 박스의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 박스의 정점 목록입니다.
	 * @param outIndices 생성된 박스 정점의 인덱스 목록입니다.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 위치 좌표와 색상이 포함된 정점의 박스를 생성합니다.
	 *
	 * @param xsize 박스의 x 축 방향으로의 크기입니다.
	 * @param ysize 박스의 y 축 방향으로의 크기입니다.
	 * @param zsize 박스의 z 축 방향으로의 크기입니다.
	 * @param color 박스의 색상입니다.
	 * @param outVertices 생성된 박스의 정점 목록입니다.
	 * @param outIndices 생성된 박스 정점의 인덱스 목록입니다.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, const Vector4f& color, std::vector<VertexPositionColor>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 위치 좌표가 포함된 XY평면 쿼드를 생성합니다.
	 *
	 * @param xsize 쿼드의 x 축 뱡향으로의 크기입니다.
	 * @param ysize 쿼드의 y 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 쿼드의 정점 목록입니다.
	 * @param outIndices 생성된 쿼드의 정점의 인덱스 목록입니다.
	 */
	static void CreateQuadXY(float xsize, float ysize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 위치 좌표가 포함된 YZ평면 쿼드를 생성합니다.
	 *
	 * @param ysize 쿼드의 y 축 방향으로의 크기입니다.
	 * @param zsize 쿼드의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 쿼드의 정점 목록입니다.
	 * @param outIndices 생성된 쿼드의 정점의 인덱스 목록입니다.
	 */
	static void CreateQuadYZ(float ysize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 위치 좌표가 포함된 XZ평면 쿼드를 생성합니다.
	 *
	 * @param xsize 쿼드의 x 축 뱡향으로의 크기입니다.
	 * @param zsize 쿼드의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 쿼드의 정점 목록입니다.
	 * @param outIndices 생성된 쿼드의 정점의 인덱스 목록입니다.
	 */
	static void CreateQuadXZ(float xsize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);
};