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

	{ // 셰이더 초기화...
		Shader* shader = nullptr;

		shader = ResourceManager::Get().AddResource<Shader>("DirectionalLight");
		shader->Initialize("DirectionalLight.vert", "DirectionalLight.frag");

		shader = ResourceManager::Get().AddResource<Shader>("PointLight");
		shader->Initialize("PointLight.vert", "PointLight.frag");

		shader = ResourceManager::Get().AddResource<Shader>("SpotLight");
		shader->Initialize("SpotLight.vert", "SpotLight.frag");

		shader = ResourceManager::Get().AddResource<Shader>("PostProcessing");
		shader->Initialize("PostProcessing.vert", "PostProcessing.frag");		
		
		shader = ResourceManager::Get().AddResource<Shader>("Skybox");
		shader->Initialize("Skybox.vert", "Skybox.frag");

		GeometryShader* geometryShader = ResourceManager::Get().AddResource<GeometryShader>("Geometry");
		geometryShader->Initialize("Geometry.vert", "Geometry.frag");
	}

	{ // 리소스 생성...
		std::vector<VertexPositionNormal> vertices;
		std::vector<uint32_t> indices;
		GeometryGenerator::CreateSphere(0.5f, 50, 50, vertices, indices);

		Mesh* mesh = ResourceManager::Get().AddResource<Mesh>("Sphere");
		mesh->Initialize(vertices, indices);

		Material* material = ResourceManager::Get().AddResource<Material>("Material");
		material->Initialize(glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(1.0f, 0.5f, 0.31f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);

		Model* model = ResourceManager::Get().AddResource<Model>("Model");
		model->Initialize(mesh, material);

		std::string resourcePath = CommandLine::GetValue("Resource");
		CubeMap* cubeMap = ResourceManager::Get().AddResource<CubeMap>("CubeMap");
		cubeMap->Initialize(
			resourcePath + "Skybox\\right.png",
			resourcePath + "Skybox\\left.png",
			resourcePath + "Skybox\\top.png",
			resourcePath + "Skybox\\bottom.png",
			resourcePath + "Skybox\\front.png",
			resourcePath + "Skybox\\back.png"
		);
	}

	{ // 게임 오브젝트 생성...
		SpotLight* light = ObjectManager::Get().AddGameObject<SpotLight>("SpotLight");
		light->Initialize(
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::cos(glm::radians(12.5f)),
			glm::cos(glm::radians(45.0f)),
			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.7f, 0.7f, 0.7f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			1.0f,
			0.09f,
			0.032f
		);

		Camera3D* camera = ObjectManager::Get().AddGameObject<Camera3D>("Camera");
		camera->Initialize(
			glm::vec3(0.0f, 0.0f, 10.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			45.0f,
			RenderManager::Get().GetRenderTargetWindowAspectRatio(),
			0.1f,
			100.0f
		);
	}

	CubeMap* cubeMap = ResourceManager::Get().GetResource<CubeMap>("CubeMap");
	Camera3D* camera = ObjectManager::Get().GetGameObject<Camera3D>("Camera");
	Model* model = ResourceManager::Get().GetResource<Model>("Model");
	SpotLight* light = ObjectManager::Get().GetGameObject<SpotLight>("SpotLight");

	while (!glfwWindowShouldClose(window.GetWindowPtr()))
	{
		glfwPollEvents();
		if (glfwGetKey(window.GetWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window.GetWindowPtr(), true);
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetRenderTargetWindowViewport();
				
		RenderManager::Get().EndFrame();
	}

	GameEngine::Release();
	return 0;
}