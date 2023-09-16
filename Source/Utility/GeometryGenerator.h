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
	 * @brief 위치 좌표와 노말(법선) 정보가 포함된 정점의 박스를 생성합니다.
	 *
	 * @param xsize 박스의 x 축 방향으로의 크기입니다.
	 * @param ysize 박스의 y 축 방향으로의 크기입니다.
	 * @param zsize 박스의 z 축 방향으로의 크기입니다.
	 * @param outVertices 생성된 박스의 정점 목록입니다.
	 * @param outIndices 생성된 박스 정점의 인덱스 목록입니다.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);
};