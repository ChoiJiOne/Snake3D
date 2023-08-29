#pragma once

#include "Vector/Vector.h"


/**
 * @brief �׸���(����)�� �� �����Դϴ�.
 */
class Cell
{
public:
	/**
	 * @brief �׸��� �� ������ �����Դϴ�.
	 * 
	 * @note
	 * - �׸����� �� ������ GRAY(ȸ��) �����̸�, ���� �׳� ������ �� �ִ� �����Դϴ�.
	 * - �׸����� �� ������ GREEN(ȸ��) ������ ��, ���� �������� ũ�Ⱑ Ŀ���ϴ�.
	 * - �׸����� �� ������ RED(������) ������ ��, ���� �������� ������ ����˴ϴ�.
	 */
	enum class EState : int32_t
	{
		GRAY  = 0x00,
		GREEN = 0x01,
		RED   = 0x02,
	};


public:
	/**
	 * @brief �׸��� �� ���� ������ �������Դϴ�.
	 */
	Cell() : state_(EState::GRAY), transform_(0.0f, 0.0f, 0.0f) {}


	/**
	 * @brief �׸��� �� ���� ������ �������Դϴ�.
	 * 
	 * @param state �׸��� �� ������ �����Դϴ�.
	 * @param transform �׸��� �� ������ ��ȯ�� ��ġ ���Դϴ�.
	 */
	Cell(const EState& state, const Vector3f& transform)
		: state_(state)
		, transform_(transform) {}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 * 
	 * @param instance ������ �ν��Ͻ��Դϴ�.
	 */
	Cell(Cell&& instance) noexcept
		: state_(instance.state_)
		, transform_(instance.transform_) {}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ������ �ν��Ͻ��Դϴ�.
	 */
	Cell(const Cell& instance) noexcept
		: state_(instance.state_)
		, transform_(instance.transform_) {}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 * 
	 * @param instance ���� ������ ���� ������ �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Cell& operator=(Cell&& instance) noexcept
	{
		if (this == &instance) return *this;

		state_ = instance.state_;
		transform_ = instance.transform_;

		return *this;
	}


	/**
	 * @brief �׸��� �� ���� ������ ���� �������Դϴ�.
	 *
	 * @param instance ���� ������ ���� ������ �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Cell& operator=(const Cell& instance) noexcept
	{
		if (this == &instance) return *this;

		state_ = instance.state_;
		transform_ = instance.transform_;

		return *this;
	}


	/**
	 * @brief ���� �׸��� �� ���� ���¸� ����ϴ�.
	 * 
	 * @return ���� �׸��� �� ���� ���¸� ��ȯ�մϴ�.
	 */
	EState GetState() const { return state_; }


	/**
	 * @brief ���� �׸��� �� ���� ���¸� �����մϴ�.
	 * 
	 * @param state ������ �׸��� �� ���� �����Դϴ�.
	 */
	void SetState(const EState& state) { state_ = state; }


	/**
	 * @brief ���� �׸��� �� ������ ��ȯ�� ��ġ���� ����ϴ�.
	 * 
	 * @return ���� �׸��� �� ������ ��ȯ�� ��ġ���� ��ȯ�մϴ�.
	 */
	Vector3f GetTransform() const { return transform_; }


	/**
	 * @brief ���� �׸��� �� ������ ��ȯ�� ��ġ���� �����մϴ�.
	 * 
	 * @param transform ������ �׸��� �� ������ ��ȯ�� ��ġ���Դϴ�.
	 */
	void SetTransform(const Vector3f& transform) { transform_ = transform; }


private:
	/**
	 * @brief ���� �׸��� �� ������ �����Դϴ�.
	 */
	EState state_ = EState::GRAY;


	/**
	 * @brief ���� �׸��� �� ������ ��ȯ�� ��ġ ���Դϴ�.
	 */
	Vector3f transform_;
};