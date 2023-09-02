#include "Shader/IShader.h"

#include "Manager/RenderManager.h"

#include <d3dcompiler.h>

HRESULT IShader::CompileShaderFromFile(const std::wstring& path, const std::string& entryPoint, const std::string& shaderModel, ID3DBlob** outBlob)
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

void IShader::CreateVertexShader(ID3D11Device* device, const std::wstring& path)
{
	HRESULT_ASSERT(CompileShaderFromFile(path, "main", "vs_5_0", &vertexShaderBuffer_), "failed to compile vertex shader...");

	HRESULT_ASSERT(device->CreateVertexShader(
		vertexShaderBuffer_->GetBufferPointer(),
		vertexShaderBuffer_->GetBufferSize(),
		nullptr,
		&vertexShader_
	), "failed to create vertex shader...");
}

void IShader::CreatePixelShader(ID3D11Device* device, const std::wstring& path)
{
	HRESULT_ASSERT(CompileShaderFromFile(path, "main", "ps_5_0", &pixelShaderBuffer_), "failed to compile pixel shader...");

	HRESULT_ASSERT(device->CreatePixelShader(
		pixelShaderBuffer_->GetBufferPointer(),
		pixelShaderBuffer_->GetBufferSize(),
		nullptr,
		&pixelShader_
	), "failed to create pixel shader...");
}

void IShader::CreateInputLayout(ID3D11Device* device, const std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayout)
{
	HRESULT_ASSERT(device->CreateInputLayout(
		&inputLayout[0],
		static_cast<UINT>(inputLayout.size()),
		vertexShaderBuffer_->GetBufferPointer(),
		vertexShaderBuffer_->GetBufferSize(),
		&inputLayout_
	), "failed to create input layout...");
}

void IShader::CreateDynamicVertexBuffer(ID3D11Device* device, const void* vertices, uint32_t vertexByteSize, uint32_t vertexCount, ID3D11Buffer** outVertexBuffer)
{
	D3D11_BUFFER_DESC vertexBufferDesc = {};

	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = vertexByteSize * vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(device->CreateBuffer(&vertexBufferDesc, &vertexData, outVertexBuffer), "failed to create dynamic vertex buffer...");
}

void IShader::CreateIndexBuffer(ID3D11Device* device, const std::vector<uint32_t>& indices, ID3D11Buffer** outIndexBuffer)
{
	D3D11_BUFFER_DESC indexBufferDesc;

	indexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	indexBufferDesc.ByteWidth = sizeof(uint32_t) * static_cast<uint32_t>(indices.size());
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA indexData;
	indexData.pSysMem = reinterpret_cast<const void*>(&indices[0]);
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(device->CreateBuffer(&indexBufferDesc, &indexData, outIndexBuffer), "failed to create index buffer...");
}

void IShader::CreateDynamicConstantBuffer(ID3D11Device* device, uint32_t bufferByteWidth, ID3D11Buffer** outConstantBuffer)
{
	D3D11_BUFFER_DESC dynamicConstantBufferDesc = {};
	dynamicConstantBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	dynamicConstantBufferDesc.ByteWidth = bufferByteWidth;
	dynamicConstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	dynamicConstantBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	dynamicConstantBufferDesc.MiscFlags = 0;
	dynamicConstantBufferDesc.StructureByteStride = 0;

	HRESULT_ASSERT(device->CreateBuffer(&dynamicConstantBufferDesc, nullptr, outConstantBuffer), "failed to create dynamic constant buffer...");
}

void IShader::CreateLinearSampler(ID3D11Device* device, ID3D11SamplerState** outLinearSampler)
{
	D3D11_SAMPLER_DESC linearSamplerDesc = { };

	linearSamplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	linearSamplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	linearSamplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	linearSamplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	linearSamplerDesc.MipLODBias = 0.0f;
	linearSamplerDesc.MaxAnisotropy = 1;
	linearSamplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	linearSamplerDesc.BorderColor[0] = 0;
	linearSamplerDesc.BorderColor[1] = 0;
	linearSamplerDesc.BorderColor[2] = 0;
	linearSamplerDesc.BorderColor[3] = 0;
	linearSamplerDesc.MinLOD = 0;
	linearSamplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	HRESULT_ASSERT(device->CreateSamplerState(&linearSamplerDesc, outLinearSampler), "failed to create linear texture sampler...");
}