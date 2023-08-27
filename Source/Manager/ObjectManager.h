#pragma once

#include <memory>
#include <unordered_map>
#include <list>

#include "Manager/IManager.h"

#include "Game/IGameObject.h"


/**
 * @brief ���� ������Ʈ�� �����ϴ� �Ŵ����Դϴ�.
 */
class ObjectManager : public IManager 
{
public:
	/**
	 * @brief ���� ������Ʈ�� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(ObjectManager);


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� �޴����� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief ���� ������Ʈ�� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ���� ������Ʈ�� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ObjectManager);


private:
	/**
	 * @brief ���� ������Ʈ �Ŵ����� �����ϴ� ������Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<IGameObject>> gameObjects_;
};