
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#include "LayoutManager.h"

namespace D3MCS::UI::Layout
{
	void LayoutManager::deflateUI()
	{
		UIManager::instance().clearUIElement();
	}

	bool LayoutManager::inflateUI(const std::unordered_multimap<std::wstring, Utility::XML::XMLElement> &sXMLRoot)
	{
		this->deflateUI();

		auto iRoot{sXMLRoot.equal_range(L"UI")};

		if (iRoot.first == iRoot.second)
			return false;

		auto sRoot{iRoot.first->second};

		if (++iRoot.first != iRoot.second)
			return false;

		//TODO : Place UI Elements here.

		return true;
	}
}