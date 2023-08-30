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


	/**
	 * @brief ���� ������Ʈ �Ŵ����� ������Ʈ�� �߰��մϴ�.
	 *
	 * @note
	 * - ���� ������Ʈ �Ŵ����� �ʱ�ȭ�� �������� �����Ƿ�, ��ȯ�ϴ� ������ ������ �̿��ؼ� �ʱ�ȭ�� ���� �����ؾ� �մϴ�.
	 * - ���� ������Ʈ�� �ñ״�ó ���� �ߺ��� ������� �ʽ��ϴ�.
	 *
	 * @param signature �Ŵ��� ���ο��� ������Ʈ���� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @return �߰��� ������Ʈ�� �����͸� ����ϴ�.
	 */
	template <typename TGameObject>
	TGameObject* AddGameObject(const std::string& signature)
	{
		ASSERT((gameObjects_.find(signature) == gameObjects_.end()), "already exist game object signature key...");

		std::unique_ptr<TGameObject> object = std::make_unique<TGameObject>();
		gameObjects_.insert({ signature, std::move(object) });

		updateObjects_.push_back(gameObjects_.at(signature).get());
		renderObjects_.push_back(gameObjects_.at(signature).get());

		return reinterpret_cast<TGameObject*>(gameObjects_.at(signature).get());
	}


	/**
	 * @brief ���� ������Ʈ �Ŵ����� �����ϴ� ���� ������Ʈ�� ����ϴ�.
	 *
	 * @param signature �Ŵ��� ���ο��� ���� ������Ʈ���� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @return �ñ״�ó�� �����ϴ� ���� ������Ʈ�� �����͸� ����ϴ�. �ñ״�ó ���� �����ϴ� ���� ������Ʈ�� ������ �� �����͸� ��ȯ�մϴ�.
	 */
	template <typename TGameObject>
	TGameObject* GetGameObject(const std::string& signature)
	{
		ASSERT((gameObjects_.find(signature) != gameObjects_.end()), "not exist game object signature key...");

		return reinterpret_cast<TGameObject*>(gameObjects_.at(signature).get());
	}


	/**
	 * @brief ���� ������Ʈ �Ŵ����� �����ϴ� ���� ������Ʈ�� �����մϴ�.
	 *
	 * @param signature ������ ���� ������Ʈ�� �ñ״�ó ���Դϴ�.
	 */
	void RemoveGameObject(const std::string& signature);


	/**
	 * @brief ������Ʈ���� �ϰ� ������Ʈ�մϴ�.
	 * 
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	void UpdateAllObjects(float deltaSeconds);


	/**
	 * @brief ������Ʈ���� �ϰ� �������մϴ�.
	 */
	void RenderAllObjects();


	/**
	 * @brief ������Ʈ�� ������Ʈ���� ���� ���θ� �����մϴ�.
	 * 
	 * @param bNeedsToBeSortedUpdate ������ ������Ʈ�� ������Ʈ���� ���� �����Դϴ�.
	 */
	bool SetNeedsToBeSortedUpdate(bool bNeedsToBeSortedUpdate) { bNeedsToBeSortedUpdate_ = bNeedsToBeSortedUpdate; }


	/**
	 * @brief �������� ������Ʈ���� ���� ���θ� �����մϴ�.
	 * 
	 * @param bNeedsToBeSortedRender ������ �������� ������Ʈ���� ���� �����Դϴ�.
	 */
	bool SetNeedsToBeSortedRender(bool bNeedsToBeSortedRender) { bNeedsToBeSortedRender_ = bNeedsToBeSortedRender; }


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


	/**
	 * @brief ������Ʈ�� ������Ʈ���� ������ ����� ������ �ʿ����� Ȯ���մϴ�.
	 */
	bool bNeedsToBeSortedUpdate_ = false;


	/**
	 * @brief ������Ʈ�� ������Ʈ���� ������ ����Դϴ�.
	 */
	std::list<IGameObject*> updateObjects_;


	/**
	 * @brief �������� ������Ʈ���� ������ ����� ������ �ʿ����� Ȯ���մϴ�.
	 */
	bool bNeedsToBeSortedRender_ = false;


	/**
	 * @brief �������� ������Ʈ���� ������ ����Դϴ�.
	 */
	std::list<IGameObject*> renderObjects_;
};