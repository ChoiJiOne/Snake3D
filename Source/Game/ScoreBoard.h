#pragma once

#include "GameObject/UIPanel.h"


/**
 * @brief 뱀의 길이를 표시하는 스코어 보드 오브젝트입니다.
 */
class ScoreBoard : public UIPanel
{
public:
	/**
	 * @brief 스코어 보드 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	ScoreBoard() = default;


	/**
	 * @brief 스코어 보드 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 스코어 보드 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~ScoreBoard();


	/**
	 * @brief 스코어 보드 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ScoreBoard);


	/**
	 * @brief 스코어 보드 오브젝트를 초기화합니다.
	 *
	 * @param width 패널의 가로 크기입니다.
	 * @param height 패널의 세로 크기입니다.
	 * @param center 패널의 중심 좌표입니다.
	 * @param font 텍스트의 폰트입니다.
	 * @param outlineRGB 패널 외곽선의 색상입니다.
	 * @param backgroundRGB 패널 내의 백그라운드 색상입니다.
	 * @param textRGB 패널 내의 텍스트 색상입니다.
	 * @param transparent 패널의 투명도입니다. 이때, 투명도 값의 범위는 0.0에서 1.0입니다.
	 */
	void Initialize(
		float width,
		float height,
		const glm::vec2& center,
		TTFont* font,
		const glm::vec3& outlineRGB,
		const glm::vec3& backgroundRGB,
		const glm::vec3& textRGB,
		float transparent = 1.0f
	);


	/**
	 * @brief 스코어 보드 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 스코어 보드 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 스코어 보드 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 뱀의 몸통 수를 얻습니다.
	 * 
	 * @return 뱀의 몸통 수를 반환합니다.
	 */
	int32_t GetNumOfSnakeBodySize();


private:
	/**
	 * @brief 뱀 오브젝트입니다.
	 */
	IGameObject* snakeObject_ = nullptr;
};