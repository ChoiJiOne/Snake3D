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
	// 여기서는 아무 동작도 수행하지 않습니다.
}

void Light::Render()
{
	// 여기서는 아무 동작도 수행하지 않습니다.
}

void Light::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}