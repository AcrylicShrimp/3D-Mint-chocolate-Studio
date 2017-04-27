
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#include "OpenGLManager.h"

namespace D3MCS::Render
{
	OpenGLManager::OpenGLManager() :
		UI::WindowMessageProcedure{WM_CREATE}
	{
		//Empty.
	}

	LRESULT OpenGLManager::handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		//Initialize OpenGL Extention.
		glewInit();

		//Get OpenGL-related values.
		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &this->nMaxAnisotropic);
	}
}