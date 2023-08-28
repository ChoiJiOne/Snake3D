#include "Shader/GlyphPassShader.h"

#include "Resource/TTFont.h"

#include "Manager/RenderManager.h"

#include "Utils/CommandLine.h"
#include "Utils/Window.h"

GlyphPassShader::~GlyphPassShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void GlyphPassShader::Initialize()
{
	ASSERT(!bIsInitialized_, "already initialize shader...");

	std::wstring shaderPath = CommandLine::GetValue(L"Shader");
	std::wstring vsPath = shaderPath + L"GlyphPassVS.hlsl";
	std::wstring psPath = shaderPath + L"GlyphPassPS.hlsl";

	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayout =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0,    DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	ID3D11Device* device = RenderManager::Get().GetDevice();
	CreateVertexShader(device, vsPath);
	CreatePixelShader(device, psPath);
	CreateInputLayout(device, inputLayout);
	CreateDynamicConstantBuffer(device, sizeof(EveryFrameBuffer), &everyFrameBuffer_);
	CreateDynamicConstantBuffer(device, sizeof(TextColorBuffer), &textColorBuffer_);
	CreateLinearSampler(device, &linearSamplerState_);

	glyphVertex_ = std::vector<VertexPositionUV>(4);
	glyphIndex_ = { 0, 1, 2, 0, 2, 3, };

	CreateDynamicVertexBuffer(
		device, 
		reinterpret_cast<const void*>(&glyphVertex_[0]),
		VertexPositionUV::GetStride(), 
		static_cast<uint32_t>(glyphVertex_.size()),
		&glyphVertexBuffer_
	);
	CreateIndexBuffer(device, glyphIndex_, &glyphIndexBuffer_);

	bIsInitialized_ = true;
}

void GlyphPassShader::Release()
{
	ASSERT(bIsInitialized_, "shader has not been initialized before...");

	SAFE_RELEASE(glyphIndexBuffer_);
	SAFE_RELEASE(glyphVertexBuffer_);
	SAFE_RELEASE(linearSamplerState_);
	SAFE_RELEASE(textColorBuffer_);
	SAFE_RELEASE(everyFrameBuffer_);
	SAFE_RELEASE(inputLayout_);
	SAFE_RELEASE(pixelShader_);
	SAFE_RELEASE(vertexShader_);
	SAFE_RELEASE(pixelShaderBuffer_);
	SAFE_RELEASE(vertexShaderBuffer_);

	bIsInitialized_ = false;
}

