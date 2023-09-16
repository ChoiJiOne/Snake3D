#pragma once

#include <vector>

#include "Utility/Vertex.h"


/**
 * @brief 지오메트리를 생성합니다.
 * 
 * @note 이 클래스는 모든 변수 및 멤버 변수가 정적(static)입니다.
 */
class GeometryGenerator
{
public:
	/**
	 * @brief XY평면 쿼드를 생성합니다.
	 * 
	 * @param xsize 쿼드의 x 축 방향으로의 크기입니다.
	 * @param ysize 쿼드의 y 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 쿼드의 정점 목록입니다.
	 * @param outIndices 생성된 쿼드 정점의 인덱스 목록입니다.
	 */
	static void CreateXYQuad(float xsize, float ysize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief YZ평면 쿼드를 생성합니다.
	 * 
	 * @param ysize 쿼드의 y 축 방향으로의 크기입니다.
	 * @param zsize 쿼드의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 쿼드의 정점 목록입니다.
	 * @param outIndices 생성된 쿼드 정점의 인덱스 목록입니다.
	 */
	static void CreateYZQuad(float ysize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief ZX평면 쿼드를 생성합니다.
	 * 
	 * @param xsize 쿼드의 x 축 방향으로의 크기입니다.
	 * @param ysize 쿼드의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 쿼드의 정점 목록입니다.
	 * @param outIndices 생성된 쿼드 정점의 인덱스 목록입니다.
	 */
	static void CreateXZQuad(float xsize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 위치 좌표와 노말(법선) 정보가 포함된 정점의 박스를 생성합니다.
	 *
	 * @param xsize 박스의 x 축 방향으로의 크기입니다.
	 * @param ysize 박스의 y 축 방향으로의 크기입니다.
	 * @param zsize 박스의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 박스의 정점 목록입니다.
	 * @param outIndices 생성된 박스 정점의 인덱스 목록입니다.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief 위치 좌표와 노말(법선) 정보가 포함된 구를 생성합니다.
	 * 
	 * @param radius 구의 반지름 길이입니다.
	 * @param sliceCount 구의 슬라이스 카운트입니다.
	 * @param stackCount 구의 스택 카운트입니다.
	 * @param outVertices 생성된 구의 정점 목록입니다.
	 * @param outIndices 생성된 구의 정점 인덱스 목록입니다.
	 */
	static void CreateSphere(float radius, uint32_t sliceCount, uint32_t stackCount, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);
};