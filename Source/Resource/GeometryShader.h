#pragma once

#include <array>

#include "Resource/Shader.h"

#include "Utility/Vertex.h"


/**
 * @brief ��, �ﰢ��, �簢�� �� �⺻ ������ �������ϴ� ���̴��Դϴ�.
 * 
 * @note �⺻ ���� �� 2D ������ �������� ���� ��ǥ��� ������ �����ϴ�.
 * @note
 * - �ﰢ���� ������ ������ ���� CCW�Դϴ�.
 * - 2���� ��ǥ��� ������ �����ϴ�.
 * �������������������������������������������� +x
 * ��
 * ��
 * ��
 * ��
 * ��
 * ��
 * ��
 * ��
 * +y
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
	 * @param projection ���� ���� ����Դϴ�.
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


	/**
	 * @brief ȭ�鿡 2D ���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param fromPosition ��ũ�� �� 2D ���� ���� ���Դϴ�.
	 * @param toPosition ��ũ�� �� 2D ���� �� ���Դϴ�.
	 * @param color 2D ���� �����Դϴ�.
	 */
	void DrawLine2D(const glm::mat4& projection, const glm::vec2& fromPosition, const glm::vec2& toPosition, const glm::vec4& color);


	/**
	 * @brief ȭ�鿡 2D �ﰢ���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param color 2D �ﰢ���� �����Դϴ�.
	 */
	void DrawTriangle2D(
		const glm::mat4& projection, 
		const glm::vec2& fromPosition, 
		const glm::vec2& byPosition,
		const glm::vec2& toPosition, 
		const glm::vec4& color
	);


	/**
	 * @brief ȭ�鿡 2D �ﰢ���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param fromColor 2D ��ǥ�� �� �ﰢ�� ���� ���� �����Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param byColor 2D ��ǥ�� �� �ﰢ�� �߰� ���� �����Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param toColor 2D ��ǥ�� �� �ﰢ�� �� ���� �����Դϴ�.
	 */
	void DrawTriangle2D(
		const glm::mat4& projection,
		const glm::vec2& fromPosition,
		const glm::vec4& fromColor,
		const glm::vec2& byPosition,
		const glm::vec4& byColor,
		const glm::vec2& toPosition,
		const glm::vec4& toColor
	);


	/**
	 * @brief ȭ�鿡 2D ���̾� ������ �ﰢ���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param color 2D �ﰢ���� �����Դϴ�.
	 */
	void DrawWireframeTriangle2D(
		const glm::mat4 & projection,
		const glm::vec2 & fromPosition,
		const glm::vec2 & byPosition,
		const glm::vec2 & toPosition,
		const glm::vec4 & color
	);


	/**
	 * @brief ȭ�鿡 2D ���̾� ������ �ﰢ���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param fromPosition 2D ��ǥ�� ���� �ﰢ�� ���� ���Դϴ�.
	 * @param fromColor 2D ��ǥ�� �� �ﰢ�� ���� ���� �����Դϴ�.
	 * @param byPosition 2D ��ǥ�� ���� �ﰢ�� �߰� ���Դϴ�.
	 * @param byColor 2D ��ǥ�� �� �ﰢ�� �߰� ���� �����Դϴ�.
	 * @param toPosition 2D ��ǥ�� ���� �ﰢ�� �� ���Դϴ�.
	 * @param toColor 2D ��ǥ�� �� �ﰢ�� �� ���� �����Դϴ�.
	 */
	void DrawWireframeTriangle2D(
		const glm::mat4& projection,
		const glm::vec2& fromPosition,
		const glm::vec4& fromColor,
		const glm::vec2& byPosition,
		const glm::vec4& byColor,
		const glm::vec2& toPosition,
		const glm::vec4& toColor
	);


	/**
	 * @brief ȭ�鿡 2D �簢���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param center 2D �簢���� �߽� ��ǥ�Դϴ�.
	 * @param width 2D �簢���� ���� ũ���Դϴ�.
	 * @param heigt 2D �簢���� ���� ũ���Դϴ�.
	 * @param color 2D �簢���� �����Դϴ�.
	 */
	void DrawRectangle2D(const glm::mat4& projection, const glm::vec2& center, float width, float height, const glm::vec4& color);


	/**
	 * @brief ȭ�鿡 2D �簢���� �׸��ϴ�.
	 * 
	 * @param projection ���� ���� ����Դϴ�.
	 * @param leftTopPosition 2D �簢���� ���� ��� ��ǥ�Դϴ�.
	 * @param rightBottomPosition 2D �簢���� ������ �ϴ� ��ǥ�Դϴ�.
	 * @param color 2D �簢���� �����Դϴ�.
	 */
	void DrawRectangle2D(
		const glm::mat4& projection, 
		const glm::vec2& leftTopPosition, 
		const glm::vec2& rightBottomPosition, 
		const glm::vec4& color
	);


	/**
	 * @brief ȭ�鿡 2D ���̾� ������ �簢���� �׸��ϴ�.
	 *
	 * @param projection ���� ���� ����Դϴ�.
	 * @param center 2D �簢���� �߽� ��ǥ�Դϴ�.
	 * @param width 2D �簢���� ���� ũ���Դϴ�.
	 * @param heigt 2D �簢���� ���� ũ���Դϴ�.
	 * @param color 2D �簢���� �����Դϴ�.
	 */
	void DrawWireframeRectangle2D(
		const glm::mat4& projection, 
		const glm::vec2& center, 
		float width, 
		float height, 
		const glm::vec4& color
	);


	/**
	 * @brief ȭ�鿡 2D ���̾� ������ �簢���� �׸��ϴ�.
	 *
	 * @param projection ���� ���� ����Դϴ�.
	 * @param leftTopPosition 2D �簢���� ���� ��� ��ǥ�Դϴ�.
	 * @param rightBottomPosition 2D �簢���� ������ �ϴ� ��ǥ�Դϴ�.
	 * @param color 2D �簢���� �����Դϴ�.
	 */
	void DrawWireframeRectangle2D(
		const glm::mat4& projection, 
		const glm::vec2& leftTopPosition, 
		const glm::vec2& rightBottomPosition, 
		const glm::vec4& color
	);


private:
	/**
	 * @brief �⺻ ������ �׸��� ���� ��带 ��Ÿ���� �������Դϴ�.
	 */
	enum class ERenderMode : int32_t
	{
		LineStrip = 0x0003,
		Triangle  = 0x0004,
	};


	/**
	 * @brief ���ؽ� ���۸� ������Ʈ�մϴ�.
	 */
	void UpdateVertexBuffer();


	/**
	 * @brief �⺻ ������ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param view �þ� ����Դϴ�. 2D�� ��� ���� ��ķ� �����ؾ� �մϴ�.
	 * @param projection ���� ����Դϴ�. 2D�� ��� ���� ���� ��ķ� �����ؾ� �մϴ�.
	 * @param renderMode �⺻ ������ �׸��� ���� ������ ����Դϴ�.
	 * @param vertexCount �⺻ ������ ���� ���Դϴ�.
	 */
	void DrawGeometry(const glm::mat4& view, const glm::mat4& projection, const ERenderMode& renderMode, int32_t vertexCount);


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