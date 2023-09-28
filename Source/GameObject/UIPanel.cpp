#include "GameObject/UIPanel.h"

#include "Manager/RenderManager.h"

#include "Resource/TTFont.h"

#include "Utility/Assertion.h"

UIPanel::~UIPanel()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void UIPanel::Initialize(float width, float height, const glm::vec2& center, const std::wstring& text, TTFont* font, const glm::vec3& outlineRGB, const glm::vec3& backgroundRGB, const glm::vec3& textRGB, float transparent)
{
	ASSERT(!bIsInitialized_, "already initialize ui panel object...");
	ASSERT(font != nullptr, "invalid text font resource...");

	width_ = width;
	height_ = height;
	center_ = center;
	text_ = text;
	font_ = font;
	outlineRGB_ = outlineRGB;
	backgroundRGB_ = backgroundRGB;
	textRGB_ = textRGB;
	transparent_ = transparent;

	bIsInitialized_ = true;
}

void UIPanel::Update(float deltaSeconds)
{
}

void UIPanel::Render()
{
	RenderManager& renderManager = RenderManager::Get();

	renderManager.RenderRectangle2D(center_, width_, height_, glm::vec4(backgroundRGB_, transparent_));
	renderManager.RenderWireframeRectangle2D(center_, width_, height_, glm::vec4(outlineRGB_, transparent_));
	renderManager.RenderText2D(font_, text_, center_, textRGB_);
}

void UIPanel::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}