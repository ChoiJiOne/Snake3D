#pragma once

#include "GameObject/IGameObject.h"

#include <glm/glm.hpp>

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
	 * @brief 현재 뱀의 이동 방향입니다.
	 */
	glm::vec3 direction_;


	/**
	 * @brief 뱀의 현재 위치입니다.
	 */
	glm::vec3 position_ = glm::vec3(0.0f, 0.5f, 0.0f);


	/**
	 * @brief 뱀의 모델입니다.
	 */
	Model* model_ = nullptr;
};