#pragma once

#include "Manager/IManager.h"

class Window; // ������ Ŭ������ ����ϱ� ���� ���� �����Դϴ�.


/**
 * @brief �Է� ó���� �����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱����Դϴ�.
 */
class InputManager : public IManager
{
public:
	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(InputManager);


	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�մϴ�.
	 *
	 * @param inputControlWindow �Է� ó�� ����� �Ǵ� �������Դϴ�.
	 */
	void Initialize(Window* inputControlWindow);


	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief �Է� ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(InputManager);


private:
	/**
	 * @brief ������ ����� �Ǵ� �������Դϴ�.
	 */
	Window* inputControlWindow_ = nullptr;
};