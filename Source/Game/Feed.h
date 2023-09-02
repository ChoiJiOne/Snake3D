#pragma once

#include "GameObject/IGameObject.h"

#include "Vector/Vector.h"

class Camera3D;
class Model;


/**
 * @brief ���� ���� �����Դϴ�.
 */
class Feed : public IGameObject
{
public:
	/**
	 * @brief �� ���� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Feed() = default;


	/**
	 * @brief �� ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���� ī�޶� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Feed();


	/**
	 * @brief �÷��̾ Feed �� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Feed);


	/**
	 * @brief �� ���� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief �� ���� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief �� ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief �� ���� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief ������ ť�� ���� �����մϴ�.
	 *
	 * @param color ������ �����Դϴ�.
	 *
	 * @return ������ ������ ť�� ���� ��ȯ�մϴ�.
	 */
	Model* CreateCubeModel(const Vector4f& color);


private:
	/**
	 * @brief ���� ���̸� �ٶ󺸰� �ִ� ī�޶��Դϴ�.
	 */
	Camera3D* camera_ = nullptr;


	/**
	 * @brief ������ ť�� �� �Դϴ�.
	 */
	Model* cubeModel_ = nullptr;


	/**
	 * @brief ������ ���� �߽� ��ġ�Դϴ�.
	 */
	Vector3f position_;
};