#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "GameObject/Camera3D.h"
#include "GameObject/DirectionalLight.h"
#include "GameObject/Light.h"
#include "GameObject/PointLight.h"
#include "GameObject/SpotLight.h"

#include "Resource/GeometryShader.h"
#include "Resource/CubeMap.h"
#include "Resource/Material.h"
#include "Resource/Mesh.h"
#include "Resource/Model.h"
#include "Resource/Shader.h"

#include "Utility/Assertion.h"
#include "Utility/Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

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

	CreateScreenVertexArray();
	CreateCubeMapVertexArray();
	CreateRenderTargetFramebuffer();
	
	bIsInitialized_ = true;
}

void RenderManager::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	glDeleteRenderbuffers(1, &renderTargetDepthStencilBuffer_);
	glDeleteTextures(1, &renderTargetColorBuffer_);
	glDeleteFramebuffers(1, &renderTargetFrameBuffer_);

	glDeleteBuffers(1, &cubeMapVertexBuffer_);
	glDeleteVertexArrays(1, &cubeMapVertexArray_);

	glDeleteBuffers(1, &screenVertexBuffer_);
	glDeleteVertexArrays(1, &screenVertexArray_);

	renderTargetWindow_ = nullptr;

	bIsInitialized_ = false;
}

void RenderManager::BeginFrame(float red, float green, float blue, float alpha, float depth, uint8_t stencil)
{
	bIsUsePostProcessing_ = false;

	glBindFramebuffer(GL_FRAMEBUFFER, renderTargetFrameBuffer_);

	SetDepthMode(true);
	SetAlphaBlend(true);
	
	glClearColor(red, green, blue, alpha);
	glClearDepth(depth);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void RenderManager::EndFrame()
{
	if (!bIsUsePostProcessing_)
	{
		Shader* shader = ResourceManager::Get().GetResource<Shader>("PostProcessing");

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, renderTargetColorBuffer_);

		shader->Bind();
		shader->SetIntParameter("screenFramebuffer", 0);
		shader->SetBoolParameter("bEnableBlur", false);
		shader->SetBoolParameter("bEnableColorEffect", false);
		shader->SetBoolParameter("bEnableInversion", false);
		shader->SetBoolParameter("bEnableGrayScale", false);

		EffectPostProcessing();

		shader->Unbind();
	}

	glfwSwapBuffers(renderTargetWindow_->GetWindowPtr());
}

void RenderManager::SetVsyncMode(bool bIsEnable)
{
	bEnableVsync_ = bIsEnable;
	glfwSwapInterval(static_cast<int32_t>(bIsEnable));
}

void RenderManager::SetDepthMode(bool bIsEnable)
{
	if (bIsEnable)
	{
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		glDisable(GL_DEPTH_TEST);
	}
}

