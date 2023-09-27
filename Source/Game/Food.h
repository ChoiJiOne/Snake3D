#pragma once

#include <array>
#include <map>

#include <glm/glm.hpp>

#include "GameObject/IGameObject.h"

class Model; // �� ���ҽ��� ����ϱ� ���� ���漱���Դϴ�.


/**
 * @brief ���� �����Դϴ�.
 */
class Food : public IGameObject
{
public:
	/**
	 * @brief ���� ���� �����Դϴ�.
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
	 * @brief ���� ���� ������Ʈ�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Food() = default;


	/**
	 * @brief ���� ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 *
	 * @note �� ������Ʈ�� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Food();


	/**
	 * @brief ���� ���� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Food);


	/**
	 * @brief ���� ���� ������Ʈ�� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief ���� ���� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param deltaSeconds ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Update(float deltaSeconds) override;


	/**
	 * @brief ���� ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 */
	virtual void Render() override;


	/**
	 * @brief ���� ���� ������Ʈ ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ ��ġ�� ����ϴ�.
	 * 
	 * @return ������ ��ġ���� ��ȯ�մϴ�.
	 */
	glm::vec3 GetPosition() const { return position_; }


	/**
	 * @brief ���̰� �������Ǵ� �ð����� ����ϴ�.
	 *
	 * @return ���̰� �������Ǵ� �ð����� ��ȯ�մϴ�.
	 */
	float GetResponeStepTime() const { return responeStepTime_; }


	/**
	 * @brief ���̰� �������Ǵ� �ð����� �����մϴ�.
	 *
	 * @param responeStepTime ���̰� �������Ǵ� �ð����Դϴ�.
	 */
	void SetResponeStepTime(float responeStepTime) { responeStepTime_ = responeStepTime; }


	/**
	 * @brief ������ Ȱ��ȭ ���θ� ����ϴ�.
	 * 
	 * @return ���̰� Ȱ��ȭ �Ǿ� �ִٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsActive() const { return bIsActive_; }


	/**
	 * @brief ������ Ȱ��ȭ ���θ� �����մϴ�.
	 * 
	 * @param bIsActive ������ ���� Ȱ��ȭ �����Դϴ�.
	 */
	void SetActive(float bIsActive) { bIsActive_ = bIsActive; }


private:
	/**
	 * @brief ������ ������ Ÿ���� ����ϴ�.
	 * 
	 * @return None Ÿ���� ������ ������ Ÿ���� ��ȯ�մϴ�.
	 */
	EType GetRandomFoodType() const;


	/**
	 * @brief ������ ��ġ�� ��ġ�մϴ�.
	 */
	void BatchRandomPosition();
	

private:
	/**
	 * @brief ���� ������ Ÿ���Դϴ�.
	 */
	EType currentType_ = EType::None;


	/**
	 * @brief ���� ������ ��ġ�Դϴ�.
	 */
	glm::vec3 position_;


	/**
	 * @brief ������ Ȱ��ȭ �����Դϴ�.
	 */
	bool bIsActive_ = true;


	/**
	 * @brief ���� �ð����Դϴ�.
	 */
	float accumulateTime_ = 0.0f;


	/**
	 * @brief ���� ������ �ð��Դϴ�.
	 */
	float responeStepTime_ = 1.0f;


	/**
	 * @brief ���� �������� ���� ���� �ð��Դϴ�.
	 */
	float responeAccumulateTime_ = 0.0f;


	/**
	 * @brief ���� Ÿ�Կ� ���� �� ���ҽ��Դϴ�.
	 */
	std::map<EType, Model*> typeToModels_;
};