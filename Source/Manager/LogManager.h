#pragma once

#include "Manager/IManager.h"


/**
 * @brief �α׸� ����ϰ� ����ϴ� �Ŵ����Դϴ�.
 * 
 * @note �� Ŭ������ �̱��� Ŭ�����Դϴ�.
 */
class LogManager : public IManager
{
public:
	/**
	 * @brief �α׸� ����� ����Դϴ�.
	 */
	enum class EMode : int32_t
	{
		CONSOLE = 0x00,  // �⺻ ����Դϴ�.
		WINDEBUG = 0x01, // Visual Studio ����� â ����Դϴ�.
	};


public:
	/**
	 * @brief �α� ó���� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(LogManager);


	/**
	 * @brief �α� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief �α� ó���� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(LogManager);
};
