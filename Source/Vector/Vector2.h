#pragma once


/**
 * @brief ���ø� ����� 2���� �����Դϴ�.
 */
template <typename T>
struct Vector2
{
	/**
	 * @brief ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector2() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	Vector2(T&& xx, T&& yy)
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	Vector2(const T& xx, const T& yy)
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector2(T&& element) noexcept
	{
		x = element;
		y = element;
	}


	/**
	 * @brief ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param element ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector2(const T& element) noexcept
	{
		x = element;
		y = element;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector2(const Vector2<T>& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
	}


	/**
	 * @brief ������ ���� �������Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector2(Vector2<T>&& instance) noexcept
	{
		x = instance.x;
		y = instance.y;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator=(const Vector2<T>& instance) noexcept
	{
		if (this == &instance) return *this;

		x = instance.x;
		y = instance.y;

		return *this;
	}


	/**
	 * @brief ������ ���� ������ �Դϴ�.
	 *
	 * @param instance ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator=(Vector2<T>&& instance) noexcept
	{
		if (this == &instance) return *this;

		x = instance.x;
		y = instance.y;

		return *this;
	}


	/**
	 * @brief ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator+(const Vector2<T>& instance) const
	{
		return Vector2<T>(x + instance.x, y + instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator+(Vector2<T>&& instance) const
	{
		return Vector2<T>(x + instance.x, y + instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-(const Vector2<T>& instance) const
	{
		return Vector2<T>(x - instance.x, y - instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-(Vector2<T>&& instance) const
	{
		return Vector2<T>(x - instance.x, y - instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator*(const Vector2<T>& instance) const
	{
		return Vector2<T>(x * instance.x, y * instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @param instance ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator*(Vector2<T>&& instance) const
	{
		return Vector2<T>(x * instance.x, y * instance.y);
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator+=(const Vector2<T>& instance) noexcept
	{
		x += instance.x;
		y += instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator+=(Vector2<T>&& instance) noexcept
	{
		x += instance.x;
		y += instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator-=(const Vector2<T>& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param instance ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator-=(Vector2<T>&& instance) noexcept
	{
		x -= instance.x;
		y -= instance.y;

		return *this;
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(const Vector2<T>& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ�ϴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ�ϴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���Ұ� ��� ��ġ�ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool operator==(Vector2<T>&& instance) noexcept
	{
		return (x == instance.x) && (y == instance.y);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(const Vector2<T>& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y);
	}


	/**
	 * @brief �� ���Ͱ� ��ġ���� �ʴ��� Ȯ���մϴ�.
	 *
	 * @param instance ��ġ���� �ʴ��� Ȯ���� �ǿ������Դϴ�.
	 *
	 * @return �� ������ ���� �� �ϳ��� ��ġ���� ������ true, ��� ��ġ�ϸ� false�� ��ȯ�մϴ�.
	 */
	bool operator!=(Vector2<T>&& instance) noexcept
	{
		return (x != instance.x) || (y != instance.y);
	}


	/**
	 * @brief ������ ù ��° �����Դϴ�.
	 */
	T x;


	/**
	 * @brief ������ �� ��° �����Դϴ�.
	 */
	T y;
};