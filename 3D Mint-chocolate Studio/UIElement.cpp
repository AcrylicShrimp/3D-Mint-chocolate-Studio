
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
	
	UIElement::UIElement(const UIElement &sSrc)
	{
		//TODO : Place your implementation of copy constructor here.
		
	}
	
	UIElement::UIElement(UIElement &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	UIElement::~UIElement()
	{
		//TODO : Place your implementation of destructor here.
		
	}
	
	/*
		TODO : Place your other constructors here.
	*/
	
	
	UIElement &UIElement::operator=(const UIElement &sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of copy assignment operator here.
		
		
		return *this;
	}
	
	UIElement &UIElement::operator=(UIElement &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of move assignment operator here.
		
		
		return *this;
	}
	
	/*
		TODO : Place your other operator overloadings here.
	*/
	
	
	/*
		TODO : Place your member function definitions here.
	*/

}