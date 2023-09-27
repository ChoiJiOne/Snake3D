#pragma once

#include <array>
#include <list>
#include <map>

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"

class Model; // 모델 리소스를 사용하기 위한 전방선언입니다.


/**
 * @brief 유저가 플레이 가능한 뱀 오브젝트입니다.
 * 
 * @note 뱀 오브젝트는 뒤로 갈 수는 없습니다.
 */
class Snake : public IGameObject
{
public:
	/**
	 * @brief 뱀 오브젝트가 이동할 수 있는 축 방향의 열거형입니다.
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
	 * @brief 뱀 오브젝트 몸통의 색상 타입입니다.
	 * 
	 * @note 무지개의 7가지 색상입니다.
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
	 * @brief 뱀 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Snake() = default;


	/**
	 * @brief 뱀 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 뱀 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Snake();


	/**
	 * @brief 뱀 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Snake);


	/**
	 * @brief 뱀 오브젝트를 초기화합니다.
	 */
	void Initialize();


	/**
	 * @brief 뱀 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 뱀 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 뱀 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 뱀의 머리 위치를 얻습니다.
	 * 
	 * @return 뱀의 머리 위치값을 반환합니다.
	 */
	glm::vec3 GetHeadPosition() const;


	/**
	 * @brief 뱀의 몸통 위치값들을 얻습니다.
	 * 
	 * @return 뱀의 몸통 위치값들을 리스트로 반환합니다.
	 */
	const std::list<glm::vec3>& GetBodyPositions() const { return bodyPositions_; }


	/**
	 * @brief 뱀이 스스로 이동하는 시간값을 얻습니다.
	 * 
	 * @return 뱀이 스스로 이동하는 시간값을 반환합니다.
	 */
	float GetMoveStepTime() const { return moveStepTime_; }


	/**
	 * @brief 뱀이 스스로 이동하는 시간값을 설정합니다.
	 * 
	 * @param moveStepTime 설정할 뱀이 스스로 이동하는 시간값입니다.
	 */
	void SetMoveStepTime(float moveStepTime) { moveStepTime_ = moveStepTime; }
	

private:
	/**
	 * @brief 뱀을 현재 이동 방향을 기준으로 이동시킵니다.
	 */
	void Move();


	/**
	 * @brief 뱀을 이동시킬 수 있는지 확인합니다.
	 * 
	 * @param direction 이동 가능한지 확인할 방향입니다.
	 */
	bool CanMove(const EAxisDirection& axisDirection);


	/**
	 * @brief 뱀이 먹이를 먹을 수 있는지 확인합니다.
	 * 
	 * @return 뱀이 먹이를 먹을 수 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool CanEatFood();


private:
	/**
	 * @brief 뱀의 몸통 위치입니다.
	 */
	std::list<glm::vec3> bodyPositions_;


	/**
	 * @brief 현재 이동 방향입니다.
	 */
	EAxisDirection currentDirection_ = EAxisDirection::None;


	/**
	 * @brief 이동 방향에 대응하는 벡터값입니다.
	 */
	std::map<EAxisDirection, glm::vec3> directionVectors;


	/**
	 * @brief 뱀이 스스로 이동하는 시간입니다.
	 */
	float moveStepTime_ = 0.0f;


	/**
	 * @brief 뱀이 스스로 이동하는 최대 시간입니다.
	 */
	const float maxMoveStepTime_ = 0.4f;
	

	/**
	 * @brief 뱀이 스스로 이동하는 최소 시간입니다.
	 */
	const float minMoveStepTime_ = 0.1f;


	/**
	 * @brief 뱀이 스스로 이동하는 누적 시간값입니다.
	 */
	float moveAccumulateTime_ = 0.0f;


	/**
	 * @brief 누적된 뱀이 먹은 먹이의 수입니다.
	 */
	int32_t numOfEatingFood_ = 0;


	/**
	 * @brief 최대 누적 먹이 수입니다.
	 */
	const int32_t maxNumOfEatingFood_ = 7;


	/**
	 * @brief 뱀 몸통의 색상 목록입니다.
	 */
	std::array<EColorType, 7> bodyColors_;


	/**
	 * @brief 컬러에 대응하는 뱀의 모델입니다.
	 */
	std::map<EColorType, Model*> colorToModels_;
};