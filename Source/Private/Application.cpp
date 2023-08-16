#include <cstdint>
#include <windows.h>
#include <d3dcompiler.h>

#include "CommandLine.h"
#include "MinidumpWriter.h"
#include "RenderManager.h"
#include "Window.h"


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
 * @brief HLSL 셰이더 파일을 컴파일합니다.
 * 
 * @param path 셰이더 파일의 경로입니다.
 * @param entryPoint 셰이더의 진입 경로입니다.
 * @param shaderModel 셰이더의 모델입니다.
 * @param outBlob 컴파일된 셰이더입니다.
 * 
 * @return 컴파일된 결과를 HRESULT 값으로 반환합니다. 컴파일에 성공하면 S_OK, 그렇지 않으면 그 외의 값을 반환합니다.
 */
HRESULT CompileShaderFromFile(const std::wstring& path, const std::string& entryPoint, const std::string& shaderModel, ID3DBlob** outBlob)
{
	HRESULT hr = S_OK;

	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

#if defined(DEBUG) || defined(RELEASE)
	shaderFlags |= D3DCOMPILE_DEBUG;
	shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

	ID3DBlob* errorBlob = nullptr;
	hr = D3DCompileFromFile(
		path.c_str(), 
		nullptr,
		nullptr, 
		entryPoint.c_str(), 
		shaderModel.c_str(),
		shaderFlags, 
		0, 
		outBlob, 
		&errorBlob
	);

	SAFE_RELEASE(errorBlob);

	return hr;
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

	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;
	ID3D11Buffer* vertexBuffer = nullptr;
	
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

		RenderManager::Get().BeginFrame(1.0f, 0.0f, 0.0f, 1.0f);
		RenderManager::Get().SetViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height));
		RenderManager::Get().EndFrame(true);
	}

	SAFE_RELEASE(vertexBuffer);
	SAFE_RELEASE(inputLayout);
	SAFE_RELEASE(pixelShader);
	SAFE_RELEASE(vertexShader);

	RenderManager::Get().Release();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}