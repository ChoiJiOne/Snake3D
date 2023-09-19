#include "SpotLight.h"

#include "Utility/Assertion.h"

SpotLight::~SpotLight()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void SpotLight::Initialize(
	const glm::vec3& position,
	const glm::vec3& direction,
	float innerCutOff,
	float outerCutOff,
	const glm::vec3& ambient,
	const glm::vec3& diffuse,
	const glm::vec3& specular,
	float constant,
	float linear,
	float quadratic
)
{
	ASSERT(!bIsInitialized_, "already initialize spot light object...");

	position_ = position;
	direction_ = direction;

	innerCutOff_ = innerCutOff;
	outerCutOff_ = outerCutOff;

	ambient_ = ambient;
	diffuse_ = diffuse;
	specular_ = specular;

	constant_ = constant;
	linear_ = linear;
	quadratic_ = quadratic;

	type_ = Light::EType::SpotLight;

	bIsInitialized_ = true;
}

void SpotLight::Update(float deltaSeconds)
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void SpotLight::Render()
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void SpotLight::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}