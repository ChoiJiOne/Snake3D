#pragma once

#include <memory>

#include "GameObject/IGameObject.h"

#include "Vector/Vector.h"

class Camera3D;


/**
 * @brief ���� �� ���� ī�޶��Դϴ�.
 */
class MainCamera : public IGameObject
{
public:
	/**
	 * @brief ���� ī�޶� ������Ʈ�� ����Ʈ �������Դϴ�.
	 * 
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�. 
	 */
	MainCamera() = default;


	/**
	 * @brief ���� ī�޶� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 * 
	 * @note ���� ī�޶� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~MainCamera();


	/**
	 * @brief ���� ī�޶� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(MainCamera);


	/**
	 * @brief ���� ī�޶� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param eyePosition ī�޶��� ���� �� ��ġ�Դϴ�.
	 * @param focusPosition ī�޶� �ٶ󺸰� �ִ� ��ġ�Դϴ�.
	 * @param upDirection ī�޶��� �� �����Դϴ�.
	 */
	void Initialize(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& upDirection);


	/**
	 * @brief ���� ī�޶� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ���� ī�޶� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @note ���� ī�޶�� �������� �������� �ʽ��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ���� ī�޶� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief 3D ī�޶��� �����͸� ����ϴ�.
	 * 
	 * @return 3D ī�޶��� �����͸� ��ȯ�մϴ�.
	 */
	Camera3D* GetCamera3D() { return camera_.get(); }


private:
	/**
	 * @brief 3D ī�޶��Դϴ�.
	 */
	std::unique_ptr<Camera3D> camera_ = nullptr;
};