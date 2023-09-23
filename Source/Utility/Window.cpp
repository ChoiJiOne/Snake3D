#include "Utility/Window.h"
#include "Utility/Assertion.h"

#include <glfw3.h>

Window::~Window()
{
	Destroy();
}

void Window::Create(const std::string& title, const int32_t& clientWidth, const int32_t& clientHeight)
{
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window_ = glfwCreateWindow(clientWidth, clientHeight, title.c_str(), nullptr, nullptr);
	ASSERT(window_ != nullptr, "failed to create GLFW window...");
}

void Window::Destroy()
{
	if (window_ != nullptr)
	{
		glfwDestroyWindow(window_);
		window_ = nullptr;
	}
}