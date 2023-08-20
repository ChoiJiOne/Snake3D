#include "IShader.h"

#include "Core/RenderManager.h"

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