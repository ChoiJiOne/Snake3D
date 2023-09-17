#pragma once

#include <cstdint>
#include <string>

#include <glm/glm.hpp>

#include "Resource/IResource.h"


/**
 * @brief GLSL ���̴��� �������ϰ� ���̴� ���α׷��� �����մϴ�.
 */
class Shader : public IResource
{
public:
	/**
	 * @brief GLSL ���̴��� Ÿ���Դϴ�.
	 */
	enum class EType : int32_t
	{
		VERTEX   = 0x00,
		FRAGMENT = 0x01,
	};


public:
	/**
	 * @brief ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Shader() = default;


	/**
	 * @brief ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~Shader();


	/**
	 * @brief ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


	/**
	 * @brief GLSL ���̴��� �������ϰ� ���̴� ���α׷��� �����մϴ�.
	 * 
	 * @param vsFile ���ؽ� ���̴��� Ȯ����(.vert)�� ������ �̸��Դϴ�.
	 * @param fsFile �����׸�Ʈ ���̴��� Ȯ����(.frag)�� ������ �̸��Դϴ�.
	 */
	void Initialize(const std::string& vsFile, const std::string& fsFile);


	/**
	 * @brief ���̴� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���̴��� ���������ο� ���ε��մϴ�.
	 */
	void Bind();


	/**
	 * @brief ���̴� ���� boolean Ÿ���� ������ ������ �����մϴ�.
	 * 
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetBoolParameter(const std::string& name, bool value);


	/**
	 * @brief ���̴� ���� int Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetIntParameter(const std::string& name, int32_t value);


	/**
	 * @brief ���̴� ���� float Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetFloatParameter(const std::string& name, float value);


	/**
	 * @brief ���̴� ���� vec2 Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetVec2Parameter(const std::string& name, const glm::vec2& value);


	/**
	 * @brief ���̴� ���� vec2 Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 */
	void SetVec2Parameter(const std::string& name, float x, float y);


	/**
	 * @brief ���̴� ���� vec3 Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetVec3Parameter(const std::string& name, const glm::vec3& value);


	/**
	 * @brief ���̴� ���� vec3 Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 * @param z ������ ������ z ���Դϴ�.
	 */
	void SetVec3Parameter(const std::string& name, float x, float y, float z);


	/**
	 * @brief ���̴� ���� vec4 Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetVec4Parameter(const std::string& name, const glm::vec4& value);


	/**
	 * @brief ���̴� ���� vec4 Ÿ���� ������ ������ �����մϴ�.
	 *
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param x ������ ������ x ���Դϴ�.
	 * @param y ������ ������ y ���Դϴ�.
	 * @param z ������ ������ z ���Դϴ�.
	 * @param w ������ ������ w ���Դϴ�.
	 */
	void SetVec4Parameter(const std::string& name, float x, float y, float z, float w);


	/**
	 * @brief ���̴� ���� 2x2 Ÿ���� ������ ������ �����մϴ�.
	 * 
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetMat2Parameter(const std::string& name, const glm::mat2& value);


	/**
	 * @brief ���̴� ���� 3x3 Ÿ���� ������ ������ �����մϴ�.
	 * 
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetMat3Parameter(const std::string& name, const glm::mat3& value);


	/**
	 * @brief ���̴� ���� 4x4 Ÿ���� ������ ������ �����մϴ�.
	 * 
	 * @param name ������ ������ �̸��Դϴ�.
	 * @param value ������ ������ ���� ���Դϴ�.
	 */
	void SetMat4Parameter(const std::string& name, const glm::mat4& value);


private:
	/**
	 * @brief GLSL ���̴� ������ ������ ���ڿ��� ��ȯ�մϴ�.
	 * 
	 * @param path GLSL ���̴� ������ ����Դϴ�.
	 */
	std::string ConvertGLSLSourceToString(const std::string& path);


	/**
	 * @brief ���̴� ��ü�� �����ϰ� ���̴� �ҽ��� �������մϴ�.
	 * 
	 * @note ���̴� ��ü ������ �����ϸ� 0�� �ƴ� ���� ��ȯ�մϴ�.
	 * 
	 * @param type ���̴� Ÿ���Դϴ�.
	 * @param source ���̴� �ҽ��Դϴ�.
	 * 
	 * @return �����ϵ� ���̴� ��ü�� ���̵� ��ȯ�մϴ�.
	 */
	uint32_t CreateAndCompileShader(const EType& type, const std::string& source);


private:
	/**
	 * @brief ���̴� ���� �α׸� ����ϱ� ���� ���ڿ� ������ �ִ� ũ���Դϴ�.
	 */
	static const int32_t MAX_BUFFER_SIZE = 1024;

	
	/**
	 * @brief ���̴� ���� �α׸� ����ϱ� ���� ���ڿ� �����Դϴ�.
	 */
	static char buffer_[MAX_BUFFER_SIZE];
	

	/**
	 * @brief ���̴� ���α׷��� ���̵��Դϴ�.
	 */
	uint32_t programID_ = 0;
};