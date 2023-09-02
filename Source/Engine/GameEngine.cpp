#include "Engine/GameEngine.h"

bool GameEngine::bIsInitialized_ = false;
int32_t GameEngine::majorVersion_ = 0;
int32_t GameEngine::minorVersion_ = 0;
std::unique_ptr<Window> GameEngine::mainWindow_ = nullptr;

/**
 * @brief 엔진 내부의 메니저 포인터입니다.
 */
static std::array<IManager*, 5> managers_ = 
{
	&ObjectManager::Get(),
	&ResourceManager::Get(),
	&RenderManager::Get(),
	&AudioManager::Get(),
	&InputManager::Get(),
};

void GameEngine::LaunchStartup()
{
	ASSERT(!bIsInitialized_, "already launch game engine startup...");

	MinidumpWriter::RegisterUnhandledExceptionFilter();

	CommandLine::Parse(GetCommandLineW());

	MinidumpWriter::SetMinidumpPath(CommandLine::GetValue(L"Crash"));

	AudioManager::Get().Initialize();
	InputManager::Get().Initialize();

	ApplyEngineConfig();
	ApplyClientConfig();

	RenderManager::Get().SetRenderTargetWindow(mainWindow_.get());
	RenderManager::Get().Initialize();

	ResourceManager::Get().Initialize();
	ObjectManager::Get().Initialize();

	RenderManager::Get().SetDepthStencilMode(true);
	RenderManager::Get().SetBlendMode(true);
	RenderManager::Get().SetRasterizerMode(true, true);

	bIsInitialized_ = true;
}

void GameEngine::LaunchShutdown()
{
	ASSERT(bIsInitialized_, "you have to launch game engine startup...");

	for (auto& manager : managers_)
	{
		manager->Release();
	}

	MinidumpWriter::UnregisterUnhandledExceptionFilter();

	bIsInitialized_ = false;
}

void GameEngine::ApplyEngineConfig()
{
	majorVersion_ = 0;
	minorVersion_ = 0;
}

void GameEngine::ApplyClientConfig()
{
	const std::wstring className = L"Snake3D";
	const std::wstring title = L"Snake3D";
	const int32_t width = 800;
	const int32_t height = 600;
	const int32_t x = 200;
	const int32_t y = 200;

	Window::RegisterWindowClass(InputManager::WindowMessageHandler, className);
	mainWindow_ = std::make_unique<Window>();
	mainWindow_->Create(title, x, y, width, height);
}