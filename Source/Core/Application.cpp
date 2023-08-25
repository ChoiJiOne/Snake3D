#include <windows.h>

#include "Core/Camera3D.h"
#include "Core/ColorMaterial.h"
#include "Core/CommandLine.h"
#include "Core/GeometryGenerator.h"
#include "Core/GameTimer.h"
#include "Core/MathHelper.h"
#include "Core/Mesh.h"
#include "Core/MinidumpWriter.h"
#include "Core/Model.h"
#include "Core/RenderManager.h"
#include "Core/TTFont.h"
#include "Core/Vertex.h"
#include "Core/Window.h"

#include "Shader/ColorPassShader.h"
#include "Shader/ColorMaterialShader.h"
#include "Shader/GlyphPassShader.h"
#include "Shader/ShapePassShader.h"


/**
 * @brief 윈도우 메시지를 처리합니다.
 *
 * @note
 * - wParam 와 lParam 변수 모두 포인터 너비의 크기(32비트 또는 64비트)를 나타내는 정수 값입니다.
 * - 창 프로시저에서 특정 메시지를 처리하지 않는 경우 메시지 매개 변수를 DefWindowProcW 함수에 직접 전달합니다.
 *
 * @param windowHandle 윈도우에 대한 핸들입니다.
 * @param messageCode 윈도우 메시지 코드입니다.
 * @param wParam 메시지와 관련된 추가 데이터입니다.
 * @param lParam 메시지와 관련된 추가 데이터입니다.
 *
 * @return 프로그램이 Windows로 반환하는 정수값입니다.
 *
 * @see https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/writing-the-window-procedure
 */
LRESULT CALLBACK WindowMessageHandler(HWND windowHandle, uint32_t messageCode, WPARAM wParam, LPARAM lParam)
{
	switch (messageCode)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(windowHandle, messageCode, wParam, lParam);
}


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
	Window::RegisterWindowClass(WindowMessageHandler, className);

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
	font.Initialize("D:\\Work\\Snake3D\\Content\\Font\\SeoulNamsanEB.ttf", 32, 127, 32.0f);

	bool bIsDone = false;
	while (!bIsDone)
	{
		MSG msg = {};
		while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);

			if (msg.message == WM_QUIT)
			{
				bIsDone = true;
			}
		}

		if (bIsDone)
		{
			break;
		}

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));

		glyphPassShader.DrawText2D(&font, L"Hello Worldyglq", Vector2f(0.0f, 0.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f));

		RenderManager::Get().EndFrame(true);
	}

	font.Release();
	glyphPassShader.Release();
	shapePassShader.Release();
	colorMaterialShader.Release();
	model.Release();

	RenderManager::Get().Release();

	CoUninitialize();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}