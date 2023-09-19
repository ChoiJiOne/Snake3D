#pragma once

#include <string>

#include "Resource/IResource.h"


/**
 * @brief ť�� �� ���ҽ��Դϴ�.
 */
class CubeMap : public IResource
{
public:
	/**
	 * @brief ť����� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	CubeMap() = default;


	/**
	 * @brief ť����� ���� �Ҹ����Դϴ�.
	 *
	 * @note �޽� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~CubeMap();


	/**
	 * @brief ť����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(CubeMap);


	/**
	 * @brief ť����� �ʱ�ȭ�մϴ�.
	 * 
	 * @param ť��� RIGHT(+X) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param ť��� LEFT(-X) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param ť��� TOP(+Y) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param ť��� BOTTOM(-Y) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param ť��� FRONT(+Z) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param ť��� BACK(-Z) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 */
	void Initialize(
		const std::string& rightPath, 
		const std::string& leftPath,
		const std::string& topPath,
		const std::string& bottomPath,
		const std::string& frontPath,
		const std::string& backPath
	);


	/**
	 * @brief ť��� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ť��� �ؽ�ó�� ID�� ����ϴ�.
	 * 
	 * @return ť��� �ؽ�ó�� ID�� ��ȯ�մϴ�.
	 */
	uint32_t GetResourceID() { return cubeMapID_; }


private:
	/**
	 * @brief ť��� �ؽ�ó�� ID�Դϴ�.
	 */
	uint32_t cubeMapID_ = 0;
};