#include "Shader.h"

#include "Core/CommandLine.h"
#include "Core/RenderManager.h"


#include <d3dcompiler.h>

Shader::~Shader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Shader::Initialize(const std::wstring& vertexShaderPath, const std::wstring& pixelShaderPath)
{
	ASSERT(!bIsInitialized_, "already initialize shader...");
	
	HRESULT_ASSERT(CompileShaderFromFile(vertexShaderPath, "main", "vs_5_0", &vertexShaderBuffer_), "failed to compile vertex shader...");
	HRESULT_ASSERT(CompileShaderFromFile(pixelShaderPath, "main", "ps_5_0", &pixelShaderBuffer_), "failed to compile pixel shader...");

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreateVertexShader(
		vertexShaderBuffer_->GetBufferPointer(),
		vertexShaderBuffer_->GetBufferSize(),
		nullptr,
		&vertexShader_
	), "failed to create vertex shader...");

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreatePixelShader(
		pixelShaderBuffer_->GetBufferPointer(),
		pixelShaderBuffer_->GetBufferSize(),
		nullptr,
		&pixelShader_
	), "failed to create pixel shader...");

	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayout =
	{
		{ "POSITION", 0,    DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{    "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreateInputLayout(
		&inputLayout[0],
		static_cast<UINT>(inputLayout.size()),
		vertexShaderBuffer_->GetBufferPointer(),
		vertexShaderBuffer_->GetBufferSize(),
		&inputLayout_
	), "failed to create input layout...");
	
	D3D11_BUFFER_DESC everyFrameBufferDesc;
	everyFrameBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	everyFrameBufferDesc.ByteWidth = sizeof(EveryFrameBuffer);
	everyFrameBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	everyFrameBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	everyFrameBufferDesc.MiscFlags = 0;
	everyFrameBufferDesc.StructureByteStride = 0;

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreateBuffer(
		&everyFrameBufferDesc,
		nullptr,
		&everyFrameBuffer_
	), "failed to create every frame buffer...");

	bIsInitialized_ = true;
}

void Shader::Release()
{
	ASSERT(bIsInitialized_, "shader has not been initialized before...");

	SAFE_RELEASE(everyFrameBuffer_);
	SAFE_RELEASE(inputLayout_);
	SAFE_RELEASE(pixelShader_);
	SAFE_RELEASE(vertexShader_);
	SAFE_RELEASE(pixelShaderBuffer_);
	SAFE_RELEASE(vertexShaderBuffer_);

	bIsInitialized_ = false;
}

void Shader::Bind()
{
	RenderManager::Get().GetContext()->IASetInputLayout(inputLayout_);

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(RenderManager::Get().GetContext()->Map(everyFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update buffer...");

	EveryFrameBuffer* bufferPtr = reinterpret_cast<EveryFrameBuffer*>(mappedResource.pData);

	static float t = 0.0f;
	static ULONGLONG timeStart = 0;
	ULONGLONG timeCur = GetTickCount64();
	if (timeStart == 0)
		timeStart = timeCur;
	t = (timeCur - timeStart) / 1000.0f;

	Matrix4x4f world = MathHelper::ScalingMatrix(1.0f, 1.0f, 3.0f);
	Matrix4x4f view = MathHelper::LookAtMatrix(
		Vector3f(0.0f, 10.0f, -10.0f),
		Vector3f(0.0f, 0.0f, 0.0f),
		Vector3f(0.0f, 1.0f, 0.0f)
	);
	Matrix4x4f proj = MathHelper::ProjectionMatrix(
		PI_F / 4.0f,
		static_cast<float>(800) / static_cast<float>(600),
		0.01f,
		100.0f
	);

	bufferPtr->world = Matrix4x4f::Transpose(world);
	bufferPtr->view = Matrix4x4f::Transpose(view);
	bufferPtr->projection = Matrix4x4f::Transpose(proj);

	RenderManager::Get().GetContext()->Unmap(everyFrameBuffer_, 0);

	RenderManager::Get().GetContext()->VSSetShader(vertexShader_, nullptr, 0);
	uint32_t bindSlot = 0;
	RenderManager::Get().GetContext()->VSSetConstantBuffers(bindSlot, 1, &everyFrameBuffer_);

	RenderManager::Get().GetContext()->PSSetShader(pixelShader_, nullptr, 0);
}

HRESULT Shader::CompileShaderFromFile(const std::wstring& path, const std::string& entryPoint, const std::string& shaderModel, ID3DBlob** outBlob)
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