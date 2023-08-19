#include <array>
#include <cstdint>
#include <windows.h>

#include "Core/CommandLine.h"
#include "Core/MathHelper.h"
#include "Core/MinidumpWriter.h"
#include "Core/RenderManager.h"
#include "Core/Window.h"

#include "Shader/Shader.h"


struct Vertex
{
	Vector3f Position;
	Vector4f Color;
};


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

	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11Buffer* indexBuffer = nullptr;
	std::wstring shaderPath = CommandLine::GetValue(L"Shader");

	Shader shader;
	shader.Initialize(shaderPath + L"VertexShader.hlsl", shaderPath + L"PixelShader.hlsl");

	std::vector<Vertex> vertices =
	{
		Vertex{ Vector3f(-1.0f, +1.0f, -1.0f), Vector4f(0.0f, 0.0f, 1.0f, 1.0f) },
		Vertex{ Vector3f(+1.0f, +1.0f, -1.0f), Vector4f(0.0f, 1.0f, 0.0f, 1.0f) },
		Vertex{ Vector3f(+1.0f, +1.0f, +1.0f), Vector4f(0.0f, 1.0f, 1.0f, 1.0f) },
		Vertex{ Vector3f(-1.0f, +1.0f, +1.0f), Vector4f(1.0f, 0.0f, 0.0f, 1.0f) },
		Vertex{ Vector3f(-1.0f, -1.0f, -1.0f), Vector4f(1.0f, 0.0f, 1.0f, 1.0f) },
		Vertex{ Vector3f(+1.0f, -1.0f, -1.0f), Vector4f(1.0f, 1.0f, 0.0f, 1.0f) },
		Vertex{ Vector3f(+1.0f, -1.0f, +1.0f), Vector4f(1.0f, 1.0f, 1.0f, 1.0f) },
		Vertex{ Vector3f(-1.0f, -1.0f, +1.0f), Vector4f(0.0f, 0.0f, 0.0f, 1.0f) },
	};
	
	std::vector<uint32_t> indices =
	{	
		3,1,0,
		2,1,3,

		0,5,4,
		1,5,0,

		3,4,7,
		0,4,3,

		1,6,5,
		2,6,1,

		2,7,6,
		3,7,2,

		6,4,5,
		7,4,6,
	};

	D3D11_BUFFER_DESC vertexBufferDesc = {};

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(Vertex) * static_cast<UINT>(vertices.size());
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = reinterpret_cast<const void*>(&vertices[0]);
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(
		RenderManager::Get().GetDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer), 
		"failed to create vertex buffer..."
	);

	D3D11_BUFFER_DESC indexBufferDesc;
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(uint32_t) * static_cast<UINT>(indices.size());
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA indexData;
	indexData.pSysMem = reinterpret_cast<const void*>(&indices[0]);
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	HRESULT_ASSERT(
		RenderManager::Get().GetDevice()->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer),
		"failed to create index buffer..."
	);
	
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

		RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));

		uint32_t stride = sizeof(Vertex);
		UINT offset = 0;
		RenderManager::Get().GetContext()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
		RenderManager::Get().GetContext()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
		RenderManager::Get().GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		shader.Bind();

		RenderManager::Get().GetContext()->DrawIndexed(static_cast<UINT>(indices.size()), 0, 0);
		
		RenderManager::Get().EndFrame(true);
	}

	shader.Release();

	SAFE_RELEASE(indexBuffer);
	SAFE_RELEASE(vertexBuffer);

	RenderManager::Get().Release();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}