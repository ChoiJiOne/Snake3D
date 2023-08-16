#pragma once


/**
 * @brief ���ø� ����� 3���� �����Դϴ�.
 */
template <typename T>
struct Vector3
{
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 */
	Vector3(T&& xx, T&& yy, T&& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 */
	Vector3(const T& xx, const T& yy, const T& zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector3(T&& element) noexcept
	{
		x = element;
		y = element;
		z = element;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector3(const T& element) noexcept
	{
		x = element;
		y = element;
		z = element;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector3(const Vector3<T>& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
		z = instance.z;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector3(Vector3<T>&& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
		z = instance.z;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator+(const Vector3<T>& instance) const
	{
		return Vector3<T>(x + instance.x, y + instance.y, z + instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator+(Vector3<T>&& instance) const
	{
		return Vector3<T>(x + instance.x, y + instance.y, z + instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-(const Vector3<T>& instance) const
	{
		return Vector3<T>(x - instance.x, y - instance.y, z - instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-(Vector3<T>&& instance) const
	{
		return Vector3<T>(x - instance.x, y - instance.y, z - instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator*(const Vector3<T>& instance) const
	{
		return Vector3<T>(x * instance.x, y * instance.y, z * instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator*(Vector3<T>&& instance) const
	{
		return Vector3<T>(x * instance.x, y * instance.y, z * instance.z);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator+=(const Vector3<T>& instance) noexcept
	{
		x += instance.x;
		y += instance.y;
		z += instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator+=(Vector3<T>&& instance) noexcept
	{
		x += instance.x;
		y += instance.y;
		z += instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator-=(const Vector3<T>& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;
		z -= instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator-=(Vector3<T>&& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;
		z -= instance.z;

		return *this;
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vector3<T>& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y) && (z == instance.z);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vector3<T>&& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y) && (z == instance.z);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vector3<T>& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y) || (z != instance.z);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vector3<T>&& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y) || (z != instance.z);
	}


	/**
	 * @brief ������ ù ��° �����Դϴ�.
	 */
	T x;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T y;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T z;
};