void RenderManager::SetAlphaBlend(bool bIsEnable)
{
	if (bIsEnable)
	{
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
	}
	else
	{
		glDisable(GL_BLEND);
	}
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

void RenderManager::RenderLine2D(const glm::vec2& fromPosition, const glm::vec2& toPosition, const glm::vec4& color)
{
	SetDepthMode(false);

	GeometryShader* geometryShader = ResourceManager::Get().GetResource<GeometryShader>("Geometry");
	
	int32_t width = 0;
	int32_t height = 0;
	GetRenderTargetWindowSize(width, height);

	float left = 0.0f;
	float right = static_cast<float>(width);
	float bottom = static_cast<float>(height);
	float top = 0.0f;
	float nearZ = -1.0f;
	float farZ = 1.0f;
	glm::mat4 projection = glm::ortho(left, right, bottom, top, nearZ, farZ);

	geometryShader->DrawLine2D(projection, fromPosition, toPosition, color);

	SetDepthMode(true);
}

void RenderManager::RenderLine3D(Camera3D* camera, const glm::vec3& fromPosition, const glm::vec3& toPosition, const glm::vec4& color)
{
	ASSERT(camera != nullptr, "invalid camera parameter for render 3d line...");

	GeometryShader* geometryShader = ResourceManager::Get().GetResource<GeometryShader>("Geometry");

	geometryShader->DrawLine3D(camera->GetViewMatrix(), camera->GetProjectionMatrix(), fromPosition, toPosition, color);
}

void RenderManager::RenderModel3D(const glm::mat4& world, Camera3D* camera, Model* model, Light* light)
{
	ASSERT(camera != nullptr, "invalid camera parameter for render 3d model...");
	ASSERT(model != nullptr, "invalid model parameter for render 3d model...");
	ASSERT(light != nullptr, "invalid light parameter for render 3d model...");

	Shader* shader = nullptr;
	Mesh* mesh = model->GetMesh();
	Material* material = model->GetMaterial();

	Light::EType type = light->GetType();
	switch (type)
	{
	case Light::EType::DirectionalLight:
		shader = ResourceManager::Get().GetResource<Shader>("DirectionalLight");
		break;

	case Light::EType::PointLight:
		shader = ResourceManager::Get().GetResource<Shader>("PointLight");
		break;

	case Light::EType::SpotLight:
		shader = ResourceManager::Get().GetResource<Shader>("SpotLight");
		break;
	}

	shader->Bind();

	// Set Vertex Shader Parameter...
	shader->SetMat4Parameter("model", world);
	shader->SetMat4Parameter("view", camera->GetViewMatrix());
	shader->SetMat4Parameter("projection", camera->GetProjectionMatrix());

	// Set Fragment Shader Parameter...
	shader->SetVec3Parameter("viewPosition", camera->GetEyePosition());
	shader->SetVec3Parameter("material.ambient", material->GetAmbient());
	shader->SetVec3Parameter("material.diffuse", material->GetDiffuse());
	shader->SetVec3Parameter("material.specular", material->GetSpecular());
	shader->SetFloatParameter("material.specularPower", material->GetSpecularPower());

	if (type == Light::EType::DirectionalLight)
	{
		DirectionalLight* directionalLight = reinterpret_cast<DirectionalLight*>(light);

		shader->SetVec3Parameter("directionalLight.ambient", directionalLight->GetAmbient());
		shader->SetVec3Parameter("directionalLight.diffuse", directionalLight->GetDiffuse());
		shader->SetVec3Parameter("directionalLight.specular", directionalLight->GetSpecular());
		shader->SetVec3Parameter("directionalLight.direction", directionalLight->GetDirection());
	}
	else if (type == Light::EType::PointLight)
	{
		PointLight* pointLight = reinterpret_cast<PointLight*>(light);

		shader->SetVec3Parameter("pointLight.position", pointLight->GetPosition());

		shader->SetVec3Parameter("pointLight.ambient", pointLight->GetAmbient());
		shader->SetVec3Parameter("pointLight.diffuse", pointLight->GetDiffuse());
		shader->SetVec3Parameter("pointLight.specular", pointLight->GetSpecular());

		shader->SetFloatParameter("pointLight.constant", pointLight->GetConstant());
		shader->SetFloatParameter("pointLight.linear", pointLight->GetLinear());
		shader->SetFloatParameter("pointLight.quadratic", pointLight->GetQuadratic());
	}
	else if (type == Light::EType::SpotLight)
	{
		SpotLight* spotLight = reinterpret_cast<SpotLight*>(light);

		shader->SetVec3Parameter("spotLight.position", spotLight->GetPosition());
		shader->SetVec3Parameter("spotLight.direction", spotLight->GetDirection());

		shader->SetFloatParameter("spotLight.innerCutOff", spotLight->GetInnerCutOff());
		shader->SetFloatParameter("spotLight.outerCutOff", spotLight->GetOuterCutOff());

		shader->SetVec3Parameter("spotLight.ambient", spotLight->GetAmbient());
		shader->SetVec3Parameter("spotLight.diffuse", spotLight->GetDiffuse());
		shader->SetVec3Parameter("spotLight.specular", spotLight->GetSpecular());

		shader->SetFloatParameter("spotLight.constant", spotLight->GetConstant());
		shader->SetFloatParameter("spotLight.linear", spotLight->GetLinear());
		shader->SetFloatParameter("spotLight.quadratic", spotLight->GetQuadratic());
	}
	else
	{
		// 아무 동작도 수행하지 않음...
	}
	
	glBindVertexArray(mesh->GetVertexArrayObject());
	glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->Unbind();
}

void RenderManager::RenderCubeMap(Camera3D* camera, CubeMap* cubeMap)
{
	ASSERT(camera != nullptr, "invalid camera parameter for render cube map...");
	ASSERT(cubeMap != nullptr, "invalid cubeMap parameter for render cube map...");

	glDepthFunc(GL_LEQUAL);

	Shader* shader = ResourceManager::Get().GetResource<Shader>("Skybox");
	shader->Bind();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap->GetResourceID());

	shader->SetIntParameter("skybox", 0);
	shader->SetMat4Parameter("view", glm::mat4(glm::mat3(camera->GetViewMatrix())));
	shader->SetMat4Parameter("projection", camera->GetProjectionMatrix());

	glBindVertexArray(cubeMapVertexArray_);
	glDrawArrays(GL_TRIANGLES, 0, cubeMapVertexCount_);
	glBindVertexArray(0);
	
	shader->Unbind();
	glDepthFunc(GL_LESS);
}

