#pragma once

#include <vector>

#include "Utility/Vertex.h"


/**
 * @brief ������Ʈ���� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ���� �� ��� ������ ����(static)�Դϴ�.
 */
class GeometryGenerator
{
public:
	/**
	 * @brief ��ġ ��ǥ�� �븻(����) ������ ���Ե� ������ �ڽ��� �����մϴ�.
	 *
	 * @param xsize �ڽ��� x �� ���������� ũ���Դϴ�.
	 * @param ysize �ڽ��� y �� ���������� ũ���Դϴ�.
	 * @param zsize �ڽ��� z �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ �ڽ��� ���� ����Դϴ�.
	 * @param outIndices ������ �ڽ� ������ �ε��� ����Դϴ�.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);
};