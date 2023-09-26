#pragma once

#include "GameObject/IGameObject.h"

#include <glm/glm.hpp>

class Model; // �� ���ҽ��� ����ϱ� ���� ���漱���Դϴ�.


/**
 * @brief ������ �÷��� ������ �� ������Ʈ�Դϴ�.
 * 
 * @note �� ������Ʈ�� �ڷ� �� ���� �����ϴ�.
 */
class Snake : public IGameObject
{
public:
	/**
	 * @brief �� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Snake() = default;


	/**
	 * @brief �� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note �� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Snake();


	/**
	 * @brief �� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Snake);


	/**
	 * @brief �� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param color ���� RGB�����Դϴ�.
	 */
	void Initialize(const glm::vec3& colorRGB);


	/**
	 * @brief �� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief �� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief �� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ���� ���� �̵� �����Դϴ�.
	 */
	glm::vec3 direction_;


	/**
	 * @brief ���� ���� ��ġ�Դϴ�.
	 */
	glm::vec3 position_ = glm::vec3(0.0f, 0.5f, 0.0f);


	/**
	 * @brief ���� ���Դϴ�.
	 */
	Model* model_ = nullptr;
};