#pragma once

#include <memory>
#include <unordered_map>

#include "Manager/IManager.h"

#include "Resource/IResource.h"


/**
 * @brief 리소스를 관리하는 매니저입니다.
 */
class ResourceManager : public IManager
{
public:
	/**
	 * @brief 리소스를 관리하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(ResourceManager);


	/**
	 * @brief 리소스를 관리하는 메니저를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 리소스를 관리하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 리소스를 관리하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ResourceManager);
};