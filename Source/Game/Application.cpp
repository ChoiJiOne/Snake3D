#include <iostream>
#include <windows.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
		// 앞면
		-0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f, // 왼쪽 아래
		+0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f, // 오른쪽 아래
		+0.5f, +0.5f, 0.5f,  0.0f, 0.0f, 1.0f, // 오른쪽 위
		-0.5f, +0.5f, 0.5f,  0.0f, 0.0f, 1.0f, // 왼쪽 위

		// 뒷면
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // 왼쪽 아래
		+0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // 오른쪽 아래
		+0.5f, +0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // 오른쪽 위
		-0.5f, +0.5f, -0.5f,  0.0f, 0.0f, -1.0f, // 왼쪽 위

		// 왼쪽면
		-0.5f, -0.5f, -0.5f,  -1.0f, 0.0f, 0.0f, // 왼쪽 아래
		-0.5f, +0.5f, -0.5f,  -1.0f, 0.0f, 0.0f, // 왼쪽 위
		-0.5f, +0.5f, +0.5f,  -1.0f, 0.0f, 0.0f, // 오른쪽 위
		-0.5f, -0.5f, +0.5f, -1.0f, 0.0f, 0.0f, // 오른쪽 아래

		// 오른쪽면
		0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f, // 왼쪽 아래
		0.5f, 0.5f, -0.5f,    1.0f, 0.0f, 0.0f, // 왼쪽 위
		0.5f, 0.5f, 0.5f,     1.0f, 0.0f, 0.0f, // 오른쪽 위
		0.5f, -0.5f, 0.5f,    1.0f, 0.0f, 0.0f, // 오른쪽 아래

		// 위쪽면
		-0.5f, 0.5f, 0.5f,    0.0f, 1.0f, 0.0f, // 왼쪽 앞
		0.5f, 0.5f, 0.5f,     0.0f, 1.0f, 0.0f, // 오른쪽 앞
		0.5f, 0.5f, -0.5f,    0.0f, 1.0f, 0.0f, // 오른쪽 뒤
		-0.5f, 0.5f, -0.5f,   0.0f, 1.0f, 0.0f, // 왼쪽 뒤

		// 아래쪽면
		-0.5f, -0.5f, 0.5f,   0.0f, -1.0f, 0.0f, // 왼쪽 앞
		0.5f, -0.5f, 0.5f,    0.0f, -1.0f, 0.0f, // 오른쪽 앞
		0.5f, -0.5f, -0.5f,   0.0f, -1.0f, 0.0f, // 오른쪽 뒤
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f, 0.0f, // 왼쪽 뒤
	};

	std::vector<uint32_t> indices = {
		0, 1, 2, 
		2, 3, 0, // 앞면

		4, 5, 6, 
		6, 7, 4, // 뒷면

		8, 9, 10, 
		10, 11, 8, // 왼쪽면

		12, 13, 14, 
		14, 15, 12, // 오른쪽면

		16, 17, 18, 
		18, 19, 16, // 위쪽면

		20, 21, 22, 
		22, 23, 20, // 아래쪽면
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window.GetWindowPtr()))
	{
		glfwPollEvents();
		if (glfwGetKey(window.GetWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window.GetWindowPtr(), true);
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

		glViewport(0, 0, 800, 600);
		
		shader.Bind();
		
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::lookAt(glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		shader.SetMat4Parameter("model", model);
		shader.SetMat4Parameter("view", view);
		shader.SetMat4Parameter("projection", projection);
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, static_cast<int32_t>(indices.size()), GL_UNSIGNED_INT, 0);
		
		RenderManager::Get().EndFrame();
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