#pragma once

#include <cstdint>
#include <string>

#include "Utility/Macro.h"

typedef struct GLFWwindow GLFWwindow; // GLFWwindow를 사용하기 위한 전방 선언입니다.


/**
 * @brief 게임 내 윈도우 창을 생성하고 관리합니다.
 * 
 * @note 이 윈도우 클래스는 GLFW를 기반으로 합니다.
 */
class Window
{
public:
	/**
	 * @brief 게임 내 윈도우 창을 생성하고 관리하는 클래스의 기본 생성자입니다.
	 *
	 * @note 반드시 클래스 내부 요소를 초기화하는 메서드를 호출해야 합니다.
	 */
	Window() = default;


	/**
	 * @brief 게임 내 윈도우 창을 생성하고 관리하는 클래스의 가상 소멸자입니다.
	 */
	virtual ~Window();


	/**
	 * @brief 게임 내 윈도우 창을 생성하고 관리하는 클래스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Window);


	/**
	 * @brief 윈도우 창을 생성합니다.
	 *
	 * @param title 윈도우 창의 타이틀입니다.
	 * @param clientWidth 윈도우 창의 클라이언트 가로 크기입니다.
	 * @param clientHeight 윈도우 창의 클라이언트 세로 크기입니다.
	 */
	void Create(const std::string& title, const int32_t& clientWidth, const int32_t& clientHeight);


	/**
	 * @brief 윈도우 창을 명시적으로 파괴합니다.
	 */
	void Destroy();


	/**
	 * @brief GLFW 윈도우 포인터 값을 얻습니다.
	 * 
	 * @return GLFW 윈도우 포인터 값을 반환합니다.
	 */
	GLFWwindow* GetWindowPtr() { return window_; }


private:
	/**
	 * @brief GLFW 윈도우 포인터입니다.
	 */
	GLFWwindow* window_ = nullptr;
};