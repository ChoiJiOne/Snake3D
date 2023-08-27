#include <windows.h>


#include "Core/Camera3D.h"
#include "Core/Window.h"

#include "Manager/AudioManager.h"
#include "Manager/InputManager.h"
#include "Core/RenderManager.h"

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

	std::vector<VertexPosition> vertices;
	std::vector<uint32_t> indices;
	GeometryGenerator::CreateQuadXZ(10.0f, 10.0f, vertices, indices);

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

	Model model;
	model.SetMesh(vertices, indices);
	model.SetColorMaterial(Vector4f(1.0f, 1.0f, 1.0f, 1.0f));

	ColorMaterialShader colorMaterialShader;
	colorMaterialShader.Initialize();

	ShapePassShader shapePassShader;
	shapePassShader.Initialize();

	GlyphPassShader glyphPassShader;
	glyphPassShader.Initialize();

	TTFont font;
	font.Initialize("D:\\Snake3D\\Content\\Font\\SeoulNamsanEB.ttf", 32, 127, 32.0f);

	Sound sound;
	sound.Initialize("D:\\Snake3D\\Content\\Sound\\Title.mp3");

	sound.Play();
	
	while (true)
	{
		InputManager::Get().Tick();

		if (InputManager::Get().ShouldCloseWindow())
		{
			break;
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));

		float time = InputManager::Get().GetKeyPressTime(EVirtualKey::CODE_SPACE);

		glyphPassShader.DrawText2D(
			&font, 
			StringHelper::Format(L"PRESS TIME %f", time),
			Vector2f(0.0f, 0.0f), 
			Vector4f(1.0f, 0.0f, 0.0f, 1.0f)
		);
		
		RenderManager::Get().EndFrame(true);
	}

	sound.Release();
	font.Release();
	glyphPassShader.Release();
	shapePassShader.Release();
	colorMaterialShader.Release();
	model.Release();

	RenderManager::Get().Release();
	AudioManager::Get().Release();
	InputManager::Get().Release();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}