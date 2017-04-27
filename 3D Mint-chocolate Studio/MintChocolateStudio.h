
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_MINT_CHOCOLATE_STUDIO_H

#define _CLASS_D3MCS_MINT_CHOCOLATE_STUDIO_H

#include "Frame.h"
#include "FrameManager.h"
#include "GlyphManager.h"
#include "InputManager.h"
#include "OpenGLManager.h"
#include "RenderManager.h"
#include "WindowMessageProcedure.h"

#include <Windows.h>
#include <GL\glew.h>

namespace D3MCS
{
	class MintChocolateStudio final
	{
	public:
		MintChocolateStudio() = delete;
		MintChocolateStudio(const MintChocolateStudio &sSrc) = delete;
		MintChocolateStudio(MintChocolateStudio &&sSrc) = delete;
		~MintChocolateStudio() = delete;
		
	public:
		MintChocolateStudio &operator=(const MintChocolateStudio &sSrc) = delete;
		MintChocolateStudio &operator=(MintChocolateStudio &&sSrc) = delete;
		
	public:
		static void initialize();
		static void finalize();
	};
}

#endif