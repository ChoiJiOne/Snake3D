#include "GameEngine/GameEngine.h"

#include <glfw3.h>

bool GameEngine::bIsPreInitialized_ = false;
bool GameEngine::bIsPostInitialized_ = false;
Window* GameEngine::mainWindow_ = nullptr;

std::array<IManager*, 6> managers_ = 
{
	&ResourceManager::Get(),
	&ObjectManager::Get(),
	&RenderManager::Get(),
	&InputManager::Get(),
	&LogManager::Get(),
	&AudioManager::Get(),
};

void GameEngine::PreInitialize(int32_t argc, char* argv[])
{
	ASSERT(!bIsPreInitialized_, "alreay pre initialize game engine...");
	CommandLine::Parse(argc, argv);
	MinidumpWriter::RegisterUnhandledExceptionFilter();

	ASSERT(glfwInit(), "failed to initialize GLFW...");

#if defined(SHIPPING)
	::ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif

	bIsPreInitialized_ = true;
}

void GameEngine::PostInitialize(Window* mainWindow)
{
	ASSERT(bIsPreInitialized_, "Please do post initialize before doing pre initialize...");
	ASSERT(!bIsPostInitialized_, "alreay post initialize game engine...");
	ASSERT(mainWindow != nullptr, "failed to create main window or not create main window...");

	mainWindow_ = mainWindow;

	AudioManager::Get().Initialize();
	LogManager::Get().Initialize();
	InputManager::Get().Initialize(mainWindow_);
	RenderManager::Get().Initialize(mainWindow_);
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

	std::array<std::string, 7> shaderResources = {
		"DirectionalLight",
		"PointLight",
		"SpotLight",
		"PostProcessing",
		"Skybox",
		"Geometry",
		"Glyph",
	};

	Shader* shader = nullptr;
	for (const auto& shaderResource : shaderResources)
	{
		if (!shaderResource.compare("Geometry"))
		{
			shader = ResourceManager::Get().AddResource<GeometryShader>(shaderResource);
		}
		else if (!shaderResource.compare("Glyph"))
		{
			shader = ResourceManager::Get().AddResource<GlyphShader>(shaderResource);
		}
		else // Geometry와 Glyph 이외의 셰이더
		{
			shader = ResourceManager::Get().AddResource<Shader>(shaderResource);
		}

		shader->Initialize(shaderResource + ".vert", shaderResource + ".frag");
	}

	bIsPostInitialized_ = true;
}

void GameEngine::Release()
{
	ASSERT(bIsPreInitialized_, "you have to call pre initialize...");
	ASSERT(bIsPostInitialized_, "you have to call post initialize...");

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