#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief 게임의 그리드 오브젝트입니다.
 */
class Grid : public IGameObject
{
public:
	/**
	 * @brief 그리드 오브젝트 인터페이스의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Grid() = default;


	/**
	 * @brief 그리드 오브젝트 인터페이스의 가상 소멸자입니다.
	 *
	 * @note 그리드 오브젝트 인터페이스의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Grid();


	/**
	 * @brief 그리드 오브젝트 인터페이스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Grid);


	/**
	 * @brief 그리드 오브젝트를 초기화합니다.
	 * 
	 * @param minX 그리드 셀의 중심 좌표 중 최소 X좌표값입니다.
	 * @param maxX 그리드 셀의 중심 좌표 중 최대 X좌표값입니다.
	 * @param minZ 그리드 셀의 중심 좌표 중 최소 Z좌표값입니다.
	 * @param maxZ 그리드 셀의 중심 좌표 중 최대 Z좌표값입니다.
	 * @param color 그리드의 색상입니다.
	 */
	void Initialize(int32_t minX, int32_t maxX, int32_t minZ, int32_t maxZ, const glm::vec4& color);


	/**
	 * @brief 그리드 오브젝트를 업데이트합니다.
	 *
	 * @note 그리드 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 그리드 오브젝트를 화면에 그립니다.
	 *
	 * @note 그리드 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 그리드 오브젝트 내의 리소스를 할당 해제합니다.
	 *
	 * @note 그리드 오브젝트 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Release() override;
	

	/**
	 * @brief 그리드 셀 중심 좌표 중 최소 좌표값을 얻습니다.
	 *
	 * @return 그리드 셀 중심 좌표 중 최소 좌표값을 반환합니다.
	 */
	glm::vec3 GetMinPosition() const { return minPosition_; }


	/**
	 * @brief 그리드 셀 중심 좌표 중 최대 좌표값을 얻습니다.
	 *
	 * @return 그리드 셀 중심 좌표 중 최대 좌표값을 반환합니다.
	 */
	glm::vec3 GetMaxPosition() const { return maxPosition_; }


	/**
	 * @brief 그리드의 색상을 얻습니다.
	 * 
	 * @return 그리드 색상값을 반환합니다.
	 */
	glm::vec4 GetColor() const { return color_; }


private:
	/**
	 * @brief 그리드 셀의 중심 좌표 중 최소 좌표입니다.
	 */
	glm::vec3 minPosition_;


	/**
	 * @brief 그리드 셀의 중심 좌표 중 최대 좌표입니다.
	 */
	glm::vec3 maxPosition_;


	/**
	 * @brief 그리드의 색상입니다.
	 */
	glm::vec4 color_;
};