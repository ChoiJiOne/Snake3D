#include "Utils/GeometryGenerator.h"

void GeometryGenerator::CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices)
{
	outVertices.resize(0);
	outIndices.resize(0);

	float halfXSize = xsize / 2.0f;
	float halfYSize = ysize / 2.0f;
	float halfZSize = zsize / 2.0f;

	outVertices = {
		VertexPosition(Vector3f(-halfXSize, -halfYSize, +halfZSize)),
		VertexPosition(Vector3f(+halfXSize, -halfYSize, +halfZSize)),
		VertexPosition(Vector3f(+halfXSize, +halfYSize, +halfZSize)),
		VertexPosition(Vector3f(-halfXSize, +halfYSize, +halfZSize)),

		VertexPosition(Vector3f(-halfXSize, -halfYSize, -halfZSize)),
		VertexPosition(Vector3f(+halfXSize, -halfYSize, -halfZSize)),
		VertexPosition(Vector3f(+halfXSize, +halfYSize, -halfZSize)),
		VertexPosition(Vector3f(-halfXSize, +halfYSize, -halfZSize))
	};

	outIndices = {
		0, 1, 2,
		0, 2, 3,

		4, 6, 5,
		4, 7, 6,

		4, 5, 1,
		4, 1, 0,

		3, 2, 6,
		3, 6, 7,

		1, 5, 6,
		1, 6, 2,

		4, 0, 3,
		4, 3, 7
	};
}

void GeometryGenerator::CreateBox(float xsize, float ysize, float zsize, const Vector4f& color, std::vector<VertexPositionColor>& outVertices, std::vector<uint32_t>& outIndices)
{
	outVertices.resize(0);
	outIndices.resize(0);

	float halfXSize = xsize / 2.0f;
	float halfYSize = ysize / 2.0f;
	float halfZSize = zsize / 2.0f;

	outVertices = {
		VertexPositionColor(Vector3f(-halfXSize, -halfYSize, +halfZSize), color),
		VertexPositionColor(Vector3f(+halfXSize, -halfYSize, +halfZSize), color),
		VertexPositionColor(Vector3f(+halfXSize, +halfYSize, +halfZSize), color),
		VertexPositionColor(Vector3f(-halfXSize, +halfYSize, +halfZSize), color),

		VertexPositionColor(Vector3f(-halfXSize, -halfYSize, -halfZSize), color),
		VertexPositionColor(Vector3f(+halfXSize, -halfYSize, -halfZSize), color),
		VertexPositionColor(Vector3f(+halfXSize, +halfYSize, -halfZSize), color),
		VertexPositionColor(Vector3f(-halfXSize, +halfYSize, -halfZSize), color)
	};

	outIndices = {
		0, 1, 2,
		0, 2, 3,

		4, 6, 5,
		4, 7, 6,

		4, 5, 1,
		4, 1, 0,

		3, 2, 6,
		3, 6, 7,

		1, 5, 6,
		1, 6, 2,

		4, 0, 3,
		4, 3, 7
	};
}

void GeometryGenerator::CreateQuadXY(float xsize, float ysize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices)
{
	outVertices.resize(0);
	outIndices.resize(0);

	float halfXSize = xsize / 2.0f;
	float halfYSize = ysize / 2.0f;

	outVertices = {
		VertexPosition(Vector3f(-halfXSize, -halfYSize, 0.0f)),
		VertexPosition(Vector3f(-halfXSize, +halfYSize, 0.0f)),
		VertexPosition(Vector3f(+halfXSize, +halfYSize, 0.0f)),
		VertexPosition(Vector3f(+halfXSize, -halfYSize, 0.0f)),
	};

	outIndices = {
		0, 1, 2,
		0, 2, 3,
	};
}

void GeometryGenerator::CreateQuadYZ(float ysize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices)
{
	outVertices.resize(0);
	outIndices.resize(0);

	float halfYSize = ysize / 2.0f;
	float halfZSize = zsize / 2.0f;

	outVertices = {
		VertexPosition(Vector3f(0.0f, -halfYSize, -halfZSize)),
		VertexPosition(Vector3f(0.0f, +halfYSize, -halfZSize)),
		VertexPosition(Vector3f(0.0f, +halfYSize, +halfZSize)),
		VertexPosition(Vector3f(0.0f, -halfYSize, +halfZSize)),
	};

	outIndices = {
		0, 1, 2,
		0, 2, 3,
	};
}

void GeometryGenerator::CreateQuadXZ(float xsize, float zsize, std::vector<VertexPosition>& outVertices, std::vector<uint32_t>& outIndices)
{
	outVertices.resize(0);
	outIndices.resize(0);

	float halfXSize = xsize / 2.0f;
	float halfZSize = zsize / 2.0f;

	outVertices = {
		VertexPosition(Vector3f(-halfXSize, 0.0f, -halfZSize)),
		VertexPosition(Vector3f(-halfXSize, 0.0f, +halfZSize)),
		VertexPosition(Vector3f(+halfXSize, 0.0f, +halfZSize)),
		VertexPosition(Vector3f(+halfXSize, 0.0f, -halfZSize)),
	};

	outIndices = {
		0, 1, 2,
		0, 2, 3,
	};
}