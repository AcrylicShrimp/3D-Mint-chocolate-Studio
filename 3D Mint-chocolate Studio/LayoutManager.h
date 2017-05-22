
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_LAYOUT_LAYOUT_MANAGER_H

#define _CLASS_D3MCS_UI_LAYOUT_LAYOUT_MANAGER_H

#include "ManagerBase.h"
#include "UIElement.h"
#include "UIManager.h"
#include "XMLElement.h"
#include "XMLParser.h"

#include <string>
#include <unordered_map>
#include <utility>

namespace D3MCS::UI::Layout
{
	class LayoutManager final : public ManagerBase<LayoutManager>
	{
	public:
		friend ManagerBase<LayoutManager>;

	private:

		
	private:
		LayoutManager() = default;
		LayoutManager(const LayoutManager &sSrc) = delete;
		LayoutManager(LayoutManager &&sSrc) = delete;
		~LayoutManager() = default;
		
	private:
		LayoutManager &operator=(const LayoutManager &sSrc) = delete;
		LayoutManager &operator=(LayoutManager &&sSrc) = delete;
		
	public:
		inline bool inflateUIFromFile(const wchar_t *pXMLPath);
		inline bool inflateUIFromContent(const std::wstring &sXMLContent);

		void deflateUI();

	private:
		bool inflateUI(const std::unordered_multimap<std::wstring, Utility::XML::XMLElement> &sXMLRoot);
	};

	inline bool LayoutManager::inflateUIFromFile(const wchar_t *pXMLPath)
	{
		return this->inflateUI(Utility::XML::XMLParser::parseXMLFromFile(pXMLPath));
	}

	inline bool LayoutManager::inflateUIFromContent(const std::wstring &sXMLContent)
	{
		return this->inflateUI(Utility::XML::XMLParser::parseXMLFromContent(sXMLContent));
	}
}

#endif