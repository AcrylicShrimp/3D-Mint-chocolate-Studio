
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MC_UI_FRAME_MANAGER_H

#define _CLASS_D3MC_UI_FRAME_MANAGER_H

#include "Frame.h"
#include "ManagerBase.h"
#include "WindowMessageProcedure.h"

#include <cstdint>
#include <string>
#include <Windows.h>
#include <windowsx.h>

namespace D3MCS::UI
{
	class FrameManager final : public ManagerBase<FrameManager>, public WindowMessageProcedure
	{
	public:
		friend ManagerBase<FrameManager>;

	private:
		Frame sFrame;
		int32_t nX;
		int32_t nY;
		uint32_t nWidth;
		uint32_t nHeight;
		
	private:
		FrameManager();
		FrameManager(const FrameManager &sSrc) = delete;
		FrameManager(FrameManager &&sSrc) = delete;
		~FrameManager() = default;
		
	private:
		FrameManager &operator=(const FrameManager &sSrc) = delete;
		FrameManager &operator=(FrameManager &&sSrc) = delete;
		
	public:
		inline Frame &frame();
		inline const Frame &frame() const;
		inline int32_t frameX() const;
		inline int32_t frameY() const;
		inline uint32_t frameWidth() const;
		inline uint32_t frameHeight() const;

		bool createFrame(int32_t nX, int32_t nY, uint32_t nWidth, uint32_t nHeight, uint32_t nColorBit, uint32_t nDepthBit, bool bFullscreen, const std::wstring &sClassName, const std::wstring &sTitleText, HICON hIcon);
		void destroyFrame();
		virtual LRESULT handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) override;
	};

	inline Frame &FrameManager::frame()
	{
		return this->sFrame;
	}

	inline const Frame &FrameManager::frame() const
	{
		return this->sFrame;
	}

	inline int32_t FrameManager::frameX() const
	{
		return this->nX;
	}

	inline int32_t FrameManager::frameY() const
	{
		return this->nY;
	}

	inline uint32_t FrameManager::frameWidth() const
	{
		return this->nWidth;
	}

	inline uint32_t FrameManager::frameHeight() const
	{
		return this->nHeight;
	}
}

#endif