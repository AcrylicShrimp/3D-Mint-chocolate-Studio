
/*
	2017.04.25
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_UIMANAGER_H

#define _CLASS_D3MCS_UI_UIMANAGER_H

#include "Frame.h"
#include "FrameManager.h"
#include "ManagerBase.h"
#include "UIElement.h"
#include "WindowMessageProcedure.h"

#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <Windows.h>

namespace D3MCS::UI
{
	class UIManager final : public ManagerBase<UIManager>, public WindowMessageProcedure
	{
	public:
		friend ManagerBase<UIManager>;

	private:
		std::unordered_map<std::wstring, UIElement *> sUIElementMap;
		
	private:
		UIManager();
		UIManager(const UIManager &sSrc) = delete;
		UIManager(UIManager &&sSrc) = delete;
		~UIManager() = default;
		
	private:
		UIManager &operator=(const UIManager &sSrc) = delete;
		UIManager &operator=(UIManager &&sSrc) = delete;
		
	public:
		template<class UIType> inline UIType *findUIElementByName(const std::wstring &sName);
		template<class UIType> inline const UIType *findUIElementByName(const std::wstring &sName) const;
		template<class UIType, class ...ConstructorParameter> bool addUIElementByName(const std::wstring &sName, ConstructorParameter &&...sConstructorParameter);
		
		void renderAll();
		void clearUIElement();
		void removeUIElementByName(const std::wstring &sName);
		UIElement *findUIElementByName(const std::wstring &sName);
		const UIElement *findUIElementByName(const std::wstring &sName) const;
		virtual LRESULT handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) override;
	};
}

#include "UIManager.hpp"

#endif