#include "Resource/GeometryShader.h"

#include "Utility/Assertion.h"

#include <glad/glad.h>

GeometryShader::~GeometryShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void GeometryShader::Initialize(const std::string& vsFile, const std::string& fsFile)
{
	ASSERT(!bIsInitialized_, "already initialize geometry shader resource...");

	Shader::Initialize(vsFile, fsFile);

	glGenVertexArrays(1, &vertexArrayObject_);
	glGenBuffers(1, &vertexBufferObject_);

	glBindVertexArray(vertexArrayObject_);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);
	glBufferData(GL_ARRAY_BUFFER, VertexPositionColor::GetStride() * vertices_.size(), reinterpret_cast<const void*>(&vertices_[0]), GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPositionColor::GetStride(), (void*)(0));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VertexPositionColor::GetStride(), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glBindVertexArray(0);
}

void GeometryShader::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	Shader::Release();

	glDeleteBuffers(1, &vertexBufferObject_);
	glDeleteVertexArrays(1, &vertexArrayObject_);
}

void GeometryShader::DrawLine3D(const glm::mat4& view, const glm::mat4& projection, const glm::vec3& fromPosition, const glm::vec3& toPosition, const glm::vec4& color)
{
	vertices_[0] = VertexPositionColor(fromPosition, color);
	vertices_[1] = VertexPositionColor(toPosition, color);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", view);
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_LINES, 0, 2);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawLine2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec2& toPosition, const glm::vec4& color)
{
	vertices_[0] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), color);
	vertices_[1] = VertexPositionColor(glm::vec3(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f), color);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_LINES, 0, 2);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawTriangle2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec2& byPosition, const glm::vec2& toPosition, const glm::vec4& color)
{
	vertices_[0] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), color);
	vertices_[1] = VertexPositionColor(glm::vec3(  byPosition.x + 0.5f,   byPosition.y + 0.5f, 0.0f), color);
	vertices_[2] = VertexPositionColor(glm::vec3(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f), color);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawTriangle2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec4& fromColor, const glm::vec2& byPosition, const glm::vec4& byColor, const glm::vec2& toPosition, const glm::vec4& toColor)
{
	vertices_[0] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), fromColor);
	vertices_[1] = VertexPositionColor(glm::vec3(  byPosition.x + 0.5f,   byPosition.y + 0.5f, 0.0f),   byColor);
	vertices_[2] = VertexPositionColor(glm::vec3(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f),   toColor);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawWireframeTriangle2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec2& byPosition, const glm::vec2& toPosition, const glm::vec4& color)
{
	vertices_[0] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), color);
	vertices_[1] = VertexPositionColor(glm::vec3(  byPosition.x + 0.5f,   byPosition.y + 0.5f, 0.0f), color);
	vertices_[2] = VertexPositionColor(glm::vec3(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f), color);
	vertices_[3] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), color);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_LINE_STRIP, 0, 4);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawWireframeTriangle2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec4& fromColor, const glm::vec2& byPosition, const glm::vec4& byColor, const glm::vec2& toPosition, const glm::vec4& toColor)
{
	vertices_[0] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), fromColor);
	vertices_[1] = VertexPositionColor(glm::vec3(  byPosition.x + 0.5f,   byPosition.y + 0.5f, 0.0f),   byColor);
	vertices_[2] = VertexPositionColor(glm::vec3(  toPosition.x + 0.5f,   toPosition.y + 0.5f, 0.0f),   toColor);
	vertices_[3] = VertexPositionColor(glm::vec3(fromPosition.x + 0.5f, fromPosition.y + 0.5f, 0.0f), fromColor);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_LINE_STRIP, 0, 4);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawRectangle2D(const glm::mat4& projection, const glm::vec2& center, float width, float height, const glm::vec4& color)
{
	vertices_[0] = VertexPositionColor(glm::vec3(center.x - width / 2.0f + 0.5f, center.y - height / 2.0f + 0.5f, 0.0f), color);
	vertices_[1] = VertexPositionColor(glm::vec3(center.x - width / 2.0f + 0.5f, center.y + height / 2.0f + 0.5f, 0.0f), color);
	vertices_[2] = VertexPositionColor(glm::vec3(center.x + width / 2.0f + 0.5f, center.y - height / 2.0f + 0.5f, 0.0f), color);

	vertices_[3] = VertexPositionColor(glm::vec3(center.x + width / 2.0f + 0.5f, center.y - height / 2.0f + 0.5f, 0.0f), color);
	vertices_[4] = VertexPositionColor(glm::vec3(center.x - width / 2.0f + 0.5f, center.y + height / 2.0f + 0.5f, 0.0f), color);
	vertices_[5] = VertexPositionColor(glm::vec3(center.x + width / 2.0f + 0.5f, center.y + height / 2.0f + 0.5f, 0.0f), color);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

	Shader::Unbind();
}

void GeometryShader::DrawRectangle2D(const glm::mat4& projection, const glm::vec2& leftTopPosition, const glm::vec2& rightBottomPosition, const glm::vec4& color)
{
	vertices_[0] = VertexPositionColor(glm::vec3(    leftTopPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f), color);
	vertices_[1] = VertexPositionColor(glm::vec3(    leftTopPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f), color);
	vertices_[2] = VertexPositionColor(glm::vec3(rightBottomPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f), color);
	
	vertices_[3] = VertexPositionColor(glm::vec3(rightBottomPosition.x + 0.5f,     leftTopPosition.y + 0.5f, 0.0f), color);
	vertices_[4] = VertexPositionColor(glm::vec3(    leftTopPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f), color);
	vertices_[5] = VertexPositionColor(glm::vec3(rightBottomPosition.x + 0.5f, rightBottomPosition.y + 0.5f, 0.0f), color);

	void* bufferPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	std::memcpy(bufferPtr, reinterpret_cast<const void*>(&vertices_[0]), VertexPositionColor::GetStride() * vertices_.size());
	glUnmapBuffer(GL_ARRAY_BUFFER);

	Shader::Bind();

	Shader::SetMat4Parameter("view", glm::mat4(1.0f));
	Shader::SetMat4Parameter("projection", projection);

	glBindVertexArray(vertexArrayObject_);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

	Shader::Unbind();
}