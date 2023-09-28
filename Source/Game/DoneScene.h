#pragma once

#include "Scene/IScene.h"


/**
 * @brief ������ ���� ���Դϴ�.
 */
class DoneScene : public IScene
{
public:
	/**
	 * @brief ���� ���� ���� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	DoneScene() = default;


	/**
	 * @brief ���� ���� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~DoneScene();


	/**
	 * @brief ���� ���� ���� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(DoneScene);


	/**
	 * @brief ���� ���� ���� �����մϴ�.
	 */
	virtual void Entry() override;


	/**
	 * @brief ���� ���� ������ �����ϴ�.
	 */
	virtual void Leave() override;


	/**
	 * @brief ���� ���� ���� �� ������ �����մϴ�.
	 *
	 * @param deltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) override;


	/**
	 * @brief ���� ���� �̺�Ʈ�� �����մϴ�.
	 *
	 * @param quitLoopEvent ������ ���� ���� �̺�Ʈ�Դϴ�.
	 */
	void SetQuitLoopEvent(const std::function<void()>& quitLoopEvent)
	{
		quitLoopEvent_ = quitLoopEvent;
	}


private:
	/**
	 * @brief 3D ������Ʈ ����Դϴ�.
	 */
	std::vector<IGameObject*> object3Ds_;


	/**
	 * @brief ���� ���� �̺�Ʈ�Դϴ�.
	 */
	std::function<void()> quitLoopEvent_;
};