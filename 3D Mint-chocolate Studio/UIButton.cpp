
/*
	2017.04.24
	Created by AcrylicShrimp.
*/

#include "UIButton.h"

namespace D3MCS::UI
{
	UIButton::UIButton(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, float nFontSize, const std::wstring &sNewLabel) :
		UIElement(nNewX, nNewY, nNewWidth, nNewHeight),
		bIsEntered{false},
		bIsPressed{false}
	{
		//Empty.
	}

	UIButton::UIButton(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, float nFontSize, std::wstring &&sNewLabel) :
		UIElement(nNewX, nNewY, nNewWidth, nNewHeight),
		bIsEntered{false},
		bIsPressed{false}
	{
		//Empty.
	}

	UIButton::UIButton(UIButton &&sSrc) :
		UIElement(std::move(sSrc)),
		bIsEntered{sSrc.bIsEntered},
		bIsPressed{sSrc.bIsPressed}
	{
		//Empty.
	}

	UIButton::~UIButton()
	{
		//Empty.
	}

	UIButton &UIButton::operator=(UIButton &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->UIElement::operator=(std::move(sSrc));

		return *this;
	}

	void UIButton::render()
	{

	}
}