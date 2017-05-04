
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
		int32_t nAdvance;
		float nFirstX;
		float nFirstY;
		float nSecondX;
		float nSecondY;
	};

	struct GlyphState
	{
		uint8_t *pFontFile;
		FT_Face sFace;
		uint32_t nFontSize;
		uint32_t nLastX;
		uint32_t nLastY;
		bool bKerning;
		std::vector<Render::Texture> sTextureList;
		std::unordered_map<char32_t, GlyphRenderState> sGlyphRenderStateMap;
	};

	using Font = const FT_FaceRec *;

	class GlyphManager : public ManagerBase<GlyphManager>
	{
	public:
		friend ManagerBase<GlyphManager>;
		static constexpr Font NullFont = nullptr;
		
	private:
		Utility::Container<Render::VideoBuffer> sPositionBuffer;
		Utility::Container<Render::VideoBuffer> sTexCoordBuffer;
		FT_Library sFreetypeLibrary;
		std::unordered_map<std::string, std::unordered_map<int32_t, std::pair<int32_t, GlyphState>>> sGlyphMap;
		
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
		void unloadFont(Font &sFont, const std::wstring &sFontPath);
		void unbakeFontAll();
		void unbakeFont(Font sFont);
		void bakeString(Font sFont, uint32_t nFontSize, char32_t nCharacter);
		void bakeString(Font sFont, uint32_t nFontSize, const std::u32string &sString);
		void generateVertex(Font sFont, uint32_t nFontSize, char32_t nCharacter);
		void generateVertex(Font sFont, uint32_t nFontSize, const std::u32string &sString);
		//



		void clearPreparedCharacter();
		void clearBakedTexture();
		void rebakePreparedCharacter();
		void clearPreparedGlyphState(const GlyphState *pGlyphState);
		const GlyphState *prepareGlyphState(const wchar_t *pFacePath, uint32_t nFontSize);
		const GlyphState *prepareCharacter(const GlyphState *pGlyphState, char32_t nCharacter);
		const GlyphState *prepareString(const GlyphState *pGlyphState, const char32_t *pString);
	};
}

#endif