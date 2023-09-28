#pragma once

#include <string>

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"

class TTFont; // Ʈ�� Ÿ�� ��Ʈ �����Ҹ� ����ϱ� ���� ���� ����


/**
 * @brief ���� ���� 2D �г� UI ������Ʈ�Դϴ�.
 */
class UIPanel : public IGameObject
{
public:
	/**
	 * @brief 2D �г� UI ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	UIPanel() = default;


	/**
	 * @brief 2D �г� UI ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note 2D �г� UI ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~UIPanel();


	/**
	 * @brief 2D �г� UI ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(UIPanel);


	/**
	 * @brief 2D �г� UI ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param width �г��� ���� ũ���Դϴ�.
	 * @param height �г��� ���� ũ���Դϴ�.
	 * @param center �г��� �߽� ��ǥ�Դϴ�.
	 * @param text �г� ���� ǥ�õ� �ؽ�Ʈ�Դϴ�.
	 * @param font �ؽ�Ʈ�� ��Ʈ�Դϴ�.
	 * @param outlineRGB �г� �ܰ����� �����Դϴ�.
	 * @param backgroundRGB �г� ���� ��׶��� �����Դϴ�.
	 * @param textRGB �г� ���� �ؽ�Ʈ �����Դϴ�.
	 * @param transparent �г��� �����Դϴ�. �̶�, ���� ���� ������ 0.0���� 1.0�Դϴ�.
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
	 * @brief 2D �г� UI ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 2D �г� UI ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief 2D �г� UI ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief �г��� ���� ũ���Դϴ�.
	 */
	float width_ = 0.0f;


	/**
	 * @brief �г��� ���� ũ���Դϴ�.
	 */
	float height_ = 0.0f;


	/**
	 * @brief �г��� �߽� ũ���Դϴ�.
	 */
	glm::vec2 center_;


	/**
	 * @brief �гο� ǥ�õ� �ؽ�Ʈ�Դϴ�.
	 */
	std::wstring text_;


	/**
	 * @brief �ؽ�Ʈ�� ��Ʈ�Դϴ�.
	 */
	TTFont* font_ = nullptr;


	/**
	 * @brief �г��� �ܰ��� �����Դϴ�.
	 */
	glm::vec3 outlineRGB_;


	/**
	 * @brief �г� ��׶����� �����Դϴ�.
	 */
	glm::vec3 backgroundRGB_;


	/**
	 * @brief �ؽ�Ʈ�� �����Դϴ�.
	 */
	glm::vec3 textRGB_;


	/**
	 * @brief ��ư�� �����Դϴ�.
	 */
	float transparent_ = 1.0f;
};