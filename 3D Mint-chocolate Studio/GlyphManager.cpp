
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#include "GlyphManager.h"

namespace D3MCS::UI
{
	GlyphManager::GlyphManager()
	{
		FT_Init_FreeType(&this->sFreetypeLibrary);
	}

	GlyphManager::~GlyphManager()
	{
		this->unloadFontAll();

		FT_Done_FreeType(this->sFreetypeLibrary);
	}

	Font GlyphManager::loadFont(const std::wstring &sFontPath)
	{
		auto iIndex = this->sFontMap.find(sFontPath);

		if (iIndex != this->sFontMap.cend())
			return iIndex->second.second;

		std::ifstream sInput{sFontPath, std::ifstream::ate | std::ifstream::binary | std::ifstream::in};

		if (!sInput.is_open())
			return nullptr;

		auto nSize{sInput.tellg()};
		sInput.seekg(0, std::ifstream::beg);

		auto *pFont{new unsigned char[static_cast<std::size_t>(nSize)]};

		if (!pFont)
			return nullptr;

		sInput.read(reinterpret_cast<char *>(pFont), nSize);

		auto sFace{GlyphManager::NullFace};
		auto nError{FT_New_Memory_Face(this->sFreetypeLibrary, pFont, static_cast<FT_Long>(nSize), 0, &sFace)};

		if (nError)
		{
			delete[] pFont;
			return nullptr;
		}

		this->sFontMap.emplace(sFontPath, std::make_pair(pFont, sFace));

		return sFace;
	}

	void GlyphManager::unloadFontAll()
	{
		this->unbakeFontAll();

		for (auto iIndex{this->sFontMap.cbegin()}, iEnd{this->sFontMap.cend()}; iIndex != iEnd; ++iIndex)
		{
			FT_Done_Face(iIndex->second.second);
			delete[] iIndex->second.first;
		}

		this->sFontMap.clear();
	}

	void GlyphManager::unloadFont(Font sFont)
	{
		this->unbakeFont(sFont);

		for (auto iIndex{this->sFontMap.cbegin()}, iEnd{this->sFontMap.cend()}; iIndex != iEnd; ++iIndex)
			if (iIndex->second.second == sFont)
			{
				FT_Done_Face(iIndex->second.second);
				delete[] iIndex->second.first;

				this->sFontMap.erase(iIndex);

				return;
			}
	}

	void GlyphManager::unloadFont(const std::wstring &sFontPath)
	{
		this->unbakeFont(sFontPath);

		auto iIndex{this->sFontMap.find(sFontPath)};

		if (iIndex != this->sFontMap.cend())
		{
			FT_Done_Face(iIndex->second.second);
			delete[] iIndex->second.first;

			this->sFontMap.erase(sFontPath);
		}
	}

	void GlyphManager::unbakeFontAll()
	{
		this->sGlyphMap.clear();
	}

	void GlyphManager::unbakeFont(Font sFont)
	{
		this->sGlyphMap.erase(sFont);
	}

	void GlyphManager::unbakeFont(const std::wstring &sFontPath)
	{
		auto iIndex{this->sFontMap.find(sFontPath)};

		if (iIndex != this->sFontMap.cend())
			this->sGlyphMap.erase(iIndex->second.second);
	}

	void GlyphManager::bakeString(Font sFont, uint32_t nFontSize, char32_t nCharacter)
	{
		auto &sGlyphLookupMap = this->sGlyphMap[sFont];
		auto iIndex = sGlyphLookupMap.find(nFontSize);

		if (iIndex == sGlyphLookupMap.cend())
			iIndex = sGlyphLookupMap.emplace(nFontSize, GlyphState{
				const_cast<FT_Face>(sFont),
				nFontSize,
				0u,
				0u,
				FT_HAS_KERNING(sFont) != 0
		}).first;

		this->bakeCharacter(nCharacter, &iIndex->second);
	}

