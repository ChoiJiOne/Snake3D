#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "GameObject/Camera3D.h"
#include "GameObject/Light.h"

#include "Resource/Material.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"
#include "Resource/Shader.h"

#include "Utility/Assertion.h"
#include "Utility/Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

void RenderManager::Initialize(Window* renderTargetWindow)
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

void RenderManager::SetVsyncMode(bool bIsEnable)
{
	bEnableVsync_ = bIsEnable;
	glfwSwapInterval(static_cast<int32_t>(bIsEnable));
}

void RenderManager::SetViewport(int32_t x, int32_t y, int32_t width, int32_t height)
{
	glViewport(x, y, width, height);
}

void RenderManager::SetRenderTargetWindowViewport()
{
	int32_t width;
	int32_t height;
	GetRenderTargetWindowSize(width, height);
	SetViewport(0, 0, width, height);
}

void RenderManager::GetRenderTargetWindowSize(int32_t& outWidth, int32_t& outHeight)
{
	GLFWwindow* window = renderTargetWindow_->GetWindowPtr();
	glfwGetWindowSize(window, &outWidth, &outHeight);
}

float RenderManager::GetRenderTargetWindowAspectRatio()
{
	int32_t width = 0;
	int32_t height = 0;
	GetRenderTargetWindowSize(width, height);

	return static_cast<float>(width) / static_cast<float>(height);
}

void RenderManager::RenderModel3D(const glm::mat4& world, Camera3D* camera, Model* model, Light* light)
{
	Shader* shader = ResourceManager::Get().GetResource<Shader>("Shader");

	shader->Bind();

	shader->SetMat4Parameter("model", world);
	shader->SetMat4Parameter("view", camera->GetViewMatrix());
	shader->SetMat4Parameter("projection", camera->GetProjectionMatrix());

	Material* material = model->GetMaterial();

	shader->SetVec3Parameter("lightPosition", light->GetPosition());
	shader->SetVec4Parameter("lightColor", light->GetColor());
	shader->SetVec3Parameter("viewPosition", camera->GetEyePosition());
	shader->SetVec4Parameter("material.ambient", material->GetAmbient());
	shader->SetVec4Parameter("material.diffuse", material->GetDiffuse());
	shader->SetVec4Parameter("material.specular", material->GetSpecular());
	shader->SetFloatParameter("material.specularPower", material->GetSpecularPower());
	
	Mesh* mesh = model->GetMesh();

	glBindVertexArray(mesh->GetVertexArrayObject());
	glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);

	shader->Unbind();
}