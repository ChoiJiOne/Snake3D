#include <iostream>
#include <windows.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Manager/LogManager.h"
#include "Manager/RenderManager.h"

#include "Utility/Assertion.h"
#include "Utility/CommandLine.h"
#include "Utility/String.h"
#include "Utility/Logging.h"
#include "Utility/Macro.h"
#include "Utility/MinidumpWriter.h"

int32_t main(int32_t argc, char* argv[])
{
	CommandLine::Parse(argc, argv);
	MinidumpWriter::RegisterUnhandledExceptionFilter();

	LogManager::Get().Initialize();
	RenderManager::Get().Initialize();

	{// 여기에 렌더링 기능 구현 테스트 코드 추가...
		const int32_t width = 800;
		const int32_t height = 600;
		const std::string title = "Snake3D";

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (window == nullptr)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)))
		{
			glfwDestroyWindow(window);
			window = nullptr;

			glfwTerminate();
			return -1;
		}

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, true);
			}

			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		glfwDestroyWindow(window);
		window = nullptr;

		glfwTerminate();
	}

	RenderManager::Get().Release();
	LogManager::Get().Release();

	MinidumpWriter::UnregisterUnhandledExceptionFilter();
	return 0;
}