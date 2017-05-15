
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#include "SessionManager.h"

namespace D3MCS
{
	SessionManager::SessionManager() :
		UI::WindowMessageProcedure{WM_CLOSE}
	{
		//Empty.
	}
	
	LRESULT SessionManager::handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		PostQuitMessage(0);

		return 0;
	}
}