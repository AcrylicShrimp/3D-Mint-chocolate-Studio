
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MC_UI_INPUT_MANAGER_H

#define _CLASS_D3MC_UI_INPUT_MANAGER_H

#include "Frame.h"
#include "FrameManager.h"
#include "ManagerBase.h"
#include "WindowMessageProcedure.h"

#include <cstdint>
#include <cstring>
#include <Windows.h>
#include <windowsx.h>

namespace D3MCS::UI
{
	class InputManager final : public ManagerBase<InputManager>, WindowMessageProcedure
	{
	public:
		friend ManagerBase<InputManager>;

	private:
		int32_t nMouseX;
		int32_t nMouseY;
		bool vKeyState[256];
		
	private:
		InputManager();
		InputManager(const InputManager &sSrc) = delete;
		InputManager(InputManager &&sSrc) = delete;
		~InputManager() = default;
		
	private:
		InputManager &operator=(const InputManager &sSrc) = delete;
		InputManager &operator=(InputManager &&sSrc) = delete;
		
	public:
		inline int32_t mouseX() const;
		inline int32_t mouseY() const;
		inline bool keyState(uint8_t nIndex) const;

		virtual LRESULT handleWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam) override;
	};

	inline int32_t InputManager::mouseX() const
	{
		return this->nMouseX;
	}

	inline int32_t InputManager::mouseY() const
	{
		return this->nMouseY;
	}

	inline bool InputManager::keyState(uint8_t nIndex) const
	{
		return this->vKeyState[nIndex];
	}
}

#endif