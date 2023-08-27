#pragma once

#include <memory>
#include <unordered_map>

#include "Manager/IManager.h"

#include "Resource/IResource.h"


/**
 * @brief ���ҽ��� �����ϴ� �Ŵ����Դϴ�.
 */
class ResourceManager : public IManager
{
public:
	/**
	 * @brief ���ҽ��� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(ResourceManager);


	/**
	 * @brief ���ҽ��� �����ϴ� �޴����� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief ���ҽ��� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ���ҽ��� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ResourceManager);
};