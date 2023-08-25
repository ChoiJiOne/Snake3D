#pragma once

#include "Utils/Macro.h"

#include "Core/IManager.h"


/**
 * @brief ����� ó���� �����ϴ� �Ŵ����Դϴ�.
 */
class AudioManager : public IManager
{
public:
	/**
	 * @brief ����� ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(AudioManager);


	/**
	 * @brief ����� ó���� �����ϴ� �޴����� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief ����� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(AudioManager);
};