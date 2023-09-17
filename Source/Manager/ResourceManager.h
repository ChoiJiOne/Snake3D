#pragma once

#include <memory>
#include <unordered_map>

#include "Manager/IManager.h"

#include "Resource/IResource.h"

#include "Utility/Assertion.h"


/**
 * @brief ���ҽ��� �����ϴ� �Ŵ����Դϴ�.
 */
class ResourceManager : public IManager
{
public:
	/**
	 * @brief ���ҽ��� �����ϴ� �Ŵ����� �̱������� �����մϴ�.
	 */
	SINGLETON(ResourceManager);


	/**
	 * @brief ���ҽ��� �����ϴ� �޴����� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief ���ҽ��� �����ϴ� �Ŵ����� �ʱ�ȭ�� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���ҽ� �Ŵ����� ���ҽ��� �߰��մϴ�.
	 *
	 * @note
	 * - ���ҽ� �Ŵ����� �ʱ�ȭ�� �������� �����Ƿ�, ��ȯ�ϴ� ������ ������ �̿��ؼ� �ʱ�ȭ�� ���� �����ؾ� �մϴ�.
	 * - ���ҽ��� �ñ״�ó ���� �ߺ��� ������� �ʽ��ϴ�.
	 *
	 * @param signature �Ŵ��� ���ο��� ���ҽ����� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @return �߰��� ���ҽ��� �����͸� ����ϴ�.
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
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� ����ϴ�.
	 *
	 * @param signature �Ŵ��� ���ο��� ���ҽ����� ������ �ñ״�ó ���Դϴ�.
	 *
	 * @return �ñ״�ó�� �����ϴ� ���ҽ��� �����͸� ����ϴ�. �ñ״�ó ���� �����ϴ� ���ҽ��� ������ �� �����͸� ��ȯ�մϴ�.
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
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��� �����մϴ�.
	 *
	 * @param signature ������ ���ҽ��� �ñ״�ó ���Դϴ�.
	 */
	void RemoveResource(const std::string& signature);


private:
	/**
	 * @brief ���ҽ��� �����ϴ� �Ŵ����� ����Ʈ �����ڿ� ���� �Ҹ��ڸ� �߰��մϴ�.
	 */
	DEFAULT_CONSTRUCTOR_AND_VIRTUAL_DESTRUCTOR(ResourceManager);


private:
	/**
	 * @brief ���ҽ� �Ŵ����� �����ϴ� ���ҽ��Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<IResource>> resources_;
};