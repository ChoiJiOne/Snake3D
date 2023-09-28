#include "GameObject/UIButton.h"

#include "Manager/InputManager.h"

#include "Utility/Assertion.h"

UIButton::~UIButton()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void UIButton::Initialize(float width, float height, const glm::vec2& center, const std::wstring& text, TTFont* font, const glm::vec3& outlineRGB, const glm::vec3& commonRGB, const glm::vec3& activeRGB, const glm::vec3& clickRGB, const glm::vec3& textRGB, const std::function<void()>& clickEvent, float transparent)
{
	UIPanel::Initialize(width, height, center, text, font, outlineRGB, commonRGB, textRGB, transparent);

	commonBackground_ = commonRGB;
	activeBackground_ = activeRGB;
	clickBackground_ = clickRGB;
	clickEvent_ = clickEvent;
}

void UIButton::Update(float deltaSeconds)
{
	InputManager& inputManager = InputManager::Get();

	glm::vec2 minPosition = glm::vec2(center_.x - width_ / 2.0f, center_.y - height_ / 2.0f);
	glm::vec2 maxPosition = glm::vec2(center_.x + width_ / 2.0f, center_.y + height_ / 2.0f);
	glm::vec2 currentPosition = inputManager.GetCurrentMousePosition();
	
	if ((minPosition.x <= currentPosition.x && currentPosition.x <= maxPosition.x) &&
		(minPosition.y <= currentPosition.y && currentPosition.y <= maxPosition.y))
	{
		EPressState state = inputManager.GetMouseButtonPressState(EMouseButton::BUTTON_LEFT);

		if (state == EPressState::Released)
		{
			backgroundRGB_ = clickBackground_;
			clickEvent_();
		}
		else if (state == EPressState::Held)
		{
			backgroundRGB_ = clickBackground_;
		}
		else
		{
			backgroundRGB_ = activeBackground_;
		}
	}
	else
	{
		backgroundRGB_ = commonBackground_;
	}
}

void UIButton::Render()
{
	UIPanel::Render();
}

void UIButton::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");
	bIsInitialized_ = false;
}