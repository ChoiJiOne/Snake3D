#include "Resource/TTFont.h"

#include "Core/RenderManager.h"

#include "Utils/FileHelper.h"

// @third party code - BEGIN
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>
// @third party code - END

TTFont::~TTFont()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void TTFont::Initialize(const std::string& path, int32_t beginCodePoint, int32_t endCodePoint, float fontSize)
{
	ASSERT(!bIsInitialized_, "already initialize true type font...");

	beginCodePoint_ = beginCodePoint;
	endCodePoint_ = endCodePoint;

	std::vector<uint8_t> buffer;
	FileHelper::ReadBufferFromFile(path, buffer);

	stbtt_fontinfo fontInfo;
	ASSERT((stbtt_InitFont(
		&fontInfo,
		reinterpret_cast<const unsigned char*>(&buffer[0]),
		stbtt_GetFontOffsetForIndex(reinterpret_cast<const unsigned char*>(&buffer[0]), 0)
	) != 0), "failed to initialize stb_truetype...");

	std::shared_ptr<uint8_t[]> glyphAtlasBitmap = GenerateGlyphAtlasBitmap(buffer, beginCodePoint_, endCodePoint_, fontSize, glyphs_, glyphAtlasSize_);
	CreateGlyphAtlasFromBitmap(glyphAtlasBitmap, glyphAtlasSize_);
	
	bIsInitialized_ = true;
}

void TTFont::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	SAFE_RELEASE(glyphAtlas_);
	SAFE_RELEASE(glyphAtlasView_);

	bIsInitialized_ = false;
}

const Glyph& TTFont::GetGlyph(int32_t codePoint) const
{
	ASSERT(HasCodePointInRange(codePoint), "code point is out of range...");
	int32_t index = codePoint - beginCodePoint_;
	return glyphs_[index];
}

bool TTFont::HasCodePointInRange(int32_t codePoint) const
{
	return (beginCodePoint_ <= codePoint) && (codePoint <= endCodePoint_);
}

void TTFont::MeasureText(const std::wstring& text, float& outWidth, float& outHeight) const
{
	int32_t textHeight = -1;
	int32_t textWidth = 0;

	for (const auto& unicode : text)
	{
		const Glyph& glyph = GetGlyph(static_cast<int32_t>(unicode));

		int32_t currentWidth = static_cast<int32_t>(glyph.xadvance);
		int32_t currentHeight = glyph.position1.y - glyph.position0.y;

		textWidth += currentWidth;

		if (currentHeight > textHeight)
		{
			textHeight = currentHeight;
		}
	}

	outWidth = static_cast<float>(textWidth);
	outHeight = static_cast<float>(textHeight);
}

std::shared_ptr<uint8_t[]> TTFont::GenerateGlyphAtlasBitmap(
	const std::vector<uint8_t>& buffer, 
	int32_t beginCodePoint, 
	int32_t endCodePoint, 
	float fontSize, 
	std::vector<Glyph>& outGlyphs, 
	int32_t& outGlyphAtlasSize
)
{
	std::vector<stbtt_packedchar> packedchars(endCodePoint - beginCodePoint + 1);
	outGlyphs.resize(endCodePoint - beginCodePoint + 1);

	int32_t success = 0;
	stbtt_pack_context packContext;
	std::shared_ptr<uint8_t[]> bitmap = nullptr;

	for (int32_t size = 16; size < 8192; size *= 2)
	{
		bitmap = std::make_unique<uint8_t[]>(size * size);
		success = stbtt_PackBegin(&packContext, bitmap.get(), size, size, 0, 1, nullptr);
		stbtt_PackSetOversampling(&packContext, 1, 1);

		success = stbtt_PackFontRange(
			&packContext,
			reinterpret_cast<const unsigned char*>(&buffer[0]),
			0,
			fontSize,
			beginCodePoint,
			static_cast<int>(packedchars.size()),
			&packedchars[0]
		);

		if (success)
		{
			stbtt_PackEnd(&packContext);
			outGlyphAtlasSize = size;
			break;
		}
		else
		{
			stbtt_PackEnd(&packContext);
			bitmap.reset();
		}
	}

	for (std::size_t index = 0; index < packedchars.size(); ++index)
	{
		outGlyphs[index].codePoint = static_cast<int32_t>(index + beginCodePoint);

		outGlyphs[index].position0 = Vector2i(packedchars[index].x0, packedchars[index].y0);
		outGlyphs[index].position1 = Vector2i(packedchars[index].x1, packedchars[index].y1);

		outGlyphs[index].xoffset = packedchars[index].xoff;
		outGlyphs[index].yoffset = packedchars[index].yoff;

		outGlyphs[index].xoffset2 = packedchars[index].xoff2;
		outGlyphs[index].yoffset2 = packedchars[index].yoff2;

		outGlyphs[index].xadvance = packedchars[index].xadvance;
	}

	return bitmap;
}

void TTFont::CreateGlyphAtlasFromBitmap(const std::shared_ptr<uint8_t[]>& bitmap, const int32_t& glyphAtlasSize)
{
	ID3D11Device* device = RenderManager::Get().GetDevice();

	D3D11_TEXTURE2D_DESC glyphAtlasDesc = {};
	glyphAtlasDesc.Height = static_cast<uint32_t>(glyphAtlasSize);
	glyphAtlasDesc.Width = static_cast<uint32_t>(glyphAtlasSize);
	glyphAtlasDesc.MipLevels = 1;
	glyphAtlasDesc.ArraySize = 1;
	glyphAtlasDesc.Format = DXGI_FORMAT_R8_UNORM;
	glyphAtlasDesc.SampleDesc.Count = 1;
	glyphAtlasDesc.SampleDesc.Quality = 0;
	glyphAtlasDesc.Usage = D3D11_USAGE_DEFAULT;
	glyphAtlasDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	glyphAtlasDesc.CPUAccessFlags = 0;
	glyphAtlasDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA glyphAtlasBufferData;
	glyphAtlasBufferData.pSysMem = reinterpret_cast<const void*>(&bitmap[0]);
	glyphAtlasBufferData.SysMemPitch = glyphAtlasSize;
	glyphAtlasBufferData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(device->CreateTexture2D(&glyphAtlasDesc, &glyphAtlasBufferData, &glyphAtlas_), "failed to create glyph texture atlas...");

	D3D11_SHADER_RESOURCE_VIEW_DESC glyphAtlasViewDesc = {};
	glyphAtlasViewDesc.Format = DXGI_FORMAT_R8_UNORM;
	glyphAtlasViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	glyphAtlasViewDesc.Texture2D.MipLevels = glyphAtlasDesc.MipLevels;
	glyphAtlasViewDesc.Texture2D.MostDetailedMip = 0;

	HRESULT_ASSERT(device->CreateShaderResourceView(glyphAtlas_, &glyphAtlasViewDesc, &glyphAtlasView_), "failed to create glyph texture atlas view...");
}