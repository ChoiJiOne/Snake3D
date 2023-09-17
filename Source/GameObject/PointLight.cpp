#include "PointLight.h"

#include "Utility/Assertion.h"

PointLight::~PointLight()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void PointLight::Initialize(
	const glm::vec3& position,
	const glm::vec4& ambient,
	const glm::vec4& diffuse,
	const glm::vec4& specular,
	float constant,
	float linear,
	float quadratic
)
{
	ASSERT(!bIsInitialized_, "already initialize point light object...");

	position_ = position;
	ambient_ = ambient;
	diffuse_ = diffuse;
	specular_ = specular;
	constant_ = constant;
	linear_ = linear;
	quadratic_ = quadratic;

	type_ = Light::EType::PointLight;

	bIsInitialized_ = true;
}

void PointLight::Update(float deltaSeconds)
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void PointLight::Render()
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void PointLight::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}