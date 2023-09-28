#pragma once

#include <functional>

#include "GameObject/UIPanel.h"


/**
 * @brief 게임 내의 2D 버튼 UI 오브젝트입니다.
 */
class UIButton : public UIPanel
{
public:
	/**
	 * @brief 2D 버튼 UI 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	UIButton() = default;


	/**
	 * @brief 2D 버튼 UI 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 2D 버튼 UI 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~UIButton();


	/**
	 * @brief 2D 버튼 UI 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(UIButton);


	/**
	 * @brief 2D 버튼 UI 오브젝트를 초기화합니다.
	 *
	 * @param width 버튼의 가로 크기입니다.
	 * @param height 버튼의 세로 크기입니다.
	 * @param center 버튼의 중심 좌표입니다.
	 * @param text 버튼 내에 표시될 텍스트입니다.
	 * @param font 텍스트의 폰트입니다.
	 * @param outlineRGB 버튼 외곽선의 색상입니다.
	 * @param commonRGB 일반적인 백그라운드 색상입니다.
	 * @param activeRGB 활성화 시 백그라운드의 색상입니다.
	 * @param clickRGB 클릭 시 백그라운드의 색상입니다.
	 * @param textRGB 버튼 내의 텍스트 색상입니다.
	 * @param clickEvent 버튼을 클릭했을 때 실행할 이벤트입니다.
	 * @param transparent 버튼의 투명도입니다. 이때, 투명도 값의 범위는 0.0에서 1.0입니다.
	 */
	void Initialize(
		float width,
		float height,
		const glm::vec2& center,
		const std::wstring& text,
		TTFont* font,
		const glm::vec3& outlineRGB,
		const glm::vec3& commonRGB,
		const glm::vec3& activeRGB,
		const glm::vec3& clickRGB,
		const glm::vec3& textRGB,
		const std::function<void()>& clickEvent,
		float transparent = 1.0f
	);


	/**
	 * @brief 2D 버튼 UI 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 2D 버튼 UI 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 2D 버튼 UI 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 일반적인 백그라운드 색상입니다.
	 */
	glm::vec3 commonBackground_;


	/**
	 * @brief 활성화되었을 때 백그라운드 색상입니다.
	 */
	glm::vec3 activeBackground_;


	/**
	 * @brief 클릭했을 때 백그라운드 색상입니다.
	 */
	glm::vec3 clickBackground_;


	/**
	 * @brief 버튼이 클릭되었을 때 실행할 이벤트입니다.
	 */
	std::function<void()> clickEvent_;
};