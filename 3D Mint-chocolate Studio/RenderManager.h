
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_RENDER_MANAGER_H

#define _CLASS_D3MCS_UI_RENDER_MANAGER_H

#include "Frame.h"
#include "FrameManager.h"
#include "ManagerBase.h"
#include "WindowMessageProcedure.h"

#include <Windows.h>
#include <GL\GL.h>

namespace D3MCS::UI
{
	class RenderManager final : public ManagerBase<RenderManager>, WindowMessageProcedure
	{
	public:
		friend ManagerBase<RenderManager>;

	private:
		RenderManager();
		RenderManager(const RenderManager &sSrc) = delete;
		RenderManager(RenderManager &&sSrc) = delete;
		~RenderManager();
		
	private:
		RenderManager &operator=(const RenderManager &sSrc) = delete;
		RenderManager &operator=(RenderManager &&sSrc) = delete;
		
	public:
		void render();
		virtual LRESULT CALLBACK handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) override;
	};
}

#endif