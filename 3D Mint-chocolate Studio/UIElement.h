
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_UIELEMENT_H

#define _CLASS_D3MCS_UI_UIELEMENT_H

#include <cstdint>
#include <vector>
#include <Windows.h>
#include <windowsx.h>

namespace D3MCS::UI
{
	class UIElement
	{
	protected:
		static UIElement *pEnteredElement;
		static UIElement *pFocusedElement;
		static UIElement sRootElement;
		int32_t nX;
		int32_t nY;
		int32_t nWidth;
		int32_t nHeight;
		bool bHided;
		bool bEnabled;
		UIElement *pParent;
		std::vector<UIElement *> sChildList;
		
	public:
		UIElement(int32_t nNewX, int32_t nNewY, int32_t nNewWidth, int32_t nNewHeight);
		UIElement(const UIElement &sSrc) = delete;
		UIElement(UIElement &&sSrc);
		virtual ~UIElement();
		
	public:
		UIElement &operator=(const UIElement &sSrc) = delete;
		UIElement &operator=(UIElement &&sSrc);
		
	public:
		inline static UIElement *rootElement();
		inline int32_t x() const;
		inline int32_t &x();
		inline int32_t y() const;
		inline int32_t &y();
		inline int32_t width() const;
		inline int32_t &width();
		inline int32_t height() const;
		inline int32_t &height();
		inline bool &isHided();
		inline bool isHided() const;
		inline bool &isEnabled();
		inline bool isEnabled() const;
		inline bool isFocused() const;
		inline UIElement *parent() const;
		inline const std::vector<UIElement *> &child() const;
		inline void takeFocus();
		inline bool checkCollide(int32_t nPointX, int32_t nPointY) const;

		static LRESULT handleWindowMessage(UINT nMessage, WPARAM wParam, LPARAM lParam);
		void addChild(UIElement *pNewChild);
		void removeChild(UIElement *pNewChild);
		void moveUpper(uint32_t nCount = 1u);
		void moveUpperMost();
		void moveLower(uint32_t nCount = 1u);
		void moveLowerMost();
		uint32_t calcChildIndex();
		virtual void render();
		virtual void onFocusOn();
		virtual void onFocusOff();
		virtual void onMouseEnter(int32_t nX, int32_t nY);
		virtual void onMouseLeave(int32_t nX, int32_t nY);
		virtual void onMouseMove(int32_t nX, int32_t nY);
		virtual void onMouseDown(int32_t nX, int32_t nY, int32_t nKeyCode);
		virtual void onMouseUp(int32_t nX, int32_t nY, int32_t nKeyCode);
		virtual void onMouseWheel(int32_t nX, int32_t nY, int32_t nDelta);
		virtual void onKeyDown(int32_t nKeyCode);
		virtual void onKeyUp(int32_t nKeyCode);
		virtual void onKeyTyping(wchar_t nCompositionCharacter);
		virtual void onKeyTyped(wchar_t nResultCharacter);
	};

	inline UIElement *UIElement::rootElement()
	{
		return &UIElement::sRootElement;
	}

	inline int32_t UIElement::x() const
	{
		return this->nX;
	}

	inline int32_t &UIElement::x()
	{
		return this->nX;
	}

	inline int32_t UIElement::y() const
	{
		return this->nY;
	}

	inline int32_t &UIElement::y()
	{
		return this->nY;
	}

	inline int32_t UIElement::width() const
	{
		return this->nWidth;
	}

	inline int32_t &UIElement::width()
	{
		return this->nWidth;
	}

	inline int32_t UIElement::height() const
	{
		return this->nHeight;
	}

	inline int32_t &UIElement::height()
	{
		return this->nHeight;
	}

	inline bool UIElement::isHided() const
	{
		return this->bHided;
	}

	inline bool &UIElement::isHided()
	{
		return this->bHided;
	}

	inline bool UIElement::isEnabled() const
	{
		return this->bEnabled;
	}

	inline bool &UIElement::isEnabled()
	{
		return this->bEnabled;
	}

	inline bool UIElement::isFocused() const
	{
		return UIElement::pFocusedElement == this;
	}

	inline UIElement *UIElement::parent() const
	{
		return this->pParent;
	}

	inline const std::vector<UIElement *> &UIElement::child() const
	{
		return this->sChildList;
	}

	inline void UIElement::takeFocus()
	{
		if (UIElement::pFocusedElement)
			UIElement::pFocusedElement->onFocusOff();

		(UIElement::pFocusedElement = this)->onFocusOn();
	}

	inline bool UIElement::checkCollide(int32_t nPointX, int32_t nPointY) const
	{
		return this->nX <= nPointX && this->nX + this->nWidth > nPointX &&
			this->nY <= nPointY && this->nY + this->nHeight > nPointY;
	}
}

#endif