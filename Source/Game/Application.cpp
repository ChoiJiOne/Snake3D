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

	std::vector<VertexPositionNormal> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateSphere(1.0f, 50, 50, vertices, indices);

	Shader* shader = ResourceManager::Get().AddResource<Shader>("Shader");
	shader->Initialize("shader.vert", "shader.frag");

	Mesh* mesh = ResourceManager::Get().AddResource<Mesh>("Sphere");
	mesh->Initialize(vertices, indices);

	Material* material = ResourceManager::Get().AddResource<Material>("Material");
	material->Initialize(glm::vec4(1.0f, 0.5f, 0.31f, 1.0f), glm::vec4(1.0f, 0.5f, 0.31f, 1.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f), 32.0f);

	Model* model = ResourceManager::Get().AddResource<Model>("Model");
	model->Initialize(mesh, material);

	Light* light = ObjectManager::Get().AddGameObject<Light>("Light");
	light->Initialize(glm::vec3(5.0f, 5.0f, 5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	Camera3D* camera = ObjectManager::Get().AddGameObject<Camera3D>("Camera");
	camera->Initialize(
		glm::vec3(0.0f, 0.0f, 5.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		45.0f,
		RenderManager::Get().GetRenderTargetWindowAspectRatio(),
		0.1f,
		100.0f
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

		light->SetPosition(glm::vec3(
			5.0f * sinf(static_cast<float>(glfwGetTime())),
			0.0f,
			5.0f * cosf(static_cast<float>(glfwGetTime()))
		));

		RenderManager::Get().RenderModel3D(glm::mat4(1.0f), camera, model, light);
		
		RenderManager::Get().EndFrame();
	}

	GameEngine::Release();
	return 0;
}