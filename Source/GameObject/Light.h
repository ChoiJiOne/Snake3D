#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief ����Ʈ ������Ʈ�Դϴ�.
 */
class Light : public IGameObject
{
public:
	/**
	 * @brief ����Ʈ ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Light() = default;


	/**
	 * @brief ����Ʈ ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ����Ʈ ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Light();


	/**
	 * @brief ����Ʈ ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Light);


	/**
	 * @brief ����Ʈ ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param position ����Ʈ�� ��ġ�Դϴ�.
	 * @param color ����Ʈ�� �����Դϴ�.
	 */
	void Initialize(const glm::vec3 position, const glm::vec4& color);


	/**
	 * @brief ����Ʈ ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ����Ʈ ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ����Ʈ ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ����Ʈ ������Ʈ�� ���� �� ��ġ�� ����ϴ�.
	 * 
	 * @return ����Ʈ ������Ʈ�� ���� �� ��ġ�� ��ȯ�մϴ�.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief ����Ʈ ������Ʈ�� ���� �� ��ġ�� �����մϴ�.
	 * 
	 * @param position ������ ����Ʈ ������Ʈ�� ���� �� ��ġ�Դϴ�.
	 */
	void SetPosition(const glm::vec3& position) { position_ = position; }


	/**
	 * @brief ����Ʈ ������Ʈ�� ������ ����ϴ�.
	 * 
	 * @return ����Ʈ ������Ʈ�� ������ ��ȯ�մϴ�.
	 */
	glm::vec4 GetColor() const { return color_; }


	/**
	 * @brief ����Ʈ ������Ʈ�� ������ �����մϴ�.
	 * 
	 * @param color ������ ����Ʈ ������Ʈ�� �����Դϴ�.
	 */
	void SetColor(const glm::vec4& color) { color_ = color; }


private:
	/**
	 * @brief ���� ���� ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief ����Ʈ�� �����Դϴ�.
	 */
	glm::vec4 color_;
};