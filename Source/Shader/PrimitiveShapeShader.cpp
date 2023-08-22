#include "PrimitiveShapeShader.h"

#include "Core/CommandLine.h"
#include "Core/Camera3D.h"
#include "Core/RenderManager.h"
#include "Core/Window.h"

PrimitiveShapeShader::~PrimitiveShapeShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void PrimitiveShapeShader::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize shader...");

	std::wstring shaderPath = CommandLine::GetValue(L"Shader");
	std::wstring vsPath = shaderPath + L"PrimitiveShapeVS.hlsl";
	std::wstring psPath = shaderPath + L"PrimitiveShapePS.hlsl";

	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayout =
	{
		{ "POSITION", 0,    DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	ID3D11Device* device = RenderManager::Get().GetDevice();
	CreateVertexShader(device, vsPath);
	CreatePixelShader(device, psPath);
	CreateInputLayout(device, inputLayout);
	CreateDynamicConstantBuffer(device, sizeof(EveryFrameBuffer), &everyFrameBuffer_);
	CreateDynamicConstantBuffer(device, sizeof(ShapeColorBuffer), &shapeColorBuffer_);

	ConstructResourceForLine(device);

	bIsInitialized_ = true;
}

void PrimitiveShapeShader::Release()
{
	ASSERT(bIsInitialized_, "shader has not been initialized before...");

	for (auto& vertexBuffer : primitiveShapeVertexBuffer_)
	{
		SAFE_RELEASE(vertexBuffer.second);
	}

	for (auto& indexBuffer : primitiveShapeIndexBuffer_)
	{
		SAFE_RELEASE(indexBuffer.second);
	}

	SAFE_RELEASE(shapeColorBuffer_);
	SAFE_RELEASE(everyFrameBuffer_);
	SAFE_RELEASE(inputLayout_);
	SAFE_RELEASE(pixelShader_);
	SAFE_RELEASE(vertexShader_);
	SAFE_RELEASE(pixelShaderBuffer_);
	SAFE_RELEASE(vertexShaderBuffer_);

	bIsInitialized_ = false;
}

void PrimitiveShapeShader::DrawLine2D(const Vector2f& startPosition, const Vector2f& endPosition, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(true, false);

	primitiveShapeVertex_["Line"][0] = Vector3f(startPosition.x, startPosition.y, 0.0f);
	primitiveShapeVertex_["Line"][1] = Vector3f(endPosition.x, endPosition.y, 0.0f);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(primitiveShapeVertexBuffer_["Line"], 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update dynamic vertex buffer...");
	{
		VertexPosition* vertexBufferPtr = reinterpret_cast<VertexPosition*>(mappedResource.pData);

		std::memcpy(
			vertexBufferPtr,
			reinterpret_cast<const void*>(&primitiveShapeVertex_["Line"][0]),
			primitiveShapeVertex_["Line"].size() * static_cast<size_t>(VertexPosition::GetStride())
		);

		context->Unmap(primitiveShapeVertexBuffer_["Line"], 0);
	}

	HRESULT_ASSERT(context->Map(everyFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		EveryFrameBuffer* bufferPtr = reinterpret_cast<EveryFrameBuffer*>(mappedResource.pData);

		bufferPtr->view = Matrix4x4f::Identify();
		bufferPtr->projection = Matrix4x4f::Transpose(GetWindowOrthographicMatrix());

		context->Unmap(everyFrameBuffer_, 0);
	}

	HRESULT_ASSERT(context->Map(shapeColorBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		ShapeColorBuffer* bufferPtr = reinterpret_cast<ShapeColorBuffer*>(mappedResource.pData);

		bufferPtr->color = color;

		context->Unmap(shapeColorBuffer_, 0);
	}

	ID3D11Buffer* vertexBuffer = primitiveShapeVertexBuffer_["Line"];
	ID3D11Buffer* indexBuffer = primitiveShapeIndexBuffer_["Line"];
	uint32_t vertexStride = VertexPosition::GetStride();
	UINT offset = 0;

	context->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexStride, &offset);
	context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	context->IASetInputLayout(inputLayout_);

	context->VSSetShader(vertexShader_, nullptr, 0);

	uint32_t vsSlot = 0;
	context->VSSetConstantBuffers(vsSlot, 1, &everyFrameBuffer_);

	context->PSSetShader(pixelShader_, nullptr, 0);
	uint32_t psSlot = 0;
	context->PSSetConstantBuffers(psSlot, 1, &shapeColorBuffer_);

	context->DrawIndexed(static_cast<UINT>(primitiveShapeIndex_["Line"].size()), 0, 0);

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

void PrimitiveShapeShader::DrawLine3D(Camera3D* camera, const Vector3f& startPosition, const Vector3f& endPosition, const Vector4f& color)
{
	primitiveShapeVertex_["Line"][0] = startPosition;
	primitiveShapeVertex_["Line"][1] = endPosition;

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(primitiveShapeVertexBuffer_["Line"], 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update dynamic vertex buffer...");
	{
		VertexPosition* vertexBufferPtr = reinterpret_cast<VertexPosition*>(mappedResource.pData);

		std::memcpy(
			vertexBufferPtr,
			reinterpret_cast<const void*>(&primitiveShapeVertex_["Line"][0]),
			primitiveShapeVertex_["Line"].size() * static_cast<size_t>(VertexPosition::GetStride())
		);

		context->Unmap(primitiveShapeVertexBuffer_["Line"], 0);
	}

	HRESULT_ASSERT(context->Map(everyFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		EveryFrameBuffer* bufferPtr = reinterpret_cast<EveryFrameBuffer*>(mappedResource.pData);

		bufferPtr->view = Matrix4x4f::Transpose(camera->GetViewMatrix());
		bufferPtr->projection = Matrix4x4f::Transpose(camera->GetProjectionMatrix());

		context->Unmap(everyFrameBuffer_, 0);
	}

	HRESULT_ASSERT(context->Map(shapeColorBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		ShapeColorBuffer* bufferPtr = reinterpret_cast<ShapeColorBuffer*>(mappedResource.pData);

		bufferPtr->color = color;

		context->Unmap(shapeColorBuffer_, 0);
	}

	ID3D11Buffer* vertexBuffer = primitiveShapeVertexBuffer_["Line"];
	ID3D11Buffer* indexBuffer = primitiveShapeIndexBuffer_["Line"];
	uint32_t vertexStride = VertexPosition::GetStride();
	UINT offset = 0;

	context->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexStride, &offset);
	context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	context->IASetInputLayout(inputLayout_);

	context->VSSetShader(vertexShader_, nullptr, 0);

	uint32_t vsSlot = 0;
	context->VSSetConstantBuffers(vsSlot, 1, &everyFrameBuffer_);

	context->PSSetShader(pixelShader_, nullptr, 0);
	uint32_t psSlot = 0;
	context->PSSetConstantBuffers(psSlot, 1, &shapeColorBuffer_);

	context->DrawIndexed(static_cast<UINT>(primitiveShapeIndex_["Line"].size()), 0, 0);
}

void PrimitiveShapeShader::ConstructResourceForLine(ID3D11Device* device)
{
	primitiveShapeVertex_["Line"].resize(2);
	primitiveShapeIndex_["Line"] = { 0, 1 };

	CreateDynamicVertexBuffer(
		device,
		reinterpret_cast<const void*>(&primitiveShapeVertex_["Line"][0]),
		VertexPosition::GetStride(), static_cast<uint32_t>(primitiveShapeVertex_["Line"].size()),
		&primitiveShapeVertexBuffer_["Line"]
	);
	CreateIndexBuffer(device, primitiveShapeIndex_["Line"], &primitiveShapeIndexBuffer_["Line"]);
}

Matrix4x4f PrimitiveShapeShader::GetWindowOrthographicMatrix(float nearZ, float farZ)
{
	uint32_t windowWidth = 0;
	uint32_t windowHeight = 0;
	RenderManager::Get().GetRenderTargetWindow()->GetClientSize(windowWidth, windowHeight);

	return MathHelper::OrthographicMatrix(static_cast<float>(windowWidth), static_cast<float>(windowHeight), nearZ, farZ);
}