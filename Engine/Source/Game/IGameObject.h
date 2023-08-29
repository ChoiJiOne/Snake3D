#pragma once

#include "Utils/Macro.h"


/**
 * @brief ���� ������Ʈ �������̽��Դϴ�.
 * 
 * @note ���忡 ��ġ�Ǵ� ���� �� ������Ʈ�� �ݵ�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 */
class IGameObject
{
public:
	/**
	 * @brief ���� ������Ʈ �������̽��� ����Ʈ �������Դϴ�.
	 * 
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	IGameObject() = default;


	/**
	 * @brief ���� ������Ʈ �������̽��� ���� �Ҹ����Դϴ�.
	 * 
	 * @note ���� ������Ʈ �������̽��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~IGameObject() {}


	/**
	 * @brief ���� ������Ʈ �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IGameObject);


	/**
	 * @brief ���� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @note ���� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 * 
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) = 0;


	/**
	 * @brief ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @note ���� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Render() = 0;


	/**
	 * @brief ���� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 * 
	 * @note ���� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Release() = 0;


	/**
	 * @brief ���� ������Ʈ�� ������Ʈ �켱 ������ ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� ������Ʈ �켱 ������ ��ȯ�մϴ�.
	 */
	int32_t GetUpdateOrder() const { return updateOrder_; }


	/**
	 * @brief ���� ������Ʈ�� ������Ʈ �켱 ������ �����մϴ�.
	 * 
	 * @param updateOrder ������ ���� ������Ʈ�� ������Ʈ �켱�����Դϴ�.
	 */
	void SetUpdateOrder(int32_t updateOrder) { updateOrder_ = updateOrder; }


	/**
	 * @brief ���� ������Ʈ�� ������ �켱 ������ ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� ������ �켱 ������ ��ȯ�մϴ�.
	 */
	int32_t GetRenderOrder() const { return renderOrder_; }


	/**
	 * @brief ���� ������Ʈ�� ������ �켱 ������ �����մϴ�.
	 *
	 * @param renderOrder ������ ���� ������Ʈ�� ������ �켱�����Դϴ�.
	 */
	int32_t SetRenderOrder(int32_t renderOrder) { renderOrder_ = renderOrder; }


protected:
	/**
	 * @brief ���� ������Ʈ�� �ʱ�ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief ���� ������Ʈ�� ������Ʈ �켱 �����Դϴ�.
	 * 
	 * @note �� �켱 ������ �ݵ�� �����Ǿ�� �մϴ�.
	 */
	int32_t updateOrder_ = 0;


	/**
	 * @brief ���� ������Ʈ�� ������ �켱 �����Դϴ�.
	 * 
	 * @note �� �켱 ������ �ݵ�� �����Ǿ�� �մϴ�.
	 */
	int32_t renderOrder_ = 0;
};