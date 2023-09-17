#include "GameObject/Light.h"

#include "Utility/Assertion.h"

Light::~Light()
{
	if (bIsInitialized_)
	{
		Release();
	}
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