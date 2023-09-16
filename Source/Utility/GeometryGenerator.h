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
	 * @brief XY��� ���带 �����մϴ�.
	 * 
	 * @param xsize ������ x �� ���������� ũ���Դϴ�.
	 * @param ysize ������ y �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ������ ���� ����Դϴ�.
	 * @param outIndices ������ ���� ������ �ε��� ����Դϴ�.
	 */
	static void CreateXYQuad(float xsize, float ysize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief YZ��� ���带 �����մϴ�.
	 * 
	 * @param ysize ������ y �� ���������� ũ���Դϴ�.
	 * @param zsize ������ z �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ������ ���� ����Դϴ�.
	 * @param outIndices ������ ���� ������ �ε��� ����Դϴ�.
	 */
	static void CreateYZQuad(float ysize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


	/**
	 * @brief ZX��� ���带 �����մϴ�.
	 * 
	 * @param xsize ������ x �� ���������� ũ���Դϴ�.
	 * @param ysize ������ z �� ���������� ũ���Դϴ�.
	 * @param outVertices ������ ������ ���� ����Դϴ�.
	 * @param outIndices ������ ���� ������ �ε��� ����Դϴ�.
	 */
	static void CreateXZQuad(float xsize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);


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


	/**
	 * @brief ��ġ ��ǥ�� �븻(����) ������ ���Ե� ���� �����մϴ�.
	 * 
	 * @param radius ���� ������ �����Դϴ�.
	 * @param sliceCount ���� �����̽� ī��Ʈ�Դϴ�.
	 * @param stackCount ���� ���� ī��Ʈ�Դϴ�.
	 * @param outVertices ������ ���� ���� ����Դϴ�.
	 * @param outIndices ������ ���� ���� �ε��� ����Դϴ�.
	 */
	static void CreateSphere(float radius, uint32_t sliceCount, uint32_t stackCount, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices);
};