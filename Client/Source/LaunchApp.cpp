#include "MainCamera.h"

#include "Game/GameEngine.h"

/**
 * @brief Windows ���ø����̼��� ��Ʈ�� ����Ʈ�Դϴ�.
 *
 * @param hInstance �ν��Ͻ��� ���� �ڵ� �̰ų� ��⿡ ���� �ڵ��Դϴ�
 * @param hPrevInstance 16��Ʈ Windows���� ���Ǿ��� ���Դϴ�.
 * @param cmdLine �����ڵ� ���ڿ��� ���Ե� ����� �μ��Դϴ�.
 * @param showCmd �⺻ ���ø����̼� â�� �ּ�ȭ, �ִ�ȭ �Ǵ� ���������� ǥ�õǴ��� ���θ� ��Ÿ���� �÷����Դϴ�.
 *
 * @see https://learn.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point
 */
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR cmdLine, _In_ int showCmd)
{
	GameEngine::LaunchStartup();

	MainCamera* mainCamera = ObjectManager::Get().AddGameObject<MainCamera>("MainCamera");
	mainCamera->Initialize(Vector3f(0.0f, 15.0f, -25.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 1.0f, 0.0f));

	std::vector<VertexPosition> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateQuadXZ(1.0f, 1.0f, vertices, indices);

	Model* model = ResourceManager::Get().AddResource<Model>("QuadXZ");
	model->SetMesh(vertices, indices);
	model->SetColorMaterial(Vector4f(1.0f, 1.0f, 1.0f, 1.0f));

	while (true)
	{
		InputManager::Get().Tick();
		if (InputManager::Get().ShouldCloseWindow())
		{
			break;
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetWindowViewport();


		for (float x = -10.0f; x <= 10.0f; x += 1.0f)
		{
			for (float z = -10.0f; z <= 10.0f; z += 1.0f)
			{
				int32_t random = MathHelper::GenerateRandomInt(0, 2);

				if (random == 0)
				{
					model->SetColorMaterial(Vector4f(1.0f, 0.0f, 0.0f, 1.0f));
				}
				else if (random == 1)
				{
					model->SetColorMaterial(Vector4f(0.0f, 1.0f, 0.0f, 1.0f));
				}
				else
				{
					model->SetColorMaterial(Vector4f(0.0f, 0.0f, 1.0f, 1.0f));
				}

				RenderManager::Get().DrawModel3D(
					MathHelper::TranslationMatrix(x, 0.0f, z),
					mainCamera->GetCamera3D(),
					model
				);
			}
		}

		RenderManager::Get().EndFrame(true);
	}

	GameEngine::LaunchShutdown();
	return 0;
}