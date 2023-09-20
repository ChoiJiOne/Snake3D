#pragma once

#include <array>

#include "Resource/Shader.h"

#include "Utility/Vertex.h"


/**
 * @brief ��, �ﰢ��, �簢�� �� �⺻ ������ �������ϴ� ���̴��Դϴ�.
 */
class GeometryShader : public Shader
{
public:
	/**
	 * @brief �⺻ ������ �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	GeometryShader() = default;


	/**
	 * @brief �⺻ ������ �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~GeometryShader();


	/**
	 * @brief �⺻ ������ �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GeometryShader);


	/**
	 * @brief GLSL ���̴��� �������ϰ� ���̴� ���α׷��� �����մϴ�.
	 *
	 * @param vsFile ���ؽ� ���̴��� Ȯ����(.vert)�� ������ �̸��Դϴ�.
	 * @param fsFile �����׸�Ʈ ���̴��� Ȯ����(.frag)�� ������ �̸��Դϴ�.
	 */
	virtual void Initialize(const std::string& vsFile, const std::string& fsFile) override;


	/**
	 * @brief ���̴� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ȭ�鿡 3D ���� �׸��ϴ�.
	 * 
	 * @param view �þ� ����Դϴ�.
	 * @param projection ���� ����Դϴ�.
	 * @param fromPosition ���� �� 3D ���� ���� ���Դϴ�.
	 * @param toPosition ���� �� 3D ���� �� ���Դϴ�.
	 * @param color 3D ���� �����Դϴ�.
	 */
	void DrawLine3D(
		const glm::mat4& view,
		const glm::mat4& projection,
		const glm::vec3& fromPosition,
		const glm::vec3& toPosition,
		const glm::vec4& color
	);


private:
	/**
	 * @brief ���� ���� ����� �ִ� ũ���Դϴ�.
	 */
	static const int32_t MAX_VERTEX_SIZE = 6;


	/**
	 * @brief ������ ���� ����Դϴ�.
	 */
	std::array<VertexPositionColor, MAX_VERTEX_SIZE> vertices_;


	/**
	 * @brief ���� ������ ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ���� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;
};