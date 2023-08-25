#include "Model.h"

#include "Resource/ColorMaterial.h"
#include "Resource/Mesh.h"

Model::~Model()
{
	Release();
}

void Model::SetMesh(const std::vector<VertexPosition>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	uint32_t vertexStride = VertexPosition::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}


void Model::SetMesh(const std::vector<VertexPositionColor>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveColorInVertex_ = true;
	uint32_t vertexStride = VertexPositionColor::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const std::vector<VertexPositionUV>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveUVInVertex_ = true;
	uint32_t vertexStride = VertexPositionUV::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const std::vector<VertexPositionNormal>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveNormalInVertex_ = true;
	uint32_t vertexStride = VertexPositionNormal::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const std::vector<VertexPositionNormalUV>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveNormalInVertex_ = true;
	bHaveUVInVertex_ = true;
	uint32_t vertexStride = VertexPositionNormalUV::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const std::vector<VertexPositionNormalColor>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveNormalInVertex_ = true;
	bHaveColorInVertex_ = true;
	uint32_t vertexStride = VertexPositionNormalColor::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const std::vector<VertexPositionColorUV>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveColorInVertex_ = true;
	bHaveUVInVertex_ = true;
	uint32_t vertexStride = VertexPositionColorUV::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const std::vector<VertexPositionNormalColorUV>& vertices, const std::vector<uint32_t>& indices)
{
	bHavePositionInVertex_ = true;
	bHaveNormalInVertex_ = true;
	bHaveColorInVertex_ = true;
	bHaveUVInVertex_ = true;
	uint32_t vertexStride = VertexPositionNormalColorUV::GetStride();

	SetMesh(
		reinterpret_cast<const void*>(&vertices[0]),
		vertexStride,
		static_cast<uint32_t>(vertices.size()),
		reinterpret_cast<const void*>(&indices[0]),
		static_cast<uint32_t>(indices.size())
	);
}

void Model::SetMesh(const void* verticesPtr, uint32_t vertexStride, uint32_t vertexCount, const void* indicesPtr, uint32_t indexCount)
{
	if (mesh_)
	{
		mesh_->Release();
		mesh_.reset();
	}

	mesh_ = std::make_unique<Mesh>();
	mesh_->Initialize(verticesPtr, vertexStride, vertexCount, indicesPtr, indexCount);
}

void Model::SetColorMaterial(const Vector4f& color)
{
	if (material_)
	{
		material_.reset();
	}

	material_ = std::make_unique<ColorMaterial>();
	material_->SetColor(color);
}

void Model::Release()
{
	if (mesh_)
	{
		mesh_->Release();
		mesh_.reset();
	}

	if (material_)
	{
		material_.reset();
	}
}