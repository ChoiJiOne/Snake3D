#include "Game/ScoreBoard.h"
#include "Game/Snake.h"

#include "Manager/ObjectManager.h"

#include "Utility/String.h"

ScoreBoard::~ScoreBoard()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void ScoreBoard::Initialize(float width, float height, const glm::vec2& center, TTFont* font, const glm::vec3& outlineRGB, const glm::vec3& backgroundRGB, const glm::vec3& textRGB, float transparent)
{
	std::wstring text = String::Format(L"BODY : %d", GetNumOfSnakeBodySize());
	UIPanel::Initialize(width, height, center, text, font, outlineRGB, backgroundRGB, textRGB, transparent);
}

void ScoreBoard::Update(float deltaSeconds)
{
	text_ = String::Format(L"BODY : %d", GetNumOfSnakeBodySize());
}

void ScoreBoard::Render()
{
	UIPanel::Render();
}

void ScoreBoard::Release()
{
	UIPanel::Release();
}

int32_t ScoreBoard::GetNumOfSnakeBodySize()
{
	Snake* snake = ObjectManager::Get().GetGameObject<Snake>("Snake");
	return static_cast<int32_t>(snake->GetBodyPositions().size());
}