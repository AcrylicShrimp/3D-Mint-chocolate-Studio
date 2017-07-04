
/*
	2017.06.17
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_LAYOUT_UILABEL_INFLATER_H

#define _CLASS_D3MCS_UI_LAYOUT_UILABEL_INFLATER_H

#include "LayoutElementInflater.h"

#include <string>

namespace D3MCS::UI::Layout
{
	class UILabelInflater final : public LayoutElementInflater
	{
	private:
		std::wstring sIdentifier;
		
	public:
		UILabelInflater();
		UILabelInflater(const UILabelInflater &sSrc) = delete;
		UILabelInflater(UILabelInflater &&sSrc) = delete;
		~UILabelInflater() = default;
		
	public:
		UILabelInflater &operator=(const UILabelInflater &sSrc) = delete;
		UILabelInflater &operator=(UILabelInflater &&sSrc) = delete;
		
	public:
		virtual const std::wstring &identifier() const override;
		virtual bool inflateElement(const Utility::XML::XMLElement &sXMLElement) const override;
	};
}

#endif