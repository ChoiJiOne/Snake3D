#pragma once

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
		CONSOLE = 0x00,  // 기본 모드입니다.
		WINDEBUG = 0x01, // Visual Studio 디버그 창 모드입니다.
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


private:
	/**
	 * @brief 렌더링 처리를 수행하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(LogManager);


	/**
	 * @brief 현재 시스템 시간을 문자열로 얻습니다.
	 * 
	 * @return 현재 시스템 시간을 YYYY-MM-DD HH:MM:SS 형식의 문자열로 반환합니다.
	 */
	std::string GetCurrentSystemTime() const;


private:
	/**
	 * @brief 현재 로그 출력 모드입니다.
	 * 
	 * @note 기본은 콘솔 출력 모드입니다.
	 */
	EMode mode_ = EMode::CONSOLE;
};
