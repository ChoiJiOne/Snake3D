#include "Resource/CubeMap.h"

#include "Utility/Assertion.h"
#include "Utility/FileSystem.h"

#include <glad.h>
#include <stb_image.h>

CubeMap::~CubeMap()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void CubeMap::Initialize(
	const std::string& rightPath,
	const std::string& leftPath,
	const std::string& topPath,
	const std::string& bottomPath,
	const std::string& frontPath,
	const std::string& backPath
)
{
	ASSERT(!bIsInitialized_, "already initialize cube map resource...");

	std::vector<std::string> resourcePaths = 
	{
		rightPath,
		leftPath,
		topPath,
		bottomPath,
		frontPath,
		backPath,
	};

	glGenTextures(1, &cubeMapID_);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMapID_);

	int32_t width = 0;
	int32_t height = 0;
	int32_t channels = 0;
	uint8_t* buffer = nullptr;

	for(std::size_t index = 0; index < resourcePaths.size(); ++index)
	{
		ASSERT(FileSystem::IsValidPath(resourcePaths[index]), "invalid cube resource path : %s", resourcePaths[index].c_str());

		buffer = stbi_load(resourcePaths[index].c_str(), &width, &height, &channels, 0);
		ASSERT(buffer != nullptr, "failed to load resource file : %s", resourcePaths[index].c_str());

		GLenum target = static_cast<GLenum>(GL_TEXTURE_CUBE_MAP_POSITIVE_X + index);
		glTexImage2D(target, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer);
		
		stbi_image_free(buffer);
		buffer = nullptr;
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	bIsInitialized_ = true;
}

void CubeMap::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	glDeleteTextures(1, &cubeMapID_);

	bIsInitialized_ = false;
}