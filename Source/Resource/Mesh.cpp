#include "Resource/Mesh.h"

#include "Utility/Assertion.h"

#include <glad.h>

Mesh::~Mesh()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Mesh::Initialize(const std::vector<VertexPosition>& vertices, const std::vector<uint32_t>& indices)
{
	ASSERT(!bIsInitialized_, "already initialize mesh resource...");

	bHavePosition_ = true;
	indexCount_ = static_cast<uint32_t>(indices.size());

	glGenVertexArrays(1, &vertexArrayObject_);
	glGenBuffers(1, &vertexBufferObject_);
	glGenBuffers(1, &indexBufferObject_);

	glBindVertexArray(vertexArrayObject_);

	uint32_t vertexSize = VertexPosition::GetStride() * static_cast<uint32_t>(vertices.size());
	const void* vertexPtr = reinterpret_cast<const void*>(&vertices[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertexPtr, GL_STATIC_DRAW);

	uint32_t indexSize = sizeof(uint32_t) * static_cast<uint32_t>(indices.size());
	const void* indexPtr = reinterpret_cast<const void*>(&indices[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, indexPtr, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPosition::GetStride(), (void*)(0));
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	bIsInitialized_ = true;
}

void Mesh::Initialize(const std::vector<VertexPositionNormal>& vertices, const std::vector<uint32_t>& indices)
{
	ASSERT(!bIsInitialized_, "already initialize mesh resource...");

	bHavePosition_ = true;
	bHaveNormal_ = true;
	indexCount_ = static_cast<uint32_t>(indices.size());

	glGenVertexArrays(1, &vertexArrayObject_);
	glGenBuffers(1, &vertexBufferObject_);
	glGenBuffers(1, &indexBufferObject_);

	glBindVertexArray(vertexArrayObject_);

	uint32_t vertexSize = VertexPositionNormal::GetStride() * static_cast<uint32_t>(vertices.size());
	const void* vertexPtr = reinterpret_cast<const void*>(&vertices[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertexPtr, GL_STATIC_DRAW);

	uint32_t indexSize = sizeof(uint32_t) * static_cast<uint32_t>(indices.size());
	const void* indexPtr = reinterpret_cast<const void*>(&indices[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject_);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, indexPtr, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPositionNormal::GetStride(), (void*)(0));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VertexPositionNormal::GetStride(), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	bIsInitialized_ = true;
}

void Mesh::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	glDeleteBuffers(1, &indexBufferObject_);
	glDeleteBuffers(1, &vertexBufferObject_);
	glDeleteVertexArrays(1, &vertexArrayObject_);
	
	bIsInitialized_ = false;
}