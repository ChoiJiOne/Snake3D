#pragma once

#include <array>
#include <map>

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"

class Model; // 모델 리소스를 사용하기 위한 전방선언입니다.


/**
 * @brief 뱀의 먹이입니다.
 */
class Food : public IGameObject
{
public:
	/**
	 * @brief 뱀의 먹이 종류입니다.
	 */
	enum class EType : int32_t
	{
		None  = 0x00,
		White = 0x01,
		Gray  = 0x02,
		Red   = 0x03,
		Green = 0x04,
		Blue  = 0x05,
	};


public:
	/**
	 * @brief 뱀의 먹이 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Food() = default;


	/**
	 * @brief 뱀의 먹이 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 뱀 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Food();


	/**
	 * @brief 뱀의 먹이 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Food);


	/**
	 * @brief 뱀의 먹이 오브젝트를 초기화합니다.
	 */
	void Initialize();


	/**
	 * @brief 뱀의 먹이 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 뱀의 먹이 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 뱀의 먹이 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 먹이의 위치를 얻습니다.
	 * 
	 * @return 먹이의 위치값을 반환합니다.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief 먹이가 리스폰되는 시간값을 얻습니다.
	 *
	 * @return 먹이가 리스폰되는 시간값을 반환합니다.
	 */
	float GetResponeStepTime() const { return responeStepTime_; }


	/**
	 * @brief 먹이가 리스폰되는 시간값을 설정합니다.
	 *
	 * @param responeStepTime 먹이가 리스폰되는 시간값입니다.
	 */
	void SetResponeStepTime(float responeStepTime) { responeStepTime_ = responeStepTime; }


	/**
	 * @brief 먹이의 활성화 여부를 얻습니다.
	 * 
	 * @return 먹이가 활성화 되어 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsActive() const { return bIsActive_; }


	/**
	 * @brief 먹이의 활성화 여부를 설정합니다.
	 * 
	 * @param bIsActive 설정할 먹이 활성화 여부입니다.
	 */
	void SetActive(float bIsActive) { bIsActive_ = bIsActive; }


private:
	/**
	 * @brief 랜덤한 먹이의 타입을 얻습니다.
	 * 
	 * @return None 타입을 제외한 먹이의 타입을 반환합니다.
	 */
	EType GetRandomFoodType() const;


	/**
	 * @brief 랜덤한 위치로 배치합니다.
	 */
	void BatchRandomPosition();
	

private:
	/**
	 * @brief 현재 먹이의 타입입니다.
	 */
	EType currentType_ = EType::None;


	/**
	 * @brief 현재 먹이의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 먹이의 활성화 여부입니다.
	 */
	bool bIsActive_ = true;


	/**
	 * @brief 누적 시간값입니다.
	 */
	float accumulateTime_ = 0.0f;


	/**
	 * @brief 먹이 리스폰 시간입니다.
	 */
	float responeStepTime_ = 1.0f;


	/**
	 * @brief 먹이 리스폰을 위한 누적 시간입니다.
	 */
	float responeAccumulateTime_ = 0.0f;


	/**
	 * @brief 먹이 타입에 따른 모델 리소스입니다.
	 */
	std::map<EType, Model*> typeToModels_;
};