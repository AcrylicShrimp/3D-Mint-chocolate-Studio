
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MC_UI_WINDOW_MESSAGE_PROCEDURE_H

#define _CLASS_D3MC_UI_WINDOW_MESSAGE_PROCEDURE_H

#include <initializer_list>
#include <unordered_map>
#include <utility>
#include <vector>
#include <Windows.h>

namespace D3MCS::UI
{
	class WindowMessageProcedure
	{
	private:
		static std::unordered_map<UINT, std::vector<WindowMessageProcedure *>> sProcedureListMap;

	protected:
		std::initializer_list<UINT> sMessageList;
		
	public:
		WindowMessageProcedure(const std::initializer_list<UINT> &sNewMessageList);
		WindowMessageProcedure(std::initializer_list<UINT> &&sNewMessageList);
		WindowMessageProcedure(const WindowMessageProcedure &sSrc);
		WindowMessageProcedure(WindowMessageProcedure &&sSrc);
		virtual ~WindowMessageProcedure();
		
	public:
		WindowMessageProcedure &operator=(const WindowMessageProcedure &sSrc);
		WindowMessageProcedure &operator=(WindowMessageProcedure &&sSrc);

	public:
		inline const std::initializer_list<UINT> &messageList() const;
		
		static LRESULT CALLBACK processWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam);
		virtual LRESULT handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) = 0;
	};

	inline const std::initializer_list<UINT> &WindowMessageProcedure::messageList() const
	{
		return this->sMessageList;
	}
}

#endif