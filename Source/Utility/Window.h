#pragma once

#include <cstdint>
#include <string>

#include "Utility/Macro.h"

typedef struct GLFWwindow GLFWwindow; // GLFWwindow�� ����ϱ� ���� ���� �����Դϴ�.


/**
 * @brief ���� �� ������ â�� �����ϰ� �����մϴ�.
 * 
 * @note �� ������ Ŭ������ GLFW�� ������� �մϴ�.
 */
class Window
{
public:
	/**
	 * @brief ���� �� ������ â�� �����ϰ� �����ϴ� Ŭ������ �⺻ �������Դϴ�.
	 *
	 * @note �ݵ�� Ŭ���� ���� ��Ҹ� �ʱ�ȭ�ϴ� �޼��带 ȣ���ؾ� �մϴ�.
	 */
	Window() = default;


	/**
	 * @brief ���� �� ������ â�� �����ϰ� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Window();


	/**
	 * @brief ���� �� ������ â�� �����ϰ� �����ϴ� Ŭ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * @brief ������ â�� �����մϴ�.
	 *
	 * @param title ������ â�� Ÿ��Ʋ�Դϴ�.
	 * @param clientWidth ������ â�� Ŭ���̾�Ʈ ���� ũ���Դϴ�.
	 * @param clientHeight ������ â�� Ŭ���̾�Ʈ ���� ũ���Դϴ�.
	 */
	void Create(const std::string& title, const int32_t& clientWidth, const int32_t& clientHeight);


	/**
	 * @brief ������ â�� ��������� �ı��մϴ�.
	 */
	void Destroy();


	/**
	 * @brief GLFW ������ ������ ���� ����ϴ�.
	 * 
	 * @return GLFW ������ ������ ���� ��ȯ�մϴ�.
	 */
	GLFWwindow* GetWindowPtr() { return window_; }


private:
	/**
	 * @brief GLFW ������ �������Դϴ�.
	 */
	GLFWwindow* window_ = nullptr;
};