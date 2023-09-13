#pragma once

#include <string>
#include <list>

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
		Console  = 0x00,  // �⺻ ����Դϴ�.
		WinDebug = 0x01, // Visual Studio ����� â ����Դϴ�.
	};


	/**
	 * @brief �α� �����Դϴ�.
	 */
	enum class ELevel : int32_t
	{
		Info  = 0x00,  // �ܼ� ������ ����� �� ����մϴ�.
		Warn  = 0x01,  // ��� ����� �� ����մϴ�.
		Error = 0x02, // ���� �߻� �� ���� ������ ����� �� ����մϴ�.
		Debug = 0x03, // ����� ���� ������ ����� �� ����մϴ�. �̶�, DEBUG ��� �̿ܿ��� �����ϸ� ��µ��� �ʽ��ϴ�.
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


	/**
	 * @brief �α׸� ����մϴ�.
	 * 
	 * @param level ����� �α��� �����Դϴ�.
	 * @param message �α� �޼����� ���ڿ� �����Դϴ�.
	 * @param ... �α� �޼����� ���ڿ� ���Ŀ� �����ϴ� ���������Դϴ�.
	 */
	void OutputLogMessage(const ELevel& level, const char* message, ...);


	/**
	 * @brief ��µ� �α׸� ���Ϸ� �����մϴ�.
	 *
	 * @note
	 * - ���� ������ �ݵ�� TXT �����̿��� �մϴ�.
	 * - �޼��� ���ڷ� ���޵� ��ο� ���� ���, ���� �̸�, ���� Ȯ���� ��� �־�� �մϴ�.
	 *
	 * @param path ��µ� �α� ������ ������ ����Դϴ�.
	 * @param bIsCheckValid �α� ������ ����� ��ȿ�� �˻� �����Դϴ�. �⺻���� true�Դϴ�.
	 */
	void ExportOutputLog(const std::string& path, bool bIsCheckValid = true);

	
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


	/**
	 * @brief �α� ������ �����ϴ� ���ڿ��� ����ϴ�.
	 * 
	 * @param level ���ڿ��� ���� �α� �����Դϴ�.
	 * 
	 * @return �α� ������ �����ϴ� ���ڿ��� ��ȯ�մϴ�.
	 */
	std::string GetLogLevelString(const ELevel& level) const;


	/**
	 * @brief �α׸� ����մϴ�.
	 * 
	 * @param level �α��� �����Դϴ�.
	 * @param message �α��� �޽����Դϴ�.
	 */
	void OutputLogMessage(const ELevel& level, const std::string& message);

	
private:
	/**
	 * @brief ���� �α� ��� ����Դϴ�.
	 * 
	 * @note �⺻�� �ܼ� ��� ����Դϴ�.
	 */
	EMode mode_ = EMode::Console;


	/**
	 * @brief ����� �α׸� �����ϴ� ĳ���Դϴ�.
	 */
	std::list<std::string> messageCahce_;
};