void RenderManager::BlurEffect(float bias)
{
	bIsUsePostProcessing_ = true;
	Shader* shader = ResourceManager::Get().GetResource<Shader>("PostProcessing");

	ASSERT(bias > 0.0f, "The bias value must be greater than 0.0f. Bias: %.f", bias);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, renderTargetColorBuffer_);

	shader->Bind();
	shader->SetIntParameter("screenFramebuffer", 0);
	shader->SetBoolParameter("bEnableBlur", true);
	shader->SetBoolParameter("bEnableColorEffect", false);
	shader->SetBoolParameter("bEnableInversion", false);
	shader->SetBoolParameter("bEnableGrayScale", false);
	shader->SetFloatParameter("blurBias", bias);

	EffectPostProcessing();

	shader->Unbind();
}

void RenderManager::ColorEffect(float redBias, float greenBias, float blueBias)
{
	bIsUsePostProcessing_ = true;
	Shader* shader = ResourceManager::Get().GetResource<Shader>("PostProcessing");

	ASSERT((0.0f <= redBias && redBias <= 1.0f), "red bias range is 0.0f to 1.0f but, current range is %.f", redBias);
	ASSERT((0.0f <= greenBias && greenBias <= 1.0f), "green bias range is 0.0f to 1.0f but, current range is %.f", greenBias);
	ASSERT((0.0f <= blueBias && blueBias <= 1.0f), "blue bias range is 0.0f to 1.0f but, current range is %.f", blueBias);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, renderTargetColorBuffer_);

	shader->Bind();
	shader->SetIntParameter("screenFramebuffer", 0);
	shader->SetBoolParameter("bEnableBlur", false);
	shader->SetBoolParameter("bEnableColorEffect", true);
	shader->SetBoolParameter("bEnableInversion", false);
	shader->SetBoolParameter("bEnableGrayScale", false);
	shader->SetFloatParameter("redBias", redBias);
	shader->SetFloatParameter("greenBias", greenBias);
	shader->SetFloatParameter("blueBias", blueBias);

	EffectPostProcessing();

	shader->Unbind();
}

