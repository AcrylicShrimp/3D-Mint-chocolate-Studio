
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "MintChocolateStudio.h"

namespace D3MCS
{
	void MintChocolateStudio::initialize(HINSTANCE hInstance)
	{
		//Initialize all manager;
		UI::FrameManager::initialize();
		UI::InputManager::initialize();
		Render::OpenGLManager::initialize();
		UI::RenderManager::initialize();
		UI::UIManager::initialize();
		UI::GlyphManager::initialize();

		UI::UIManager::instance().addUIElementByName<UI::UITextureViewer>(L"test", 0, 0, 0u, 0u);

		MintChocolateStudio::createFrame(hInstance);

		if (!MintChocolateStudio::checkVersion())
		{
			wchar_t vBuffer[4096];
			swprintf_s(vBuffer, L"Your video card is not support required OpenGL version.\n\nOpenGL version : %S", Render::OpenGLManager::instance().version().c_str());

			MessageBox(nullptr, vBuffer, L"Unsupported OpenGL version detected", MB_OK | MB_ICONERROR);
			PostQuitMessage(-1);

			return;
		}

		if (!MintChocolateStudio::checkExtensions())
		{
			MessageBox(nullptr, L"Your video card is not support some required extensions.", L"Unsupported extensions detected", MB_OK | MB_ICONERROR);
			PostQuitMessage(-1);

			return;
		}

		auto &sGlyphManager{UI::GlyphManager::instance()};
		auto sFont{sGlyphManager.loadFont(L"Res/koverwatch.ttf")};

		sGlyphManager.bakeString(sFont, 1024u, U"ÄÐ¹ä¿À");

		auto &sTexture{sGlyphManager.findGlyphState(sFont, 1024u)->sTextureList.back()};
		UI::UIManager::instance().findUIElementByName<UI::UITextureViewer>(L"test")->setTexture(&sTexture);
		sTexture.makeActive();

		UI::FrameManager::instance().frame().setVisible(true);
	}

	bool MintChocolateStudio::checkVersion()
	{
		static constexpr auto nRequireMajor = '4';
		static constexpr auto nRequireMinor = '5';

		const auto &sVersion = Render::OpenGLManager::instance().version();

		if (sVersion.length() < 3u)
			return false;

		return sVersion[0] < nRequireMajor ? false : sVersion[0] == nRequireMajor ? sVersion[2] >= nRequireMinor : true;
	}

	bool MintChocolateStudio::checkExtensions()
	{
		using namespace std::literals;
		auto &sOpenGLManager{Render::OpenGLManager::instance()};

		return sOpenGLManager.supportExtension("GL_ARB_direct_state_access"s) &&
			sOpenGLManager.supportExtension("GL_ARB_bindless_texture"s) &&
			sOpenGLManager.supportExtension("GL_EXT_texture_filter_anisotropic"s);
	}

	void MintChocolateStudio::createFrame(HINSTANCE hInstance)
	{
		RECT sWorkArea;
		SystemParametersInfo(SPI_GETWORKAREA, 0u, &sWorkArea, 0u);
		UI::FrameManager::instance().createFrame((sWorkArea.right - sWorkArea.left) / 4u, (sWorkArea.bottom - sWorkArea.top) / 4u, (sWorkArea.right - sWorkArea.left) / 2u, (sWorkArea.bottom - sWorkArea.top) / 2u, 32u, 32u, false, L"3D Mint-chocolate Studio", L"3D Mint-chocolate Studio", LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)));

		UI::FrameManager::instance().frame().linkCurrentThread();
		Render::OpenGLManager::instance().notifyContextCreated();
	}

	void MintChocolateStudio::destroyFrame()
	{
		UI::FrameManager::instance().frame().setVisible(false);
		Render::OpenGLManager::instance().notifyContextDestroying();
		UI::FrameManager::instance().frame().unlinkCurrentThread();

		UI::FrameManager::instance().destroyFrame();
	}

	void MintChocolateStudio::finalize()
	{
		MintChocolateStudio::destroyFrame();

		UI::GlyphManager::finalize();
		UI::UIManager::finalize();
		UI::RenderManager::finalize();
		Render::OpenGLManager::finalize();
		UI::InputManager::finalize();
		UI::FrameManager::finalize();
	}
}