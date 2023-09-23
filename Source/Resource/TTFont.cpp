#include "Resource/TTFont.h"

#include "Utility/Assertion.h"
#include "Utility/FileSystem.h"

#include <fstream>
#include <iterator>

#include <glad.h>
#include <stb_rect_pack.h>
#include <stb_truetype.h>

TTFont::~TTFont()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void TTFont::Initialize(const std::string& path, int32_t beginCodePoint, int32_t endCodePoint, float fontSize)
{
	ASSERT(!bIsInitialized_, "already initialize true type font resource...");

	std::vector<uint8_t> buffer = ReadTrueTypeFontFile(path);

	beginCodePoint_ = beginCodePoint;
	endCodePoint_ = endCodePoint;

	stbtt_fontinfo fontInfo;
	const unsigned char* bufferPtr = reinterpret_cast<const unsigned char*>(&buffer[0]);
	ASSERT((stbtt_InitFont(&fontInfo, bufferPtr, stbtt_GetFontOffsetForIndex(bufferPtr, 0)) != 0), "failed to initialize stb_truetype...");

	std::shared_ptr<uint8_t[]> glyphAtlasBitmap = GenerateGlyphAtlasBitmap(buffer, beginCodePoint_, endCodePoint_, fontSize, glyphs_, glyphAtlasSize_);
	CreateGlyphAtlasFromBitmap(glyphAtlasBitmap, glyphAtlasSize_);

	bIsInitialized_ = true;
}

void TTFont::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	glDeleteTextures(1, &glyphAtlasID_);

	bIsInitialized_ = false;
}

const Glyph& TTFont::GetGlyph(int32_t codePoint) const
{
	ASSERT(HasCodePointInRange(codePoint), "%d is invalid code point in true type font...", codePoint);
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

std::vector<uint8_t> TTFont::ReadTrueTypeFontFile(const std::string& path)
{
	ASSERT(FileSystem::IsFilePath(path), "%s is not file path...", path.c_str());
	ASSERT(FileSystem::IsValidPath(path), "invalid true type font path : %s", path.c_str());

	std::ifstream readFile(path, std::ios::binary);
	ASSERT(readFile.is_open(), "can't open true type font file : %s", path.c_str());
	std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(readFile), {});
	readFile.close();

	return buffer;
}

std::shared_ptr<uint8_t[]> TTFont::GenerateGlyphAtlasBitmap(const std::vector<uint8_t>& buffer, int32_t beginCodePoint, int32_t endCodePoint, float fontSize, std::vector<Glyph>& outGlyphs, int32_t& outGlyphAtlasSize)
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

		outGlyphs[index].position0 = glm::ivec2(packedchars[index].x0, packedchars[index].y0);
		outGlyphs[index].position1 = glm::ivec2(packedchars[index].x1, packedchars[index].y1);

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
	glGenTextures(1, &glyphAtlasID_);
	glBindTexture(GL_TEXTURE_2D, glyphAtlasID_);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	const void* bufferPtr = reinterpret_cast<const void*>(&bitmap[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, glyphAtlasSize, glyphAtlasSize, 0, GL_RED, GL_UNSIGNED_BYTE, bufferPtr);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}