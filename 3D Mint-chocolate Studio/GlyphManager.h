
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_GLYPH_MANAGER_H

#define _CLASS_D3MCS_UI_GLYPH_MANAGER_H

#include "ManagerBase.h"
#include "Texture.h"
#include "WindowMessageProcedure.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

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

	class GlyphManager : public ManagerBase<GlyphManager>, public WindowMessageProcedure
	{
	public:
		friend ManagerBase<GlyphManager>;
		
	private:
		std::unordered_map<std::pair<std::string, int32_t>, std::pair<int32_t, GlyphState>> sGlyphStateMap;
		
	private:
		GlyphManager();
		GlyphManager(const GlyphManager &sSrc);
		GlyphManager(GlyphManager &&sSrc);
		~GlyphManager();
		
	private:
		GlyphManager &operator=(const GlyphManager &sSrc);
		GlyphManager &operator=(GlyphManager &&sSrc);
		
	public:
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