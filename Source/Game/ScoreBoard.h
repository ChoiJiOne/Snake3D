#pragma once

#include "GameObject/UIPanel.h"


/**
 * @brief ���� ���̸� ǥ���ϴ� ���ھ� ���� ������Ʈ�Դϴ�.
 */
class ScoreBoard : public UIPanel
{
public:
	/**
	 * @brief ���ھ� ���� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	ScoreBoard() = default;


	/**
	 * @brief ���ھ� ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���ھ� ���� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~ScoreBoard();


	/**
	 * @brief ���ھ� ���� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ScoreBoard);


	/**
	 * @brief ���ھ� ���� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 *
	 * @param width �г��� ���� ũ���Դϴ�.
	 * @param height �г��� ���� ũ���Դϴ�.
	 * @param center �г��� �߽� ��ǥ�Դϴ�.
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
		TTFont* font,
		const glm::vec3& outlineRGB,
		const glm::vec3& backgroundRGB,
		const glm::vec3& textRGB,
		float transparent = 1.0f
	);


	/**
	 * @brief ���ھ� ���� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ���ھ� ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ���ھ� ���� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ���� ���� ���� ����ϴ�.
	 * 
	 * @return ���� ���� ���� ��ȯ�մϴ�.
	 */
	int32_t GetNumOfSnakeBodySize();


private:
	/**
	 * @brief �� ������Ʈ�Դϴ�.
	 */
	IGameObject* snakeObject_ = nullptr;
};