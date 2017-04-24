
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
		bIsPressed{false},
		nFontSize{nFontSize},
		sLabel{sNewLabel}
	{
		//Empty.
	}

	UIButton::UIButton(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, float nFontSize, std::wstring &&sNewLabel) :
		UIElement(nNewX, nNewY, nNewWidth, nNewHeight),
		bIsEntered{false},
		bIsPressed{false},
		nFontSize{nFontSize},
		sLabel{std::move(sNewLabel)}
	{
		//Empty.
	}

	UIButton::UIButton(const UIButton &sSrc) :
		UIElement(sSrc),
		bIsEntered{sSrc.bIsEntered},
		bIsPressed{sSrc.bIsPressed},
		nFontSize{sSrc.nFontSize},
		sLabel{sSrc.sLabel}
	{
		//Empty.
	}

	UIButton::UIButton(UIButton &&sSrc) :
		UIElement(sSrc),
		bIsEntered{sSrc.bIsEntered},
		bIsPressed{sSrc.bIsPressed},
		nFontSize{sSrc.nFontSize},
		sLabel{std::move(sSrc.sLabel)}
	{
		//Empty.
	}

	UIButton::~UIButton()
	{
		//Empty.
	}

	UIButton &UIButton::operator=(const UIButton &sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->UIElement::operator=(sSrc);
		this->sLabel = sSrc.sLabel;

		return *this;
	}

	UIButton &UIButton::operator=(UIButton &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->UIElement::operator=(sSrc);
		this->sLabel = std::move(sSrc.sLabel);

		return *this;
	}

	void UIButton::render()
	{

	}
}