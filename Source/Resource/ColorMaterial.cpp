#include "Resource/ColorMaterial.h"

ColorMaterial::~ColorMaterial()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void ColorMaterial::Release()
{
	ASSERT(bIsInitialized_, "you have to initialize color material...");
	bIsInitialized_ = false;
}