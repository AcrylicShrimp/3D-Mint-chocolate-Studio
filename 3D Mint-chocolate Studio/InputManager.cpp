
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "InputManager.h"

namespace D3MCS::UI
{
	InputManager::InputManager() :
		WindowMessageProcedure{WM_MOUSEMOVE, WM_KEYDOWN, WM_KEYUP},
		nMouseX{0u},
		nMouseY{0u}
	{
		memset(this->vKeyState, 0, sizeof(this->vKeyState));
	}

	LRESULT CALLBACK InputManager::handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		if (hWindow != FrameManager::instance().frame().windowHandle())
			return 0;

		switch (nMessage)
		{
		case WM_MOUSEMOVE:
		{
			this->nMouseX = GET_X_LPARAM(lParam);
			this->nMouseY = GET_Y_LPARAM(lParam);
		}
		break;
		case WM_KEYDOWN:
		case WM_KEYUP:
		break;
		{
			this->vKeyState[wParam] = nMessage == WM_KEYDOWN;
		}
		break;
		default:
			break;
		}

		return 0;
	}
}