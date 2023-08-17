#include <array>
#include <cstdint>
#include <windows.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#include "CommandLine.h"
#include "MathHelper.h"
#include "MinidumpWriter.h"
#include "RenderManager.h"
#include "Window.h"


struct Vertex
{
	Vector3<float> Position;
	Vector4<float> Color;
};

struct EveryFrame
{
	Matrix4x4<float> world;
	//DirectX::XMMATRIX world;
	DirectX::XMMATRIX view;
	DirectX::XMMATRIX projection;
};


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
 * @brief HLSL ���̴� ������ �������մϴ�.
 * 
 * @param path ���̴� ������ ����Դϴ�.
 * @param entryPoint ���̴��� ���� ����Դϴ�.
 * @param shaderModel ���̴��� ���Դϴ�.
 * @param outBlob �����ϵ� ���̴��Դϴ�.
 * 
 * @return �����ϵ� ����� HRESULT ������ ��ȯ�մϴ�. �����Ͽ� �����ϸ� S_OK, �׷��� ������ �� ���� ���� ��ȯ�մϴ�.
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

	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;
	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11Buffer* indexBuffer = nullptr;
	ID3D11Buffer* everyFrame = nullptr;
	ID3DBlob* vsBlob = nullptr;
	ID3DBlob* psBlob = nullptr;
	
	std::wstring shaderPath = CommandLine::GetValue(L"Shader");
	HRESULT_ASSERT(CompileShaderFromFile(shaderPath + L"VertexShader.hlsl", "main", "vs_5_0", &vsBlob), "failed to compile vertex shader...");
	HRESULT_ASSERT(CompileShaderFromFile(shaderPath + L"PixelShader.hlsl", "main", "ps_5_0", &psBlob), "failed to compile pixel shader...");
	
	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreateVertexShader(
		vsBlob->GetBufferPointer(),
		vsBlob->GetBufferSize(),
		nullptr,
		&vertexShader
	), "failed to create vertex shader...");

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreatePixelShader(
		psBlob->GetBufferPointer(),
		psBlob->GetBufferSize(),
		nullptr,
		&pixelShader
	), "failed to create pixel shader...");

	std::vector<D3D11_INPUT_ELEMENT_DESC> layouts =
	{
		{ "POSITION", 0,    DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{    "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreateInputLayout(
		&layouts[0],
		static_cast<UINT>(layouts.size()),
		vsBlob->GetBufferPointer(),
		vsBlob->GetBufferSize(),
		&inputLayout
	), "failed to create input layout...");
	
	SAFE_RELEASE(vsBlob);
	SAFE_RELEASE(psBlob);

	D3D11_BUFFER_DESC everyFrameBufferDesc;
	everyFrameBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	everyFrameBufferDesc.ByteWidth = sizeof(EveryFrame);
	everyFrameBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	everyFrameBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	everyFrameBufferDesc.MiscFlags = 0;
	everyFrameBufferDesc.StructureByteStride = 0;

	HRESULT_ASSERT(RenderManager::Get().GetDevice()->CreateBuffer(
		&everyFrameBufferDesc,
		nullptr,
		&everyFrame
	), "failed to create every frame buffer...");

	std::vector<Vertex> vertices =
	{
		Vertex{ Vector3<float>(-1.0f, +1.0f, -1.0f), Vector4<float>(0.0f, 0.0f, 1.0f, 1.0f) },
		Vertex{ Vector3<float>(+1.0f, +1.0f, -1.0f), Vector4<float>(0.0f, 1.0f, 0.0f, 1.0f) },
		Vertex{ Vector3<float>(+1.0f, +1.0f, +1.0f), Vector4<float>(0.0f, 1.0f, 1.0f, 1.0f) },
		Vertex{ Vector3<float>(-1.0f, +1.0f, +1.0f), Vector4<float>(1.0f, 0.0f, 0.0f, 1.0f) },
		Vertex{ Vector3<float>(-1.0f, -1.0f, -1.0f), Vector4<float>(1.0f, 0.0f, 1.0f, 1.0f) },
		Vertex{ Vector3<float>(+1.0f, -1.0f, -1.0f), Vector4<float>(1.0f, 1.0f, 0.0f, 1.0f) },
		Vertex{ Vector3<float>(+1.0f, -1.0f, +1.0f), Vector4<float>(1.0f, 1.0f, 1.0f, 1.0f) },
		Vertex{ Vector3<float>(-1.0f, -1.0f, +1.0f), Vector4<float>(0.0f, 0.0f, 0.0f, 1.0f) },
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

		RenderManager::Get().GetContext()->IASetInputLayout(inputLayout);

		D3D11_MAPPED_SUBRESOURCE mappedResource;
		HRESULT_ASSERT(RenderManager::Get().GetContext()->Map(everyFrame, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource), "failed to update buffer...");

		EveryFrame* bufferPtr = reinterpret_cast<EveryFrame*>(mappedResource.pData);

		static float t = 0.0f;
		static ULONGLONG timeStart = 0;
		ULONGLONG timeCur = GetTickCount64();
		if (timeStart == 0)
			timeStart = timeCur;
		t = (timeCur - timeStart) / 1000.0f;

		//Matrix4x4f M = MathHelper::RotationZMatrix(t);
		Matrix4x4f M = MathHelper::ScalingMatrix(1.0f, 1.0f, std::abs(5.0f * sin(t)));
		//M = M * MathHelper::GetTranslationMatrix(2.0f, 2.0f, 2.0f);

		bufferPtr->world = Matrix4x4<float>::Transpose(M);//Matrix4x4<float>::Transpose(M);
		//bufferPtr->world = DirectX::XMMatrixTranspose(DirectX::XMMatrixRotationZ(t));
		bufferPtr->view = DirectX::XMMatrixTranspose(DirectX::XMMatrixLookAtLH(
			DirectX::XMVectorSet(0.0f, 10.0f, -10.0f, 0.0f),
			DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f),
			DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f)
		));
		bufferPtr->projection = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixPerspectiveFovLH(DirectX::XM_PIDIV4, static_cast<float>(width) / static_cast<float>(height), 0.01f, 100.0f)
		);
		RenderManager::Get().GetContext()->Unmap(everyFrame, 0);

		RenderManager::Get().GetContext()->VSSetShader(vertexShader, nullptr, 0);
		uint32_t bindSlot = 0;
		RenderManager::Get().GetContext()->VSSetConstantBuffers(bindSlot, 1, &everyFrame);

		RenderManager::Get().GetContext()->PSSetShader(pixelShader, nullptr, 0);

		RenderManager::Get().GetContext()->DrawIndexed(static_cast<UINT>(indices.size()), 0, 0);
		
		RenderManager::Get().EndFrame(true);
	}

	SAFE_RELEASE(indexBuffer);
	SAFE_RELEASE(vertexBuffer);
	SAFE_RELEASE(everyFrame);
	SAFE_RELEASE(inputLayout);
	SAFE_RELEASE(pixelShader);
	SAFE_RELEASE(vertexShader);

	RenderManager::Get().Release();

	SetUnhandledExceptionFilter(topLevelExceptionFilter);
	return 0;
}