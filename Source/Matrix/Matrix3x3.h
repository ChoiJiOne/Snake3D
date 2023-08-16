#pragma once


/**
 * @brief ���ø� ����� 3x3 ����Դϴ�.
 */
template <typename T>
struct Matrix3x3
{
	/**
	 * @brief ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix3x3() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0);
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 */
	Matrix3x3(
		T&& m00, T&& m01, T&& m02,
		T&& m10, T&& m11, T&& m12,
		T&& m20, T&& m21, T&& m22
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 */
	Matrix3x3(
		const T& m00, const T& m01, const T& m02,
		const T& m10, const T& m11, const T& m12,
		const T& m20, const T& m21, const T& m22
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix3x3(T&& element) noexcept
	{
		m[0][0] = element; m[0][1] = element; m[0][2] = element;
		m[1][0] = element; m[1][1] = element; m[1][2] = element;
		m[2][0] = element; m[2][1] = element; m[2][2] = element;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix3x3(const T& element) noexcept
	{
		m[0][0] = element; m[0][1] = element; m[0][2] = element;
		m[1][0] = element; m[1][1] = element; m[1][2] = element;
		m[2][0] = element; m[2][1] = element; m[2][2] = element;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix3x3(Matrix3x3<T>&& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix3x3(const Matrix3x3<T>& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator=(Matrix3x3<T>&& instance) noexcept
	{
		if (this == &instance) return *this;

		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2];

		return *this;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator=(const Matrix3x3<T>& instance) noexcept
	{
		if (this == &instance) return *this;

		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2];

		return *this;
	}


	/**
	 * @brief ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� - ��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator-() const
	{
		return Matrix3x3<T>(
			-m[0][0], -m[0][1], -m[0][2],
			-m[1][0], -m[1][1], -m[1][2],
			-m[2][0], -m[2][1], -m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator+(Matrix3x3<T>&& instance)
	{
		return Matrix3x3<T>(
			m[0][0] + instance.m[0][0], m[0][1] + instance.m[0][1], m[0][2] + instance.m[0][2],
			m[1][0] + instance.m[1][0], m[1][1] + instance.m[1][1], m[1][2] + instance.m[1][2],
			m[2][0] + instance.m[2][0], m[2][1] + instance.m[2][1], m[2][2] + instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator+(const Matrix3x3<T>& instance)
	{
		return Matrix3x3<T>(
			m[0][0] + instance.m[0][0], m[0][1] + instance.m[0][1], m[0][2] + instance.m[0][2],
			m[1][0] + instance.m[1][0], m[1][1] + instance.m[1][1], m[1][2] + instance.m[1][2],
			m[2][0] + instance.m[2][0], m[2][1] + instance.m[2][1], m[2][2] + instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator-(Matrix3x3<T>&& instance)
	{
		return Matrix3x3<T>(
			m[0][0] - instance.m[0][0], m[0][1] - instance.m[0][1], m[0][2] - instance.m[0][2],
			m[1][0] - instance.m[1][0], m[1][1] - instance.m[1][1], m[1][2] - instance.m[1][2],
			m[2][0] - instance.m[2][0], m[2][1] - instance.m[2][1], m[2][2] - instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator-(const Matrix3x3<T>& instance)
	{
		return Matrix3x3<T>(
			m[0][0] - instance.m[0][0], m[0][1] - instance.m[0][1], m[0][2] - instance.m[0][2],
			m[1][0] - instance.m[1][0], m[1][1] - instance.m[1][1], m[1][2] - instance.m[1][2],
			m[2][0] - instance.m[2][0], m[2][1] - instance.m[2][1], m[2][2] - instance.m[2][2]
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator*(Matrix3x3<T>&& instance)
	{
		return Matrix3x3(
			m[0][0] * instance.m[0][0] + m[0][1] * instance.m[1][0] + m[0][2] * instance.m[2][0],
			m[0][0] * instance.m[0][1] + m[0][1] * instance.m[1][1] + m[0][2] * instance.m[2][1],
			m[0][0] * instance.m[0][2] + m[0][1] * instance.m[1][2] + m[0][2] * instance.m[2][2],
			m[1][0] * instance.m[0][0] + m[1][1] * instance.m[1][0] + m[1][2] * instance.m[2][0],
			m[1][0] * instance.m[0][1] + m[1][1] * instance.m[1][1] + m[1][2] * instance.m[2][1],
			m[1][0] * instance.m[0][2] + m[1][1] * instance.m[1][2] + m[1][2] * instance.m[2][2],
			m[2][0] * instance.m[0][0] + m[2][1] * instance.m[1][0] + m[2][2] * instance.m[2][0],
			m[2][0] * instance.m[0][1] + m[2][1] * instance.m[1][1] + m[2][2] * instance.m[2][1],
			m[2][0] * instance.m[0][2] + m[2][1] * instance.m[1][2] + m[2][2] * instance.m[2][2],
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix3x3<T> operator*(const Matrix3x3<T>& instance)
	{
		return Matrix3x3(
			m[0][0] * instance.m[0][0] + m[0][1] * instance.m[1][0] + m[0][2] * instance.m[2][0],
			m[0][0] * instance.m[0][1] + m[0][1] * instance.m[1][1] + m[0][2] * instance.m[2][1],
			m[0][0] * instance.m[0][2] + m[0][1] * instance.m[1][2] + m[0][2] * instance.m[2][2],
			m[1][0] * instance.m[0][0] + m[1][1] * instance.m[1][0] + m[1][2] * instance.m[2][0],
			m[1][0] * instance.m[0][1] + m[1][1] * instance.m[1][1] + m[1][2] * instance.m[2][1],
			m[1][0] * instance.m[0][2] + m[1][1] * instance.m[1][2] + m[1][2] * instance.m[2][2],
			m[2][0] * instance.m[0][0] + m[2][1] * instance.m[1][0] + m[2][2] * instance.m[2][0],
			m[2][0] * instance.m[0][1] + m[2][1] * instance.m[1][1] + m[2][2] * instance.m[2][1],
			m[2][0] * instance.m[0][2] + m[2][1] * instance.m[1][2] + m[2][2] * instance.m[2][2],
			);
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator+=(Matrix3x3<T>&& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1]; m[0][2] += instance.m[0][2];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1]; m[1][2] += instance.m[1][2];
		m[2][0] += instance.m[2][0]; m[2][1] += instance.m[2][1]; m[2][2] += instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator+=(const Matrix3x3<T>& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1]; m[0][2] += instance.m[0][2];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1]; m[1][2] += instance.m[1][2];
		m[2][0] += instance.m[2][0]; m[2][1] += instance.m[2][1]; m[2][2] += instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator-=(Matrix3x3<T>&& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1]; m[0][2] -= instance.m[0][2];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1]; m[1][2] -= instance.m[1][2];
		m[2][0] -= instance.m[2][0]; m[2][1] -= instance.m[2][1]; m[2][2] -= instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator-=(const Matrix3x3<T>& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1]; m[0][2] -= instance.m[0][2];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1]; m[1][2] -= instance.m[1][2];
		m[2][0] -= instance.m[2][0]; m[2][1] -= instance.m[2][1]; m[2][2] -= instance.m[2][2];

		return *this;
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Matrix3x3<T>&& instance) noexcept
	{
		return (m[0][0] == instance.m[0][0])
			&& (m[0][1] == instance.m[0][1])
			&& (m[0][2] == instance.m[0][2])
			&& (m[1][0] == instance.m[1][0])
			&& (m[1][1] == instance.m[1][1])
			&& (m[1][2] == instance.m[1][2])
			&& (m[2][0] == instance.m[2][0])
			&& (m[2][1] == instance.m[2][1])
			&& (m[2][2] == instance.m[2][2]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Matrix3x3<T>& instance) noexcept
	{
		return (m[0][0] == instance.m[0][0])
			&& (m[0][1] == instance.m[0][1])
			&& (m[0][2] == instance.m[0][2])
			&& (m[1][0] == instance.m[1][0])
			&& (m[1][1] == instance.m[1][1])
			&& (m[1][2] == instance.m[1][2])
			&& (m[2][0] == instance.m[2][0])
			&& (m[2][1] == instance.m[2][1])
			&& (m[2][2] == instance.m[2][2]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Matrix3x3<T>&& instance) noexcept
	{
		return (m[0][0] != instance.m[0][0])
			|| (m[0][1] != instance.m[0][1])
			|| (m[0][2] != instance.m[0][2])
			|| (m[1][0] != instance.m[1][0])
			|| (m[1][1] != instance.m[1][1])
			|| (m[1][2] != instance.m[1][2])
			|| (m[2][0] != instance.m[2][0])
			|| (m[2][1] != instance.m[2][1])
			|| (m[2][2] != instance.m[2][2]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Matrix3x3<T>& instance) noexcept
	{
		return (m[0][0] != instance.m[0][0])
			|| (m[0][1] != instance.m[0][1])
			|| (m[0][2] != instance.m[0][2])
			|| (m[1][0] != instance.m[1][0])
			|| (m[1][1] != instance.m[1][1])
			|| (m[1][2] != instance.m[1][2])
			|| (m[2][0] != instance.m[2][0])
			|| (m[2][1] != instance.m[2][1])
			|| (m[2][2] != instance.m[2][2]);
	}


	/**
	 * @brief ����� ���� ��ķ� �����մϴ�.
	 */
	void Identify()
	{
		m[0][0] = static_cast<T>(1); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(1); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(1);
	}


	/**
	 * @brief ����� �����Դϴ�.
	 */
	T m[3][3];
};