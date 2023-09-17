#include "GameEngine/GameEngine.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int32_t main(int32_t argc, char* argv[])
{
	GameEngine::PreInitialize(argc, argv);

	Window window;
	window.Create("Snake3D", 800, 600);

	GameEngine::PostInitialize(&window);
	
	std::string shaderPath = CommandLine::GetValue("Shader");
	Shader shader;
	shader.Initialize(shaderPath + "shader.vert", shaderPath + "shader.frag");
	
	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateSphere(1.0f, 50, 50, vertices, indices);

	Mesh mesh;
	mesh.Initialize(vertices, indices);

	Camera3D camera;
	camera.Initialize(
		glm::vec3(3.0f, 3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		45.0f, RenderManager::Get().GetRenderTargetWindowAspectRatio(), 0.1f, 100.0f
	);
	
	while (!glfwWindowShouldClose(window.GetWindowPtr()))
	{
		glfwPollEvents();
		if (glfwGetKey(window.GetWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window.GetWindowPtr(), true);
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetRenderTargetWindowViewport();
		
		shader.Bind();
		
		glm::mat4 model = glm::rotate(glm::mat4(1.0f), static_cast<float>(glfwGetTime()) / 10.0f, glm::vec3(0.0f, 1.0f, 0.0f));

		shader.SetMat4Parameter("model", model);
		shader.SetMat4Parameter("view", camera.GetViewMatrix());
		shader.SetMat4Parameter("projection", camera.GetProjectionMatrix());
		
		glBindVertexArray(mesh.GetVertexArrayObject());
		glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
		
		RenderManager::Get().EndFrame();
	}

	mesh.Release();
	shader.Release();
	window.Destroy();

	GameEngine::Release();
	return 0;
}