#pragma once


/**
 * @brief 템플릿 기반의 3차원 벡터입니다.
 */
template <typename T>
struct Vector3
{
	/**
	 * @brief 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vector3(T&& xx, T&& yy, T&& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vector3(const T& xx, const T& yy, const T& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param element 모든 원소를 초기화 할 값입니다.
	 */
	Vector3(T&& element) noexcept
	{
		x = element;
		y = element;
		z = element;
	}


	/**
	 * @brief 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param element 모든 원소를 초기화 할 값입니다.
	 */
	Vector3(const T& element) noexcept
	{
		x = element;
		y = element;
		z = element;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param instance 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector3(const Vector3<T>& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
		z = instance.z;
	}


	/**
	 * @brief 벡터의 복사 생성자입니다.
	 *
	 * @param instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector3(Vector3<T>&& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
		z = instance.z;
	}


	/**
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator=(const Vector3<T>& instance) noexcept
	{
		if (this == &instance) return *this;

		x = instance.x;
		y = instance.y;
		z = instance.z;

		return *this;
	}


	/**
	 * @brief 벡터의 대입 연산자 입니다.
	 *
	 * @param instance 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator=(Vector3<T>&& instance) noexcept
	{
		if (this == &instance) return *this;

		x = instance.x;
		y = instance.y;
		z = instance.z;

		return *this;
	}


	/**
	 * @brief 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector3<T> operator+(const Vector3<T>& instance) const
	{
		return Vector3<T>(x + instance.x, y + instance.y, z + instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param instance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector3<T> operator+(Vector3<T>&& instance) const
	{
		return Vector3<T>(x + instance.x, y + instance.y, z + instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector3<T> operator-(const Vector3<T>& instance) const
	{
		return Vector3<T>(x - instance.x, y - instance.y, z - instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param instance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector3<T> operator-(Vector3<T>&& instance) const
	{
		return Vector3<T>(x - instance.x, y - instance.y, z - instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector3<T> operator*(const Vector3<T>& instance) const
	{
		return Vector3<T>(x * instance.x, y * instance.y, z * instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @param instance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector3<T> operator*(Vector3<T>&& instance) const
	{
		return Vector3<T>(x * instance.x, y * instance.y, z * instance.z);
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator+=(const Vector3<T>& instance) noexcept
	{
		x += instance.x;
		y += instance.y;
		z += instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator+=(Vector3<T>&& instance) noexcept
	{
		x += instance.x;
		y += instance.y;
		z += instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator-=(const Vector3<T>& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;
		z -= instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param instance 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator-=(Vector3<T>&& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;
		z -= instance.z;

		return *this;
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(const Vector3<T>& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y) && (z == instance.z);
	}


	/**
	 * @brief 두 벡터가 일치하는지 확인합니다.
	 *
	 * @param instance 일치하는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소가 모두 일치하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool operator==(Vector3<T>&& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y) && (z == instance.z);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(const Vector3<T>& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y) || (z != instance.z);
	}


	/**
	 * @brief 두 벡터가 일치하지 않는지 확인합니다.
	 *
	 * @param instance 일치하지 않는지 확인할 피연산자입니다.
	 *
	 * @return 두 벡터의 원소 중 하나라도 일치하지 않으면 true, 모두 일치하면 false를 반환합니다.
	 */
	bool operator!=(Vector3<T>&& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y) || (z != instance.z);
	}


	/**
	 * @brief 벡터의 첫 번째 원소입니다.
	 */
	T x;


	/**
	 * @brief 벡터의 두 번째 원소입니다.
	 */
	T y;


	/**
	 * @brief 벡터의 세 번째 원소입니다.
	 */
	T z;
};