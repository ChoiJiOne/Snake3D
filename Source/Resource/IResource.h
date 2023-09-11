#pragma once

#include "Utility/Macro.h"


/**
 * @brief ���ҽ��� �������̽��Դϴ�.
 *
 * @note ���� ���� ���ҽ��� �ݵ�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 */
class IResource
{
public:
	/**
	 * @brief ���ҽ� �������̽��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	IResource() = default;


	/**
	 * @brief ���ҽ� �������̽��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���ҽ� �������̽��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~IResource() {}


	/**
	 * @brief ���ҽ� �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IResource);


	/**
	 * @brief ���ҽ� �������̽� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 *
	 * @note ���ҽ� �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Release() = 0;


protected:
	/**
	 * @brief ���ҽ��� �ʱ�ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;
};