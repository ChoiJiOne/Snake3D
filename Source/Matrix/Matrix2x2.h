#pragma once


/**
 * @brief ���ø� ����� 2x2 ����Դϴ�.
 */
template <typename T>
struct Matrix2x2
{
	/**
	 * @brief ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix2x2() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0);
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 */
	Matrix2x2(
		T&& m00, T&& m01,
		T&& m10, T&& m11
	)
	{
		m[0][0] = m00; m[0][1] = m01;
		m[1][0] = m10; m[1][1] = m11;
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 */
	Matrix2x2(
		const T& m00, const T& m01,
		const T& m10, const T& m11
	)
	{
		m[0][0] = m00; m[0][1] = m01;
		m[1][0] = m10; m[1][1] = m11;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix2x2(T&& element) noexcept
	{
		m[0][0] = element; m[0][1] = element;
		m[1][0] = element; m[1][1] = element;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix2x2(const T& element) noexcept
	{
		m[0][0] = element; m[0][1] = element;
		m[1][0] = element; m[1][1] = element;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix2x2(Matrix2x2<T>&& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix2x2(const Matrix2x2<T>& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator=(Matrix2x2<T>&& instance) noexcept
	{
		if (this == &instance) return *this;

		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1];

		return *this;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator=(const Matrix2x2<T>& instance) noexcept
	{
		if (this == &instance) return *this;

		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1];

		return *this;
	}


	/**
	 * @brief ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� - ��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-() const
	{
		return Matrix2x2<T>(
			-m[0][0], -m[0][1],
			-m[1][0], -m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator+(Matrix2x2<T>&& instance)
	{
		return Matrix2x2<T>(
			m[0][0] + instance.m[0][0], m[0][1] + instance.m[0][1],
			m[1][0] + instance.m[1][0], m[1][1] + instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator+(const Matrix2x2<T>& instance)
	{
		return Matrix2x2<T>(
			m[0][0] + instance.m[0][0], m[0][1] + instance.m[0][1],
			m[1][0] + instance.m[1][0], m[1][1] + instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-(Matrix2x2<T>&& instance)
	{
		return Matrix2x2<T>(
			m[0][0] - instance.m[0][0], m[0][1] - instance.m[0][1],
			m[1][0] - instance.m[1][0], m[1][1] - instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-(const Matrix2x2<T>& instance)
	{
		return Matrix2x2<T>(
			m[0][0] - instance.m[0][0], m[0][1] - instance.m[0][1],
			m[1][0] - instance.m[1][0], m[1][1] - instance.m[1][1]
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator*(Matrix2x2<T>&& instance)
	{
		return Matrix2x2(
			m[0][0] * instance.m[0][0] + m[0][1] * instance.m[1][0],
			m[0][0] * instance.m[0][1] + m[0][1] * instance.m[1][1],
			m[1][0] * instance.m[0][0] + m[1][1] * instance.m[1][0],
			m[1][0] * instance.m[0][1] + m[1][1] * instance.m[1][1]
		);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator*(const Matrix2x2<T>& instance)
	{
		return Matrix2x2(
			m[0][0] * instance.m[0][0] + m[0][1] * instance.m[1][0],
			m[0][0] * instance.m[0][1] + m[0][1] * instance.m[1][1],
			m[1][0] * instance.m[0][0] + m[1][1] * instance.m[1][0],
			m[1][0] * instance.m[0][1] + m[1][1] * instance.m[1][1]
		);
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator+=(Matrix2x2<T>&& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator+=(const Matrix2x2<T>& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator-=(Matrix2x2<T>&& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator-=(const Matrix2x2<T>& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1];

		return *this;
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Matrix2x2<T>&& instance) noexcept
	{
		return (m[0][0] == instance.m[0][0])
			&& (m[0][1] == instance.m[0][1])
			&& (m[1][0] == instance.m[1][0])
			&& (m[1][1] == instance.m[1][1]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Matrix2x2<T>& instance) noexcept
	{
		return (m[0][0] == instance.m[0][0])
			&& (m[0][1] == instance.m[0][1])
			&& (m[1][0] == instance.m[1][0])
			&& (m[1][1] == instance.m[1][1]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Matrix2x2<T>&& instance) noexcept
	{
		return (m[0][0] != instance.m[0][0])
			|| (m[0][1] != instance.m[0][1])
			|| (m[1][0] != instance.m[1][0])
			|| (m[1][1] != instance.m[1][1]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Matrix2x2<T>& instance) noexcept
	{
		return (m[0][0] != instance.m[0][0])
			|| (m[0][1] != instance.m[0][1])
			|| (m[1][0] != instance.m[1][0])
			|| (m[1][1] != instance.m[1][1]);
	}


	/**
	 * @brief ����� ���� ��ķ� �����մϴ�.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1);
	}


	/**
	 * @brief ����� �����Դϴ�.
	 */
	T m[2][2];
};