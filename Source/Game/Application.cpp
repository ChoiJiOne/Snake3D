#include <iostream>
#include <windows.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Manager/LogManager.h"
#include "Manager/RenderManager.h"

#include "Resource/Shader.h"

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

	{// 여기에 렌더링 기능 구현 테스트 코드 추가...
		const int32_t width = 800;
		const int32_t height = 600;
		const std::string title = "Snake3D";

		glfwInit();
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (window == nullptr)
		{
			glfwTerminate();
			return -1;
		}

		RenderManager::Get().Initialize(window, false);

		std::string shaderPath = CommandLine::GetValue("Shader");
		Shader shader;
		shader.Initialize(shaderPath + "shader.vert", shaderPath + "shader.frag");

		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f, // left  
			 0.5f, -0.5f, 0.0f, // right 
			 0.0f,  0.5f, 0.0f  // top
		};

		std::vector<uint32_t> indices = {
			0, 1, 2,
		};

		uint32_t VBO;
		uint32_t EBO;
		uint32_t VAO;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), reinterpret_cast<const void*>(&vertices[0]), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * indices.size(), reinterpret_cast<const void*>(&indices[0]), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, true);
			}

			glViewport(0, 0, width, height);
			glClearColor(0.5f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, static_cast<int32_t>(indices.size()), GL_UNSIGNED_INT, 0);

			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);

		shader.Release();

		glfwDestroyWindow(window);
		window = nullptr;

		glfwTerminate();
	}

	RenderManager::Get().Release();
	LogManager::Get().Release();

	MinidumpWriter::UnregisterUnhandledExceptionFilter();
	return 0;
}