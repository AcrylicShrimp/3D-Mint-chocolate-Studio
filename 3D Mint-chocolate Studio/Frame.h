
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_FRAME_H

#define _CLASS_D3MCS_UI_FRAME_H

#include <cstdint>
#include <string>
#include <utility>
#include <Windows.h>

namespace D3MCS::UI
{
	struct FrameAttribute
	{
	public:
		int32_t nX;
		int32_t nY;
		uint32_t nWidth;
		uint32_t nHeight;
		uint32_t nColorBit;
		uint32_t nDepthBit;
		bool bFullscreen;
		std::wstring sClassName;
		std::wstring sTitleText;
		HICON hIcon;
		WNDPROC fWndProc;
	};

	class Frame final
	{
	private:
		HDC hDeviceContext{nullptr};
		HGLRC hRenderingContext{nullptr};
		HWND hWindow{nullptr};
		HINSTANCE hInstance{nullptr};
		std::wstring sClassName;
		bool bCreated{false};
		bool bVisible{false};
		bool bFullscr{false};

	public:
		Frame() = default;
		Frame(const Frame &sSrc) = delete;
		Frame(Frame &&sSrc);
		~Frame();

	public:
		Frame &operator=(const Frame &sSrc) = delete;
		Frame &operator=(Frame &&sSrc);

	public:
		inline HDC deviceContext() const;
		inline HGLRC renderingContext() const;
		inline HWND windowHandle() const;
		inline HINSTANCE instanceHandle() const;
		inline bool isCreated() const;
		inline bool isVisible() const;
		inline bool isFullscr() const;
		inline bool linkCurrentThread() const;
		inline void unlinkCurrentThread() const;
		inline void setVisible(bool bNewVisible);
		inline void setFileDraggable(bool bNewDraggable);

		bool createFrame(const FrameAttribute &sFrameAttribute);
		void destroyFrame();
	};

	inline HDC Frame::deviceContext() const
	{
		return this->hDeviceContext;
	}

	inline HGLRC Frame::renderingContext() const
	{
		return this->hRenderingContext;
	}

	inline HWND Frame::windowHandle() const
	{
		return this->hWindow;
	}

	inline HINSTANCE Frame::instanceHandle() const
	{
		return this->hInstance;
	}

	inline bool Frame::isCreated() const
	{
		return this->bCreated;
	}

	inline bool Frame::isVisible() const
	{
		return this->bVisible;
	}

	inline bool Frame::isFullscr() const
	{
		return this->bFullscr;
	}

	inline bool Frame::linkCurrentThread() const
	{
		return wglMakeCurrent(this->hDeviceContext, this->hRenderingContext) != 0;
	}

	inline void Frame::unlinkCurrentThread() const
	{
		wglMakeCurrent(nullptr, nullptr);
	}

	inline void Frame::setVisible(bool bNewVisible)
	{
		ShowWindow(this->hWindow, (this->bVisible = bNewVisible) ? SW_SHOW : SW_HIDE);
	}

	inline void Frame::setFileDraggable(bool bNewDraggable)
	{
		DragAcceptFiles(this->hWindow, bNewDraggable);
	}
}

#endif