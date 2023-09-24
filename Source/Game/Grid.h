#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief ������ �׸��� ������Ʈ�Դϴ�.
 */
class Grid : public IGameObject
{
public:
	/**
	 * @brief �׸��� ������Ʈ �������̽��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Grid() = default;


	/**
	 * @brief �׸��� ������Ʈ �������̽��� ���� �Ҹ����Դϴ�.
	 *
	 * @note �׸��� ������Ʈ �������̽��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Grid();


	/**
	 * @brief �׸��� ������Ʈ �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Grid);


	/**
	 * @brief �׸��� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param minX �׸��� ���� �߽� ��ǥ �� �ּ� X��ǥ���Դϴ�.
	 * @param maxX �׸��� ���� �߽� ��ǥ �� �ִ� X��ǥ���Դϴ�.
	 * @param minZ �׸��� ���� �߽� ��ǥ �� �ּ� Z��ǥ���Դϴ�.
	 * @param maxZ �׸��� ���� �߽� ��ǥ �� �ִ� Z��ǥ���Դϴ�.
	 * @param color �׸����� �����Դϴ�.
	 */
	void Initialize(int32_t minX, int32_t maxX, int32_t minZ, int32_t maxZ, const glm::vec4& color);


	/**
	 * @brief �׸��� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @note �׸��� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief �׸��� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 *
	 * @note �׸��� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief �׸��� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 *
	 * @note �׸��� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Release() override;
	

	/**
	 * @brief �׸��� �� �߽� ��ǥ �� �ּ� ��ǥ���� ����ϴ�.
	 *
	 * @return �׸��� �� �߽� ��ǥ �� �ּ� ��ǥ���� ��ȯ�մϴ�.
	 */
	glm::vec3 GetMinPosition() const { return minPosition_; }


	/**
	 * @brief �׸��� �� �߽� ��ǥ �� �ִ� ��ǥ���� ����ϴ�.
	 *
	 * @return �׸��� �� �߽� ��ǥ �� �ִ� ��ǥ���� ��ȯ�մϴ�.
	 */
	glm::vec3 GetMaxPosition() const { return maxPosition_; }


	/**
	 * @brief �׸����� ������ ����ϴ�.
	 * 
	 * @return �׸��� ������ ��ȯ�մϴ�.
	 */
	glm::vec4 GetColor() const { return color_; }


private:
	/**
	 * @brief �׸��� ���� �߽� ��ǥ �� �ּ� ��ǥ�Դϴ�.
	 */
	glm::vec3 minPosition_;


	/**
	 * @brief �׸��� ���� �߽� ��ǥ �� �ִ� ��ǥ�Դϴ�.
	 */
	glm::vec3 maxPosition_;


	/**
	 * @brief �׸����� �����Դϴ�.
	 */
	glm::vec4 color_;
};