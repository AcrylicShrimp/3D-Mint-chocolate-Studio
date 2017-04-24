
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_UIELEMENT_H

#define _CLASS_D3MCS_UI_UIELEMENT_H

#include <cstdint>
#include <utility>

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
		UIElement(UIElement &&sSrc);
		virtual ~UIElement();
		
	public:
		UIElement &operator=(const UIElement &sSrc);
		UIElement &operator=(UIElement &&sSrc);
		
	public:
		inline int32_t x() const;
		inline void x(int32_t nNewX);
		inline int32_t y() const;
		inline void y(int32_t nNewY);
		inline uint32_t width() const;
		inline void width(uint32_t nNewWidth);
		inline uint32_t height() const;
		inline void height(uint32_t nNewHeight);
		inline bool isFocused() const;
		inline void takeFocuse();

		virtual void render() = 0;
	};

	inline int32_t UIElement::x() const
	{
		return this->nX;
	}

	inline void UIElement::x(int32_t nNewX)
	{
		this->nX = nNewX;
	}

	inline int32_t UIElement::y() const
	{
		return this->nY;
	}

	inline void UIElement::y(int32_t nNewY)
	{
		this->nY = nNewY;
	}

	inline uint32_t UIElement::width() const
	{
		return this->nWidth;
	}

	inline void UIElement::width(uint32_t nNewWidth)
	{
		this->nWidth = nNewWidth;
	}

	inline uint32_t UIElement::height() const
	{
		return this->nHeight;
	}

	inline void UIElement::height(uint32_t nNewHeight)
	{
		this->nHeight = nNewHeight;
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