
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_OPEN_GLMANAGER_H

#define _CLASS_D3MCS_RENDER_OPEN_GLMANAGER_H

#include "ManagerBase.h"
#include "WindowMessageProcedure.h"

#include <Windows.h>
#include <GL\glew.h>

namespace D3MCS::Render
{
	class OpenGLManager final : public ManagerBase<OpenGLManager>, public UI::WindowMessageProcedure
	{
	public:
		friend ManagerBase<OpenGLManager>;

	private:
		float nMaxAnisotropic;
		
	private:
		OpenGLManager();
		OpenGLManager(const OpenGLManager &sSrc) = delete;
		OpenGLManager(OpenGLManager &&sSrc) = delete;
		~OpenGLManager() = default;
		
	public:
		OpenGLManager &operator=(const OpenGLManager &sSrc) = delete;
		OpenGLManager &operator=(OpenGLManager &&sSrc) = delete;
		
	public:
		virtual LRESULT handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) override;

		inline float maxAnisotropic() const;
	};

	inline float OpenGLManager::maxAnisotropic() const
	{
		return this->nMaxAnisotropic;
	}
}

#endif