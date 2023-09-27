#pragma once

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
	 * @brief 뱀 오브젝트가 이동할 수 있는 방향의 열거형입니다.
	 */
	enum class EMove : int32_t
	{
		None = 0x00,
		Left = 0x01,
		Right = 0x02,
		Straight = 0x03,
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
	 * 
	 * @param color 뱀의 RGB색상입니다.
	 */
	void Initialize(const glm::vec3& colorRGB);


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
	

private:
	/**
	 * @brief 뱀을 이동시킵니다.
	 * 
	 * @param move 뱀의 이동 방향입니다.
	 */
	void Move(const EMove& move);


private:
	/**
	 * @brief 뱀의 현재 위치입니다.
	 */
	glm::vec3 position_ = glm::vec3(0.0f, 0.5f, 0.0f);


	/**
	 * @brief 현재 이동 방향입니다.
	 */
	EAxisDirection currentDirection_ = EAxisDirection::None;


	/**
	 * @brief 뱀의 모델입니다.
	 */
	Model* model_ = nullptr;


	/**
	 * @brief 이동 방향에 대응하는 벡터값입니다.
	 */
	std::map<EAxisDirection, glm::vec3> directionVectors;


	/**
	 * @brief 뱀이 스스로 이동하는 시간입니다.
	 */
	float moveStepTime_ = 1.0f;


	/**
	 * @brief 뱀이 스스로 이동하는 누적 시간값입니다.
	 */
	float moveAccumulateTime_ = 0.0f;
};