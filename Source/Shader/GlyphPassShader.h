#pragma once

#include "Utils/Vertex.h"

#include "Shader/IShader.h"

struct Glyph;
class TTFont;


/**
 * @brief �۸����� �������ϴ� ���̴��Դϴ�.
 * 
 * 
 * @note
 * - �� ���̴����� ó���ϴ� 2D�� ��ǥ��� ������ �����ϴ�.
 *                y
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 * ����������������������������������������������������������������x
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 *                ��
 */
class GlyphPassShader : public IShader
{
public:
	/**
	 * @brief �� ������ ����Ǵ� ��� �����Դϴ�.
	 */
	struct EveryFrameBuffer
	{
		Matrix4x4f projection;
	};


	/**
	 * @brief �ؽ�Ʈ�� ���� ��� �����Դϴ�.
	 */
	struct TextColorBuffer
	{
		Vector4f color;
	};


public:
	/**
	 * @brief �۸����� �������ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note �ʱ�ȭ�� �ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	GlyphPassShader() = default;


	/**
	 * @brief �۸����� �������ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ���̴� �� ���ҽ��� �Ҵ� �����ϱ� ���ؼ��� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~GlyphPassShader();


	/**
	 * @brief �۸����� �������ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GlyphPassShader);


	/**
	 * @brief �۸����� �������ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 */
	virtual void Initialize() override;


	/**
	 * @brief �۸����� �������ϴ� ���̴��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief 2D �ؽ�Ʈ�� ����ۿ� �������մϴ�.
	 * 
	 * @param font �ؽ�Ʈ�� �������� �� ������ ��Ʈ�Դϴ�.
	 * @param text �������� �ؽ�Ʈ�Դϴ�.
	 * @param center 2D ��ǥ�� ���� �ؽ�Ʈ �߽� ��ǥ�Դϴ�.
	 * @param color �ؽ�Ʈ�� �����Դϴ�.
	 */
	void DrawText2D(TTFont* font, const std::wstring& text, const Vector2f& center, const Vector4f& color);


private:
	/**
	 * @brief ������ â�� ���� ���� ���� ����� ����ϴ�.
	 *
	 * @param nearZ ����� Ŭ���� �������� �Ÿ��Դϴ�. �⺻ ���� 0.01f �Դϴ�.
	 * @param farZ ���Ÿ� Ŭ���� �������� �Ÿ��Դϴ�. �⺻ ���� 100.0f �Դϴ�.
	 *
	 * @return ������ â�� ���� ���� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix4x4f GetWindowOrthographicMatrix(float nearZ = 0.01f, float farZ = 100.0f);


	/**
	 * @brief ���� ���۸� �۸����� �°� ������Ʈ�մϴ�.
	 * 
	 * @param context ���۸� ������Ʈ�� �� ����� ���ؽ�Ʈ�Դϴ�.
	 * @param glyph �۸����Դϴ�.
	 * @param glyphAtlasSize �۸��� �ؽ�ó ��Ʋ���� ũ���Դϴ�.
	 * @param position 2D ��ǥ�� �� �۸����� ��ġ�Դϴ�.
	 */
	void UpdateGlyphVertexBuffer(ID3D11DeviceContext* context, const Glyph& glyph, float glyphAtlasSize, const Vector2f& position);


private:
	/**
	 * @brief �� ������ ����Ǵ� ���̴� ���� ��� �����Դϴ�.
	 */
	ID3D11Buffer* everyFrameBuffer_ = nullptr;


	/**
	 * @brief �ؽ�Ʈ ������ ��Ÿ���� ���̴� ���� ��� �����Դϴ�.
	 */
	ID3D11Buffer* textColorBuffer_ = nullptr;


	/**
	 * @brief �ؽ�ó ���ø��� ���� ���÷� �����Դϴ�.
	 */
	ID3D11SamplerState* linearSamplerState_ = nullptr;


	/**
	 * @brief �۸����� ���� ����Դϴ�.
	 */
	std::vector<VertexPositionUV> glyphVertex_;


	/**
	 * @brief �۸����� ���� �����Դϴ�.
	 */
	ID3D11Buffer* glyphVertexBuffer_ = nullptr;


	/**
	 * @brief �۸����� �ε��� ����Դϴ�.
	 */
	std::vector<uint32_t> glyphIndex_;


	/**
	 * @brief �۸����� �ε��� �����Դϴ�.
	 */
	ID3D11Buffer* glyphIndexBuffer_ = nullptr;
};