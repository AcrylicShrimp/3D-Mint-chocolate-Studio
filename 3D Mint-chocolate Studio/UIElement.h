
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_UIELEMENT_H

#define _CLASS_D3MCS_UI_UIELEMENT_H

#include <cstdint>

namespace D3MCS::UI
{
	class UIElement
	{
	protected:
		static UIElement *pFocusedElement;
		int32_t nX;
		int32_t nY;
		uint32_t nWidth;
		uint32_t nHeight;
		
	public:
		UIElement(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight);
		UIElement(const UIElement &sSrc);
		virtual ~UIElement();
		
	public:
		UIElement &operator=(const UIElement &sSrc);
		
	public:
		inline int32_t x() const;
		inline int32_t &x();
		inline int32_t y() const;
		inline int32_t &y();
		inline uint32_t width() const;
		inline uint32_t &width();
		inline uint32_t height() const;
		inline uint32_t &height();
		inline bool isFocused() const;
		inline void takeFocuse();

		virtual void render() = 0;
		virtual void onFocusOn();
		virtual void onFocusOff();
		virtual void onMouseEnter();
		virtual void onMouseLeave();
		virtual void onMouseMove(int32_t nX, int32_t nY);
		virtual void onMouseDown(int32_t nKeyCode);
		virtual void onMouseUp(int32_t nKeyCode);
		virtual void onMouseWheel(int32_t nDelta);
		virtual void onKeyDown(int32_t nKeyCode);
		virtual void onKeyUp(int32_t nKeyCode);
		virtual void onKeyTyping(wchar_t nCompositionCharacter);
		virtual void onKeyTyped(wchar_t nResultCharacter);
	};

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

	inline uint32_t UIElement::width() const
	{
		return this->nWidth;
	}

	inline uint32_t &UIElement::width()
	{
		return this->nWidth;
	}

	inline uint32_t UIElement::height() const
	{
		return this->nHeight;
	}

	inline uint32_t &UIElement::height()
	{
		return this->nHeight;
	}

	inline bool UIElement::isFocused() const
	{
		return UIElement::pFocusedElement == this;
	}

	inline void UIElement::takeFocuse()
	{
		UIElement::pFocusedElement = this;
	}
}

#endif