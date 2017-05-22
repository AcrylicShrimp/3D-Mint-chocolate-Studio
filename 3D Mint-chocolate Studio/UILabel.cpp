
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#include "UILabel.h"

namespace D3MCS::UI
{
	UILabel::UILabel(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight) :
		UIElement{nNewX, nNewY, nNewWidth, nNewHeight},
		sFont{GlyphManager::NullFont},
		nFontSize{0u}
	{
		INIT_CONTEXT;
	}

	UILabel::UILabel(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight, const char32_t *pContent) :
		UIElement{nNewX, nNewY, nNewWidth, nNewHeight},
		sFont{GlyphManager::NullFont},
		nFontSize{0u},
		sContent{pContent}
	{
		INIT_CONTEXT;
	}

	UILabel::UILabel(UILabel &&sSrc) :
		UIElement{std::move(sSrc)},
		sShader{std::move(sSrc.sShader)},
		sShaderInput{std::move(sSrc.sShaderInput)},
		sVertexBuffer{std::move(sSrc.sVertexBuffer)},
		sTextureBuffer{std::move(sSrc.sTextureBuffer)},
		sFont{sSrc.sFont},
		nFontSize{sSrc.nFontSize},
		sContent{std::move(sSrc.sContent)}
	{
		//Empty.
	}

	UILabel::~UILabel()
	{
		FIN_CONTEXT;
	}

	UILabel &UILabel::operator=(UILabel &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->UIElement::operator=(std::move(sSrc));

		this->sShader = std::move(sSrc.sShader);
		this->sShaderInput = std::move(sSrc.sShaderInput);
		this->sVertexBuffer = std::move(sSrc.sVertexBuffer);
		this->sTextureBuffer = std::move(sSrc.sTextureBuffer);
		this->sFont = sSrc.sFont;
		this->nFontSize = sSrc.nFontSize;
		this->sContent = std::move(sSrc.sContent);

		return *this;
	}

	void UILabel::setFont(Font sNewFont, uint32_t nNewFontSize)
	{
		this->sFont = sNewFont;
		this->nFontSize = nNewFontSize;

		//TODO : Decrease the reference count of the last font and size here.

		GlyphManager::instance().bakeString(this->sFont, this->nFontSize, this->sContent.c_str());
	}

	void UILabel::setContent(const char32_t pContent)
	{
		this->sContent = pContent;

		//TODO : Decrease the reference count of the last font and size here.

		GlyphManager::instance().bakeString(this->sFont, this->nFontSize, this->sContent.c_str());

		if (!Render::OpenGLManager::instance().isContextCreated())
			return;

		auto pGlyphState = GlyphManager::instance().findGlyphState(this->sFont, this->nFontSize);

		if (!pGlyphState)
			return;

		float nCurrentX{static_cast<float>(this->nX)};
		float nCurrentY{static_cast<float>(this->nY)};
		auto iEnd{pGlyphState->sGlyphRenderStateLookup.cend()};

		for (auto nCharacter : this->sContent)
		{
			auto iIndex{pGlyphState->sGlyphRenderStateLookup.find(nCharacter)};

			if (iIndex == iEnd)
				continue;
		}
	}

	void UILabel::render()
	{

	}

	void UILabel::onContextCreated()
	{
		this->sShader.init();


		this->sShaderInput.init();
		this->sVertexBuffer.init();
		this->sTextureBuffer.init();
	}

	void UILabel::onContextDestroying()
	{
		this->sShader.fin();
		this->sShaderInput.fin();
		this->sVertexBuffer.fin();
		this->sTextureBuffer.fin();
	}
}