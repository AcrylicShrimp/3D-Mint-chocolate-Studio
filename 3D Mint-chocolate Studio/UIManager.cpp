
/*
	2017.04.25
	Created by AcrylicShrimp.
*/

#include "UIManager.h"

namespace D3MCS::UI
{
	UIManager::UIManager() :
		WindowMessageProcedure{WM_KEYDOWN, WM_KEYUP, WM_MOUSEMOVE, WM_MOUSEWHEEL, WM_IME_STARTCOMPOSITION, WM_IME_ENDCOMPOSITION, WM_IME_COMPOSITION, WM_CHAR}
	{
		//Empty.
	}

	void UIManager::renderAll()
	{
		if (!UIElement::rootElement()->isEnabled())
			return;

		std::deque<UIElement *> sRenderQueue;

		//Reverse!
		for (auto pChild : UIElement::rootElement()->child())
			if (pChild->isEnabled())
				sRenderQueue.emplace_front(pChild);

		while (!sRenderQueue.empty())
		{
			auto pNext = sRenderQueue.front();
			sRenderQueue.pop_front();

			if (!pNext->isHided())
				pNext->render();

			//Reverse!
			auto &sChildList = pNext->child();
			for (auto iIndex = sChildList.rbegin(), iEnd = sChildList.rend(); iIndex != iEnd; ++iIndex)
				if ((*iIndex)->isEnabled())
					sRenderQueue.emplace_back(*iIndex);
		}
	}

	void UIManager::clearUIElement()
	{
		for (auto pUIElement : this->sUIElementMap)
			delete pUIElement.second;

		this->sUIElementMap.clear();
	}

	void UIManager::removeUIElementByName(const std::wstring &sName)
	{
		auto iIndex = this->sUIElementMap.find(sName);

		if (iIndex == this->sUIElementMap.cend())
			return;

		delete iIndex->second;

		this->sUIElementMap.erase(iIndex);
	}

	UIElement *UIManager::findUIElementByName(const std::wstring &sName)
	{
		auto iIndex = this->sUIElementMap.find(sName);

		return iIndex != this->sUIElementMap.cend() ? iIndex->second : nullptr;
	}

	const UIElement *UIManager::findUIElementByName(const std::wstring &sName) const
	{
		auto iIndex = this->sUIElementMap.find(sName);

		return iIndex != this->sUIElementMap.cend() ? iIndex->second : nullptr;
	}

	LRESULT UIManager::handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		if (hWindow != FrameManager::instance().frame().windowHandle())
			return 0;

		UIElement::handleWindowMessage(nMessage, wParam, lParam);

		return 0;
	}
}