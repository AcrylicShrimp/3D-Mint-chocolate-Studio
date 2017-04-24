
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "RenderManager.h"

namespace D3MCS::UI
{
	RenderManager::RenderManager() :
		WindowMessageProcedure{WM_ERASEBKGND, WM_PAINT}
	{
		//Empty.
	}

	RenderManager::~RenderManager()
	{
		//Empty.
	}

	void RenderManager::render()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		SwapBuffers(FrameManager::instance().frame().deviceContext());
	}
	
	LRESULT CALLBACK RenderManager::handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		if (hWindow != FrameManager::instance().frame().windowHandle())
			return 0;

		switch (nMessage)
		{
		case WM_ERASEBKGND:
			break;
		case WM_PAINT:
		{
			this->render();
		}
		break;
		default:
			break;
		}

		return 0;
	}
}