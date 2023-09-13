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


	/**
	 * @brief ���� �α� ��� ��带 ����ϴ�.
	 * 
	 * @return ���� �α� ��� ��带 ��ȯ�մϴ�.
	 */
	EMode GetMode() const { return mode_; }


	/**
	 * @brief ���� �α� ��� ��带 �����մϴ�.
	 * 
	 * @param mode ������ �α� ��� ����Դϴ�.
	 */
	void SetMode(const EMode& mode) { mode_ = mode; }


private:
	/**
	 * @brief ������ ó���� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(LogManager);


	/**
	 * @brief ���� �ý��� �ð��� ���ڿ��� ����ϴ�.
	 * 
	 * @return ���� �ý��� �ð��� YYYY-MM-DD HH:MM:SS ������ ���ڿ��� ��ȯ�մϴ�.
	 */
	std::string GetCurrentSystemTime() const;


private:
	/**
	 * @brief ���� �α� ��� ����Դϴ�.
	 * 
	 * @note �⺻�� �ܼ� ��� ����Դϴ�.
	 */
	EMode mode_ = EMode::CONSOLE;
};
