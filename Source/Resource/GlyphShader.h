#pragma once

#include <array>

#include "Resource/Shader.h"

#include "Utility/Vertex.h"

struct Glyph;
class TTFont;


/**
 * @brief �۸����� �̿��ؼ� �ؽ�Ʈ�� �������ϴ� ���̴��Դϴ�.
 *
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
class GlyphShader : public Shader
{
public:
	/**
	 * @brief �۸����� �̿��ؼ� �ؽ�Ʈ�� �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	GlyphShader() = default;


	/**
	 * @brief �۸����� �̿��ؼ� �ؽ�Ʈ�� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴��� ���� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~GlyphShader();


	/**
	 * @brief �۸����� �̿��ؼ� �ؽ�Ʈ�� �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GlyphShader);


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
	 * @brief 2D �ؽ�Ʈ�� ����ۿ� �������մϴ�.
	 *
	 * @param projection ���� ���� ����Դϴ�.
	 * @param font �ؽ�Ʈ�� �������� �� ������ ��Ʈ�Դϴ�.
	 * @param text �������� �ؽ�Ʈ�Դϴ�.
	 * @param center 2D ��ǥ�� ���� �ؽ�Ʈ �߽� ��ǥ�Դϴ�.
	 * @param color �ؽ�Ʈ�� RGB �����Դϴ�.
	 */
	void DrawText2D(const glm::mat4& projection, TTFont* font, const std::wstring& text, const glm::vec2& center, const glm::vec3& color);


private:
	/**
	 * @brief �۸��� ������ �̿��ؼ� ���� ���۸� ������Ʈ�մϴ�.
	 * 
	 * @param glyph �۸����Դϴ�.
	 * @param glyphAtlasSize �۸��� ��Ʋ�� ũ���Դϴ�.
	 * @param position 2D ��ǥ�� ���� �۸��� ��ġ�Դϴ�.
	 */
	void UpdateGlyphVertexBuffer(const Glyph& glyph, float glyphAtlasSize, const glm::vec2& position);

	
private:
	/**
	 * @brief ���ؽ� ���۸� ������Ʈ�մϴ�.
	 */
	void UpdateVertexBuffer();


private:
	/**
	 * @brief �۸��� ���� ����� �ִ� ũ���Դϴ�.
	 */
	static const int32_t MAX_VERTEX_SIZE = 6;


	/**
	 * @brief �۸��� ���� ����Դϴ�.
	 */
	std::array<VertexPositionTexture, MAX_VERTEX_SIZE> glyphVertices_;


	/**
	 * @brief �۸��� ���� ������ ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief �۸��� ���� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;
};