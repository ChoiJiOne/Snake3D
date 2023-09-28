#pragma once

#include <string>

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"

class TTFont; // 트루 타입 폰트 리스소를 사용하기 위한 전방 선언


/**
 * @brief 게임 내의 2D 패널 UI 오브젝트입니다.
 */
class UIPanel : public IGameObject
{
public:
	/**
	 * @brief 2D 패널 UI 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	UIPanel() = default;


	/**
	 * @brief 2D 패널 UI 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 2D 패널 UI 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~UIPanel();


	/**
	 * @brief 2D 패널 UI 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(UIPanel);


	/**
	 * @brief 2D 패널 UI 오브젝트를 초기화합니다.
	 * 
	 * @param width 패널의 가로 크기입니다.
	 * @param height 패널의 세로 크기입니다.
	 * @param center 패널의 중심 좌표입니다.
	 * @param text 패널 내에 표시될 텍스트입니다.
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
		const std::wstring& text,
		TTFont* font,
		const glm::vec3 outlineRGB,
		const glm::vec3 backgroundRGB,
		const glm::vec3 textRGB,
		float transparent = 1.0f
	);


	/**
	 * @brief 2D 패널 UI 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 2D 패널 UI 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 2D 패널 UI 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 패널의 가로 크기입니다.
	 */
	float width_ = 0.0f;


	/**
	 * @brief 패널의 세로 크기입니다.
	 */
	float height_ = 0.0f;


	/**
	 * @brief 패널의 중심 크기입니다.
	 */
	glm::vec2 center_;


	/**
	 * @brief 패널에 표시될 텍스트입니다.
	 */
	std::wstring text_;


	/**
	 * @brief 텍스트의 폰트입니다.
	 */
	TTFont* font_ = nullptr;


	/**
	 * @brief 패널의 외곽선 색상입니다.
	 */
	glm::vec3 outlineRGB_;


	/**
	 * @brief 패널 백그라운드의 색상입니다.
	 */
	glm::vec3 backgroundRGB_;


	/**
	 * @brief 텍스트의 색상입니다.
	 */
	glm::vec3 textRGB_;


	/**
	 * @brief 버튼의 투명도입니다.
	 */
	float transparent_ = 1.0f;
};