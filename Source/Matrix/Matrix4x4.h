#pragma once


/**
 * @brief ���ø� ����� 4x4 ����Դϴ�.
 */
template <typename T>
struct Matrix4x4
{
	/**
	 * @brief ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix4x4() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(0);
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m03 ����� (0, 3) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m13 ����� (1, 3) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 * @param m23 ����� (2, 3) �����Դϴ�.
	 * @param m30 ����� (3, 0) �����Դϴ�.
	 * @param m31 ����� (3, 1) �����Դϴ�.
	 * @param m32 ����� (3, 2) �����Դϴ�.
	 * @param m33 ����� (3, 3) �����Դϴ�.
	 */
	Matrix4x4(
		T&& m00, T&& m01, T&& m02, T&& m03,
		T&& m10, T&& m11, T&& m12, T&& m13,
		T&& m20, T&& m21, T&& m22, T&& m23,
		T&& m30, T&& m31, T&& m32, T&& m33
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}


	/**
	 * @brief ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m03 ����� (0, 3) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m13 ����� (1, 3) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 * @param m23 ����� (2, 3) �����Դϴ�.
	 * @param m30 ����� (3, 0) �����Դϴ�.
	 * @param m31 ����� (3, 1) �����Դϴ�.
	 * @param m32 ����� (3, 2) �����Դϴ�.
	 * @param m33 ����� (3, 3) �����Դϴ�.
	 */
	Matrix4x4(
		const T& m00, const T& m01, const T& m02, const T& m03,
		const T& m10, const T& m11, const T& m12, const T& m13,
		const T& m20, const T& m21, const T& m22, const T& m23,
		const T& m30, const T& m31, const T& m32, const T& m33
	)
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix4x4(T&& element) noexcept
	{
		m[0][0] = element; m[0][1] = element; m[0][2] = element; m[0][3] = element;
		m[1][0] = element; m[1][1] = element; m[1][2] = element; m[1][3] = element;
		m[2][0] = element; m[2][1] = element; m[2][2] = element; m[2][3] = element;
		m[3][0] = element; m[3][1] = element; m[3][2] = element; m[3][3] = element;
	}


