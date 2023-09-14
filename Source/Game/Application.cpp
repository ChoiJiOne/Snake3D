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
#include "Utility/Window.h"

int32_t main(int32_t argc, char* argv[])
{
	CommandLine::Parse(argc, argv);
	MinidumpWriter::RegisterUnhandledExceptionFilter();

	ASSERT(glfwInit(), "failed to initialize GLFW...");

	Window window;
	window.Create("Snake3D", 800, 600);

	LogManager::Get().Initialize();
	RenderManager::Get().Initialize(&window, false);

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

	while (!glfwWindowShouldClose(window.GetWindowPtr()))
	{
		glfwPollEvents();
		if (glfwGetKey(window.GetWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window.GetWindowPtr(), true);
		}

		glViewport(0, 0, 800, 600);
		glClearColor(0.5f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, static_cast<int32_t>(indices.size()), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window.GetWindowPtr());
	}

	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);

	shader.Release();

	RenderManager::Get().Release();
	LogManager::Get().Release();

	window.Destroy();
	glfwTerminate();

	MinidumpWriter::UnregisterUnhandledExceptionFilter();
	return 0;
}