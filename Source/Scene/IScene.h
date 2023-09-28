#pragma once

#include <vector>

#include "GameObject/IGameObject.h"


/**
 * @brief ���� �� �������̽��Դϴ�.
 */
class IScene
{
public:
	/**
	 * @brief ���� �� �������̽��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	IScene() = default;


	/**
	 * @brief ���� �� �������̽��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~IScene() {}


	/**
	 * @brief ���� �� �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(IScene);


	/**
	 * @brief ���� ���� �����մϴ�.
	 */
	virtual void Entry() = 0;


	/**
	 * @brief ���� ������ �����ϴ�.
	 */
	virtual void Leave() = 0;


	/**
	 * @brief ���� �� ������ �����մϴ�.
	 *
	 * @param deltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) = 0;


	/**
	 * @brief ���� ���� �����մϴ�.
	 * 
	 * @param nextScene ������ ���� ���� �������Դϴ�.
	 */
	void SetNextScene(IScene* nextScene) { nextScene_ = nextScene; }


	/**
	 * @brief ���� ���� ����ϴ�.
	 * 
	 * @return ���� ���� �����͸� ��ȯ�մϴ�.
	 */
	IScene* GetNextScene() { return nextScene_; }


	/**
	 * @brief �� Ȱ��ȭ ���θ� Ȯ���մϴ�.
	 * 
	 * @return ���� Ȱ��ȭ�Ǿ� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsActive() const { return bIsActive_; }


	/**
	 * @brief �� Ȱ��ȭ ���θ� �����մϴ�.
	 * 
	 * @param bIsActive ������ �� Ȱ��ȭ �����Դϴ�.
	 */
	void SetActive(bool bIsActive) { bIsActive_ = bIsActive; }


protected:
	/**
	 * @brief ���� ����� ���� ���Դϴ�.
	 */
	IScene* nextScene_ = nullptr;


	/**
	 * @brief ���� Ȱ��ȭ �Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsActive_ = false;


	/**
	 * @brief �� ���� ������Ʈ �ؾ� �� ���� ������Ʈ ����Դϴ�.
	 */
	std::vector<IGameObject*> updateObjects_;


	/**
	 * @brief �� ���� ������ �ؾ� �� ���� ������Ʈ ����Դϴ�.
	 */
	std::vector<IGameObject*> renderObjects_;
};