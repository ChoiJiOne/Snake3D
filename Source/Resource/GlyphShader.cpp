#include "Resource/GlyphShader.h"
#include "Resource/TTFont.h"

#include "Utility/Assertion.h"

#include <glad/glad.h>

GlyphShader::~GlyphShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void GlyphShader::Initialize(const std::string& vsFile, const std::string& fsFile)
{
	ASSERT(!bIsInitialized_, "already initialize glyph shader resource...");

	Shader::Initialize(vsFile, fsFile);

	glGenVertexArrays(1, &vertexArrayObject_);
	glGenBuffers(1, &vertexBufferObject_);

	glBindVertexArray(vertexArrayObject_);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);
	glBufferData(GL_ARRAY_BUFFER, VertexPositionTexture::GetStride() * glyphVertices_.size(), reinterpret_cast<const void*>(&glyphVertices_[0]), GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPositionTexture::GetStride(), (void*)(0));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VertexPositionTexture::GetStride(), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void GlyphShader::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	Shader::Release();

	glDeleteBuffers(1, &vertexBufferObject_);
	glDeleteVertexArrays(1, &vertexArrayObject_);
}

void GlyphShader::DrawText2D(const glm::mat4& projection, TTFont* font, const std::wstring& text, const glm::vec2& center, const glm::vec3& color)
{
	float textWidth = 0.0f;
	float textHeight = 0.0f;
	font->MeasureText(text, textWidth, textHeight);

	float glyphAtlasSize = font->GetGlyphAtlasSize();

	glm::vec2 position(center.x - textWidth / 2.0f, center.y + textHeight / 2.0f);

	Shader::Bind();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, font->GetGlyphAtlasID());

	Shader::SetIntParameter("glyphAtlas", 0);
	Shader::SetVec3Parameter("glyphColor", color);
	Shader::SetMat4Parameter("projection", projection);

	for (const auto& unicode : text)
	{
		const Glyph& glyph = font->GetGlyph(static_cast<int32_t>(unicode));
		UpdateGlyphVertexBuffer(glyph, glyphAtlasSize, position);

		glBindVertexArray(vertexArrayObject_);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		position.x += glyph.xadvance;
	}

	Shader::Unbind();
}

void GlyphShader::UpdateGlyphVertexBuffer(const Glyph& glyph, float glyphAtlasSize, const glm::vec2& position)
{
	float unicodeWidth = static_cast<float>(glyph.position1.x - glyph.position0.x);
	float unicodeHeight = static_cast<float>(glyph.position1.y - glyph.position0.y);

	glyphVertices_[0] = VertexPositionTexture
	(
		glm::vec3(position.x + glyph.xoffset, position.y + glyph.yoffset, 0.0f),
		glm::vec2(static_cast<float>(glyph.position0.x) / glyphAtlasSize, static_cast<float>(glyph.position0.y) / glyphAtlasSize)
	);

	glyphVertices_[1] = VertexPositionTexture
	(
		glm::vec3(position.x + glyph.xoffset, position.y + unicodeHeight + glyph.yoffset, 0.0f),
		glm::vec2(static_cast<float>(glyph.position0.x) / glyphAtlasSize, static_cast<float>(glyph.position1.y) / glyphAtlasSize)
	);

	glyphVertices_[2] = VertexPositionTexture
	(
		glm::vec3(position.x + glyph.xoffset + unicodeWidth, position.y + glyph.yoffset, 0.0f),
		glm::vec2(static_cast<float>(glyph.position1.x) / glyphAtlasSize, static_cast<float>(glyph.position0.y) / glyphAtlasSize)
	);

	glyphVertices_[3] = VertexPositionTexture
	(
		glm::vec3(position.x + glyph.xoffset + unicodeWidth, position.y + glyph.yoffset, 0.0f),
		glm::vec2(static_cast<float>(glyph.position1.x) / glyphAtlasSize, static_cast<float>(glyph.position0.y) / glyphAtlasSize)
	);

	glyphVertices_[4] = VertexPositionTexture
	(
		glm::vec3(position.x + glyph.xoffset, position.y + unicodeHeight + glyph.yoffset, 0.0f),
		glm::vec2(static_cast<float>(glyph.position0.x) / glyphAtlasSize, static_cast<float>(glyph.position1.y) / glyphAtlasSize)
	);

	glyphVertices_[5] = VertexPositionTexture
	(
		glm::vec3(position.x + glyph.xoffset + unicodeWidth, position.y + unicodeHeight + glyph.yoffset, 0.0f),
		glm::vec2(static_cast<float>(glyph.position1.x) / glyphAtlasSize, static_cast<float>(glyph.position1.y) / glyphAtlasSize)
	);

	UpdateVertexBuffer();
}

void GlyphShader::UpdateVertexBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&glyphVertices_[0]), VertexPositionTexture::GetStride() * glyphVertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}