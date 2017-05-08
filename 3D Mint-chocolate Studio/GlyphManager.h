
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_GLYPH_MANAGER_H

#define _CLASS_D3MCS_UI_GLYPH_MANAGER_H

#include "Container.h"
#include "ManagerBase.h"
#include "Texture.h"
#include "VideoBuffer.h"

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <Windows.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_BITMAP_H
#include FT_GLYPH_H

namespace D3MCS::UI
{
	struct GlyphRenderState
	{
	public:
		std::size_t nTextureIndex;
		uint32_t nWidth;
		uint32_t nHeight;
		int32_t nBiasX;
		int32_t nBiasY;
		int32_t nAdvanceX;
		int32_t nAdvanceY;
		float nFirstX;
		float nFirstY;
		float nSecondX;
		float nSecondY;
	};

	using GlyphRenderStateLookup = std::unordered_map<char32_t, GlyphRenderState>;

	struct GlyphState
	{
	public:
		FT_Face sFace;
		uint32_t nFontSize;
		uint32_t nLastX;
		uint32_t nLastY;
		bool bKerning;
		std::vector<Render::Texture> sTextureList;
		GlyphRenderStateLookup sGlyphRenderStateLookup;
	};

	using Font = const FT_FaceRec *;
	using FontMap = std::unordered_map<std::wstring, std::pair<FT_Byte *, FT_Face>>;
	using GlyphLookupMap = std::unordered_map<uint32_t, GlyphState>;
	using GlyphMap = std::unordered_map<Font, GlyphLookupMap>;

	class GlyphManager : public ManagerBase<GlyphManager>
	{
	public:
		friend ManagerBase<GlyphManager>;
		static constexpr Font NullFont{nullptr};
		static constexpr FT_Face NullFace{nullptr};
		
	private:
		FT_Library sFreetypeLibrary;
		FontMap sFontMap;
		GlyphMap sGlyphMap;
		
	private:
		GlyphManager();
		GlyphManager(const GlyphManager &sSrc) = delete;
		GlyphManager(GlyphManager &&sSrc) = delete;
		~GlyphManager();
		
	private:
		GlyphManager &operator=(const GlyphManager &sSrc) = delete;
		GlyphManager &operator=(GlyphManager &&sSrc) = delete;
		
	public:
		Font loadFont(const std::wstring &sFontPath);
		void unloadFontAll();
		void unloadFont(Font sFont);
		void unloadFont(const std::wstring &sFontPath);
		void unbakeFontAll();
		void unbakeFont(Font sFont);
		void unbakeFont(const std::wstring &sFontPath);
		void bakeString(Font sFont, uint32_t nFontSize, char32_t nCharacter);
		void bakeString(Font sFont, uint32_t nFontSize, const char32_t *pString);
		const GlyphState *findGlyphState(Font sFont, uint32_t nFontSize) const;

	private:
		void bakeCharacter(char32_t nCharacter, GlyphState *pGlyphState);
	};
}

#endif