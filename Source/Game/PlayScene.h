#pragma once

#include "Scene/IScene.h"


/**
 * @brief ������ �÷��� ���Դϴ�.
 */
class PlayScene : public IScene
{
	/**
	 * @brief ���� �÷��� ���� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	PlayScene() = default;


	/**
	 * @brief ���� �÷��� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayScene();


	/**
	 * @brief ���� �÷��� ���� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PlayScene);


	/**
	 * @brief ���� �÷��� ���� �����մϴ�.
	 */
	virtual void Entry() override;


	/**
	 * @brief ���� �÷��� ������ �����ϴ�.
	 */
	virtual void Leave() override;


	/**
	 * @brief ���� �÷��� ���� �� ������ �����մϴ�.
	 *
	 * @param deltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) override;
};