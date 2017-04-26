
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_GLYPH_MANAGER_H

#define _CLASS_D3MCS_UI_GLYPH_MANAGER_H

#include <cstdint>
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
		uint32_t nTextureIndex;

	};

	struct GlyphState
	{
		uint8_t *pFontFile;
		FT_Face sFace;
		uint32_t nFontSize;
		uint32_t nLastX;
		uint32_t nLastY;
		bool bKerning;

	};

	class GlyphManager
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		GlyphManager();
		GlyphManager(const GlyphManager &sSrc);
		GlyphManager(GlyphManager &&sSrc);
		~GlyphManager();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		GlyphManager &operator=(const GlyphManager &sSrc);
		GlyphManager &operator=(GlyphManager &&sSrc);
		/*
			TODO : Place your other operator overloadings here.
		*/
		
		
	public:
		/*
			TODO : Place your member function declarations here.
		*/
		
	};
}

#endif