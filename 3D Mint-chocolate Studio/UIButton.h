
/*
	2017.04.24
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_UIBUTTON_H

#define _CLASS_D3MCS_UI_UIBUTTON_H

#include "UIElement.h"

#include <cstdint>
#include <string>
#include <utility>
#include <Windows.h>
#include <GL\glew.h>

namespace D3MCS::UI
{
	class UIButton : public UIElement
	{
	private:
		bool bIsEntered;
		bool bIsPressed;
		
	public:
		UIButton(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, float nFontSize, const std::wstring &sNewLabel);
		UIButton(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, float nFontSize, std::wstring &&sNewLabel);
		UIButton(const UIButton &sSrc) = delete;
		UIButton(UIButton &&sSrc);
		~UIButton();
		
	public:
		UIButton &operator=(const UIButton &sSrc) = delete;
		UIButton &operator=(UIButton &&sSrc);
		
	public:
		inline bool isEntered() const;
		inline bool isPressed() const;
		inline const std::wstring &label() const;
		inline std::wstring &label();

		virtual void render() override;
	};

	inline bool UIButton::isEntered() const
	{
		return this->bIsEntered;
	}

	inline bool UIButton::isPressed() const
	{
		return this->bIsPressed;
	}
}

#endif