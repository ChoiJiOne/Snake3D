#pragma once

#include <string>

#include "GameObject/IGameObject.h"


class CubeMap; // ť��� ���ҽ��� ����ϱ� ���� ���� �����Դϴ�.


/**
 * @brief ���� ��� ������Ʈ�Դϴ�.
 */
class SpaceBackground : public IGameObject
{
public:
	/**
	 * @brief ���� ��� ������Ʈ �������̽��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	SpaceBackground() = default;


	/**
	 * @brief ���� ��� ������Ʈ �������̽��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���� ��� ������Ʈ �������̽��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~SpaceBackground();


	/**
	 * @brief ���� ��� ������Ʈ �������̽��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpaceBackground);


	/**
	 * @brief ���� ��� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param cameraSignature ���� ��� ������ �� ������ ī�޶� ������Ʈ�� �ñ״�ó ���Դϴ�.
	 */
	void Initialize(const std::string& cameraSignature);


	/**
	 * @brief ���� ��� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @note ���� ��� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ���� ��� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 *
	 * @note ���� ��� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ���� ��� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 *
	 * @note ���� ��� ������Ʈ �������̽��� ��ӹ޴� ���� Ŭ�������� �ݵ�� �����ؾ� �մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ť��� ���ҽ��Դϴ�.
	 */
	CubeMap* cubeMap_ = nullptr;


	/**
	 * @brief ť��� �������� ������ ī�޶� ������Ʈ �ñ״�ó ���Դϴ�.
	 */
	std::string cameraSignature_;
};