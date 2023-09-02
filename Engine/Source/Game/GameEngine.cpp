#include "Game/GameEngine.h"

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
	std::wstring clientConfigPath = CommandLine::GetValue(L"ClientConfig");
	json clientConfig = JsonHelper::LoadJsonFromFile(clientConfigPath);

	ASSERT(clientConfig.contains("window"), "invalid window in client config file...");
	ASSERT(clientConfig["window"].contains("class"), "invalid class in client config file...");
	ASSERT(clientConfig["window"].contains("title"), "invalid title in client config file...");
	ASSERT(clientConfig["window"].contains("x"), "invalid x in client config file...");
	ASSERT(clientConfig["window"].contains("y"), "invalid y in client config file...");
	ASSERT(clientConfig["window"].contains("w"), "invalid w in client config file...");
	ASSERT(clientConfig["window"].contains("h"), "invalid h in client config file...");

	const std::string className = clientConfig["window"]["class"];
	const std::string title = clientConfig["window"]["title"];
	const int32_t width = clientConfig["window"]["w"];
	const int32_t height = clientConfig["window"]["h"];
	const int32_t x = clientConfig["window"]["x"];
	const int32_t y = clientConfig["window"]["y"];

	Window::RegisterWindowClass(InputManager::WindowMessageHandler, StringHelper::Convert(className));
	mainWindow_ = std::make_unique<Window>();
	mainWindow_->Create(StringHelper::Convert(title), x, y, width, height);
}