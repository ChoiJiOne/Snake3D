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

	CommandLine::Parse(GetCommandLineW());
	MinidumpWriter::SetMinidumpPath(CommandLine::GetValue(L"Crash"));

	const std::wstring className = L"Snake3D";
	Window::RegisterWindowClass(InputManager::WindowMessageHandler, className);

	AudioManager::Get().Initialize();
	InputManager::Get().Initialize();
	
	const int32_t width = 800;
	const int32_t height = 600;
	const int32_t x = 200;
	const int32_t y = 200;
	const std::wstring title = L"Snake3D";

	Window window;
	window.Create(title, x, y, width, height);

	RenderManager::Get().SetRenderTargetWindow(&window);
	RenderManager::Get().Initialize();
	RenderManager::Get().SetDepthStencilMode(true);
	RenderManager::Get().SetBlendMode(true);
	RenderManager::Get().SetRasterizerMode(true, true);

	ResourceManager::Get().Initialize();

	Camera3D camera;
	camera.Initialzie(
		Vector3f(0.0f, 10.0f, -10.0f),
		Vector3f(0.0f, 0.0f, 0.0f),
		Vector3f(0.0f, 1.0f, 0.0f),
		PI_F / 4.0f,
		static_cast<float>(width) / static_cast<float>(height),
		0.1f,
		100.0f
	);
	
	std::vector<VertexPosition> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateQuadXZ(10.0f, 10.0f, vertices, indices);

	Model* model = ResourceManager::Get().AddResource<Model>("QuadXZ");
	model->SetMesh(vertices, indices);
	model->SetColorMaterial(Vector4f(1.0f, 1.0f, 0.0f, 1.0f));

	//TTFont* font = ResourceManager::Get().AddResource<TTFont>("SeoulNamsanEB");
	//font->Initialize("D:\\Work\\Snake3D\\Content\\Font\\SeoulNamsanEB.ttf", 32, 127, 32.0f);

	ObjectManager::Get().Initialize();

	GameTimer gameTimer;
	gameTimer.Reset();
	
	while (true)
	{
		gameTimer.Tick();
		InputManager::Get().Tick();

		if (InputManager::Get().ShouldCloseWindow())
		{
			break;
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));

		RenderManager::Get().DrawModel3D(MathHelper::RotationYMatrix(gameTimer.GetTotalSeconds()), &camera, model);
		//RenderManager::Get().DrawText2D(font, L"Hello World", Vector2f(0.0f, 0.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f));

		RenderManager::Get().EndFrame(true);
	}
	
	ObjectManager::Get().Release();
	ResourceManager::Get().Release();
	RenderManager::Get().Release();
	AudioManager::Get().Release();
	InputManager::Get().Release();

	GameEngine::LaunchShutdown();
	return 0;
}