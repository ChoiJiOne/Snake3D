#pragma once

#include <vector>

#include "Core/Vertex.h"

#include "Vector/Vector.h"


/**
 * @brief ���ؽ��� �ε��� ����� �����մϴ�.
 * 
 * @note �� Ŭ������ ��� ���� �� ��� ������ ������ ����(static) Ŭ�����Դϴ�.
 */
class GeometryGenerator
{
public:
	/**
	 * @brief ��ġ ��ǥ�� ���Ե� ������ �ڽ��� �����մϴ�.
	 *
	 * @param xsize �ڽ��� x �� ���������� ũ���Դϴ�.
	 * @param ysize �ڽ��� y �� ���������� ũ���Դϴ�.
	 * @param zsize �ڽ��� z �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ �ڽ��� ���� ����Դϴ�.
	 * @param outIndices ������ �ڽ� ������ �ε��� ����Դϴ�.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief ��ġ ��ǥ�� ������ ���Ե� ������ �ڽ��� �����մϴ�.
	 *
	 * @param xsize �ڽ��� x �� ���������� ũ���Դϴ�.
	 * @param ysize �ڽ��� y �� ���������� ũ���Դϴ�.
	 * @param zsize �ڽ��� z �� ���������� ũ���Դϴ�.
	 * @param color �ڽ��� �����Դϴ�.
	 * @param outVertices ������ �ڽ��� ���� ����Դϴ�.
	 * @param outIndices ������ �ڽ� ������ �ε��� ����Դϴ�.
	 */
	static void CreateBox(float xsize, float ysize, float zsize, const Vector4f& color, std::vector<VertexPositionColor>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief ��ġ ��ǥ�� ���Ե� XY��� ���带 �����մϴ�.
	 *
	 * @param xsize ������ x �� ���������� ũ���Դϴ�.
	 * @param ysize ������ y �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ������ ���� ����Դϴ�.
	 * @param outIndices ������ ������ ������ �ε��� ����Դϴ�.
	 */
	static void CreateQuadXY(float xsize, float ysize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief ��ġ ��ǥ�� ���Ե� YZ��� ���带 �����մϴ�.
	 *
	 * @param ysize ������ y �� ���������� ũ���Դϴ�.
	 * @param zsize ������ z �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ������ ���� ����Դϴ�.
	 * @param outIndices ������ ������ ������ �ε��� ����Դϴ�.
	 */
	static void CreateQuadYZ(float ysize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief ��ġ ��ǥ�� ���Ե� XZ��� ���带 �����մϴ�.
	 *
	 * @param xsize ������ x �� ���������� ũ���Դϴ�.
	 * @param zsize ������ z �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ������ ���� ����Դϴ�.
	 * @param outIndices ������ ������ ������ �ε��� ����Դϴ�.
	 */
	static void CreateQuadXZ(float xsize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices);
};