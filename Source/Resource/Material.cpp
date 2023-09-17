#include "Resource/Material.h"

#include "Utility/Assertion.h"

Material::~Material()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Material::Initialize(const glm::vec4& ambient, const glm::vec4& diffuse, const glm::vec4& specular, float power)
{
	ASSERT(!bIsInitialized_, "already initialize material resource...");

	ambient_ = ambient;
	diffuse_ = diffuse;
	specular_ = specular;
	specularPower_ = power;

	bIsInitialized_ = true;
}

void Material::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	bIsInitialized_ = false;
}