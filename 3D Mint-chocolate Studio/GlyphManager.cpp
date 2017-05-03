
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
		FT_Done_FreeType(this->sFreetypeLibrary);
	}
}