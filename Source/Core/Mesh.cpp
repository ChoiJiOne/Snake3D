#include "Mesh.h"

#include "Core/RenderManager.h"

Mesh::~Mesh()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Mesh::Initialize(const void* verticesPtr, uint32_t vertexStride, uint32_t vertexCount, const void* indicesPtr, uint32_t indexCount)
{
	ASSERT(!bIsInitialized_, "already initialize mesh...");

	vertexStride_ = vertexStride;
	vertexCount_ = vertexCount;
	indexCount_ = indexCount;

	ID3D11Device* device = RenderManager::Get().GetDevice();

	D3D11_BUFFER_DESC vertexBufferDesc = {};
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = vertexStride * vertexCount_;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = verticesPtr;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(device->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer_), "failed to create vertex buffer...");

	D3D11_BUFFER_DESC indexBufferDesc;
	indexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	indexBufferDesc.ByteWidth = sizeof(uint32_t) * indexCount_;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA indexData;
	indexData.pSysMem = indicesPtr;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(device->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer_), "failed to create index buffer...");
	
	bIsInitialized_ = true;
}

void Mesh::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	SAFE_RELEASE(indexBuffer_);
	SAFE_RELEASE(vertexBuffer_);

	bIsInitialized_ = false;
}