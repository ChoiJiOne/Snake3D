#pragma once

#include "Manager/LogManager.h"


/**
 * @brief INFO ������ �α׸� ����մϴ�.
 * 
 * @param ... �α� �޽����Դϴ�.
 */
#ifndef INFO_LOG
#define INFO_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Info, __VA_ARGS__);
#endif


/**
 * @brief WARN ������ �α׸� ����մϴ�.
 *
 * @param ... �α� �޽����Դϴ�.
 */
#ifndef WARN_LOG
#define WARN_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Warn, __VA_ARGS__);
#endif


/**
 * @brief ERROR ������ �α׸� ����մϴ�.
 *
 * @param ... �α� �޽����Դϴ�.
 */
#ifndef ERROR_LOG
#define ERROR_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Error, __VA_ARGS__);
#endif


/**
 * @brief DEBUG ������ �α׸� ����մϴ�.
 *
 * @param ... �α� �޽����Դϴ�.
 */
#if defined(DEBUG)
#define DEBUG_LOG(...)\
LogManager::Get().OutputLogMessage(LogManager::ELevel::Debug, __VA_ARGS__);
#else
#define DEBUG_LOG(...)
#endif