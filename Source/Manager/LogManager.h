#pragma once

#include <string>
#include <list>

#include "Manager/IManager.h"


/**
 * @brief 로그를 기록하고 출력하는 매니저입니다.
 * 
 * @note 이 클래스는 싱글턴 클래스입니다.
 */
class LogManager : public IManager
{
public:
	/**
	 * @brief 로그를 출력할 모드입니다.
	 */
	enum class EMode : int32_t
	{
		Console  = 0x00,  // 기본 모드입니다.
		WinDebug = 0x01, // Visual Studio 디버그 창 모드입니다.
	};


	/**
	 * @brief 로그 레벨입니다.
	 */
	enum class ELevel : int32_t
	{
		Info  = 0x00,  // 단순 정보를 출력할 때 사용합니다.
		Warn  = 0x01,  // 경고를 출력할 때 사용합니다.
		Error = 0x02, // 에러 발생 시 에러 정보를 출력할 때 사용합니다.
		Debug = 0x03, // 디버그 관련 정보를 출력할 때 사용합니다. 이때, DEBUG 모드 이외에서 실행하면 출력되지 않습니다.
	};


public:
	/**
	 * @brief 로그 처리를 수행하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(LogManager);


	/**
	 * @brief 로그 처리를 수행하는 매니저를 초기화합니다.
	 */
	void Initialize();


	/**
	 * @brief 로그 처리를 수행하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 현재 로그 출력 모드를 얻습니다.
	 * 
	 * @return 현재 로그 출력 모드를 반환합니다.
	 */
	EMode GetMode() const { return mode_; }


	/**
	 * @brief 현재 로그 출력 모드를 설정합니다.
	 * 
	 * @param mode 설정할 로그 출력 모드입니다.
	 */
	void SetMode(const EMode& mode) { mode_ = mode; }


	/**
	 * @brief 로그를 출력합니다.
	 * 
	 * @param level 출력할 로그의 레벨입니다.
	 * @param message 로그 메세지의 문자열 형식입니다.
	 * @param ... 로그 메세지의 문자열 형식에 대응하는 가변인자입니다.
	 */
	void OutputLogMessage(const ELevel& level, const char* message, ...);


	/**
	 * @brief 출력된 로그를 파일로 저장합니다.
	 *
	 * @note
	 * - 파일 형식은 반드시 TXT 파일이여야 합니다.
	 * - 메서드 인자로 전달된 경로에 파일 경로, 파일 이름, 파일 확장자 모두 있어야 합니다.
	 *
	 * @param path 출력된 로그 파일을 저장할 경로입니다.
	 */
	void ExportOutputLogToPath(const std::string& path);


	/**
	 * @brief 로그 파일을 저장합니다.
	 * 
	 * @note
	 * - 명령행 인자에 로그 파일 경로가 설정되어 있지 않으면 실행 파일 경로에 저장합니다.
	 * - 명령행 인자에 로그 파일 경로가 유효하지 않으면 실행 파일 경로에 저장합니다.
	 */
	void ExportOutputLog();
	
	
private:
	/**
	 * @brief 로그 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(LogManager);


	/**
	 * @brief 현재 시스템 시간을 문자열로 얻습니다.
	 * 
	 * @return 현재 시스템 시간을 YYYY-MM-DD HH:MM:SS 형식의 문자열로 반환합니다.
	 */
	std::string GetCurrentSystemTime() const;


	/**
	 * @brief 로그 레벨에 대응하는 문자열을 얻습니다.
	 * 
	 * @param level 문자열을 얻을 로그 레벨입니다.
	 * 
	 * @return 로그 레벨에 대응하는 문자열을 반환합니다.
	 */
	std::string GetLogLevelString(const ELevel& level) const;


	/**
	 * @brief 로그를 출력합니다.
	 * 
	 * @param level 로그의 레벨입니다.
	 * @param message 로그의 메시지입니다.
	 */
	void OutputLogMessage(const ELevel& level, const std::string& message);

	
private:
	/**
	 * @brief 현재 로그 출력 모드입니다.
	 * 
	 * @note 기본은 콘솔 출력 모드입니다.
	 */
	EMode mode_ = EMode::Console;


	/**
	 * @brief 출력한 로그를 저장하는 캐쉬입니다.
	 */
	std::list<std::string> messageCahce_;
};