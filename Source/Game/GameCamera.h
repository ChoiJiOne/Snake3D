#pragma once

#include "GameObject/Camera3D.h"


/**
 * @brief ���� ���� ī�޶� ������Ʈ�Դϴ�.
 */
class GameCamera : public Camera3D
{
public:
	/**
	 * @brief ���� ���� ī�޶� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	GameCamera() = default;


	/**
	 * @brief ���� ���� ī�޶� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���� ���� ī�޶� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~GameCamera();


	/**
	 * @brief ���� ���� ī�޶� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GameCamera);


	/**
	 * @brief ���� ���� ī�޶� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @note ���� ���� ī�޶�� �׻� ������ �ٶ󺸰� �ֽ��ϴ�.
	 *
	 * @param eyePosition ī�޶��� ���� �� ��ġ�Դϴ�.
	 * @param fovRadians ����� ���� �ʵ� ����(����)�Դϴ�.
	 * @param aspectRatio �� ������ X:Y �����Դϴ�.
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 */
	void Initialize(const glm::vec3& eyePosition, float fovRadians, float aspectRatio, float nearZ, float farZ);


	/**
	 * @brief ���� ���� ī�޶� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ���� ���� ī�޶� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ���� ���� ī�޶� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;
};