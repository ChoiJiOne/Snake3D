#include "Shader/ShapePassShader.h"

#include "Core/Camera3D.h"
#include "Core/Window.h"

#include "Manager/RenderManager.h"

#include "Utils/CommandLine.h"

ShapePassShader::~ShapePassShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void ShapePassShader::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize shader...");

	std::wstring shaderPath = CommandLine::GetValue(L"Shader");
	std::wstring vsPath = shaderPath + L"ShapePassVS.hlsl";
	std::wstring psPath = shaderPath + L"ShapePassPS.hlsl";

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
	ConstructResourceForTriangle(device);
	ConstructResourceForRect(device);
	ConstructResourceForWireframeRect(device);

	bIsInitialized_ = true;
}

void ShapePassShader::Release()
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

void ShapePassShader::DrawLine2D(const Vector2f& startPosition, const Vector2f& endPosition, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(true, false);

	primitiveShapeVertex_["Line"][0] = Vector3f(startPosition.x + 0.5f, startPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Line"][1] = Vector3f(  endPosition.x + 0.5f,   endPosition.y + 0.5f, 0.0f);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	UpdatePrimitiveShapeVertexBuffer(context, "Line");
	UpdateEveryFrameBuffer(context, Matrix4x4f::Identify(), GetWindowOrthographicMatrix());
	UpdatePrimitiveShapeColorBuffer(context, color);
	DrawPrimitiveShape(context, "Line", D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

void ShapePassShader::DrawTriangle2D(const Vector2f& fromPosition, const Vector2f& byPosition, const Vector2f& toPosition, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(true, false);

	primitiveShapeVertex_["Triangle"][0] = Vector3f(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Triangle"][1] = Vector3f(  byPosition.x + 0.5f,   byPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Triangle"][2] = Vector3f(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	UpdatePrimitiveShapeVertexBuffer(context, "Triangle");
	UpdateEveryFrameBuffer(context, Matrix4x4f::Identify(), GetWindowOrthographicMatrix());
	UpdatePrimitiveShapeColorBuffer(context, color);
	DrawPrimitiveShape(context, "Triangle", D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

void ShapePassShader::DrawWireframeTriangle2D(const Vector2f& fromPosition, const Vector2f& byPosition, const Vector2f& toPosition, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(false, false);

	primitiveShapeVertex_["Triangle"][0] = Vector3f(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Triangle"][1] = Vector3f(  byPosition.x + 0.5f,   byPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Triangle"][2] = Vector3f(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	UpdatePrimitiveShapeVertexBuffer(context, "Triangle");
	UpdateEveryFrameBuffer(context, Matrix4x4f::Identify(), GetWindowOrthographicMatrix());
	UpdatePrimitiveShapeColorBuffer(context, color);
	DrawPrimitiveShape(context, "Triangle", D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

void ShapePassShader::DrawRect2D(const Vector2f& leftTopPosition, const Vector2f& rightBottomPosition, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(true, false);

	primitiveShapeVertex_["Rect"][0] = Vector3f(    leftTopPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Rect"][1] = Vector3f(    leftTopPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Rect"][2] = Vector3f(rightBottomPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["Rect"][3] = Vector3f(rightBottomPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	UpdatePrimitiveShapeVertexBuffer(context, "Rect");
	UpdateEveryFrameBuffer(context, Matrix4x4f::Identify(), GetWindowOrthographicMatrix());
	UpdatePrimitiveShapeColorBuffer(context, color);
	DrawPrimitiveShape(context, "Rect", D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

void ShapePassShader::DrawWireframeRect2D(const Vector2f& leftTopPosition, const Vector2f& rightBottomPosition, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(true, false);

	primitiveShapeVertex_["WireframeRect"][0] = Vector3f(    leftTopPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["WireframeRect"][1] = Vector3f(    leftTopPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["WireframeRect"][2] = Vector3f(rightBottomPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f);
	primitiveShapeVertex_["WireframeRect"][3] = Vector3f(rightBottomPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	UpdatePrimitiveShapeVertexBuffer(context, "WireframeRect");
	UpdateEveryFrameBuffer(context, Matrix4x4f::Identify(), GetWindowOrthographicMatrix());
	UpdatePrimitiveShapeColorBuffer(context, color);
	DrawPrimitiveShape(context, "WireframeRect", D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

void ShapePassShader::DrawLine3D(Camera3D* camera, const Vector3f& startPosition, const Vector3f& endPosition, const Vector4f& color)
{
	primitiveShapeVertex_["Line"][0] = startPosition;
	primitiveShapeVertex_["Line"][1] = endPosition;

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	UpdatePrimitiveShapeVertexBuffer(context, "Line");
	UpdateEveryFrameBuffer(context, camera->GetViewMatrix(), camera->GetProjectionMatrix());
	UpdatePrimitiveShapeColorBuffer(context, color);
	DrawPrimitiveShape(context, "Line", D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
}

void ShapePassShader::ConstructResourceForLine(ID3D11Device* device)
{
	primitiveShapeVertex_["Line"].resize(2);
	primitiveShapeIndex_["Line"] = { 0, 1 };

	ConstructResourceForPrimitiveShape(device, "Line");
}

void ShapePassShader::ConstructResourceForTriangle(ID3D11Device* device)
{
	primitiveShapeVertex_["Triangle"].resize(3);
	primitiveShapeIndex_["Triangle"] = { 0, 1, 2 };

	ConstructResourceForPrimitiveShape(device, "Triangle");
}

void ShapePassShader::ConstructResourceForRect(ID3D11Device* device)
{
	primitiveShapeVertex_["Rect"].resize(4);
	primitiveShapeIndex_["Rect"] = { 0, 1, 2, 0, 2, 3 };

	ConstructResourceForPrimitiveShape(device, "Rect");
}

void ShapePassShader::ConstructResourceForWireframeRect(ID3D11Device* device)
{
	primitiveShapeVertex_["WireframeRect"].resize(4);
	primitiveShapeIndex_["WireframeRect"] = { 0, 1, 1, 2, 2, 3, 3, 0 };
	
	ConstructResourceForPrimitiveShape(device, "WireframeRect");
}

void ShapePassShader::ConstructResourceForPrimitiveShape(ID3D11Device* device, const std::string& signature)
{
	CreateDynamicVertexBuffer(
		device,
		reinterpret_cast<const void*>(&primitiveShapeVertex_[signature][0]),
		VertexPosition::GetStride(), static_cast<uint32_t>(primitiveShapeVertex_[signature].size()),
		&primitiveShapeVertexBuffer_[signature]
	);
	CreateIndexBuffer(device, primitiveShapeIndex_[signature], &primitiveShapeIndexBuffer_[signature]);
}

Matrix4x4f ShapePassShader::GetWindowOrthographicMatrix(float nearZ, float farZ)
{
	uint32_t windowWidth = 0;
	uint32_t windowHeight = 0;
	RenderManager::Get().GetRenderTargetWindow()->GetClientSize(windowWidth, windowHeight);

	return MathHelper::OrthographicMatrix(static_cast<float>(windowWidth), static_cast<float>(windowHeight), nearZ, farZ);
}

void ShapePassShader::UpdatePrimitiveShapeVertexBuffer(ID3D11DeviceContext* context, const std::string& signature)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(primitiveShapeVertexBuffer_[signature], 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update primitive shape vertex buffer...");
	{
		VertexPosition* vertexBufferPtr = reinterpret_cast<VertexPosition*>(mappedResource.pData);

		std::memcpy(
			vertexBufferPtr,
			reinterpret_cast<const void*>(&primitiveShapeVertex_[signature][0]),
			primitiveShapeVertex_[signature].size() * static_cast<size_t>(VertexPosition::GetStride())
		);

		context->Unmap(primitiveShapeVertexBuffer_[signature], 0);
	}
}

void ShapePassShader::UpdateEveryFrameBuffer(ID3D11DeviceContext* context, const Matrix4x4f& view, const Matrix4x4f& projection)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(everyFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		EveryFrameBuffer* bufferPtr = reinterpret_cast<EveryFrameBuffer*>(mappedResource.pData);

		bufferPtr->view = Matrix4x4f::Transpose(view);
		bufferPtr->projection = Matrix4x4f::Transpose(projection);

		context->Unmap(everyFrameBuffer_, 0);
	}
}

void ShapePassShader::UpdatePrimitiveShapeColorBuffer(ID3D11DeviceContext* context, const Vector4f& color)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(shapeColorBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update primitive shape color constant buffer...");
	{
		ShapeColorBuffer* bufferPtr = reinterpret_cast<ShapeColorBuffer*>(mappedResource.pData);

		bufferPtr->color = color;

		context->Unmap(shapeColorBuffer_, 0);
	}
}

void ShapePassShader::DrawPrimitiveShape(ID3D11DeviceContext* context, const std::string& signature, const D3D_PRIMITIVE_TOPOLOGY& topology)
{
	ID3D11Buffer* vertexBuffer = primitiveShapeVertexBuffer_[signature];
	ID3D11Buffer* indexBuffer = primitiveShapeIndexBuffer_[signature];
	uint32_t vertexStride = VertexPosition::GetStride();
	UINT offset = 0;

	context->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexStride, &offset);
	context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	context->IASetPrimitiveTopology(topology);
	context->IASetInputLayout(inputLayout_);

	context->VSSetShader(vertexShader_, nullptr, 0);

	uint32_t vsSlot = 0;
	context->VSSetConstantBuffers(vsSlot, 1, &everyFrameBuffer_);

	context->PSSetShader(pixelShader_, nullptr, 0);
	uint32_t psSlot = 0;
	context->PSSetConstantBuffers(psSlot, 1, &shapeColorBuffer_);

	context->DrawIndexed(static_cast<UINT>(primitiveShapeIndex_[signature].size()), 0, 0);
}