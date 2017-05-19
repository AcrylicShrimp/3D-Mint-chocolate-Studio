
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_LAYOUT_UILABEL_H

#define _CLASS_D3MCS_UI_LAYOUT_UILABEL_H

#include "Container.h"
#include "GlyphManager.h"
#include "OpenGLManager.h"
#include "Shader.h"
#include "ShaderInput.h"
#include "Texture.h"
#include "UIElement.h"
#include "VideoBuffer.h"

#include <cstdint>
#include <string>
#include <utility>

namespace D3MCS::UI
{
	class UILabel final : public UIElement, public Render::OpenGLContextHandler
	{
	private:
		Utility::Container<Render::Shader> sShader;
		Utility::Container<Render::ShaderInput> sShaderInput;
		Utility::Container<Render::VideoBuffer> sVertexBuffer;
		Utility::Container<Render::VideoBuffer> sTextureBuffer;
		Font sFont;
		uint32_t nFontSize;
		std::u32string sContent;
		
	public:
		UILabel(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight);
		UILabel(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, const char32_t *pContent);
		UILabel(const UILabel &sSrc) = delete;
		UILabel(UILabel &&sSrc);
		~UILabel();
		
	public:
		UILabel &operator=(const UILabel &sSrc) = delete;
		UILabel &operator=(UILabel &&sSrc);
		
	public:
		inline const std::u32string &content() const;

		void setFont(Font sNewFont, uint32_t nNewFontSize);
		void setContent(const char32_t pContent);
		virtual void render() override;
		virtual void onContextCreated() override;
		virtual void onContextDestroying() override;
	};

	inline const std::u32string & UILabel::content() const
	{
		return this->sContent;
	}
}

#endif