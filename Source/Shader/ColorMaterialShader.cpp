#include "ColorMaterialShader.h"

#include "Core/CommandLine.h"
#include "Core/Camera3D.h"
#include "Core/ColorMaterial.h"
#include "Core/Mesh.h"
#include "Core/Model.h"
#include "Core/RenderManager.h"

#include <d3dcompiler.h>

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

	HRESULT_ASSERT(CompileShaderFromFile(vsPath, "main", "vs_5_0", &vertexShaderBuffer_), "failed to compile vertex shader...");
	HRESULT_ASSERT(CompileShaderFromFile(psPath, "main", "ps_5_0", &pixelShaderBuffer_), "failed to compile pixel shader...");

	ID3D11Device* device = RenderManager::Get().GetDevice();

	HRESULT_ASSERT(device->CreateVertexShader(
		vertexShaderBuffer_->GetBufferPointer(),
		vertexShaderBuffer_->GetBufferSize(),
		nullptr,
		&vertexShader_
	), "failed to create vertex shader...");

	HRESULT_ASSERT(device->CreatePixelShader(
		pixelShaderBuffer_->GetBufferPointer(),
		pixelShaderBuffer_->GetBufferSize(),
		nullptr,
		&pixelShader_
	), "failed to create pixel shader...");

	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayout =
	{
		{ "POSITION", 0,    DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	HRESULT_ASSERT(device->CreateInputLayout(
		&inputLayout[0],
		static_cast<UINT>(inputLayout.size()),
		vertexShaderBuffer_->GetBufferPointer(),
		vertexShaderBuffer_->GetBufferSize(),
		&inputLayout_
	), "failed to create input layout...");

	D3D11_BUFFER_DESC everyFrameBufferDesc = {};
	everyFrameBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	everyFrameBufferDesc.ByteWidth = sizeof(EveryFrameBuffer);
	everyFrameBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	everyFrameBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	everyFrameBufferDesc.MiscFlags = 0;
	everyFrameBufferDesc.StructureByteStride = 0;

	HRESULT_ASSERT(device->CreateBuffer(&everyFrameBufferDesc, nullptr, &everyFrameBuffer_), "failed to create every frame buffer...");

	D3D11_BUFFER_DESC colorMaterialBufferDesc = {};
	colorMaterialBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	colorMaterialBufferDesc.ByteWidth = sizeof(ColorMaterialBuffer);
	colorMaterialBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	colorMaterialBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	colorMaterialBufferDesc.MiscFlags = 0;
	colorMaterialBufferDesc.StructureByteStride = 0;

	HRESULT_ASSERT(device->CreateBuffer(&colorMaterialBufferDesc, nullptr, &colorMaterialBuffer_), "failed to create color material buffer...");

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

	RenderManager::Get().GetContext()->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexStride, &offset);
	RenderManager::Get().GetContext()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	RenderManager::Get().GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	RenderManager::Get().GetContext()->IASetInputLayout(inputLayout_);

	RenderManager::Get().GetContext()->VSSetShader(vertexShader_, nullptr, 0);

	uint32_t vsSlot = 0;
	RenderManager::Get().GetContext()->VSSetConstantBuffers(vsSlot, 1, &everyFrameBuffer_);

	RenderManager::Get().GetContext()->PSSetShader(pixelShader_, nullptr, 0);
	uint32_t psSlot = 0;
	RenderManager::Get().GetContext()->PSSetConstantBuffers(psSlot, 1, &colorMaterialBuffer_);

	RenderManager::Get().GetContext()->DrawIndexed(static_cast<UINT>(mesh->GetIndexCount()), 0, 0);
}

HRESULT ColorMaterialShader::CompileShaderFromFile(const std::wstring& path, const std::string& entryPoint, const std::string& shaderModel, ID3DBlob** outBlob)
{
	HRESULT hr = S_OK;

	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

#if defined(DEBUG) || defined(RELEASE)
	shaderFlags |= D3DCOMPILE_DEBUG;
	shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

	ID3DBlob* errorBlob = nullptr;

	hr = D3DCompileFromFile(
		path.c_str(),
		nullptr,
		nullptr,
		entryPoint.c_str(),
		shaderModel.c_str(),
		shaderFlags,
		0,
		outBlob,
		&errorBlob
	);

	SAFE_RELEASE(errorBlob);
	return hr;
}