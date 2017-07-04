
/*
	2017.06.15
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_LAYOUT_LAYOUT_ELEMENT_INFLATER_H

#define _CLASS_D3MCS_UI_LAYOUT_LAYOUT_ELEMENT_INFLATER_H

#include "UIElement.h"
#include "XMLElement.h"

#include <string>

namespace D3MCS::UI::Layout
{
	class LayoutElementInflater
	{
	public:
		LayoutElementInflater() = default;
		LayoutElementInflater(const LayoutElementInflater &sSrc) = default;
		LayoutElementInflater(LayoutElementInflater &&sSrc) = default;
		virtual ~LayoutElementInflater() = 0;
		
	public:
		LayoutElementInflater &operator=(const LayoutElementInflater &sSrc) = default;
		LayoutElementInflater &operator=(LayoutElementInflater &&sSrc) = default;
		
	public:
		virtual const std::wstring &identifier() const = 0;
		virtual bool inflateElement(const Utility::XML::XMLElement &sXMLElement) const = 0;
	};
}

#endif