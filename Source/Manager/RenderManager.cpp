#include "Manager/RenderManager.h"

#include "Utility/Assertion.h"
#include "Utility/Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

void RenderManager::Initialize(Window* renderTargetWindow, bool bEnableVsync)
{
	ASSERT(!bIsInitialized_, "already initialize render manager...");

	ASSERT(renderTargetWindow, "render target window is nullptr");
	renderTargetWindow_ = renderTargetWindow;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion_);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion_);
	INFO_LOG("OpenGL version is %d.%d", majorVersion_, minorVersion_);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	INFO_LOG("OpenGL mode is core profile mode...");

	glfwMakeContextCurrent(renderTargetWindow_->GetWindowPtr());

	ASSERT(gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)), "failed to initialize OpenGL function loader...");

	glfwSwapInterval(static_cast<int32_t>(bEnableVsync));
	INFO_LOG("vsync mode %s", bEnableVsync ? "enable" : "disable");

	glEnable(GL_DEPTH_TEST); // Enable Depth Test
	glEnable(GL_BLEND); // Enable Blending

	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	renderTargetWindow_ = nullptr;

	bIsInitialized_ = false;
}

void RenderManager::BeginFrame(float red, float green, float blue, float alpha, float depth, uint8_t stencil)
{
	glClearColor(red, green, blue, alpha);
	glClearDepth(depth);
	glClearStencil(stencil);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void RenderManager::EndFrame()
{
	glfwSwapBuffers(renderTargetWindow_->GetWindowPtr());
}