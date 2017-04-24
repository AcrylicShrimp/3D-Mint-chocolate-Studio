
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "UIElement.h"

namespace D3MCS::UI
{
	UIElement *UIElement::pFocusedElement{nullptr};

	UIElement::UIElement(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight) :
		nX{nNewX},
		nY{nNewY},
		nWidth{nNewWidth},
		nHeight{nNewHeight}
	{
		//Empty.
	}

	UIElement::UIElement(const UIElement &sSrc) :
		nX{sSrc.nX},
		nY{sSrc.nY},
		nWidth{sSrc.nWidth},
		nHeight{sSrc.nHeight}
	{
		//Empty.
	}
	
	UIElement::~UIElement()
	{
		if (UIElement::pFocusedElement == this)
			UIElement::pFocusedElement = nullptr;
	}
	
	UIElement &UIElement::operator=(const UIElement &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->nX = sSrc.nX;
		this->nY = sSrc.nY;
		this->nWidth = sSrc.nWidth;
		this->nHeight = sSrc.nHeight;
		
		return *this;
	}
}