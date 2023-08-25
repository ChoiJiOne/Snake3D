#pragma once

#include <d3d11.h>
#include <vector>
#include <string>
#include <memory>

#include "Utils/Macro.h"

#include "Vector/Vector.h"


/**
 * @brief �ؽ�ó ��Ʋ�󽺿� ǥ�õ� �۸��� �����Դϴ�.
 */
struct Glyph
{
	int32_t codePoint;
	Vector2i position0;
	Vector2i position1;
	float xoffset;
	float yoffset;
	float xoffset2;
	float yoffset2;
	float xadvance;
};


/**
 * @brief Ʈ�� Ÿ�� ��Ʈ�� �����ϴ� ���ڵ��� �ؽ�ó ��Ʋ���Դϴ�.
 */
class TTFont
{
public:
	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ�� �ε��ϰ� �ؽ�Ʈ �ؽ�ó ��Ʋ�󽺸� �����ϴ� ��Ʈ�� �⺻ �������Դϴ�.
	 * 
	 * @note �ʱ�ȭ�� �����ϱ� ���ؼ��� �ݵ�� Initialzie �޼��带 ȣ���ؾ� �մϴ�.
	 */
	TTFont() = default;


	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ�� ���� �Ҹ����Դϴ�.
	 * 
	 * @note ������ �����ϱ� ���ؼ��� �ݵ�� Release �޼��带 ȣ���ؾ� �մϴ�.
	 */
	virtual ~TTFont();


	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ Ŭ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(TTFont);


	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ ������ �ε��ϰ� �۸��� ��Ʋ�󽺸� �����մϴ�.
	 * 
	 * @note �۸��� �ؽ�ó ��Ʋ�� ������ ���۰� ���� �ڵ� ����Ʈ�� �����մϴ�.
	 * 
	 * @param path Ʈ�� Ÿ�� ��Ʈ ������ ����Դϴ�.
	 * @param beginCodePoint �۸��� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param endCodePoint �۸��� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param fontSize ��Ʈ�� ũ���Դϴ�.
	 */
	void Initialize(const std::string& path, int32_t beginCodePoint, int32_t endCodePoint, float fontSize);


	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ Ŭ���� ������ ���ҽ��� �����մϴ�.
	 */
	void Release();


	/**
	 * @brief �۸��� �ؽ�ó ��Ʋ���� �����͸� ����ϴ�.
	 *
	 * @return �۸��� �ؽ�ó ��Ʋ���� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11Texture2D* GetGlyphAtlas() { return glyphAtlas_; }


	/**
	 * @brief ���������ο� ���ε� �� �۸��� �ؽ�ó ��Ʋ�� ���ҽ� ���� �����͸� ����ϴ�.
	 *
	 * @return ���������ο� ���ε� �� �۸��� �ؽ�ó ��Ʋ�� ���ҽ� ���� �����͸� ��ȯ�մϴ�.
	 */
	ID3D11ShaderResourceView* GetGlyphAtlasView() { return glyphAtlasView_; }


	/**
	 * @brief �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� ������ ����ϴ�.
	 *
	 * @param codePoint ��ġ �� ������ �˰� ���� �ڵ� ����Ʈ ���Դϴ�.
	 * 
	 * @return �ڵ� ����Ʈ�� �����ϴ� ������ ��ġ �� ũ�� ������ ��ȯ�մϴ�.
	 */
	const Glyph& GetGlyph(int32_t codePoint) const;


	/**
	 * @brief �ؽ�ó ��Ʋ���� ũ�⸦ ����ϴ�.
	 *
	 * @return �ؽ�ó ��Ʋ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetGlyphAtlasSize() const { return glyphAtlasSize_; }


	/**
	 * @brief �ڵ� ����Ʈ�� ���� ���� ���ԵǴ��� Ȯ���մϴ�.
	 *
	 * @param codePoint ���� �˻縦 ������ �ڵ� ����Ʈ ���Դϴ�.
	 *
	 * @return ���� ���� �ִٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HasCodePointInRange(int32_t codePoint) const;


	/**
	 * @brief �ؽ�Ʈ�� ũ�⸦ �����մϴ�.
	 *
	 * @note ���� ������ �ȼ� �����Դϴ�.
	 *
	 * @param text ������ �ؽ�Ʈ�Դϴ�.
	 * @param outWidth ������ �ؽ�Ʈ�� ���� ũ���Դϴ�.
	 * @param outHeight ������ �ؽ�Ʈ�� ���� ũ���Դϴ�.
	 */
	void MeasureText(const std::wstring& text, float& outWidth, float& outHeight) const;


private:
	/**
	 * @brief �۸��� �ؽ�ó ��Ʋ�� ��Ʈ���� �����մϴ�.
	 *
	 * @note �۸��� �ؽ�ó ��Ʋ���� ���� ���� ũ��� �����ϴ�.
	 *
	 * @param buffer Ʈ�� Ÿ�� ��Ʈ ���ҽ� �����Դϴ�.
	 * @param beginCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param endCodePoint ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param fontSize ��Ʈ�� ũ���Դϴ�.
	 * @param outGlyphs �ؽ�ó ��Ʋ�� ���� �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� �����Դϴ�.
	 * @param outGlyphAtlasSize �۸��� �ؽ�ó ��Ʋ�� ũ���Դϴ�.
	 *
	 * @return ������ �۸��� �ؽ�ó ��Ʋ�� ��Ʈ���� ��ȯ�մϴ�.
	 */
	std::shared_ptr<uint8_t[]> GenerateGlyphAtlasBitmap(
		const std::vector<uint8_t>& buffer,
		int32_t beginCodePoint,
		int32_t endCodePoint,
		float fontSize,
		std::vector<Glyph>& outGlyphs,
		int32_t& outGlyphAtlasSize
	);


	/**
	 * @brief �ؽ�ó ��Ʋ�� ��Ʈ������ ���� �ؽ�ó ���ҽ��� �����մϴ�.
	 * 
	 * @param bitmap �ؽ�ó ��Ʋ�� ��Ʈ���Դϴ�.
	 * @param atlasSize �ؽ�ó ��Ʋ�� ��Ʈ���� ���� ���� ũ���Դϴ�
	 */
	void CreateGlyphAtlasFromBitmap(
		const std::shared_ptr<uint8_t[]>& bitmap,
		const int32_t& glyphAtlasSize
	);


private:
	/**
	 * @brief Ʈ�� Ÿ�� ��Ʈ Ŭ������ �ʱ�ȭ�� ���� �ִ��� Ȯ���մϴ�.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 *
	 * @note �ؽ�ó ��Ʋ�󽺴� �������� �����մϴ�.
	 */
	int32_t beginCodePoint_ = 0;


	/**
	 * @brief ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 *
	 * @note �ؽ�ó ��Ʋ�󽺴� ������ �����մϴ�.
	 */
	int32_t endCodePoint_ = 0;


	/**
	 * @brief �۸��� �ؽ�ó ��Ʋ���� ũ���Դϴ�.
	 */
	int32_t glyphAtlasSize_ = 0;


	/**
	 * @brief �۸��� �ؽ�ó ��Ʋ�� ���� �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� �����Դϴ�.
	 */
	std::vector<Glyph> glyphs_;


	/**
	 * @brief �۸��� �ؽ�ó ��Ʋ���Դϴ�.
	 */
	ID3D11Texture2D* glyphAtlas_ = nullptr;


	/**
	 * @brief �۸��� �ؽ�ó ��Ʋ�� ���ҽ� ���Դϴ�.
	 */
	ID3D11ShaderResourceView* glyphAtlasView_ = nullptr;
};