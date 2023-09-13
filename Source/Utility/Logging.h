#pragma once

#include "Manager/LogManager.h"


/**
 * @brief INFO 형식의 로그를 출력합니다.
 * 
 * @param ... 로그 메시지입니다.
 */
#ifndef INFO_LOG
#define INFO_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Info, __VA_ARGS__);
#endif


/**
 * @brief WARN 형식의 로그를 출력합니다.
 *
 * @param ... 로그 메시지입니다.
 */
#ifndef WARN_LOG
#define WARN_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Warn, __VA_ARGS__);
#endif


/**
 * @brief ERROR 형식의 로그를 출력합니다.
 *
 * @param ... 로그 메시지입니다.
 */
#ifndef ERROR_LOG
#define ERROR_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Error, __VA_ARGS__);
#endif


/**
 * @brief DEBUG 형식의 로그를 출력합니다.
 *
 * @param ... 로그 메시지입니다.
 */
#if defined(DEBUG)
#define DEBUG_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Debug, __VA_ARGS__);
#else
#define DEBUG_LOG(...)
#endif