
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_SESSION_MANAGER_H

#define _CLASS_D3MCS_SESSION_MANAGER_H

#include "ManagerBase.h"
#include "WindowMessageProcedure.h"

#include <Windows.h>

namespace D3MCS
{
	class SessionManager final : public ManagerBase<SessionManager>, public UI::WindowMessageProcedure
	{
	public:
		friend ManagerBase<SessionManager>;

	private:
		SessionManager();
		SessionManager(const SessionManager &sSrc) = delete;
		SessionManager(SessionManager &&sSrc) = delete;
		~SessionManager() = default;
		
	private:
		SessionManager &operator=(const SessionManager &sSrc) = delete;
		SessionManager &operator=(SessionManager &&sSrc) = delete;
		
	public:
		virtual LRESULT handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) override;
	};
}

#endif