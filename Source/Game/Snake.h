#pragma once

#include <map>

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"

class Model; // �� ���ҽ��� ����ϱ� ���� ���漱���Դϴ�.


/**
 * @brief ������ �÷��� ������ �� ������Ʈ�Դϴ�.
 * 
 * @note �� ������Ʈ�� �ڷ� �� ���� �����ϴ�.
 */
class Snake : public IGameObject
{
public:
	/**
	 * @brief �� ������Ʈ�� �̵��� �� �ִ� �� ������ �������Դϴ�.
	 */
	enum class EAxisDirection : int32_t
	{
		None = 0x00,      // (+0.0f, +0.0f, +0.0f)
		PositiveX = 0x01, // (+1.0f, +0.0f, +0.0f)
		NegativeX = 0x02, // (-1.0f, +0.0f, +0.0f)
		PositiveZ = 0x03, // (+0.0f, +0.0f, +1.0f)
		NegativeZ = 0x04, // (+0.0f, +0.0f, -1.0f)
	};


public:
	/**
	 * @brief �� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Snake() = default;


	/**
	 * @brief �� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note �� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Snake();


	/**
	 * @brief �� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Snake);


	/**
	 * @brief �� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 * 
	 * @param color ���� RGB�����Դϴ�.
	 */
	void Initialize(const glm::vec3& colorRGB);


	/**
	 * @brief �� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief �� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief �� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���� ���� ��ġ�� ����ϴ�.
	 * 
	 * @return ���� ���� ��ġ���� ��ȯ�մϴ�.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief ���� ������ �̵��ϴ� �ð����� ����ϴ�.
	 * 
	 * @return ���� ������ �̵��ϴ� �ð����� ��ȯ�մϴ�.
	 */
	float GetMoveStepTime() const { return moveStepTime_; }


	/**
	 * @brief ���� ������ �̵��ϴ� �ð����� �����մϴ�.
	 * 
	 * @param moveStepTime ������ ���� ������ �̵��ϴ� �ð����Դϴ�.
	 */
	void SetMoveStepTime(float moveStepTime) { moveStepTime_ = moveStepTime; }
	

private:
	/**
	 * @brief ���� ���� �̵� ������ �������� �̵���ŵ�ϴ�.
	 */
	void Move();


	/**
	 * @brief ���� �׸��� ���� ���� ������� Ȯ���մϴ�.
	 * 
	 * @return ���� �׸��� ���� �ۿ� ����ٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsExitGrid();


	/**
	 * @brief ���� ���̸� ���� �� �ִ��� Ȯ���մϴ�.
	 * 
	 * @return ���� ���̸� ���� �� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool CanEatFood();


private:
	/**
	 * @brief ���� ���� ��ġ�Դϴ�.
	 */
	glm::vec3 position_ = glm::vec3(0.0f, 0.5f, 0.0f);


	/**
	 * @brief ���� �̵� �����Դϴ�.
	 */
	EAxisDirection currentDirection_ = EAxisDirection::None;


	/**
	 * @brief ���� ���Դϴ�.
	 */
	Model* model_ = nullptr;


	/**
	 * @brief �̵� ���⿡ �����ϴ� ���Ͱ��Դϴ�.
	 */
	std::map<EAxisDirection, glm::vec3> directionVectors;


	/**
	 * @brief ���� ������ �̵��ϴ� �ð��Դϴ�.
	 */
	float moveStepTime_ = 1.0f;


	/**
	 * @brief ���� ������ �̵��ϴ� ���� �ð����Դϴ�.
	 */
	float moveAccumulateTime_ = 0.0f;
};