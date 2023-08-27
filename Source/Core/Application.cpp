#include <windows.h>

#include "Core/Camera3D.h"
#include "Core/Window.h"

#include "Manager/AudioManager.h"
#include "Manager/InputManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "Resource/ColorMaterial.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"
#include "Resource/Sound.h"
#include "Resource/TTFont.h"

#include "Shader/ColorPassShader.h"
#include "Shader/ColorMaterialShader.h"
#include "Shader/GlyphPassShader.h"
#include "Shader/ShapePassShader.h"

#include "Utils/CommandLine.h"
#include "Utils/GeometryGenerator.h"
#include "Utils/GameTimer.h"
#include "Utils/MathHelper.h"
#include "Utils/MinidumpWriter.h"
#include "Utils/Vertex.h"


/**
 * @brief Windows 애플리케이션의 엔트리 포인트입니다.
 *
 * @param hInstance 인스턴스에 대한 핸들 이거나 모듈에 대한 핸들입니다
 * @param hPrevInstance 16비트 Windows에서 사용되었던 값입니다.
 * @param cmdLine 유니코드 문자열로 포함된 명령줄 인수입니다.
 * @param showCmd 기본 애플리케이션 창이 최소화, 최대화 또는 정상적으로 표시되는지 여부를 나타내는 플래그입니다.
 *
 * @see https://learn.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point
 */
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR cmdLine, _In_ int showCmd)
{
	LPTOP_LEVEL_EXCEPTION_FILTER topLevelExceptionFilter = SetUnhandledExceptionFilter(MinidumpWriter::DetectApplicationCrash);

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

	ColorMaterialShader colorMaterialShader;
	colorMaterialShader.Initialize();

	ShapePassShader shapePassShader;
	shapePassShader.Initialize();

	GlyphPassShader glyphPassShader;
	glyphPassShader.Initialize();

	TTFont* font = ResourceManager::Get().AddResource<TTFont>("SeoulNamsanEB");
	font->Initialize("D:\\Snake3D\\Content\\Font\\SeoulNamsanEB.ttf", 32, 127, 32.0f);

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

		colorMaterialShader.Draw(MathHelper::RotationYMatrix(gameTimer.GetTotalSeconds()), &camera, model);
		glyphPassShader.DrawText2D(font, L"Hello World", Vector2f(0.0f, 0.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f));
		
		RenderManager::Get().EndFrame(true);
	}

	glyphPassShader.Release();
	shapePassShader.Release();
	colorMaterialShader.Release();

	ResourceManager::Get().Release();
	RenderManager::Get().Release();
	AudioManager::Get().Release();
	InputManager::Get().Release();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}