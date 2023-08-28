#pragma once

#include <d3d11.h>

#include "Resource/IResource.h"


/**
 * @brief 메시 클래스입니다.
 */
class Mesh : public IResource
{
public:
	/**
	 * @brief 메시 클래스의 기본 생성자입니다.
	 * 
	 * @note 초기화를 수행하기 위해서는 반드시 Initialize 메서드를 호출해야 합니다.
	 */
	Mesh() = default;


	/**
	 * @brief 메시 클래스의 가상 소멸자입니다.
	 * 
	 * @note 해제를 수행하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Mesh();


	/**
	 * @brief 메시 클래스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Mesh);


	/**
	 * @brief 메시 클래스를 초기화합니다.
	 * 
	 * @param verticesPtr 버텍스 버퍼의 포인터입니다.
	 * @param vertexStride 버텍스 버퍼의 간격 크기입니다.
	 * @param vertexCount 버텍스 버퍼의 수입니다.
	 * @param indicesPtr 인덱스 버퍼의 포인터입니다.
	 * @param indexCount 인덱스 버퍼의 수입니다.
	 */
	void Initialize(const void* verticesPtr, uint32_t vertexStride, uint32_t vertexCount, const void* indicesPtr, uint32_t indexCount);

	
	/**
	 * @brief 메시 클래스를 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 버텍스 버퍼 인터페이스의 포인터를 얻습니다.
	 * 
	 * @return 버텍스 버퍼 인터페이스의 포인터를 반환합니다.
	 */
	ID3D11Buffer* GetVertexBufferPtr() { return vertexBuffer_; }


	/**
	 * @brief 인덱스 버퍼 인터페이스의 포인터를 얻습니다.
	 * 
	 * @return 인덱스 버퍼 인터페이스의 포인터를 반환합니다.
	 */
	ID3D11Buffer* GetIndexBufferPtr() { return indexBuffer_; }


	/**
	 * @brief 버텍스 버퍼의 간격 크기를 얻습니다.
	 * 
	 * @return 버텍스 버퍼의 간격 크기를 반환합니다.
	 */
	uint32_t GetVertexStride() { return vertexStride_; }


	/**
	 * @brief 버텍스 버퍼의 수를 얻습니다.
	 * 
	 * @return 버텍스 버퍼의 수를 반환합니다.
	 */
	uint32_t GetVertexCount() { return vertexCount_; }


	/**
	 * @brief 인덱스 버퍼의 수를 얻습니다.
	 * 
	 * @return 인덱스 버퍼의 수를 반환합니다.
	 */
	uint32_t GetIndexCount() { return indexCount_; }
	

private:
	/**
	 * @brief 비정형 메모리인 버퍼 리소스에 액세스 가능한 버텍스 버퍼 인터페이스입니다. 
	 */
	ID3D11Buffer* vertexBuffer_ = nullptr;


	/**
	 * @brief 비정형 메모리인 버퍼 리소스에 액세스 가능한 버텍스 인덱스 인터페이스입니다. 
	 */
	ID3D11Buffer* indexBuffer_ = nullptr;


	/**
	 * @brief 버텍스 버퍼의 크기 간격입니다.
	 */
	uint32_t vertexStride_ = 0;


	/**
	 * @brief 버텍스 버퍼의 수입니다.
	 */
	uint32_t vertexCount_ = 0;


	/**
	 * @brief 인덱스 버퍼의 수입니다.
	 */
	uint32_t indexCount_ = 0;
};