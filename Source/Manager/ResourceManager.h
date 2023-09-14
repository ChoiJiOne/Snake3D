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
	void Initialize();


	/**
	 * @brief 리소스를 관리하는 매니저의 초기화를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 리소스 매니저에 리소스를 추가합니다.
	 *
	 * @note
	 * - 리소스 매니저는 초기화를 수행하지 않으므로, 반환하는 포인터 변수를 이용해서 초기화를 따로 수행해야 합니다.
	 * - 리소스의 시그니처 값은 중복을 허용하지 않습니다.
	 *
	 * @param signature 매니저 내부에서 리소스들을 구분할 시그니처 값입니다.
	 *
	 * @return 추가된 리소스의 포인터를 얻습니다.
	 */
	template <typename TResource>
	TResource* AddResource(const std::string& signature)
	{
		ASSERT((resources_.find(signature) == resources_.end()), "already exist resource signature key...");

		std::unique_ptr<TResource> resource = std::make_unique<TResource>();
		resources_.insert({ signature, std::move(resource) });

		return reinterpret_cast<TResource*>(resources_.at(signature).get());
	}


	/**
	 * @brief 리소스 매니저가 관리하는 리소스를 얻습니다.
	 *
	 * @param signature 매니저 내부에서 리소스들을 구분할 시그니처 값입니다.
	 *
	 * @return 시그니처에 대응하는 리소스의 포인터를 얻습니다. 시그니처 값에 대응하는 리소스가 없으면 널 포인터를 반환합니다.
	 */
	template <typename TResource>
	TResource* GetResource(const std::string& signature)
	{
		TResource* resource = nullptr;

		if (resources_.find(signature) != resources_.end())
		{
			resource = reinterpret_cast<TResource*>(resources_.at(signature).get());
		}

		return resource;
	}


	/**
	 * @brief 리소스 매니저가 관리하는 리소스를 삭제합니다.
	 *
	 * @param signature 삭제할 리소스의 시그니처 값입니다.
	 */
	void RemoveResource(const std::string& signature);


private:
	/**
	 * @brief 리소스를 관리하는 매니저의 디폴트 생성자와 가상 소멸자를 추가합니다.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ResourceManager);


private:
	/**
	 * @brief 리소스 매니저가 관리하는 리소스입니다.
	 */
	std::unordered_map<std::string, std::unique_ptr<IResource>> resources_;
};