	/**
	 * @brief ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix4x4(const T& element) noexcept
	{
		m[0][0] = element; m[0][1] = element; m[0][2] = element; m[0][3] = element;
		m[1][0] = element; m[1][1] = element; m[1][2] = element; m[1][3] = element;
		m[2][0] = element; m[2][1] = element; m[2][2] = element; m[2][3] = element;
		m[3][0] = element; m[3][1] = element; m[3][2] = element; m[3][3] = element;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix4x4(Matrix4x4<T>&& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2]; m[0][3] = instance.m[0][3];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2]; m[1][3] = instance.m[1][3];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2]; m[2][3] = instance.m[2][3];
		m[3][0] = instance.m[3][0]; m[3][1] = instance.m[3][1]; m[3][2] = instance.m[3][2]; m[3][3] = instance.m[3][3];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix4x4(const Matrix4x4<T>& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2]; m[0][3] = instance.m[0][3];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2]; m[1][3] = instance.m[1][3];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2]; m[2][3] = instance.m[2][3];
		m[3][0] = instance.m[3][0]; m[3][1] = instance.m[3][1]; m[3][2] = instance.m[3][2]; m[3][3] = instance.m[3][3];
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator=(Matrix4x4<T>&& instance) noexcept
	{
		if (this == &instance) return *this;

		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2]; m[0][3] = instance.m[0][3];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2]; m[1][3] = instance.m[1][3];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2]; m[2][3] = instance.m[2][3];
		m[3][0] = instance.m[3][0]; m[3][1] = instance.m[3][1]; m[3][2] = instance.m[3][2]; m[3][3] = instance.m[3][3];

		return *this;
	}


	/**
	 * @brief ����� ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator=(const Matrix4x4<T>& instance) noexcept
	{
		if (this == &instance) return *this;

		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2]; m[0][3] = instance.m[0][3];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2]; m[1][3] = instance.m[1][3];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2]; m[2][3] = instance.m[2][3];
		m[3][0] = instance.m[3][0]; m[3][1] = instance.m[3][1]; m[3][2] = instance.m[3][2]; m[3][3] = instance.m[3][3];

		return *this;
	}


	/**
	 * @brief ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� - ��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator-() const
	{
		return Matrix4x4<T>(
			-m[0][0], -m[0][1], -m[0][2], -m[0][3],
			-m[1][0], -m[1][1], -m[1][2], -m[1][3],
			-m[2][0], -m[2][1], -m[2][2], -m[2][3],
			-m[3][0], -m[3][1], -m[3][2], -m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator+(Matrix4x4<T>&& instance)
	{
		return Matrix4x4<T>(
			m[0][0] + instance.m[0][0], m[0][1] + instance.m[0][1], m[0][2] + instance.m[0][2], m[0][3] + instance.m[0][3],
			m[1][0] + instance.m[1][0], m[1][1] + instance.m[1][1], m[1][2] + instance.m[1][2], m[1][3] + instance.m[1][3],
			m[2][0] + instance.m[2][0], m[2][1] + instance.m[2][1], m[2][2] + instance.m[2][2], m[2][3] + instance.m[2][3],
			m[3][0] + instance.m[3][0], m[3][1] + instance.m[3][1], m[3][2] + instance.m[3][2], m[3][3] + instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator+(const Matrix4x4<T>& instance)
	{
		return Matrix4x4<T>(
			m[0][0] + instance.m[0][0], m[0][1] + instance.m[0][1], m[0][2] + instance.m[0][2], m[0][3] + instance.m[0][3],
			m[1][0] + instance.m[1][0], m[1][1] + instance.m[1][1], m[1][2] + instance.m[1][2], m[1][3] + instance.m[1][3],
			m[2][0] + instance.m[2][0], m[2][1] + instance.m[2][1], m[2][2] + instance.m[2][2], m[2][3] + instance.m[2][3],
			m[3][0] + instance.m[3][0], m[3][1] + instance.m[3][1], m[3][2] + instance.m[3][2], m[3][3] + instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator-(Matrix4x4<T>&& instance)
	{
		return Matrix4x4<T>(
			m[0][0] - instance.m[0][0], m[0][1] - instance.m[0][1], m[0][2] - instance.m[0][2], m[0][3] - instance.m[0][3],
			m[1][0] - instance.m[1][0], m[1][1] - instance.m[1][1], m[1][2] - instance.m[1][2], m[1][3] - instance.m[1][3],
			m[2][0] - instance.m[2][0], m[2][1] - instance.m[2][1], m[2][2] - instance.m[2][2], m[2][3] - instance.m[2][3],
			m[3][0] - instance.m[3][0], m[3][1] - instance.m[3][1], m[3][2] - instance.m[3][2], m[3][3] - instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator-(const Matrix4x4<T>& instance)
	{
		return Matrix4x4<T>(
			m[0][0] - instance.m[0][0], m[0][1] - instance.m[0][1], m[0][2] - instance.m[0][2], m[0][3] - instance.m[0][3],
			m[1][0] - instance.m[1][0], m[1][1] - instance.m[1][1], m[1][2] - instance.m[1][2], m[1][3] - instance.m[1][3],
			m[2][0] - instance.m[2][0], m[2][1] - instance.m[2][1], m[2][2] - instance.m[2][2], m[2][3] - instance.m[2][3],
			m[3][0] - instance.m[3][0], m[3][1] - instance.m[3][1], m[3][2] - instance.m[3][2], m[3][3] - instance.m[3][3]
			);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator*(Matrix4x4<T>&& instance)
	{
		return Matrix4x4(
			m[0][0] * instance.m[0][0] + m[0][1] * instance.m[1][0] + m[0][2] * instance.m[2][0] + m[0][3] * instance.m[3][0],
			m[0][0] * instance.m[0][1] + m[0][1] * instance.m[1][1] + m[0][2] * instance.m[2][1] + m[0][3] * instance.m[3][1],
			m[0][0] * instance.m[0][2] + m[0][1] * instance.m[1][2] + m[0][2] * instance.m[2][2] + m[0][3] * instance.m[3][2],
			m[0][0] * instance.m[0][3] + m[0][1] * instance.m[1][3] + m[0][2] * instance.m[2][3] + m[0][3] * instance.m[3][3],
			m[1][0] * instance.m[0][0] + m[1][1] * instance.m[1][0] + m[1][2] * instance.m[2][0] + m[1][3] * instance.m[3][0],
			m[1][0] * instance.m[0][1] + m[1][1] * instance.m[1][1] + m[1][2] * instance.m[2][1] + m[1][3] * instance.m[3][1],
			m[1][0] * instance.m[0][2] + m[1][1] * instance.m[1][2] + m[1][2] * instance.m[2][2] + m[1][3] * instance.m[3][2],
			m[1][0] * instance.m[0][3] + m[1][1] * instance.m[1][3] + m[1][2] * instance.m[2][3] + m[1][3] * instance.m[3][3],
			m[2][0] * instance.m[0][0] + m[2][1] * instance.m[1][0] + m[2][2] * instance.m[2][0] + m[2][3] * instance.m[3][0],
			m[2][0] * instance.m[0][1] + m[2][1] * instance.m[1][1] + m[2][2] * instance.m[2][1] + m[2][3] * instance.m[3][1],
			m[2][0] * instance.m[0][2] + m[2][1] * instance.m[1][2] + m[2][2] * instance.m[2][2] + m[2][3] * instance.m[3][2],
			m[2][0] * instance.m[0][3] + m[2][1] * instance.m[1][3] + m[2][2] * instance.m[2][3] + m[2][3] * instance.m[3][3],
			m[3][0] * instance.m[0][0] + m[3][1] * instance.m[1][0] + m[3][2] * instance.m[2][0] + m[3][3] * instance.m[3][0],
			m[3][0] * instance.m[0][1] + m[3][1] * instance.m[1][1] + m[3][2] * instance.m[2][1] + m[3][3] * instance.m[3][1],
			m[3][0] * instance.m[0][2] + m[3][1] * instance.m[1][2] + m[3][2] * instance.m[2][2] + m[3][3] * instance.m[3][2],
			m[3][0] * instance.m[0][3] + m[3][1] * instance.m[1][3] + m[3][2] * instance.m[2][3] + m[3][3] * instance.m[3][3]
		);
	}


	/**
	 * @brief �� ����� ���մϴ�.
	 *
	 * @param instance ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4<T> operator*(const Matrix4x4<T>& instance)
	{
		return Matrix4x4(
			m[0][0] * instance.m[0][0] + m[0][1] * instance.m[1][0] + m[0][2] * instance.m[2][0] + m[0][3] * instance.m[3][0],
			m[0][0] * instance.m[0][1] + m[0][1] * instance.m[1][1] + m[0][2] * instance.m[2][1] + m[0][3] * instance.m[3][1],
			m[0][0] * instance.m[0][2] + m[0][1] * instance.m[1][2] + m[0][2] * instance.m[2][2] + m[0][3] * instance.m[3][2],
			m[0][0] * instance.m[0][3] + m[0][1] * instance.m[1][3] + m[0][2] * instance.m[2][3] + m[0][3] * instance.m[3][3],
			m[1][0] * instance.m[0][0] + m[1][1] * instance.m[1][0] + m[1][2] * instance.m[2][0] + m[1][3] * instance.m[3][0],
			m[1][0] * instance.m[0][1] + m[1][1] * instance.m[1][1] + m[1][2] * instance.m[2][1] + m[1][3] * instance.m[3][1],
			m[1][0] * instance.m[0][2] + m[1][1] * instance.m[1][2] + m[1][2] * instance.m[2][2] + m[1][3] * instance.m[3][2],
			m[1][0] * instance.m[0][3] + m[1][1] * instance.m[1][3] + m[1][2] * instance.m[2][3] + m[1][3] * instance.m[3][3],
			m[2][0] * instance.m[0][0] + m[2][1] * instance.m[1][0] + m[2][2] * instance.m[2][0] + m[2][3] * instance.m[3][0],
			m[2][0] * instance.m[0][1] + m[2][1] * instance.m[1][1] + m[2][2] * instance.m[2][1] + m[2][3] * instance.m[3][1],
			m[2][0] * instance.m[0][2] + m[2][1] * instance.m[1][2] + m[2][2] * instance.m[2][2] + m[2][3] * instance.m[3][2],
			m[2][0] * instance.m[0][3] + m[2][1] * instance.m[1][3] + m[2][2] * instance.m[2][3] + m[2][3] * instance.m[3][3],
			m[3][0] * instance.m[0][0] + m[3][1] * instance.m[1][0] + m[3][2] * instance.m[2][0] + m[3][3] * instance.m[3][0],
			m[3][0] * instance.m[0][1] + m[3][1] * instance.m[1][1] + m[3][2] * instance.m[2][1] + m[3][3] * instance.m[3][1],
			m[3][0] * instance.m[0][2] + m[3][1] * instance.m[1][2] + m[3][2] * instance.m[2][2] + m[3][3] * instance.m[3][2],
			m[3][0] * instance.m[0][3] + m[3][1] * instance.m[1][3] + m[3][2] * instance.m[2][3] + m[3][3] * instance.m[3][3]
		);
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator+=(Matrix4x4<T>&& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1]; m[0][2] += instance.m[0][2]; m[0][3] += instance.m[0][3];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1]; m[1][2] += instance.m[1][2]; m[1][3] += instance.m[1][3];
		m[2][0] += instance.m[2][0]; m[2][1] += instance.m[2][1]; m[2][2] += instance.m[2][2]; m[2][3] += instance.m[2][3];
		m[3][0] += instance.m[3][0]; m[3][1] += instance.m[3][1]; m[3][2] += instance.m[3][2]; m[3][3] += instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator+=(const Matrix4x4<T>& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1]; m[0][2] += instance.m[0][2]; m[0][3] += instance.m[0][3];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1]; m[1][2] += instance.m[1][2]; m[1][3] += instance.m[1][3];
		m[2][0] += instance.m[2][0]; m[2][1] += instance.m[2][1]; m[2][2] += instance.m[2][2]; m[2][3] += instance.m[2][3];
		m[3][0] += instance.m[3][0]; m[3][1] += instance.m[3][1]; m[3][2] += instance.m[3][2]; m[3][3] += instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator-=(Matrix4x4<T>&& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1]; m[0][2] -= instance.m[0][2]; m[0][3] -= instance.m[0][3];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1]; m[1][2] -= instance.m[1][2]; m[1][3] -= instance.m[1][3];
		m[2][0] -= instance.m[2][0]; m[2][1] -= instance.m[2][1]; m[2][2] -= instance.m[2][2]; m[2][3] -= instance.m[2][3];
		m[3][0] -= instance.m[3][0]; m[3][1] -= instance.m[3][1]; m[3][2] -= instance.m[3][2]; m[3][3] -= instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix4x4<T>& operator-=(const Matrix4x4<T>& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1]; m[0][2] -= instance.m[0][2]; m[0][3] -= instance.m[0][3];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1]; m[1][2] -= instance.m[1][2]; m[1][3] -= instance.m[1][3];
		m[2][0] -= instance.m[2][0]; m[2][1] -= instance.m[2][1]; m[2][2] -= instance.m[2][2]; m[2][3] -= instance.m[2][3];
		m[3][0] -= instance.m[3][0]; m[3][1] -= instance.m[3][1]; m[3][2] -= instance.m[3][2]; m[3][3] -= instance.m[3][3];

		return *this;
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Matrix4x4<T>&& instance) noexcept
	{
		return (m[0][0] == instance.m[0][0])
			&& (m[0][1] == instance.m[0][1])
			&& (m[0][2] == instance.m[0][2])
			&& (m[0][3] == instance.m[0][3])
			&& (m[1][0] == instance.m[1][0])
			&& (m[1][1] == instance.m[1][1])
			&& (m[1][2] == instance.m[1][2])
			&& (m[1][3] == instance.m[1][3])
			&& (m[2][0] == instance.m[2][0])
			&& (m[2][1] == instance.m[2][1])
			&& (m[2][2] == instance.m[2][2])
			&& (m[2][3] == instance.m[2][3])
			&& (m[3][0] == instance.m[3][0])
			&& (m[3][1] == instance.m[3][1])
			&& (m[3][2] == instance.m[3][2])
			&& (m[3][3] == instance.m[3][3]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� ����Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Matrix4x4<T>& instance) noexcept
	{
		return (m[0][0] == instance.m[0][0])
			&& (m[0][1] == instance.m[0][1])
			&& (m[0][2] == instance.m[0][2])
			&& (m[0][3] == instance.m[0][3])
			&& (m[1][0] == instance.m[1][0])
			&& (m[1][1] == instance.m[1][1])
			&& (m[1][2] == instance.m[1][2])
			&& (m[1][3] == instance.m[1][3])
			&& (m[2][0] == instance.m[2][0])
			&& (m[2][1] == instance.m[2][1])
			&& (m[2][2] == instance.m[2][2])
			&& (m[2][3] == instance.m[2][3])
			&& (m[3][0] == instance.m[3][0])
			&& (m[3][1] == instance.m[3][1])
			&& (m[3][2] == instance.m[3][2])
			&& (m[3][3] == instance.m[3][3]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Matrix4x4<T>&& instance) noexcept
	{
		return (m[0][0] != instance.m[0][0])
			|| (m[0][1] != instance.m[0][1])
			|| (m[0][2] != instance.m[0][2])
			|| (m[0][3] != instance.m[0][3])
			|| (m[1][0] != instance.m[1][0])
			|| (m[1][1] != instance.m[1][1])
			|| (m[1][2] != instance.m[1][2])
			|| (m[1][3] != instance.m[1][3])
			|| (m[2][0] != instance.m[2][0])
			|| (m[2][1] != instance.m[2][1])
			|| (m[2][2] != instance.m[2][2])
			|| (m[2][3] != instance.m[2][3])
			|| (m[3][0] != instance.m[3][0])
			|| (m[3][1] != instance.m[3][1])
			|| (m[3][2] != instance.m[3][2])
			|| (m[3][3] != instance.m[3][3]);
	}


	/**
	 * @brief �� ����� ���Ұ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param ��ġ���� �ʴ��� Ȯ���� �� �������Դϴ�.
	 *
	 * @return �� ����� ���Ұ� ��ġ���� ������ true, ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Matrix4x4<T>& instance) noexcept
	{
		return (m[0][0] != instance.m[0][0])
			|| (m[0][1] != instance.m[0][1])
			|| (m[0][2] != instance.m[0][2])
			|| (m[0][3] != instance.m[0][3])
			|| (m[1][0] != instance.m[1][0])
			|| (m[1][1] != instance.m[1][1])
			|| (m[1][2] != instance.m[1][2])
			|| (m[1][3] != instance.m[1][3])
			|| (m[2][0] != instance.m[2][0])
			|| (m[2][1] != instance.m[2][1])
			|| (m[2][2] != instance.m[2][2])
			|| (m[2][3] != instance.m[2][3])
			|| (m[3][0] != instance.m[3][0])
			|| (m[3][1] != instance.m[3][1])
			|| (m[3][2] != instance.m[3][2])
			|| (m[3][3] != instance.m[3][3]);
	}


	/**
	 * @brief ���� ����� ����ϴ�.
	 *
	 * @return ���� ����� ��ȯ�մϴ�.
	 */
	static Matrix4x4<T> Identify()
	{
		return Matrix4x4<T>(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief ��ġ ����� ����ϴ�.
	 * 
	 * @instance ��ġ ��ų ����Դϴ�.
	 * 
	 * @return ��ġ�� ����� ��ȯ�մϴ�.
	 */
	static Matrix4x4<T> Transpose(const Matrix4x4<T>& instance)
	{
		return Matrix4x4<T>(
			instance.m[0][0], instance.m[1][0], instance.m[2][0], instance.m[3][0], 
			instance.m[0][1], instance.m[1][1], instance.m[2][1], instance.m[3][1], 
			instance.m[0][2], instance.m[1][2], instance.m[2][2], instance.m[3][2], 
			instance.m[0][3], instance.m[1][3], instance.m[2][3], instance.m[3][3]
		);
	}


	/**
	 * @brief ����� �����Դϴ�.
	 */
	T m[4][4];
};