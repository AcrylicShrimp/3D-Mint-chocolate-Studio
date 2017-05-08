
/*
	2017.05.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_UITEXTURE_VIEWER_H

#define _CLASS_D3MCS_UI_UITEXTURE_VIEWER_H

#include "Container.h"
#include "OpenGLManager.h"
#include "Shader.h"
#include "ShaderInput.h"
#include "Texture.h"
#include "UIElement.h"
#include "VideoBuffer.h"

#include <cstdint>
#include <fstream>
#include <string>
#include <utility>
#include <GL\glew.h>

namespace D3MCS::UI
{
	class UITextureViewer final : public UIElement, public Render::OpenGLContextHandler
	{
	private:
		const Render::Texture *pTexture;
		Utility::Container<Render::Shader> sShader;
		Utility::Container<Render::ShaderInput> sShaderInput;
		Utility::Container<Render::VideoBuffer> sVertexBuffer;
		Utility::Container<Render::VideoBuffer> sTexCoordBuffer;
		
	public:
		UITextureViewer(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight);
		UITextureViewer(const UITextureViewer &sSrc) = delete;
		UITextureViewer(UITextureViewer &&sSrc);
		~UITextureViewer();
		
	public:
		UITextureViewer &operator=(const UITextureViewer &sSrc) = delete;
		UITextureViewer &operator=(UITextureViewer &&sSrc);
		
	public:
		inline const Render::Texture *texture() const;

		void setTexture(const Render::Texture *pNewTexture);
		virtual void render() override;
		virtual void onContextCreated() override;
		virtual void onContextDestroying() override;
	};

	inline const Render::Texture *UITextureViewer::texture() const
	{
		return this->pTexture;
	}
}

#endif