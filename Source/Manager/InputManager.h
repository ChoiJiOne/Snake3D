#pragma once

#include <unordered_map>

#include "Manager/IManager.h"

class Window; // ������ Ŭ������ ����ϱ� ���� ���� �����Դϴ�.


/**
 * @brief �Է� ���¸� ��Ÿ���ϴ�.
 *
 * @note �����ӿ� ���� �Է� �����Դϴ�.
 * ---------------------------------------
 * | ���� ������ | ���� ������ | �Է� ���� |
 * ---------------------------------------
 * |     0      |     0      | None       |
 * |     0      |     1      | Pressed    |
 * |     1      |     0      | Released   |
 * |     1      |     1      | Held       |
 * ---------------------------------------
 */
enum class EPressState : int32_t
{
	None     = 0x00,
	Pressed  = 0x01,
	Released = 0x02,
	Held     = 0x03
};


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


	/**
	 * @brief �Է� ���¸� ������Ʈ �մϴ�.
	 */
	void Tick();


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