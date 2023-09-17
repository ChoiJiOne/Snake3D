#pragma once

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"


/**
 * @brief 라이트 오브젝트입니다.
 */
class Light : public IGameObject
{
public:
	/**
	 * @brief 라이트 오브젝트의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Light() = default;


	/**
	 * @brief 라이트 오브젝트의 가상 소멸자입니다.
	 *
	 * @note 라이트 오브젝트의 내부 리소스를 할당 해제하기 위해서는 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Light();


	/**
	 * @brief 라이트 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Light);


	/**
	 * @brief 라이트 오브젝트를 초기화합니다.
	 * 
	 * @param position 라이트의 위치입니다.
	 * @param color 라이트의 색상입니다.
	 */
	void Initialize(const glm::vec3 position, const glm::vec4& color);


	/**
	 * @brief 라이트 오브젝트를 업데이트합니다.
	 * 
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief 라이트 오브젝트를 화면에 그립니다.
	 */
	virtual void Render() override;


	/**
	 * @brief 라이트 오브젝트 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 라이트 오브젝트의 월드 상 위치를 얻습니다.
	 * 
	 * @return 라이트 오브젝트의 월드 상 위치를 반환합니다.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief 라이트 오브젝트의 월드 상 위치를 설정합니다.
	 * 
	 * @param position 설정할 라이트 오브젝트의 월드 상 위치입니다.
	 */
	void SetPosition(const glm::vec3& position) { position_ = position; }


	/**
	 * @brief 라이트 오브젝트의 색상을 얻습니다.
	 * 
	 * @return 라이트 오브젝트의 색상을 반환합니다.
	 */
	glm::vec4 GetColor() const { return color_; }


	/**
	 * @brief 라이트 오브젝트의 색상을 설정합니다.
	 * 
	 * @param color 설정할 라이트 오브젝트의 색상입니다.
	 */
	void SetColor(const glm::vec4& color) { color_ = color; }


private:
	/**
	 * @brief 월드 상의 위치입니다.
	 */
	glm::vec3 position_;


	/**
	 * @brief 라이트의 색상입니다.
	 */
	glm::vec4 color_;
};