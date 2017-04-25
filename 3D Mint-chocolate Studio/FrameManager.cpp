
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "FrameManager.h"

namespace D3MCS::UI
{
	FrameManager::FrameManager() :
		WindowMessageProcedure{WM_MOVE, WM_SIZE, WM_SIZING, WM_MOVING},
		nX{0},
		nY{0},
		nWidth{0u},
		nHeight{0u}
	{
		//Empty.
	}

	bool FrameManager::createFrame(int32_t nX, int32_t nY, uint32_t nWidth, uint32_t nHeight, uint32_t nColorBit, uint32_t nDepthBit, bool bFullscreen, const std::wstring &sClassName, const std::wstring &sTitleText, HICON hIcon)
	{
		return this->sFrame.createFrame({nX, nY, nWidth, nHeight, nColorBit, nDepthBit, bFullscreen, sClassName, sTitleText, hIcon, WindowMessageProcedure::processWindowMessage});
	}

	void FrameManager::destroyFrame()
	{
		this->sFrame.destroyFrame();
	}

	LRESULT FrameManager::handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		if (hWindow != this->sFrame.windowHandle())
			return 0;

		switch (nMessage)
		{
		case WM_MOVE:
		{
			this->nX = GET_X_LPARAM(lParam);
			this->nY = GET_Y_LPARAM(lParam);
		}
		break;
		case WM_SIZE:
		{
			this->nWidth = GET_X_LPARAM(lParam);
			this->nHeight = GET_Y_LPARAM(lParam);
		}
		break;
		case WM_SIZING:
		{
			auto const pRect{reinterpret_cast <const RECT *>(lParam)};

			this->nX = pRect->left;
			this->nY = pRect->top;
			this->nWidth = pRect->right - pRect->left;
			this->nHeight = pRect->bottom - pRect->top;
		}
		break;
		case WM_MOVING:
		{
			auto const pRect{reinterpret_cast <const RECT *>(lParam)};

			this->nX = pRect->left;
			this->nY = pRect->top;
			this->nWidth = pRect->right - pRect->left;
			this->nHeight = pRect->bottom - pRect->top;
		}
		break;
		default:
			break;
		}

		return 0;
	}
}