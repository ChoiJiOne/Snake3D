#pragma once

#include "GameObject/IGameObject.h"

#include "Vector/Vector.h"

class Camera3D;
class Model;


/**
 * @brief 뱀이 먹을 먹이입니다.
 */
class Feed : public IGameObject
{
public:
	/**
	 * @brief 뱀 먹이 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Feed() = default;


	/**
	 * @brief 뱀 먹이 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 메인 카메라 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Feed();


	/**
	 * @brief 플레이어가 Feed 뱀 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Feed);


	/**
	 * @brief 뱀 먹이 오브젝트를 초기화합니다.
	 */
	void Initialize();


	/**
	 * @brief 뱀 먹이 오브젝트를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 뱀 먹이 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 뱀 먹이 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


private:
	/**
	 * @brief 먹이의 큐브 모델을 생성합니다.
	 *
	 * @param color 먹이의 색상입니다.
	 *
	 * @return 생성된 먹이의 큐브 모델을 반환합니다.
	 */
	Model* CreateCubeModel(const Vector4f& color);


private:
	/**
	 * @brief 현재 먹이를 바라보고 있는 카메라입니다.
	 */
	Camera3D* camera_ = nullptr;


	/**
	 * @brief 먹이의 큐브 모델 입니다.
	 */
	Model* cubeModel_ = nullptr;


	/**
	 * @brief 먹이의 현재 중심 위치입니다.
	 */
	Vector3f position_;
};