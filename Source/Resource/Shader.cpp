#include "Resource/Shader.h"

#include "Utility/Assertion.h"
#include "Utility/FileSystem.h"
#include "Utility/Logging.h"

#include <fstream>
#include <sstream>

#include <glad/glad.h>

char Shader::buffer_[MAX_BUFFER_SIZE];

Shader::~Shader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Shader::Initialize(const std::string& vsPath, const std::string& fsPath)
{
	ASSERT(!bIsInitialized_, "already initialize shader resource...");

	std::string vsSource = ConvertGLSLSourceToString(vsPath);
	std::string fsSource = ConvertGLSLSourceToString(fsPath);

	uint32_t vsID = CreateAndCompileShader(EType::VERTEX, vsSource);
	ASSERT(vsID != 0, "failed to create and compile vertex shader : %s", vsPath.c_str());

	uint32_t fsID = CreateAndCompileShader(EType::FRAGMENT, fsSource);
	ASSERT(fsID != 0, "failed to create and compile fragment shader : %s", fsPath.c_str());

	programID_ = glCreateProgram();
	glAttachShader(programID_, vsID);
	glAttachShader(programID_, fsID);
	glLinkProgram(programID_);

	int32_t success;
	glGetProgramiv(programID_, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programID_, MAX_BUFFER_SIZE, nullptr, buffer_);
		ERROR_LOG("failed to link shader program : %s", buffer_);
	}
	ASSERT(success, "failed to initialize shader resource...");

	glDeleteShader(vsID);
	glDeleteShader(fsID);

	bIsInitialized_ = true;
}

void Shader::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	if (programID_ != 0)
	{
		glDeleteProgram(programID_);
	}

	bIsInitialized_ = false;
}

void Shader::Bind()
{
	glUseProgram(programID_);
}

std::string Shader::ConvertGLSLSourceToString(const std::string& path)
{
	ASSERT(FileSystem::IsValidPath(path), "invalid GLSL shader path : %s", path.c_str());

	std::ifstream shaderFile(path);
	ASSERT(shaderFile.is_open(), "failed to open GLSL shader file : %s", path.c_str());

	std::stringstream shaderStringStream;
	shaderStringStream << shaderFile.rdbuf();

	shaderFile.close();

	return shaderStringStream.str();
}

uint32_t Shader::CreateAndCompileShader(const EType& type, const std::string& source)
{
	uint32_t shaderType = 0;
	switch (type)
	{
	case EType::VERTEX:
		shaderType = GL_VERTEX_SHADER;
		break;

	case EType::FRAGMENT:
		shaderType = GL_FRAGMENT_SHADER;
		break;

	default:
		shaderType = -1;
		break;
	}

	const char* sourcePtr = source.c_str();
	uint32_t shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &sourcePtr, nullptr);
	glCompileShader(shaderID);

	int32_t success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, MAX_BUFFER_SIZE, nullptr, buffer_);
		ERROR_LOG("failed to compile shader : %s", buffer_);
	}

	return shaderID;
}