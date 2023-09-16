#pragma once

#include <vector>

#include "Resource/IResource.h"

#include "Utility/Vertex.h"


/**
 * @brief 메시 클래스입니다.
 */
class Mesh : public IResource
{
public:
	/**
	 * @brief 메시의 디폴트 생성자입니다.
	 * 
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Mesh() = default;


	/**
	 * @brief 메시의 가상 소멸자입니다.
	 * 
	 * @note 메시 내부 리소스를 할당 해제하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Mesh();


	/**
	 * @brief 메시의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Mesh);


	/**
	 * @brief 정점과 인덱스를 기반으로 메시를 생성합니다.
	 * 
	 * @param vertices 메시를 구성할 정점 목록입니다.
	 * @param indices 메시를 구성할 인덱스 목록입니다.
	 */
	void Initialize(const std::vector<VertexPosition>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 정점과 인덱스를 기반으로 메시를 생성합니다.
	 *
	 * @param vertices 메시를 구성할 정점 목록입니다.
	 * @param indices 메시를 구성할 인덱스 목록입니다.
	 */
	void Initialize(const std::vector<VertexPositionNormal>& vertices, const std::vector<uint32_t>& indices);


	/**
	 * @brief 메시 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 메시의 정점에 위치를 포함했는지 확인합니다.
	 * 
	 * @return 메시의 정점에 위치를 포함하고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HavePosition() const { return bHavePosition_; }


	/**
	 * @brief 메시의 정점에 노말(법선) 벡터를 포함했는지 확인합니다.
	 * 
	 * @return 메시의 정점에 노말(법선) 벡터를 포함하고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveNormal() const { return bHaveNormal_; }


	/**
	 * @brief 메시의 정점에 색상을 포함했는지 확인합니다. 
	 * 
	 * @return 메시의 정점에 색상을 포함하고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveColor() const { return bHaveColor_; }


	/**
	 * @brief 메시의 정점에 텍스처 좌표를 포함했는지 확인합니다.
	 * 
	 * @return 메시의 정점에 텍스처 좌표를 포함하고 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveTextureCoordinate() const { return bHaveTextureCoordinate_; }


	/**
	 * @brief 메시 정점의 인덱스 카운트 값을 얻습니다.
	 * 
	 * @return 메시 정점의 인덱스 카운트 값을 반환합니다.
	 */
	uint32_t GetIndexCount() const { return indexCount_; }


	/**
	 * @brief 메시 정점과 인덱스의 버텍스 목록 오브젝트 ID를 얻습니다.
	 * 
	 * @return 정점과 인덱스의 버텍스 목록 오브젝트 ID를 반환합니다.
	 */
	uint32_t GetVertexArrayObject() const { return vertexArrayObject_; }


private:
	/**
	 * @brief 메시의 정점에 위치를 포함했는지 확인합니다.
	 */
	bool bHavePosition_ = false;


	/**
	 * @brief 메시의 정점에 노말(법선) 벡터를 포함했는지 확인합니다.
	 */
	bool bHaveNormal_ = false;


	/**
	 * @brief 메시의 정점에 색상을 포함했는지 확인합니다.
	 */
	bool bHaveColor_ = false;


	/**
	 * @brief 메시의 정점에 텍스처 좌표를 포함했는지 확인합니다.
	 */
	bool bHaveTextureCoordinate_ = false;


	/**
	 * @brief 정점의 인덱스 카운트입니다.
	 */
	uint32_t indexCount_ = 0;


	/**
	 * @brief 정점의 버텍스 버퍼 ID입니다.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief 정점의 인덱스 버퍼 ID입니다.
	 */
	uint32_t indexBufferObject_ = 0;


	/**
	 * @brief 정점의 버텍스 목록 ID입니다.
	 */
	uint32_t vertexArrayObject_ = 0;
};