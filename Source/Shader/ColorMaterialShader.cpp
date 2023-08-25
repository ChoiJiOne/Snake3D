#include "Shader/ColorMaterialShader.h"

#include "Resource/Mesh.h"
#include "Resource/Model.h"

#include "Core/ColorMaterial.h"
#include "Core/RenderManager.h"
#include "Core/Camera3D.h"

#include "Utils/CommandLine.h"

ColorMaterialShader::~ColorMaterialShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void ColorMaterialShader::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize shader...");

	std::wstring shaderPath = CommandLine::GetValue(L"Shader");
	std::wstring vsPath = shaderPath + L"ColorMaterialVS.hlsl";
	std::wstring psPath = shaderPath + L"ColorMaterialPS.hlsl";

	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayout =
	{
		{ "POSITION", 0,    DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	ID3D11Device* device = RenderManager::Get().GetDevice();
	CreateVertexShader(device, vsPath);
	CreatePixelShader(device, psPath);
	CreateInputLayout(device, inputLayout);
	CreateDynamicConstantBuffer(device, sizeof(EveryFrameBuffer), &everyFrameBuffer_);
	CreateDynamicConstantBuffer(device, sizeof(ColorMaterialBuffer), &colorMaterialBuffer_);

	bIsInitialized_ = true;
}

void ColorMaterialShader::Release()
{
	ASSERT(bIsInitialized_, "shader has not been initialized before...");

	SAFE_RELEASE(colorMaterialBuffer_);
	SAFE_RELEASE(everyFrameBuffer_);
	SAFE_RELEASE(inputLayout_);
	SAFE_RELEASE(pixelShader_);
	SAFE_RELEASE(vertexShader_);
	SAFE_RELEASE(pixelShaderBuffer_);
	SAFE_RELEASE(vertexShaderBuffer_);

	bIsInitialized_ = false;
}

void ColorMaterialShader::Draw(const Matrix4x4f& world, Camera3D* camera, Model* model)
{
	ASSERT(model->HavePosition(), "not match model vertex and shader input layout...");
	ASSERT(model->HaveColorMaterial(), "this shader need color material...");

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(everyFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		EveryFrameBuffer* bufferPtr = reinterpret_cast<EveryFrameBuffer*>(mappedResource.pData);

		bufferPtr->world = Matrix4x4f::Transpose(world);
		bufferPtr->view = Matrix4x4f::Transpose(camera->GetViewMatrix());
		bufferPtr->projection = Matrix4x4f::Transpose(camera->GetProjectionMatrix());

		context->Unmap(everyFrameBuffer_, 0);
	}

	HRESULT_ASSERT(context->Map(colorMaterialBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		ColorMaterial* colorMaterial = model->GetColorMaterial();
		ColorMaterialBuffer* bufferPtr = reinterpret_cast<ColorMaterialBuffer*>(mappedResource.pData);

		bufferPtr->color = colorMaterial->GetColor();

		context->Unmap(colorMaterialBuffer_, 0);
	}

	Mesh* mesh = model->GetMesh();

	ID3D11Buffer* vertexBuffer = mesh->GetVertexBufferPtr();
	ID3D11Buffer* indexBuffer = mesh->GetIndexBufferPtr();
	uint32_t vertexStride = mesh->GetVertexStride();
	UINT offset = 0;

	context->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexStride, &offset);
	context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	context->IASetInputLayout(inputLayout_);

	context->VSSetShader(vertexShader_, nullptr, 0);

	uint32_t vsSlot = 0;
	context->VSSetConstantBuffers(vsSlot, 1, &everyFrameBuffer_);

	context->PSSetShader(pixelShader_, nullptr, 0);
	uint32_t psSlot = 0;
	context->PSSetConstantBuffers(psSlot, 1, &colorMaterialBuffer_);

	context->DrawIndexed(static_cast<UINT>(mesh->GetIndexCount()), 0, 0);
}