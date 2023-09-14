#include "Manager/RenderManager.h"

#include "Utility/Assertion.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

void RenderManager::Initialize(GLFWwindow* renderTargetWindow, bool bEnableVsync)
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");
	ASSERT(renderTargetWindow, "render target window is nullptr");

	INFO_LOG("vsync mode %s", bEnableVsync ? "enable" : "disable");

	renderTargetWindow_ = renderTargetWindow;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion_);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion_);
	INFO_LOG("OpenGL version is %d.%d", majorVersion_, minorVersion_);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	INFO_LOG("OpenGL mode is core profile mode...");

	glfwMakeContextCurrent(renderTargetWindow_);

	ASSERT(gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)), "failed to initialize OpenGL function loader...");
	
	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	renderTargetWindow_ = nullptr;

	bIsInitialized_ = false;
}