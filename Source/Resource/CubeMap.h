#pragma once

#include <string>

#include "Resource/IResource.h"


/**
 * @brief 큐브 맵 리소스입니다.
 */
class CubeMap : public IResource
{
public:
	/**
	 * @brief 큐브맵의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	CubeMap() = default;


	/**
	 * @brief 큐브맵의 가상 소멸자입니다.
	 *
	 * @note 메시 내부 리소스를 할당 해제하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~CubeMap();


	/**
	 * @brief 큐브맵의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(CubeMap);


	/**
	 * @brief 큐브맵을 초기화합니다.
	 * 
	 * @param 큐브맵 RIGHT(+X) 부분의 텍스처 리소스 경로입니다.
	 * @param 큐브맵 LEFT(-X) 부분의 텍스처 리소스 경로입니다.
	 * @param 큐브맵 TOP(+Y) 부분의 텍스처 리소스 경로입니다.
	 * @param 큐브맵 BOTTOM(-Y) 부분의 텍스처 리소스 경로입니다.
	 * @param 큐브맵 FRONT(+Z) 부분의 텍스처 리소스 경로입니다.
	 * @param 큐브맵 BACK(-Z) 부분의 텍스처 리소스 경로입니다.
	 */
	void Initialize(
		const std::string& rightPath, 
		const std::string& leftPath,
		const std::string& topPath,
		const std::string& bottomPath,
		const std::string& frontPath,
		const std::string& backPath
	);


	/**
	 * @brief 큐브맵 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 큐브맵 텍스처의 ID를 얻습니다.
	 * 
	 * @return 큐브맵 텍스처의 ID를 반환합니다.
	 */
	uint32_t GetResourceID() { return cubeMapID_; }


private:
	/**
	 * @brief 큐브맵 텍스처의 ID입니다.
	 */
	uint32_t cubeMapID_ = 0;
};