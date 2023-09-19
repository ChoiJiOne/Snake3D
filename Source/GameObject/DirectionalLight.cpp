#include "DirectionalLight.h"

#include "Utility/Assertion.h"

DirectionalLight::~DirectionalLight()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void DirectionalLight::Initialize(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, const glm::vec3& direction)
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
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void DirectionalLight::Render()
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void DirectionalLight::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}