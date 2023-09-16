#include "Utility/GeometryGenerator.h"

#include <glm/ext/scalar_constants.hpp>

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

void GeometryGenerator::CreateSphere(float radius, uint32_t sliceCount, uint32_t stackCount, std::vector<VertexPositionNormal>& outVertices, std::vector<uint32_t>& outIndices)
{
	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;

	vertices.push_back(VertexPositionNormal(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f));

	float phiStep = glm::pi<float>() / static_cast<float>(stackCount);
	float thetaStep = 2.0f * glm::pi<float>() / static_cast<float>(sliceCount);

	VertexPositionNormal vertex;
	for (uint32_t i = 1; i <= stackCount - 1; ++i)
	{
		float phi = static_cast<float>(i) * phiStep;

		for (uint32_t j = 0; j <= sliceCount; ++j)
		{
			float theta = static_cast<float>(j) * thetaStep;

			vertex.position_.x = radius * glm::sin(phi) * glm::cos(theta);
			vertex.position_.y = radius * glm::cos(phi);
			vertex.position_.z = radius * glm::sin(phi) * glm::sin(theta);

			vertex.normal_ = glm::normalize(vertex.position_);

			vertices.push_back(vertex);
		}
	}

	vertices.push_back(VertexPositionNormal(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f));

	for (uint32_t index = 1; index <= sliceCount; ++index)
	{
		indices.push_back(0);
		indices.push_back(index + 0);
		indices.push_back(index + 1);
	}

	uint32_t baseIndex = 1;
	uint32_t ringVertexCount = sliceCount + 1;
	for (uint32_t i = 0; i < stackCount - 2; ++i)
	{
		for (uint32_t j = 0; j < sliceCount; ++j)
		{
			indices.push_back(baseIndex + (i + 0) * ringVertexCount + j + 0);
			indices.push_back(baseIndex + (i + 1) * ringVertexCount + j + 0);
			indices.push_back(baseIndex + (i + 0) * ringVertexCount + j + 1);

			indices.push_back(baseIndex + (i + 1) * ringVertexCount + j + 0);
			indices.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
			indices.push_back(baseIndex + (i + 0) * ringVertexCount + j + 1);
		}
	}

	uint32_t southPoleIndex = static_cast<uint32_t>(vertices.size()) - 1;
	baseIndex = southPoleIndex - ringVertexCount;
	for (uint32_t i = 0; i < sliceCount; ++i)
	{
		indices.push_back(southPoleIndex);
		indices.push_back(baseIndex + i + 1);
		indices.push_back(baseIndex + i + 0);
	}

	outVertices = vertices;
	outIndices = indices;
}