#include <array>
#include <cstdint>
#include <windows.h>

#include "Core/Camera3D.h"
#include "Core/ColorMaterial.h"
#include "Core/CommandLine.h"
#include "Core/GeometryGenerator.h"
#include "Core/MathHelper.h"
#include "Core/Mesh.h"
#include "Core/MinidumpWriter.h"
#include "Core/Model.h"
#include "Core/RenderManager.h"
#include "Core/Vertex.h"
#include "Core/Window.h"

#include "Shader/ColorPassShader.h"
#include "Shader/ColorMaterialShader.h"
#include "Shader/PrimitiveShapeShader.h"


/**
 * @brief ������ �޽����� ó���մϴ�.
 *
 * @note
 * - wParam �� lParam ���� ��� ������ �ʺ��� ũ��(32��Ʈ �Ǵ� 64��Ʈ)�� ��Ÿ���� ���� ���Դϴ�.
 * - â ���ν������� Ư�� �޽����� ó������ �ʴ� ��� �޽��� �Ű� ������ DefWindowProcW �Լ��� ���� �����մϴ�.
 *
 * @param windowHandle �����쿡 ���� �ڵ��Դϴ�.
 * @param messageCode ������ �޽��� �ڵ��Դϴ�.
 * @param wParam �޽����� ���õ� �߰� �������Դϴ�.
 * @param lParam �޽����� ���õ� �߰� �������Դϴ�.
 *
 * @return ���α׷��� Windows�� ��ȯ�ϴ� �������Դϴ�.
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
	RenderManager::Get().SetDepthBuffer(true);
	RenderManager::Get().SetAlphaBlend(true);
	RenderManager::Get().SetFillMode(true);

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

	PrimitiveShapeShader primitiveShapeShader;
	primitiveShapeShader.Initialize();
	
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

		static float t = 0.0f;
		static ULONGLONG timeStart = 0;
		ULONGLONG timeCur = GetTickCount64();
		if (timeStart == 0)
			timeStart = timeCur;
		t = (timeCur - timeStart) / 1000.0f;

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));
		
		model.SetColorMaterial(Vector4f(std::sin(t), std::cos(t), 1.0f, 1.0f));
		colorMaterialShader.Draw(Matrix4x4f::Identify(), &camera, &model);

		primitiveShapeShader.DrawLine3D(&camera, Vector3f(0.0f, 0.0f, 0.0f), Vector3f(10.0f,  0.0f,  0.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f));
		primitiveShapeShader.DrawLine3D(&camera, Vector3f(0.0f, 0.0f, 0.0f), Vector3f( 0.0f, 10.0f,  0.0f), Vector4f(0.0f, 1.0f, 0.0f, 1.0f));
		primitiveShapeShader.DrawLine3D(&camera, Vector3f(0.0f, 0.0f, 0.0f), Vector3f( 0.0f,  0.0f, 10.0f), Vector4f(0.0f, 0.0f, 1.0f, 1.0f));
		
		RenderManager::Get().EndFrame(true);
	}

	primitiveShapeShader.Release();
	colorMaterialShader.Release();
	model.Release();

	RenderManager::Get().Release();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}