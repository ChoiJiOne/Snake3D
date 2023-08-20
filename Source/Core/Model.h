#pragma once

#include <memory>
#include <vector>

#include "Core/Macro.h"
#include "Core/Vertex.h"

class Mesh;
class ColorMaterial;


/**
 * @brief 메시와 메터리얼(재질)을 포함한 모델 클래스입니다.
 */
class Model
{
public:
	/**
	 * @brief 모델 클래스의 기본 생성자입니다.
	 * 
	 * @note 초기화를 수행하기 위해서는 반드시 Set~ 메서드를 호출해야 합니다.
	 */
	Model() = default;


	/**
	 * @brief 모델 클래스의 가상 소멸자입니다.
	 * 
	 * @note 해제를 수행하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Model();


	/**
	 * @brief 모델 클래스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Model);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 * 
	 * @param vertices 모델 메시의 정점 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPosition>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 색상을 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionColor>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 텍스처 위치를 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 노말(법선) 벡터를 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionNormal>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 노말(법선) 벡터, 텍스처 위치를 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionNormalUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 노말(법선) 벡터, 색상을 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionNormalColor>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 색상, 텍스처 위치를 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionColorUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 메시를 설정합니다.
	 *
	 * @param vertices 모델 메시의 위치와 노말(법선) 벡터, 색상, 텍스처 위치를 포함한 버텍스의 목록입니다.
	 * @param indices 모델 메시의 인덱스 목록입니다.
	 */
	void SetMesh(const std::vector<VertexPositionNormalColorUV>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 모델의 색상 메터리얼을 설정합니다.
	 * 
	 * @param color 모델 메터리얼의 색상입니다.
	 */
	void SetColorMaterial(const Vector4f & color);


	/**
	 * @brief 모델 클래스를 해제합니다.
	 */
	void Release();


	/**
	 * @brief 모델 메시의 정점에 위치 정보를 가지고 있는지 확인합니다.
	 * 
	 * @return 가지고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HavePosition() { return bHavePositionInVertex_; }
	 
	 
	/**
	 * @brief 모델 메시의 정점에 노말(법선) 벡터 정보를 가지고 있는지 확인합니다.
	 * 
	 * @return 가지고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveNormal() { return bHaveNormalInVertex_; }


	/**
	 * @brief 모델 메시의 정점에 색상 정보를 가지고 있는지 확인합니다.
	 * 
	 * @return 가지고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveColor() { return bHaveColorInVertex_; }


	/**
	 * @brief 모델 메시의 정점에 텍스처 위치 정보를 가지고 있는지 확인합니다.
	 * 
	 * @return 가지고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveUV() { return bHaveUVInVertex_; }


	/**
	 * @brief 모델이 컬러 메터리얼을 가지고 있는지 확인합니다.
	 * 
	 * @return 색상 메터리얼을 가지고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveColorMaterial() { return material_ != nullptr; }

	
	/**
	 * @brief 모델의 메시를 얻습니다.
	 * 
	 * @return 모델의 메시 포인터를 반환합니다.
	 */
	Mesh* GetMesh() { return mesh_.get(); }


	/**
	 * @brief 모델의 색상 메터리얼을 얻습니다.
	 * 
	 * @return 모델의 색상 메터리얼 포인터를 반환합니다.
	 */
	ColorMaterial* GetColorMaterial() { return material_.get(); }


private:
	/**
	 * @brief 모델의 메시를 설정합니다.
	 * 
	 * @param verticesPtr 버텍스 버퍼의 포인터입니다.
	 * @param vertexStride 버텍스 버퍼의 간격 크기입니다.
	 * @param vertexCount 버텍스 버퍼의 수입니다.
	 * @param indicesPtr 인덱스 버퍼의 포인터입니다.
	 * @param indexCount 인덱스 버퍼의 수입니다.
	 */
	void SetMesh(const void* verticesPtr, uint32_t vertexStride, uint32_t vertexCount, const void* indicesPtr, uint32_t indexCount);


private:
	/**
	 * @brief 정점이 위치 정보를 가지고 있는지 확인합니다.
	 */
	bool bHavePositionInVertex_ = false;


	/**
	 * @brief 정점이 노말(법선) 벡터 정보를 가지고 있는지 확인합니다.
	 */
	bool bHaveNormalInVertex_ = false;


	/**
	 * @brief 정점이 색상 정보를 가지고 있는지 확인합니다.
	 */
	bool bHaveColorInVertex_ = false;


	/**
	 * @brief 정점이 텍스처 위치 정보를 가지고 있는지 확인합니다.
	 */
	bool bHaveUVInVertex_ = false;


	/**
	 * @brief 모델의 메시입니다.
	 */
	std::unique_ptr<Mesh> mesh_ = nullptr;


	/**
	 * @brief 모델의 색상 메터리얼입니다.
	 */
	std::unique_ptr<ColorMaterial> material_ = nullptr;
};