#include "DirectionalLight.h"

#include "Utility/Assertion.h"

DirectionalLight::~DirectionalLight()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void DirectionalLight::Initialize(const glm::vec4& ambient, const glm::vec4& diffuse, const glm::vec4& specular, const glm::vec3& direction)
{
	ASSERT(!bIsInitialized_, "already initialize directional light object...");

	ambient_ = ambient;
	diffuse_ = diffuse;
	specular_ = specular;
	direction_ = direction;

	type_ = Light::EType::DirectionalLight;

	bIsInitialized_ = true;
}

void DirectionalLight::Update(float deltaSeconds)
{
	// 여기서는 아무 동작도 수행하지 않습니다.
}

void DirectionalLight::Render()
{
	// 여기서는 아무 동작도 수행하지 않습니다.
}

void DirectionalLight::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}