void RenderManager::InversionEffect()
{
	bIsUsePostProcessing_ = true;
	Shader* shader = ResourceManager::Get().GetResource<Shader>("PostProcessing");
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, renderTargetColorBuffer_);

	shader->Bind();
	shader->SetIntParameter("screenFramebuffer", 0);
	shader->SetBoolParameter("bEnableBlur", false);
	shader->SetBoolParameter("bEnableColorEffect", false);
	shader->SetBoolParameter("bEnableInversion", true);
	shader->SetBoolParameter("bEnableGrayScale", false);

	EffectPostProcessing();

	shader->Unbind();
}

void RenderManager::GrayScaleEffect()
{
	bIsUsePostProcessing_ = true;
	Shader* shader = ResourceManager::Get().GetResource<Shader>("PostProcessing");

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, renderTargetColorBuffer_);

	shader->Bind();
	shader->SetIntParameter("screenFramebuffer", 0);
	shader->SetBoolParameter("bEnableBlur", false);
	shader->SetBoolParameter("bEnableColorEffect", false);
	shader->SetBoolParameter("bEnableInversion", false);
	shader->SetBoolParameter("bEnableGrayScale", true);

	EffectPostProcessing();

	shader->Unbind();
}

void RenderManager::CreateScreenVertexArray()
{
	std::vector<float> screenNDCVertices =
	{
		-1.0f,  1.0f,  0.0f, 1.0f,
		-1.0f, -1.0f,  0.0f, 0.0f,
		 1.0f, -1.0f,  1.0f, 0.0f,

		-1.0f,  1.0f,  0.0f, 1.0f,
		 1.0f, -1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f,  1.0f, 1.0f
	};
	screenVertexCount_ = static_cast<int32_t>(screenNDCVertices.size()) / 4;

	glGenVertexArrays(1, &screenVertexArray_);
	glGenBuffers(1, &screenVertexBuffer_);

	glBindVertexArray(screenVertexArray_);
	glBindBuffer(GL_ARRAY_BUFFER, screenVertexBuffer_);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * screenNDCVertices.size(), reinterpret_cast<const void*>(&screenNDCVertices[0]), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

	glBindVertexArray(0);
}

void RenderManager::CreateCubeMapVertexArray()
{
	std::vector<float> cubeMapVertices = 
	{
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f
	};
	cubeMapVertexCount_ = static_cast<int32_t>(cubeMapVertices.size()) / 3;

	glGenVertexArrays(1, &cubeMapVertexArray_);
	glGenBuffers(1, &cubeMapVertexBuffer_);

	glBindVertexArray(cubeMapVertexArray_);
	glBindBuffer(GL_ARRAY_BUFFER, cubeMapVertexBuffer_);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * cubeMapVertices.size(), reinterpret_cast<const void*>(&cubeMapVertices[0]), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glBindVertexArray(0);
}

void RenderManager::CreateRenderTargetFramebuffer()
{
	int32_t backBufferWidth = 0;
	int32_t backBufferHeight = 0;
	GetRenderTargetWindowSize(backBufferWidth, backBufferHeight);

	glGenFramebuffers(1, &renderTargetFrameBuffer_);
	glBindFramebuffer(GL_FRAMEBUFFER, renderTargetFrameBuffer_);

	glGenTextures(1, &renderTargetColorBuffer_);
	glBindTexture(GL_TEXTURE_2D, renderTargetColorBuffer_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, backBufferWidth, backBufferHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderTargetColorBuffer_, 0);

	glGenRenderbuffers(1, &renderTargetDepthStencilBuffer_);
	glBindRenderbuffer(GL_RENDERBUFFER, renderTargetDepthStencilBuffer_);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, backBufferWidth, backBufferHeight);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderTargetDepthStencilBuffer_);

	ASSERT((glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE), "failed to create render target framebuffer...");

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RenderManager::EffectPostProcessing()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	SetDepthMode(false);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(screenVertexArray_);
	glDrawArrays(GL_TRIANGLES, 0, screenVertexCount_);
	glBindVertexArray(0);

	SetDepthMode(true);
}