	void GlyphManager::bakeString(Font sFont, uint32_t nFontSize, const char32_t *pString)
	{
		auto &sGlyphLookupMap = this->sGlyphMap[sFont];
		auto iIndex = sGlyphLookupMap.find(nFontSize);

		if (iIndex == sGlyphLookupMap.cend())
			iIndex = sGlyphLookupMap.emplace(nFontSize, GlyphState{
			const_cast<FT_Face>(sFont),
			nFontSize,
			0u,
			0u,
			FT_HAS_KERNING(sFont) != 0
		}).first;

		for (auto *pIndex{pString}; *pIndex != '\0'; ++pIndex)
			this->bakeCharacter(*pIndex, &iIndex->second);
	}

	void GlyphManager::bakeCharacter(char32_t nCharacter, GlyphState *pGlyphState)
	{
		FT_Set_Pixel_Sizes(pGlyphState->sFace, 0u, pGlyphState->nFontSize);

		if (FT_Load_Char(pGlyphState->sFace, nCharacter, FT_LOAD_RENDER))
			return;

		auto nWidth{static_cast<unsigned int>(pGlyphState->sFace->glyph->metrics.width >> 6)};
		auto nHeight{static_cast<unsigned int>(pGlyphState->sFace->glyph->metrics.height >> 6)};

		if (pGlyphState->nLastX != 0u && pGlyphState->nLastX + nWidth > 2048u)
		{
			pGlyphState->nLastX = 0u;
			pGlyphState->nLastY += pGlyphState->nFontSize + 1u;
		}

		if (pGlyphState->sTextureList.empty() || pGlyphState->nLastY != 0u && pGlyphState->nLastY + nHeight > 2048u)
		{
			pGlyphState->nLastX = 0u;
			pGlyphState->nLastY = 0u;
			pGlyphState->sTextureList.emplace_back();

			auto &sTexture{pGlyphState->sTextureList.back()};

			sTexture.specifyTexel(2048, 2048, Render::InternalFormat::R8);
			sTexture.setMagFilteringMode(Render::TexelFilter::Linear);
			sTexture.setMinFilteringMode(Render::TexelFilter::Linear, Render::MipmapFilter::None);
			sTexture.setSWrappingMode(Render::WrappingMode::ClampEdge);
			sTexture.setTWrappingMode(Render::WrappingMode::ClampEdge);
		}

		if (pGlyphState->nLastX + nWidth > 2048u)
			nWidth = 2048u - pGlyphState->nLastX;

		if (pGlyphState->nLastY + nHeight > 2048u)
			nHeight = 2048u - pGlyphState->nLastY;

		FT_Bitmap sBitmap;
		FT_Bitmap_New(&sBitmap);

		if (FT_Bitmap_Convert(this->sFreetypeLibrary, &pGlyphState->sFace->glyph->bitmap, &sBitmap, 1))
		{
			FT_Bitmap_Done(this->sFreetypeLibrary, &sBitmap);
			return;
		}

		if (pGlyphState->sFace->glyph->bitmap.pixel_mode == FT_Pixel_Mode::FT_PIXEL_MODE_MONO)
			for (auto nIndex{0u}, nSize{sBitmap.width * sBitmap.rows}; nIndex < nSize; ++nIndex)
				sBitmap.buffer[nIndex] = sBitmap.buffer[nIndex] ? 255u : 0u;

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		pGlyphState->sTextureList.back().updateTexel(pGlyphState->nLastX, pGlyphState->nLastY, sBitmap.width, sBitmap.rows, Render::ExternalFormat::R, Render::TexelType::Byte, sBitmap.buffer);

		FT_Bitmap_Done(this->sFreetypeLibrary, &sBitmap);

		pGlyphState->sGlyphRenderStateLookup.emplace(
			nCharacter,
			GlyphRenderState
		{
			pGlyphState->sTextureList.size() - 1u,
			nWidth,
			nHeight,
			pGlyphState->sFace->glyph->metrics.horiBearingX >> 6,
			pGlyphState->sFace->glyph->metrics.horiBearingY >> 6,
			pGlyphState->sFace->glyph->metrics.horiAdvance >> 6,
			pGlyphState->sFace->glyph->metrics.vertAdvance >> 6,
			static_cast<float>(pGlyphState->nLastX) / 2048.f,
			static_cast<float>(pGlyphState->nLastY) / 2048.f,
			static_cast<float>(pGlyphState->nLastX + nWidth) / 2048.f,
			static_cast<float>(pGlyphState->nLastY + nHeight) / 2048.f
		});
	}
}