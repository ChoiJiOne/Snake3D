#pragma once


/**
 * @brief ���ø� ����� 4���� �����Դϴ�.
 */
template <typename T>
struct Vector4
{
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector4() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vector4(T&& xx, T&& yy, T&& zz, T&& ww)
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vector4(const T& xx, const T& yy, const T& zz, const T& ww)
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector4(T&& element) noexcept
	{
		x = element;
		y = element;
		z = element;
		w = element;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector4(const T& element) noexcept
	{
		x = element;
		y = element;
		z = element;
		w = element;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector4(const Vector4<T>& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
		z = instance.z;
		w = instance.w;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector4(Vector4<T>&& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
		z = instance.z;
		w = instance.w;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator=(const Vector4<T>& instance) noexcept
	{
		if (this == &instance) return *this;

		x = instance.x;
		y = instance.y;
		z = instance.z;
		w = instance.w;

		return *this;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator=(Vector4<T>&& instance) noexcept
	{
		if (this == &instance) return *this;

		x = instance.x;
		y = instance.y;
		z = instance.z;
		w = instance.w;

		return *this;
	}


	/**
	 * @brief ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator+(const Vector4<T>& instance) const
	{
		return Vector4<T>(x + instance.x, y + instance.y, z + instance.z, w + instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator+(Vector4<T>&& instance) const
	{
		return Vector4<T>(x + instance.x, y + instance.y, z + instance.z, w + instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-(const Vector4<T>& instance) const
	{
		return Vector4<T>(x - instance.x, y - instance.y, z - instance.z, w - instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-(Vector4<T>&& instance) const
	{
		return Vector4<T>(x - instance.x, y - instance.y, z - instance.z, w - instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator*(const Vector4<T>& instance) const
	{
		return Vector4<T>(x * instance.x, y * instance.y, z * instance.z, w * instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator*(Vector4<T>&& instance) const
	{
		return Vector4<T>(x * instance.x, y * instance.y, z * instance.z, w * instance.w);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator+=(const Vector4<T>& instance) noexcept
	{
		x += instance.x;
		y += instance.y;
		z += instance.z;
		w += instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator+=(Vector4<T>&& instance) noexcept
	{
		x += instance.x;
		y += instance.y;
		z += instance.z;
		w += instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator-=(const Vector4<T>& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;
		z -= instance.z;
		w -= instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector4<T>& operator-=(Vector4<T>&& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;
		z -= instance.z;
		w -= instance.w;

		return *this;
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vector4<T>& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y) && (z == instance.z) && (w == instance.w);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vector4<T>&& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y) && (z == instance.z) && (w == instance.w);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vector4<T>& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y) || (z != instance.z) || (w != instance.w);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vector4<T>&& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y) || (z != instance.z) || (w != instance.w);
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


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T w;
};