void GlyphPassShader::DrawText2D(TTFont* font, const std::wstring& text, const Vector2f& center, const Vector4f& color)
{
	RenderManager::Get().SetDepthStencilMode(false);
	RenderManager::Get().SetRasterizerMode(true, false);

	ID3D11DeviceContext* context = RenderManager::Get().GetContext();

	float textWidth = 0.0f;
	float textHeight = 0.0f;
	font->MeasureText(text, textWidth, textHeight);

	float glyphAtlasSize = static_cast<float>(font->GetGlyphAtlasSize());
	Vector2f position(center.x - textWidth / 2.0f, center.y - textHeight / 2.0f);

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	HRESULT_ASSERT(context->Map(everyFrameBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update constant buffer...");
	{
		EveryFrameBuffer* bufferPtr = reinterpret_cast<EveryFrameBuffer*>(mappedResource.pData);
		bufferPtr->projection = Matrix4x4f::Transpose(GetWindowOrthographicMatrix());
		context->Unmap(everyFrameBuffer_, 0);
	}

	HRESULT_ASSERT(context->Map(textColorBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update primitive shape color constant buffer...");
	{
		TextColorBuffer* bufferPtr = reinterpret_cast<TextColorBuffer*>(mappedResource.pData);
		bufferPtr->color = color;
		context->Unmap(textColorBuffer_, 0);
	}

	for (const auto& unicode : text)
	{
		const Glyph& glyph = font->GetGlyph(static_cast<int32_t>(unicode));
		UpdateGlyphVertexBuffer(context, glyph, glyphAtlasSize, position);

		uint32_t vertexStride = VertexPositionUV::GetStride();
		UINT offset = 0;

		context->IASetVertexBuffers(0, 1, &glyphVertexBuffer_, &vertexStride, &offset);
		context->IASetIndexBuffer(glyphIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		context->IASetInputLayout(inputLayout_);

		context->VSSetShader(vertexShader_, nullptr, 0);

		uint32_t vsSlot = 0;
		context->VSSetConstantBuffers(vsSlot, 1, &everyFrameBuffer_);

		ID3D11ShaderResourceView* glyphAtlasView = font->GetGlyphAtlasView();

		context->PSSetShader(pixelShader_, nullptr, 0);
		uint32_t psSlot = 0;
		context->PSSetConstantBuffers(psSlot, 1, &textColorBuffer_);
		context->PSSetShaderResources(psSlot, 1, &glyphAtlasView);
		context->PSSetSamplers(psSlot, 1, &linearSamplerState_);
		
		context->DrawIndexed(static_cast<uint32_t>(glyphIndex_.size()), 0, 0);

		position.x += glyph.xadvance;
	}

	RenderManager::Get().SetRasterizerMode(true, true);
	RenderManager::Get().SetDepthStencilMode(true);
}

Matrix4x4f GlyphPassShader::GetWindowOrthographicMatrix(float nearZ, float farZ)
{
	uint32_t windowWidth = 0;
	uint32_t windowHeight = 0;
	RenderManager::Get().GetRenderTargetWindow()->GetClientSize(windowWidth, windowHeight);

	return MathHelper::OrthographicMatrix(static_cast<float>(windowWidth), static_cast<float>(windowHeight), nearZ, farZ);
}

void GlyphPassShader::UpdateGlyphVertexBuffer(ID3D11DeviceContext* context, const Glyph& glyph, float glyphAtlasSize, const Vector2f& position)
{
	float unicodeWidth = static_cast<float>(glyph.position1.x - glyph.position0.x);
	float unicodeHeight = static_cast<float>(glyph.position1.y - glyph.position0.y);

	glyphVertex_[0] = VertexPositionUV(
		Vector3f(position.x + glyph.xoffset, position.y - unicodeHeight - glyph.yoffset, 0.0f),
		Vector2f(static_cast<float>(glyph.position0.x) / glyphAtlasSize, static_cast<float>(glyph.position1.y) / glyphAtlasSize)
	);

	glyphVertex_[1] = VertexPositionUV(
		Vector3f(position.x + glyph.xoffset, position.y - glyph.yoffset, 0.0f),
		Vector2f(static_cast<float>(glyph.position0.x) / glyphAtlasSize, static_cast<float>(glyph.position0.y) / glyphAtlasSize)
	);

	glyphVertex_[2] = VertexPositionUV(
		Vector3f(position.x + glyph.xoffset + unicodeWidth, position.y - glyph.yoffset, 0.0f),
		Vector2f(static_cast<float>(glyph.position1.x) / glyphAtlasSize, static_cast<float>(glyph.position0.y) / glyphAtlasSize)
	);

	glyphVertex_[3] = VertexPositionUV(
		Vector3f(position.x + glyph.xoffset + unicodeWidth, position.y - unicodeHeight - glyph.yoffset, 0.0f),
		Vector2f(static_cast<float>(glyph.position1.x) / glyphAtlasSize, static_cast<float>(glyph.position1.y) / glyphAtlasSize)
	);

	D3D11_MAPPED_SUBRESOURCE vertexBufferMappedResource;
	HRESULT_ASSERT(context->Map(glyphVertexBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &vertexBufferMappedResource), "failed to update glypy vertex buffer...");
	{
		VertexPositionUV* bufferPtr = reinterpret_cast<VertexPositionUV*>(vertexBufferMappedResource.pData);
		std::memcpy(bufferPtr, reinterpret_cast<const void*>(&glyphVertex_[0]), glyphVertex_.size() * VertexPositionUV::GetStride());
		context->Unmap(glyphVertexBuffer_, 0);
	}
}