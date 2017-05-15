
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#include "UILabel.h"

namespace D3MCS::UI
{
	UILabel::UILabel(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight)
	{

	}
	
	UILabel::UILabel(UILabel &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	UILabel::~UILabel()
	{
		//TODO : Place your implementation of destructor here.
		
	}

	UILabel &UILabel::operator=(UILabel &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		//TODO : Place your implementation of move assignment operator here.
		
		
		return *this;
	}

	void UILabel::render()
	{

	}

	void UILabel::onContextCreated()
	{

	}

	void UILabel::onContextDestroying()
	{

	}
}