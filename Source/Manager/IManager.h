#pragma once

#include "Utility/Macro.h"


/**
 * @brief �Ŵ��� �������̽� �Դϴ�.
 *
 * @note ���λ�� �Ŵ������ ���� Ŭ������ �ݵ�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 */
class IManager
{
public:
	/**
	 * @brief �Ŵ��� �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IManager);


	/**
	 * @brief �Ŵ��� �������̽��� �����մϴ�.
	 *
	 * @note �ݵ�� �� �޼��带 �̿��ؼ� �����ؾ� �մϴ�.
	 */
	virtual void Release() = 0;


protected:
	/**
	 * @brief �Ŵ��� �������̽��� ����Ʈ �����ڿ� ���� �Ҹ����Դϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(IManager);


protected:
	/**
	 * @brief �Ŵ��� �������̽��� �ʱ�ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;
};