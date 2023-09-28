#pragma once

#include <functional>

#include "GameObject/UIPanel.h"


/**
 * @brief ���� ���� 2D ��ư UI ������Ʈ�Դϴ�.
 */
class UIButton : public UIPanel
{
public:
	/**
	 * @brief 2D ��ư UI ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	UIButton() = default;


	/**
	 * @brief 2D ��ư UI ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note 2D ��ư UI ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~UIButton();


	/**
	 * @brief 2D ��ư UI ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(UIButton);


	/**
	 * @brief 2D ��ư UI ������Ʈ�� �ʱ�ȭ�մϴ�.
	 *
	 * @param width ��ư�� ���� ũ���Դϴ�.
	 * @param height ��ư�� ���� ũ���Դϴ�.
	 * @param center ��ư�� �߽� ��ǥ�Դϴ�.
	 * @param text ��ư ���� ǥ�õ� �ؽ�Ʈ�Դϴ�.
	 * @param font �ؽ�Ʈ�� ��Ʈ�Դϴ�.
	 * @param outlineRGB ��ư �ܰ����� �����Դϴ�.
	 * @param commonRGB �Ϲ����� ��׶��� �����Դϴ�.
	 * @param activeRGB Ȱ��ȭ �� ��׶����� �����Դϴ�.
	 * @param clickRGB Ŭ�� �� ��׶����� �����Դϴ�.
	 * @param textRGB ��ư ���� �ؽ�Ʈ �����Դϴ�.
	 * @param clickEvent ��ư�� Ŭ������ �� ������ �̺�Ʈ�Դϴ�.
	 * @param transparent ��ư�� �����Դϴ�. �̶�, ���� ���� ������ 0.0���� 1.0�Դϴ�.
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
	 * @brief 2D ��ư UI ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 2D ��ư UI ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief 2D ��ư UI ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief �Ϲ����� ��׶��� �����Դϴ�.
	 */
	glm::vec3 commonBackground_;


	/**
	 * @brief Ȱ��ȭ�Ǿ��� �� ��׶��� �����Դϴ�.
	 */
	glm::vec3 activeBackground_;


	/**
	 * @brief Ŭ������ �� ��׶��� �����Դϴ�.
	 */
	glm::vec3 clickBackground_;


	/**
	 * @brief ��ư�� Ŭ���Ǿ��� �� ������ �̺�Ʈ�Դϴ�.
	 */
	std::function<void()> clickEvent_;
};