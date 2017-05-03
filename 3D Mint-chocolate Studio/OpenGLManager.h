
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_OPEN_GLMANAGER_H

#define _CLASS_D3MCS_RENDER_OPEN_GLMANAGER_H

#include "ManagerBase.h"
#include "WindowMessageProcedure.h"

#include <string>
#include <unordered_set>
#include <Windows.h>
#include <GL\glew.h>

namespace D3MCS::Render
{
#define INIT_CONTEXT \
if (OpenGLManager::instance().isContextCreated()) \
	this->onContextCreated()

#define FIN_CONTEXT \
if (OpenGLManager::instance().isContextCreated()) \
	this->onContextDestroying();

	class OpenGLContextHandler
	{
	public:
		friend class OpenGLManager;

	private:
		static std::unordered_set<OpenGLContextHandler *> sContextHandlerSet;

	public:
		OpenGLContextHandler();
		OpenGLContextHandler(const OpenGLContextHandler &sSrc) = default;
		OpenGLContextHandler(OpenGLContextHandler &&sSrc) = default;
		virtual ~OpenGLContextHandler();

	public:
		OpenGLContextHandler &operator=(const OpenGLContextHandler &sSrc) = default;
		OpenGLContextHandler &operator=(OpenGLContextHandler &&sSrc) = default;

	public:
		virtual void onContextCreated() = 0;
		virtual void onContextDestroying() = 0;
	};

	class OpenGLManager final : public ManagerBase<OpenGLManager>, public OpenGLContextHandler
	{
	public:
		friend ManagerBase<OpenGLManager>;

	private:
		bool bContextCreated;
		float nMaxAnisotropic;
		std::string sVersion;
		std::string sGLSLVersion;
		std::string sVendorName;
		std::string sRendererName;
		std::unordered_set<std::string> sExtensionSet;

	private:
		OpenGLManager();
		OpenGLManager(const OpenGLManager &sSrc) = delete;
		OpenGLManager(OpenGLManager &&sSrc) = delete;
		~OpenGLManager() = default;

	public:
		OpenGLManager &operator=(const OpenGLManager &sSrc) = delete;
		OpenGLManager &operator=(OpenGLManager &&sSrc) = delete;

	public:
		inline bool isContextCreated() const;
		inline float maxAnisotropic() const;
		inline const std::string &version() const;
		inline const std::string &GLSLversion() const;
		inline const std::string &vendorName() const;
		inline const std::string &rendererName() const;
		inline bool supportExtension(const std::string &sExtensionName) const;

		void notifyContextCreated();
		void notifyContextDestroying();
		virtual void onContextCreated() override;
		virtual void onContextDestroying() override;
	};

	inline bool OpenGLManager::isContextCreated() const
	{
		return this->bContextCreated;
	}

	inline float OpenGLManager::maxAnisotropic() const
	{
		return this->nMaxAnisotropic;
	}

	inline const std::string &OpenGLManager::version() const
	{
		return this->sVersion;
	}

	inline const std::string &OpenGLManager::GLSLversion() const
	{
		return this->sGLSLVersion;
	}

	inline const std::string &OpenGLManager::vendorName() const
	{
		return this->sVendorName;
	}

	inline const std::string &OpenGLManager::rendererName() const
	{
		return this->sRendererName;
	}

	inline bool OpenGLManager::supportExtension(const std::string &sExtensionName) const
	{
		return this->sExtensionSet.find(sExtensionName) != this->sExtensionSet.cend();
	}
}

#endif