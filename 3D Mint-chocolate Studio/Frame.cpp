
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "Frame.h"

namespace D3MCS::UI
{
	Frame::Frame(Frame &&sSrc) :
		hDeviceContext{sSrc.hDeviceContext},
		hRenderingContext{sSrc.hRenderingContext},
		hWindow{sSrc.hWindow},
		hInstance{sSrc.hInstance},
		sClassName{std::move(sSrc.sClassName)}
	{
		sSrc.hDeviceContext = nullptr;
		sSrc.hRenderingContext = nullptr;
		sSrc.hWindow = nullptr;
		sSrc.hInstance = nullptr;
	}

	Frame::~Frame()
	{
		this->destroyFrame();
	}

	Frame &Frame::operator=(Frame &&sSrc)
	{
		this->hDeviceContext = sSrc.hDeviceContext;
		this->hRenderingContext = sSrc.hRenderingContext;
		this->hWindow = sSrc.hWindow;
		this->hInstance = sSrc.hInstance;
		this->sClassName = std::move(sSrc.sClassName);
		this->bCreated = sSrc.bCreated;
		this->bVisible = sSrc.bVisible;
		this->bFullscr = sSrc.bFullscr;

		sSrc.hDeviceContext = nullptr;
		sSrc.hRenderingContext = nullptr;
		sSrc.hWindow = nullptr;
		sSrc.hInstance = nullptr;

		return *this;
	}

	bool Frame::createFrame(const FrameAttribute &sFrameAttribute)
	{
		if (this->bCreated)
			return false;

		WNDCLASSW sClass
		{
			CS_OWNDC,															//style
			sFrameAttribute.fWndProc,											//lpfnWndProc
			0,																	//cbClsExtra
			0,																	//cbWndExtra
			this->hInstance = GetModuleHandleW(nullptr),						//hInstance
			sFrameAttribute.hIcon,												//hIcon
			LoadCursorW(nullptr, IDC_ARROW),									//hCursor
			nullptr,															//hbrBackground
			nullptr,															//lpszMenuName
			(this->sClassName = sFrameAttribute.sClassName).c_str()				//lpszClassName
		};

		if (!RegisterClassW(&sClass))
		{
			this->destroyFrame();
			return false;
		}

		uint32_t nStyle;
		uint32_t nExStyle;
		RECT sClientRect{};

		if (this->bFullscr = sFrameAttribute.bFullscreen)
		{
			nStyle = WS_POPUP;
			nExStyle = WS_EX_APPWINDOW;

			GetWindowRect(GetDesktopWindow(), &sClientRect);

			DEVMODEW sDevMode
			{
				//Empty.
			};

			sDevMode.dmSize = sizeof(DEVMODEW);
			sDevMode.dmPelsWidth = sClientRect.right;
			sDevMode.dmPelsHeight = sClientRect.bottom;
			sDevMode.dmBitsPerPel = sFrameAttribute.nColorBit;
			sDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

			if (ChangeDisplaySettingsW(&sDevMode, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
				return this->bFullscr = false;
		}
		else
		{
			nStyle = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
			nExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

			sClientRect.right = static_cast <int32_t>(sFrameAttribute.nWidth);
			sClientRect.bottom = static_cast <int32_t>(sFrameAttribute.nHeight);
		}

		AdjustWindowRectEx(&sClientRect, nStyle, false, nExStyle);

		sClientRect.right -= sClientRect.left;
		sClientRect.bottom -= sClientRect.top;

		if (!(this->hWindow = CreateWindowExW(
			nExStyle,
			sFrameAttribute.sClassName.c_str(),
			sFrameAttribute.sTitleText.c_str(),
			nStyle,
			sFrameAttribute.nX,
			sFrameAttribute.nY,
			sClientRect.right,
			sClientRect.bottom,
			nullptr,
			nullptr,
			this->hInstance,
			nullptr)))
		{
			this->destroyFrame();
			return false;
		}

		PIXELFORMATDESCRIPTOR sPixelFormatDesc
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, static_cast <uint8_t>(sFrameAttribute.nColorBit),
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, static_cast <uint8_t>(sFrameAttribute.nDepthBit), 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
		};

		if (!(this->hDeviceContext = GetDC(this->hWindow)))
		{
			this->destroyFrame();
			return false;
		}

		int32_t nPixelFormat = ChoosePixelFormat(this->hDeviceContext, &sPixelFormatDesc);
		if (!nPixelFormat)
		{
			this->destroyFrame();
			return false;
		}

		if (!SetPixelFormat(this->hDeviceContext, nPixelFormat, &sPixelFormatDesc))
		{
			this->destroyFrame();
			return false;
		}

		if (!(this->hRenderingContext = wglCreateContext(this->hDeviceContext)))
		{
			this->destroyFrame();
			return false;
		}

		SetForegroundWindow(this->hWindow);
		SetFocus(this->hWindow);

		this->bCreated = true;

		return true;
	}

	void Frame::destroyFrame()
	{
		this->bCreated =
			this->bVisible = false;

		if (this->bFullscr)
		{
			ChangeDisplaySettingsW(nullptr, 0ul);
			this->bFullscr = false;
		}

		if (this->hRenderingContext)
			wglDeleteContext(this->hRenderingContext);

		if (this->hWindow)
		{
			if (this->hDeviceContext)
				ReleaseDC(this->hWindow, this->hDeviceContext);

			DestroyWindow(this->hWindow);
		}

		UnregisterClassW(this->sClassName.c_str(), this->hInstance);

		this->hDeviceContext = nullptr;
		this->hRenderingContext = nullptr;
		this->hWindow = nullptr;
		this->hInstance = nullptr;
	}
}