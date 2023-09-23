#include "GameEngine/GameEngine.h"

#include <glfw3.h>

bool GameEngine::bIsPreInitialized_ = false;
bool GameEngine::bIsPostInitialized_ = false;
Window* GameEngine::mainWindow_ = nullptr;

std::array<IManager*, 5> managers_ = 
{
	&ResourceManager::Get(),
	&ObjectManager::Get(),
	&RenderManager::Get(),
	&LogManager::Get(),
	&AudioManager::Get(),
};

void GameEngine::PreInitialize(int32_t argc, char* argv[])
{
	CommandLine::Parse(argc, argv);
	MinidumpWriter::RegisterUnhandledExceptionFilter();

	ASSERT(glfwInit(), "failed to initialize GLFW...");
}

void GameEngine::PostInitialize(Window* mainWindow)
{
	ASSERT(mainWindow != nullptr, "failed to create main window or not create main window...");
	mainWindow_ = mainWindow;

	AudioManager::Get().Initialize();
	LogManager::Get().Initialize();
	RenderManager::Get().Initialize(mainWindow);
	ObjectManager::Get().Initialize();
	ResourceManager::Get().Initialize();

	std::string vsync = CommandLine::GetValue("Vsync");
	std::transform(vsync.begin(), vsync.end(), vsync.begin(), std::tolower);
	RenderManager::Get().SetVsyncMode(!vsync.compare("on") ? true : false);

	if(vsync.compare("on") && vsync.compare("off")) // 둘 다 만족하지 않을 경우...
	{
		WARN_LOG("set vsync default mode...");
		WARN_LOG("default mode is disable vsync...");
	}
}

void GameEngine::Release()
{
	for (auto& manager : managers_)
	{
		if (manager->IsInitialized())
		{
			manager->Release();
		}
	}
	
	mainWindow_->Destroy();

	glfwTerminate();
	MinidumpWriter::UnregisterUnhandledExceptionFilter();
}