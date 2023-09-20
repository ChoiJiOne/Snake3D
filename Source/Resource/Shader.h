#pragma once

#include <cstdint>
#include <string>

#include <glm/glm.hpp>

#include "Resource/IResource.h"


/**
 * @brief GLSL 셰이더를 컴파일하고 셰이더 프로그램을 관리합니다.
 */
class Shader : public IResource
{
public:
	/**
	 * @brief GLSL 셰이더의 타입입니다.
	 */
	enum class EType : int32_t
	{
		VERTEX   = 0x00,
		FRAGMENT = 0x01,
	};


public:
	/**
	 * @brief 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Shader() = default;


	/**
	 * @brief 셰이더의 가상 소멸자입니다.
	 *
	 * @note 셰이더의 내부 리소스를 할당 해제하기 위해서는 반드시 Release 메서드를 호출해야 합니다.
	 */
	virtual ~Shader();


	/**
	 * @brief 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


	/**
	 * @brief GLSL 셰이더를 컴파일하고 셰이더 프로그램을 생성합니다.
	 * 
	 * @param vsFile 버텍스 셰이더의 확장자(.vert)를 포함한 이름입니다.
	 * @param fsFile 프레그먼트 셰이더의 확장자(.frag)를 포함한 이름입니다.
	 */
	virtual void Initialize(const std::string& vsFile, const std::string& fsFile);


	/**
	 * @brief 셰이더 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 셰이더를 파이프라인에 바인딩합니다.
	 */
	void Bind();


	/**
	 * @brief 셰이더를 바인딩 해제합니다.
	 */
	void Unbind();


	/**
	 * @brief 셰이더 내에 boolean 타입의 유니폼 변수를 설정합니다.
	 * 
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetBoolParameter(const std::string& name, bool value);


	/**
	 * @brief 셰이더 내에 int 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetIntParameter(const std::string& name, int32_t value);


	/**
	 * @brief 셰이더 내에 float 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetFloatParameter(const std::string& name, float value);


	/**
	 * @brief 셰이더 내에 vec2 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetVec2Parameter(const std::string& name, const glm::vec2& value);


	/**
	 * @brief 셰이더 내에 vec2 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param x 유니폼 변수의 x 값입니다.
	 * @param y 유니폼 변수의 y 값입니다.
	 */
	void SetVec2Parameter(const std::string& name, float x, float y);


	/**
	 * @brief 셰이더 내에 vec3 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetVec3Parameter(const std::string& name, const glm::vec3& value);


	/**
	 * @brief 셰이더 내에 vec3 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param x 유니폼 변수의 x 값입니다.
	 * @param y 유니폼 변수의 y 값입니다.
	 * @param z 유니폼 변수의 z 값입니다.
	 */
	void SetVec3Parameter(const std::string& name, float x, float y, float z);


	/**
	 * @brief 셰이더 내에 vec4 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetVec4Parameter(const std::string& name, const glm::vec4& value);


	/**
	 * @brief 셰이더 내에 vec4 타입의 유니폼 변수를 설정합니다.
	 *
	 * @param name 유니폼 변수의 이름입니다.
	 * @param x 유니폼 변수의 x 값입니다.
	 * @param y 유니폼 변수의 y 값입니다.
	 * @param z 유니폼 변수의 z 값입니다.
	 * @param w 유니폼 변수의 w 값입니다.
	 */
	void SetVec4Parameter(const std::string& name, float x, float y, float z, float w);


	/**
	 * @brief 셰이더 내에 2x2 타입의 유니폼 변수를 설정합니다.
	 * 
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetMat2Parameter(const std::string& name, const glm::mat2& value);


	/**
	 * @brief 셰이더 내에 3x3 타입의 유니폼 변수를 설정합니다.
	 * 
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetMat3Parameter(const std::string& name, const glm::mat3& value);


	/**
	 * @brief 셰이더 내에 4x4 타입의 유니폼 변수를 설정합니다.
	 * 
	 * @param name 유니폼 변수의 이름입니다.
	 * @param value 유니폼 변수의 설정 값입니다.
	 */
	void SetMat4Parameter(const std::string& name, const glm::mat4& value);


private:
	/**
	 * @brief GLSL 셰이더 파일의 내용을 문자열로 변환합니다.
	 * 
	 * @param path GLSL 셰이더 파일의 경로입니다.
	 */
	std::string ConvertGLSLSourceToString(const std::string& path);


	/**
	 * @brief 셰이더 객체를 생성하고 셰이더 소스를 컴파일합니다.
	 * 
	 * @note 셰이더 객체 생성에 성공하면 0이 아닌 값을 반환합니다.
	 * 
	 * @param type 셰이더 타입입니다.
	 * @param source 셰이더 소스입니다.
	 * 
	 * @return 컴파일된 셰이더 객체의 아이디를 반환합니다.
	 */
	uint32_t CreateAndCompileShader(const EType& type, const std::string& source);


private:
	/**
	 * @brief 셰이더 관련 로그를 기록하기 위한 문자열 버퍼의 최대 크기입니다.
	 */
	static const int32_t MAX_BUFFER_SIZE = 1024;

	
	/**
	 * @brief 셰이더 관련 로그를 기록하기 위한 문자열 버퍼입니다.
	 */
	static char buffer_[MAX_BUFFER_SIZE];
	

	/**
	 * @brief 셰이더 프로그램의 아이디입니다.
	 */
	uint32_t programID_ = 0;
};