#pragma once

#include <vector>

#include "Cell.h"

#include "Game/IGameObject.h"

#include "Vector/Vector.h"

class Camera3D;
class Model;


/**
 * @brief 게임이 진행될 그리드입니다.
 */
class Grid : public IGameObject
{
public:
	/**
	 * @brief 게임이 진행될 그리드 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Grid() = default;


	/**
	 * @brief 게임이 진행될 그리드 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Grid();


	/**
	 * @brief 게임이 진행될 그리드 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Grid);


	/**
	 * @brief 게임이 진행될 그리드 오브젝트를 초기화합니다.
	 * 
	 * @param minX 그리드 셀의 중심 좌표 중 최소 X좌표값입니다.
	 * @param maxX 그리드 셀의 중심 좌표 중 최대 X좌표값입니다.
	 * @param minZ 그리드 셀의 중심 좌표 중 최소 Z좌표값입니다.
	 * @param maxZ 그리드 셀의 중심 좌표 중 최대 Z좌표값입니다.
	 */
	void Initialize(int32_t minX, int32_t maxX, int32_t minZ, int32_t maxZ);


	/**
	 * @brief 게임이 진행될 그리드 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 게임이 진행될 그리드 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 게임이 진행될 그리드 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 그리드 셀 중심 좌표 중 최소 좌표값을 얻습니다.
	 * 
	 * @return 그리드 셀 중심 좌표 중 최소 좌표값을 반환합니다.
	 */
	Vector3f GetMinPosition() const { return minPosition_; }


	/**
	 * @brief 그리드 셀 중심 좌표 중 최대 좌표값을 얻습니다.
	 * 
	 * @return 그리드 셀 중심 좌표 중 최대 좌표값을 반환합니다.
	 */
	Vector3f GetMaxPosition() const { return maxPosition_; }


private:
	/**
	 * @brief XZ 평면 쿼드 모델을 생성합니다.
	 * 
	 * @return 생성된 XZ 평면 쿼드 모델의 포인터를 반환합니다.
	 */
	Model* CreateXZQuadModel();


private:
	/**
	 * @brief 현재 그리드를 바라보고 있는 카메라입니다.
	 */
	Camera3D* camera_ = nullptr;


	/**
	 * @brief 그리드의 XZ 평면 쿼드 모델 입니다.
	 */
	Model* xzQuadModel_ = nullptr;


	/**
	 * @brief 그리드 셀 중심 좌표 중 최소 좌표값입니다.
	 */
	Vector3f minPosition_;


	/**
	 * @brief 그리드 셀 중심 좌표 중 최대 좌표값입니다.
	 */
	Vector3f maxPosition_;


	/**
	 * @brief 그리드의 셀입니다.
	 */
	std::vector<Cell> cells_;
};