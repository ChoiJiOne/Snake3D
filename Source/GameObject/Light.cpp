#include "GameObject/Light.h"

#include "Utility/Assertion.h"

Light::~Light()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Light::Initialize(const glm::vec3 position, const glm::vec4& color)
{
	ASSERT(!bIsInitialized_, "already initialize light object...");

	position_ = position;
	color_ = color;

	bIsInitialized_ = true;
}

void Light::Update(float deltaSeconds)
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void Light::Render()
{
	// ���⼭�� �ƹ� ���۵� �������� �ʽ��ϴ�.
}

void Light::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}