#include "Grid.h"
#include "MainCamera.h"

#include "Manager/ObjectManager.h"
#include "Manager/RenderManager.h"
#include "Manager/ResourceManager.h"

#include "Resource/ColorMaterial.h"
#include "Resource/Model.h"
#include "Resource/Mesh.h"

#include "Utils/Camera3D.h"
#include "Utils/GeometryGenerator.h"
#include "Utils/MathHelper.h"

Grid::~Grid()
{
}

void Grid::Initialize(int32_t minX, int32_t maxX, int32_t minZ, int32_t maxZ)
{
	ASSERT(!bIsInitialized_, "already initialize grid object...");

	camera_ = ObjectManager::Get().GetGameObject<MainCamera>("MainCamera")->GetCamera3D();
	xzQuadModel_ = CreateXZQuadModel();

	minX = MathHelper::Min<int32_t>(minX, maxX);
	maxX = MathHelper::Max<int32_t>(minX, maxX);

	minZ = MathHelper::Min<int32_t>(minZ, maxZ);
	maxZ = MathHelper::Max<int32_t>(minZ, maxZ);

	minPosition_ = Vector3f(static_cast<float>(minX), 0.0f, static_cast<float>(minZ));
	maxPosition_ = Vector3f(static_cast<float>(maxX), 0.0f, static_cast<float>(maxZ));

	for (int32_t x = minX; x <= maxX; ++x)
	{
		for (int32_t z = minZ; z <= maxZ; ++z)
		{
			cells_.push_back(Cell(Cell::EState::GRAY, Vector3f(static_cast<float>(x), 0.0f, static_cast<float>(z))));
		}
	}

	SetRandomCellToGreenState();

	bIsInitialized_ = true;
}

void Grid::Update(float deltaSeconds)
{
}

void Grid::Render()
{
	Vector3f transform;
	for (auto& cell : cells_)
	{
		transform = cell.GetTransform();
		xzQuadModel_->SetColorMaterial(cell.GetStateColor());
		RenderManager::Get().DrawModel3D(MathHelper::TranslationMatrix(transform.x, 0.0f, transform.z), camera_, xzQuadModel_);;
	}
}

void Grid::Release()
{
	ASSERT(bIsInitialized_, "you have to initialize grid object...");

	bIsInitialized_ = false;
}

Model* Grid::CreateXZQuadModel()
{
	std::vector<VertexPosition> vertices;
	std::vector<uint32_t> indices;
	float xsize = 1.0f;
	float zsize = 1.0f;
	GeometryGenerator::CreateQuadXZ(xsize, zsize, vertices, indices);

	Model* model = ResourceManager::Get().AddResource<Model>("QuadXZ");
	model->SetMesh(vertices, indices);
	model->SetColorMaterial(Vector4f(1.0f, 1.0f, 1.0f, 1.0f)); // 기본 색상 메터리얼 설정

	return model;
}

void Grid::SetRandomCellToGreenState()
{
	while (true)
	{
		int32_t randomIndex = MathHelper::GenerateRandomInt(0, static_cast<int32_t>(cells_.size()) - 1);
		if (cells_[randomIndex].GetState() == Cell::EState::GRAY)
		{
			cells_[randomIndex].SetState(Cell::EState::GREEN);
			break;
		}
	}
}
