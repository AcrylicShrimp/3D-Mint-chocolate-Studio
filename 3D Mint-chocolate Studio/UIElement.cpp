
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

	void UIElement::onFocusOn()
	{
		//Empty.
	}

	void UIElement::onFocusOff()
	{
		//Empty.
	}

	void UIElement::onMouseEnter()
	{
		//Empty.
	}

	void UIElement::onMouseLeave()
	{
		//Empty.
	}

	void UIElement::onMouseMove(int32_t nX, int32_t nY)
	{
		//Empty.
	}

	void UIElement::onMouseDown(int32_t nKeyCode)
	{
		//Empty.
	}

	void UIElement::onMouseUp(int32_t nKeyCode)
	{
		//Empty.
	}

	void UIElement::onMouseWheel(int32_t nDelta)
	{
		//Empty.
	}

	void UIElement::onKeyDown(int32_t nKeyCode)
	{
		//Empty.
	}

	void UIElement::onKeyUp(int32_t nKeyCode)
	{
		//Empty.
	}

	void UIElement::onKeyTyping(wchar_t nCompositionCharacter)
	{
		//Empty.
	}

	void UIElement::onKeyTyped(wchar_t nResultCharacter)
	{
		//Empty.
	}
}