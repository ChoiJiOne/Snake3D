#pragma once

#include "Scene/IScene.h"


/**
 * @brief ������ �غ� ���Դϴ�.
 */
class ReadyScene : public IScene
{
	/**
	 * @brief ���� �غ� ���� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	ReadyScene() = default;


	/**
	 * @brief ���� �غ� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~ReadyScene();


	/**
	 * @brief ���� �غ� ���� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ReadyScene);


	/**
	 * @brief ���� �غ� ���� �����մϴ�.
	 */
	virtual void Entry() override;


	/**
	 * @brief ���� �غ� ������ �����ϴ�.
	 */
	virtual void Leave() override;


	/**
	 * @brief ���� �غ� ���� �� ������ �����մϴ�.
	 *
	 * @param deltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) override;
};