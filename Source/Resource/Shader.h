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
	 * @param vsPath ���ؽ� ���̴��� ����Դϴ�.
	 * @param fsPath �����׸�Ʈ ���̴��� ����Դϴ�.
	 */
	void Initialize(const std::string& vsPath, const std::string& fsPath);


	/**
	 * @brief ���̴� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���̴��� ���������ο� ���ε��մϴ�.
	 */
	void Bind();
	

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