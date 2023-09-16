#include "Utility/GeometryGenerator.h"

void GeometryGenerator::CreateBox(float xsize, float ysize, float zsize, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices)
{
	float halfX = xsize / 2.0f;
	float halfY = ysize / 2.0f;
	float halfZ = zsize / 2.0f;
		
	outVertices = {
		VertexPositionNormal(-halfX, -halfY, -halfZ, 0.0f, 0.0f, -1.0f),
		VertexPositionNormal(-halfX, +halfY, -halfZ, 0.0f, 0.0f, -1.0f),
		VertexPositionNormal(+halfX, +halfY, -halfZ, 0.0f, 0.0f, -1.0f),
		VertexPositionNormal(+halfX, -halfY, -halfZ, 0.0f, 0.0f, -1.0f),

		VertexPositionNormal(-halfX, -halfY, +halfZ, 0.0f, 0.0f, 1.0f),
		VertexPositionNormal(+halfX, -halfY, +halfZ, 0.0f, 0.0f, 1.0f),
		VertexPositionNormal(+halfX, +halfY, +halfZ, 0.0f, 0.0f, 1.0f),
		VertexPositionNormal(-halfX, +halfY, +halfZ, 0.0f, 0.0f, 1.0f),

		VertexPositionNormal(-halfX, +halfY, -halfZ, 0.0f, 1.0f, 0.0f),
		VertexPositionNormal(-halfX, +halfY, +halfZ, 0.0f, 1.0f, 0.0f),
		VertexPositionNormal(+halfX, +halfY, +halfZ, 0.0f, 1.0f, 0.0f),
		VertexPositionNormal(+halfX, +halfY, -halfZ, 0.0f, 1.0f, 0.0f),

		VertexPositionNormal(-halfX, -halfY, -halfZ, 0.0f, -1.0f, 0.0f),
		VertexPositionNormal(+halfX, -halfY, -halfZ, 0.0f, -1.0f, 0.0f),
		VertexPositionNormal(+halfX, -halfY, +halfZ, 0.0f, -1.0f, 0.0f),
		VertexPositionNormal(-halfX, -halfY, +halfZ, 0.0f, -1.0f, 0.0f),

		VertexPositionNormal(-halfX, -halfY, +halfZ, -1.0f, 0.0f, 0.0f),
		VertexPositionNormal(-halfX, +halfY, +halfZ, -1.0f, 0.0f, 0.0f),
		VertexPositionNormal(-halfX, +halfY, -halfZ, -1.0f, 0.0f, 0.0f),
		VertexPositionNormal(-halfX, -halfY, -halfZ, -1.0f, 0.0f, 0.0f),

		VertexPositionNormal(+halfX, -halfY, -halfZ, 1.0f, 0.0f, 0.0f),
		VertexPositionNormal(+halfX, +halfY, -halfZ, 1.0f, 0.0f, 0.0f),
		VertexPositionNormal(+halfX, +halfY, +halfZ, 1.0f, 0.0f, 0.0f),
		VertexPositionNormal(+halfX, -halfY, +halfZ, 1.0f, 0.0f, 0.0f),
	};

	outIndices = {
		0, 2, 1,
		0, 3, 2,

		4, 6, 5,
		4, 7, 6,

		8, 10, 9,
		8, 11, 10,

		12, 14, 13,
		12, 15, 14,

		16, 18, 17,
		16, 19, 18,

		20, 22, 21,
		20, 23, 22,
	};
}