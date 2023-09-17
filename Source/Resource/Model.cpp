#include "Resource/Model.h"
#include "Resource/Material.h"
#include "Resource/Mesh.h"

#include "Utility/Assertion.h"

Model::~Model()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void Model::Initialize(Mesh* mesh, Material* material)
{
	ASSERT(!bIsInitialized_, "already initialize model resource...");
	ASSERT(mesh != nullptr, "model mesh is invalid...");
	ASSERT(material != nullptr, "model material is invalid...");
	
	mesh_ = mesh;
	material_ = material;

	bIsInitialized_ = true;
}

void Model::Release()
{
	ASSERT(bIsInitialized_, "you have to call Initialize method...");

	mesh_ = nullptr;
	material_ = nullptr;

	bIsInitialized_ = false;
}