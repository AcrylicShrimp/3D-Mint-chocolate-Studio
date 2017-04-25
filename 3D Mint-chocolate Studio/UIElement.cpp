
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "UIElement.h"

namespace D3MCS::UI
{
	UIElement *UIElement::pEnteredElement{nullptr};
	UIElement *UIElement::pFocusedElement{nullptr};

	UIElement::UIElement(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight) :
		nX{nNewX},
		nY{nNewY},
		nWidth{nNewWidth},
		nHeight{nNewHeight},
		bHided{false},
		bEnabled{true},
		pParent{nullptr}
	{
		//Empty.
	}

	UIElement::UIElement(UIElement &&sSrc) :
		nX{sSrc.nX},
		nY{sSrc.nY},
		nWidth{sSrc.nWidth},
		nHeight{sSrc.nHeight},
		bHided{sSrc.bHided},
		bEnabled{sSrc.bEnabled},
		pParent{nullptr},
		sChildList{std::move(sSrc.sChildList)}
	{
		if (sSrc.pParent)
		{
			sSrc.pParent->addChild(this);
			sSrc.pParent->removeChild(&sSrc);
		}

		for (auto pChild : this->sChildList)
			pChild->pParent = this;
	}

	UIElement::~UIElement()
	{
		if (this->pParent)
			this->pParent->removeChild(this);

		if (UIElement::pFocusedElement == this)
			UIElement::pFocusedElement = nullptr;
	}

	UIElement &UIElement::operator=(UIElement &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		if (this->pParent)
			this->pParent->removeChild(this);

		if (sSrc.pParent)
		{
			sSrc.pParent->addChild(this);
			sSrc.pParent->removeChild(&sSrc);
		}

		this->nX = sSrc.nX;
		this->nY = sSrc.nY;
		this->nWidth = sSrc.nWidth;
		this->nHeight = sSrc.nHeight;
		this->bHided = sSrc.bHided;
		this->bEnabled = sSrc.bEnabled;
		this->sChildList = std::move(sSrc.sChildList);

		for (auto pChild : this->sChildList)
			pChild->pParent = this;

		return *this;
	}

	void UIElement::renderAll()
	{

	}

	LRESULT UIElement::handleWindowMessage(UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (nMessage)
		{
		case WM_MOUSEMOVE:

			break;

		default:
			break;
		}

		return 0;
	}

	void UIElement::addChild(UIElement *pNewChild)
	{
		for (auto pChild : this->sChildList)
			if (pChild == pNewChild)
				return;

		this->sChildList.emplace_back(pNewChild);

		if (pNewChild->pParent)
			pNewChild->pParent->removeChild(pNewChild);

		pNewChild->pParent = this;
	}

	void UIElement::removeChild(UIElement *pNewChild)
	{
		for (auto iIndex = this->sChildList.begin(), iEnd = this->sChildList.end(); iIndex != iEnd; ++iIndex)
			if (*iIndex == pNewChild)
			{
				(*iIndex)->pParent = nullptr;
				this->sChildList.erase(iIndex);

				return;
			}
	}

	void UIElement::moveUpper(uint32_t nCount)
	{
		if (!this->pParent)
			return;

		auto nIndex{0u};
		for (; this->pParent->sChildList[nIndex] != this; ++nIndex);

		this->sChildList.erase(this->pParent->sChildList.cbegin() + nIndex);

		if (nIndex + nCount < this->pParent->sChildList.size())
			this->sChildList.insert(this->pParent->sChildList.cbegin() + nIndex + nCount, this);
		else
			this->sChildList.insert(this->pParent->sChildList.cend(), this);
	}

	void UIElement::moveUpperMost()
	{
		if (!this->pParent)
			return;

		auto iIndex{this->pParent->sChildList.cbegin()};
		for (; (*iIndex) != this; ++iIndex);

		this->sChildList.erase(iIndex);
		this->sChildList.insert(this->sChildList.cend(), this);
	}

	void UIElement::moveLower(uint32_t nCount)
	{
		if (!this->pParent)
			return;

		auto nIndex{0u};
		for (; this->pParent->sChildList[nIndex] != this; ++nIndex);

		this->sChildList.erase(this->pParent->sChildList.cbegin() + nIndex);

		if (nIndex > nCount)
			this->sChildList.insert(this->pParent->sChildList.cbegin() + nIndex - nCount, this);
		else
			this->sChildList.insert(this->pParent->sChildList.cbegin(), this);
	}

	void UIElement::moveLowerMost()
	{
		if (!this->pParent)
			return;

		auto iIndex{this->pParent->sChildList.cbegin()};
		for (; (*iIndex) != this; ++iIndex);

		this->sChildList.erase(iIndex);
		this->sChildList.insert(this->sChildList.cbegin(), this);
	}

	void UIElement::render()
	{
		if (this->bHided)
			return;

		for (auto pChild : this->sChildList)
			pChild->render();
	}

	void UIElement::onFocusOn()
	{
		//Empty.
	}

	void UIElement::onFocusOff()
	{
		//Empty.
	}

	void UIElement::onMouseEnter(int32_t nX, int32_t nY)
	{
		//Empty.
	}

	void UIElement::onMouseLeave(int32_t nX, int32_t nY)
	{
		//Empty.
	}

	void UIElement::onMouseMove(int32_t nX, int32_t nY)
	{
		for (auto iIndex{this->sChildList.rbegin()}, iEnd{this->sChildList.rend()}; iIndex != iEnd; ++iIndex)
			if ((*iIndex)->checkCollide(nX, nY) && !(*iIndex)->bHided)
			{
				(*iIndex)->onMouseMove(nX, nY);
				return;
			}
	}

	void UIElement::onMouseDown(int32_t nX, int32_t nY, int32_t nKeyCode)
	{
		for (auto iIndex{this->sChildList.rbegin()}, iEnd{this->sChildList.rend()}; iIndex != iEnd; ++iIndex)
			if ((*iIndex)->checkCollide(nX, nY) && !(*iIndex)->bHided)
			{
				(*iIndex)->onMouseDown(nX, nY, nKeyCode);
				return;
			}

		if (nKeyCode & MK_LBUTTON || nKeyCode & MK_RBUTTON)
			this->takeFocus();
	}

	void UIElement::onMouseUp(int32_t nX, int32_t nY, int32_t nKeyCode)
	{
		for (auto iIndex{this->sChildList.rbegin()}, iEnd{this->sChildList.rend()}; iIndex != iEnd; ++iIndex)
			if ((*iIndex)->checkCollide(nX, nY) && !(*iIndex)->bHided)
			{
				(*iIndex)->onMouseUp(nX, nY, nKeyCode);
				return;
			}
	}

	void UIElement::onMouseWheel(int32_t nX, int32_t nY, int32_t nDelta)
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