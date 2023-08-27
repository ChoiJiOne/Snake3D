#pragma once

#include <memory>
#include <unordered_map>
#include <list>

#include "Manager/IManager.h"

#include "Game/IGameObject.h"


/**
 * @brief 게임 오브젝트를 관리하는 매니저입니다.
 */
class ObjectManager : public IManager 
{
public:
	/**
	 * @brief 게임 오브젝트를 관리하는 매니저를 싱글턴으로 설정합니다.
	 */
	SINGLETON(ObjectManager);


	/**
	 * @brief 게임 오브젝트를 관리하는 메니저를 초기화합니다.
	 */
	virtual void Initialize() override;


	/**
	 * @brief 게임 오브젝트를 관리하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 게임 오브젝트를 관리하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ObjectManager);


private:
	/**
	 * @brief 게임 오브젝트 매니저가 관리하는 오브젝트입니다.
	 */
	std::unordered_map<std::string, std::unique_ptr<IGameObject>> gameObjects_;
};