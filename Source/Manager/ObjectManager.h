#pragma once

#include <memory>
#include <unordered_map>
#include <list>

#include "Manager/IManager.h"

#include "GameObject/IGameObject.h"


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


	/**
	 * @brief 게임 오브젝트 매니저에 오브젝트를 추가합니다.
	 *
	 * @note
	 * - 게임 오브젝트 매니저는 초기화를 수행하지 않으므로, 반환하는 포인터 변수를 이용해서 초기화를 따로 수행해야 합니다.
	 * - 게임 오브젝트의 시그니처 값은 중복을 허용하지 않습니다.
	 *
	 * @param signature 매니저 내부에서 오브젝트들을 구분할 시그니처 값입니다.
	 *
	 * @return 추가된 오브젝트의 포인터를 얻습니다.
	 */
	template <typename TGameObject>
	TGameObject* AddGameObject(const std::string& signature)
	{
		ASSERT((gameObjects_.find(signature) == gameObjects_.end()), "already exist game object signature key...");

		std::unique_ptr<TGameObject> object = std::make_unique<TGameObject>();
		gameObjects_.insert({ signature, std::move(object) });

		return reinterpret_cast<TGameObject*>(gameObjects_.at(signature).get());
	}


	/**
	 * @brief 게임 오브젝트 매니저가 관리하는 게임 오브젝트를 얻습니다.
	 *
	 * @param signature 매니저 내부에서 게임 오브젝트들을 구분할 시그니처 값입니다.
	 *
	 * @return 시그니처에 대응하는 게임 오브젝트의 포인터를 얻습니다. 시그니처 값에 대응하는 게임 오브젝트가 없으면 널 포인터를 반환합니다.
	 */
	template <typename TGameObject>
	TGameObject* GetGameObject(const std::string& signature)
	{
		ASSERT((gameObjects_.find(signature) != gameObjects_.end()), "not exist game object signature key...");

		return reinterpret_cast<TGameObject*>(gameObjects_.at(signature).get());
	}


	/**
	 * @brief 게임 오브젝트 매니저가 관리하는 게임 오브젝트를 삭제합니다.
	 *
	 * @param signature 삭제할 게임 오브젝트의 시그니처 값입니다.
	 */
	void RemoveGameObject(const std::string& signature);

	
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