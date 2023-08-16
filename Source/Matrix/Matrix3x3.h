#pragma once


/**
 * @brief 템플릿 기반의 3x3 행렬입니다.
 */
template <typename T>
struct Matrix3x3
{
	/**
	 * @brief 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix3x3() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0);
	}


	/**
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
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
	 * @brief 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
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
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix3x3(T&& element) noexcept
	{
		m[0][0] = element; m[0][1] = element; m[0][2] = element;
		m[1][0] = element; m[1][1] = element; m[1][2] = element;
		m[2][0] = element; m[2][1] = element; m[2][2] = element;
	}


	/**
	 * @brief 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param element 모든 원소를 초기화 할 값입니다.
	 */
	Matrix3x3(const T& element) noexcept
	{
		m[0][0] = element; m[0][1] = element; m[0][2] = element;
		m[1][0] = element; m[1][1] = element; m[1][2] = element;
		m[2][0] = element; m[2][1] = element; m[2][2] = element;
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix3x3(Matrix3x3<T>&& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2];
	}


	/**
	 * @brief 행렬의 복사 생성자입니다.
	 *
	 * @param instance 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix3x3(const Matrix3x3<T>& instance) noexcept
	{
		m[0][0] = instance.m[0][0]; m[0][1] = instance.m[0][1]; m[0][2] = instance.m[0][2];
		m[1][0] = instance.m[1][0]; m[1][1] = instance.m[1][1]; m[1][2] = instance.m[1][2];
		m[2][0] = instance.m[2][0]; m[2][1] = instance.m[2][1]; m[2][2] = instance.m[2][2];
	}


	/**
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
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
	 * @brief 행렬의 대입 연산자입니다.
	 *
	 * @param instance 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
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
	 * @brief 행렬의 모든 원소에 - 부호를 취합니다.
	 *
	 * @return 모든 원소에 - 부호를 취한 새로운 행렬을 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param instance 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
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
	 * @brief 두 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param instance 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬을 곱합니다.
	 *
	 * @param instance 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
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
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator+=(Matrix3x3<T>&& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1]; m[0][2] += instance.m[0][2];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1]; m[1][2] += instance.m[1][2];
		m[2][0] += instance.m[2][0]; m[2][1] += instance.m[2][1]; m[2][2] += instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator+=(const Matrix3x3<T>& instance) noexcept
	{
		m[0][0] += instance.m[0][0]; m[0][1] += instance.m[0][1]; m[0][2] += instance.m[0][2];
		m[1][0] += instance.m[1][0]; m[1][1] += instance.m[1][1]; m[1][2] += instance.m[1][2];
		m[2][0] += instance.m[2][0]; m[2][1] += instance.m[2][1]; m[2][2] += instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator-=(Matrix3x3<T>&& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1]; m[0][2] -= instance.m[0][2];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1]; m[1][2] -= instance.m[1][2];
		m[2][0] -= instance.m[2][0]; m[2][1] -= instance.m[2][1]; m[2][2] -= instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator-=(const Matrix3x3<T>& instance) noexcept
	{
		m[0][0] -= instance.m[0][0]; m[0][1] -= instance.m[0][1]; m[0][2] -= instance.m[0][2];
		m[1][0] -= instance.m[1][0]; m[1][1] -= instance.m[1][1]; m[1][2] -= instance.m[1][2];
		m[2][0] -= instance.m[2][0]; m[2][1] -= instance.m[2][1]; m[2][2] -= instance.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하는지 확인합니다.
	 *
	 * @param instance 일치하는지 확인할 행렬입니다.
	 *
	 * @return 두 행렬의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
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
	 * @brief 두 행렬의 원소가 일치하지 않는지 확인합니다.
	 *
	 * @param 일치하지 않는지 확인할 피 연산자입니다.
	 *
	 * @return 두 행렬의 원소가 일치하지 않으면 true, 일치하면 false를 반환합니다.
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
	 * @brief 단위 행렬을 얻습니다.
	 *
	 * @return 단위 행렬을 반환합니다.
	 */
	static Matrix3x3<T> Identify()
	{
		return Matrix3x3<T>(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 행렬의 원소입니다.
	 */
	T m[3][3];
};