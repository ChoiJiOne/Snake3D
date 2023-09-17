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
	 * @brief ����Ʈ�� �����Դϴ�.
	 */
	enum class EType : int32_t
	{
		None             = 0x00,
		DirectionalLight = 0x01,
		PointLight       = 0x02,
		SpotLight        = 0x03,
	};


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


protected:
	/**
	 * @brief ����Ʈ�� Ÿ���Դϴ�.
	 */
	EType type_ = EType::None;
};