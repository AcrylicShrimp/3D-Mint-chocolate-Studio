
/*
	2017.06.17
	Created by AcrylicShrimp.
*/

#include "UILabelInflater.h"

namespace D3MCS::UI::Layout
{
	UILabelInflater::UILabelInflater() :
		sIdentifier{L"Label"}
	{
		//Empty.
	}

	const std::wstring &UILabelInflater::identifier() const
	{
		return this->sIdentifier;
	}

	bool UILabelInflater::inflateElement(const Utility::XML::XMLElement & sXMLElement) const
	{
		if (sXMLElement.name() != this->sIdentifier)
			return false;



		return true;
	}
}