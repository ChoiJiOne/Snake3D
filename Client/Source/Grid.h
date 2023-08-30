#pragma once

#include <vector>

#include "Cell.h"

#include "Game/IGameObject.h"

#include "Vector/Vector.h"

class Camera3D;
class Model;


/**
 * @brief ������ ����� �׸����Դϴ�.
 */
class Grid : public IGameObject
{
public:
	/**
	 * @brief ������ ����� �׸��� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Grid() = default;


	/**
	 * @brief ������ ����� �׸��� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���� ī�޶� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Grid();


	/**
	 * @brief ������ ����� �׸��� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Grid);


	/**
	 * @brief ������ ����� �׸��� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param minX �׸��� ���� �߽� ��ǥ �� �ּ� X��ǥ���Դϴ�.
	 * @param maxX �׸��� ���� �߽� ��ǥ �� �ִ� X��ǥ���Դϴ�.
	 * @param minZ �׸��� ���� �߽� ��ǥ �� �ּ� Z��ǥ���Դϴ�.
	 * @param maxZ �׸��� ���� �߽� ��ǥ �� �ִ� Z��ǥ���Դϴ�.
	 */
	void Initialize(int32_t minX, int32_t maxX, int32_t minZ, int32_t maxZ);


	/**
	 * @brief ������ ����� �׸��� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ������ ����� �׸��� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ������ ����� �׸��� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief XZ ��� ���� ���� �����մϴ�.
	 * 
	 * @return ������ XZ ��� ���� ���� �����͸� ��ȯ�մϴ�.
	 */
	Model* CreateXZQuadModel();


private:
	/**
	 * @brief ���� �׸��带 �ٶ󺸰� �ִ� ī�޶��Դϴ�.
	 */
	Camera3D* camera_ = nullptr;


	/**
	 * @brief �׸����� XZ ��� ���� �� �Դϴ�.
	 */
	Model* xzQuadModel_ = nullptr;


	/**
	 * @brief �׸��� �� �߽� ��ǥ �� �ּ� ��ǥ���Դϴ�.
	 */
	Vector3f minPosition_;


	/**
	 * @brief �׸��� �� �߽� ��ǥ �� �ִ� ��ǥ���Դϴ�.
	 */
	Vector3f maxPosition_;


	/**
	 * @brief �׸����� ���Դϴ�.
	 */
	std::vector<Cell> cells_;
};