#pragma once

#include <array>
#include <list>
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


	/**
	 * @brief �� ������Ʈ ������ ���� Ÿ���Դϴ�.
	 * 
	 * @note �������� 7���� �����Դϴ�.
	 */
	enum class EColorType : int32_t
	{
		Red = 0x00,    // (1.0, 0.0, 0.0)
		Orange = 0x01, // (1.0, 0.5, 0.0)
		Yellow = 0x02, // (1.0, 1.0, 0.0)
		Green = 0x03,  // (0.0, 1.0, 0.0)
		Blue = 0x04,   // (0.0, 0.0, 1.0)
		Indigo = 0x05, // (0.0, 0.0, 0.5)
		Violet = 0x06, // (0.5, 0.0, 0.5)
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
	 */
	void Initialize();


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
	 * @brief ���� �Ӹ� ��ġ�� ����ϴ�.
	 * 
	 * @return ���� �Ӹ� ��ġ���� ��ȯ�մϴ�.
	 */
	glm::vec3 GetHeadPosition() const;


	/**
	 * @brief ���� ���� ��ġ������ ����ϴ�.
	 * 
	 * @return ���� ���� ��ġ������ ����Ʈ�� ��ȯ�մϴ�.
	 */
	const std::list<glm::vec3>& GetBodyPositions() const { return bodyPositions_; }


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


	/**
	 * @brief ���� ���� �̵� ������ ����ϴ�.
	 * 
	 * @return ���� ���� �̵� ������ ��ȯ�մϴ�.
	 */
	EAxisDirection GetAxisDirection() const { return currentDirection_; }
	

private:
	/**
	 * @brief ���� ���� �̵� ������ �������� �̵���ŵ�ϴ�.
	 */
	void Move();


	/**
	 * @brief ���� �̵���ų �� �ִ��� Ȯ���մϴ�.
	 * 
	 * @param direction �̵� �������� Ȯ���� �����Դϴ�.
	 */
	bool CanMove(const EAxisDirection& axisDirection);


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
	std::list<glm::vec3> bodyPositions_;


	/**
	 * @brief ���� �̵� �����Դϴ�.
	 */
	EAxisDirection currentDirection_ = EAxisDirection::None;


	/**
	 * @brief �̵� ���⿡ �����ϴ� ���Ͱ��Դϴ�.
	 */
	std::map<EAxisDirection, glm::vec3> directionVectors;


	/**
	 * @brief ���� ������ �̵��ϴ� �ð��Դϴ�.
	 */
	float moveStepTime_ = 0.0f;


	/**
	 * @brief ���� ������ �̵��ϴ� �ִ� �ð��Դϴ�.
	 */
	const float maxMoveStepTime_ = 0.4f;
	

	/**
	 * @brief ���� ������ �̵��ϴ� �ּ� �ð��Դϴ�.
	 */
	const float minMoveStepTime_ = 0.1f;


	/**
	 * @brief ���� ������ �̵��ϴ� ���� �ð����Դϴ�.
	 */
	float moveAccumulateTime_ = 0.0f;


	/**
	 * @brief ������ ���� ���� ������ ���Դϴ�.
	 */
	int32_t numOfEatingFood_ = 0;


	/**
	 * @brief �ִ� ���� ���� ���Դϴ�.
	 */
	const int32_t maxNumOfEatingFood_ = 7;


	/**
	 * @brief �� ������ ���� ����Դϴ�.
	 */
	std::array<EColorType, 7> bodyColors_;


	/**
	 * @brief �÷��� �����ϴ� ���� ���Դϴ�.
	 */
	std::map<EColorType, Model*> colorToModels_;
};