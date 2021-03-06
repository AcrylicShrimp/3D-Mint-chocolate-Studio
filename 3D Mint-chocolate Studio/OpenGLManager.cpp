
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#include "OpenGLManager.h"

namespace D3MCS::Render
{
	std::unordered_set<OpenGLContextHandler *> OpenGLContextHandler::sContextHandlerSet;

	OpenGLContextHandler::OpenGLContextHandler()
	{
		this->sContextHandlerSet.emplace(this);
	}

	OpenGLContextHandler::~OpenGLContextHandler()
	{
		this->sContextHandlerSet.erase(this);
	}

	OpenGLManager::OpenGLManager() :
		bContextCreated{false},
		nMaxAnisotropic{1.f}
	{
		//Empty.
	}

	void OpenGLManager::notifyContextCreated()
	{
		for (auto pContextHandler : OpenGLContextHandler::sContextHandlerSet)
			pContextHandler->onContextCreated();
	}

	void OpenGLManager::notifyContextDestroying()
	{
		for (auto pContextHandler : OpenGLContextHandler::sContextHandlerSet)
			pContextHandler->onContextDestroying();
	}

	void OpenGLManager::onContextCreated()
	{
		//Initialize OpenGL Extention.
		glewInit();

		this->bContextCreated = true;

		//Get OpenGL-related values.
		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &this->nMaxAnisotropic);
		this->sVersion = reinterpret_cast<const char *>(glGetString(GL_VERSION));
		this->sGLSLVersion = reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));
		this->sVendorName = reinterpret_cast<const char *>(glGetString(GL_VENDOR));
		this->sRendererName = reinterpret_cast<const char *>(glGetString(GL_RENDERER));

		//Get all of supported extension.
		std::string sExtension{reinterpret_cast<const char *>(glGetString(GL_EXTENSIONS))};
		std::string sBuffer;
		sBuffer.reserve(64u);

		for (auto iIndex{sExtension.cbegin()}, iEnd{sExtension.cend()}; ; ++iIndex)
		{
			auto iTemp{iIndex};
			while (iTemp != iEnd && *iTemp != ' ')
			{
				sBuffer += *iTemp;
				++iTemp;
			}

			this->sExtensionSet.emplace(sBuffer);

			if (iTemp == iEnd)
				break;

			iIndex = iTemp;
			sBuffer.clear();
		}

		//Enable/Disable OpenGL features.
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);

		glPointSize(10.f);

		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLManager::onContextDestroying()
	{
		this->bContextCreated = false;
	}
}