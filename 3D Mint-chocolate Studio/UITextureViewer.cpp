
/*
	2017.05.08
	Created by AcrylicShrimp.
*/

#include "UITextureViewer.h"

namespace D3MCS::UI
{
	UITextureViewer::UITextureViewer(int32_t nNewX, int32_t nNewY, uint32_t nNewWidth, uint32_t nNewHeight) :
		UIElement{nNewX, nNewY, nNewWidth, nNewHeight},
		pTexture{nullptr}
	{
		INIT_CONTEXT;
	}
	
	UITextureViewer::UITextureViewer(UITextureViewer &&sSrc) :
		UIElement{std::move(sSrc)},
		pTexture{sSrc.pTexture},
		sShader{std::move(sSrc.sShader)},
		sShaderInput{std::move(sSrc.sShaderInput)},
		sVertexBuffer{std::move(sSrc.sVertexBuffer)},
		sTexCoordBuffer{std::move(sSrc.sTexCoordBuffer)}
	{
		//Empty.
	}
	
	UITextureViewer::~UITextureViewer()
	{
		FIN_CONTEXT;
	}
	
	UITextureViewer &UITextureViewer::operator=(UITextureViewer &&sSrc)
	{
		if(&sSrc == this)
			return *this;

		UIElement::operator=(std::move(sSrc));
		this->~UITextureViewer();

		this->pTexture = sSrc.pTexture;
		this->sShader = std::move(sSrc.sShader);
		this->sShaderInput = std::move(sSrc.sShaderInput);
		this->sVertexBuffer = std::move(sSrc.sVertexBuffer);
		this->sTexCoordBuffer = std::move(sSrc.sTexCoordBuffer);
		
		return *this;
	}

	void UITextureViewer::setTexture(const Render::Texture *pNewTexture)
	{
		if ((this->pTexture = pNewTexture) && this->sShader.loaded())
			this->sShader.containedLoad().setUniform("uniform_texture", this->pTexture->textureHandle());
	}

	void UITextureViewer::render()
	{
		this->sShader.containedLoad().useShader();
		this->sShaderInput.containedLoad().bind();

		glDrawArrays(GL_TRIANGLES, 0, 6u);
	}

	void UITextureViewer::onContextCreated()
	{
		std::ifstream sVertexInput{L"Res/Shader/uitextureviewer.vs", std::ifstream::binary | std::ifstream::in};
		std::string sVertexSource{std::ifstream::_Iter{sVertexInput}, std::ifstream::_Iter{}};
		
		std::ifstream sFragmentInput{L"Res/Shader/uitextureviewer.fs", std::ifstream::binary | std::ifstream::in};
		std::string sFragmentSource{std::ifstream::_Iter{sFragmentInput}, std::ifstream::_Iter{}};

		this->sShader.init();
		this->sShader.containedLoad().attachShader(Render::ShaderType::Vertex, sVertexSource.c_str());
		this->sShader.containedLoad().attachShader(Render::ShaderType::Fragment, sFragmentSource.c_str());
		this->sShader.containedLoad().linkShader();

		this->sShaderInput.init();
		this->sShaderInput.containedLoad().enableIndex(0u);
		this->sShaderInput.containedLoad().specifyFormatAsFloat(0u, 4, Render::FloatElementType::Float, false, 0u);
		this->sShaderInput.containedLoad().enableIndex(1u);
		this->sShaderInput.containedLoad().specifyFormatAsFloat(1u, 2, Render::FloatElementType::Float, false, 0u);

		float vVertexData[]
		{
			-1.0f, 1.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 0.0f, 1.0f,

			1.0f, 1.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f
		};

		this->sVertexBuffer.init();
		this->sVertexBuffer.containedLoad().specifyData(Render::BufferUsage::StaticDraw, sizeof(vVertexData), vVertexData);

		float vTexCoordData[]
		{
			0.0f, 1.0f,
			0.0f, 0.0f,
			1.0f, 1.0f,

			1.0f, 1.0f,
			0.0f, 0.0f,
			1.0f, 0.0f
		};

		this->sTexCoordBuffer.init();
		this->sTexCoordBuffer.containedLoad().specifyData(Render::BufferUsage::StaticDraw, sizeof(vTexCoordData), vTexCoordData);

		this->sShaderInput.containedLoad().bindIndex(0u, 0u);
		this->sShaderInput.containedLoad().bindIndex(1u, 1u);
		this->sShaderInput.containedLoad().attachBuffer(0u, 0u, this->sVertexBuffer.containedLoad(), 0, sizeof(float) * 4);
		this->sShaderInput.containedLoad().attachBuffer(1u, 0u, this->sTexCoordBuffer.containedLoad(), 0, sizeof(float) * 2);
		
		if (this->pTexture)
			this->sShader.containedLoad().setUniform("uniform_texture", this->pTexture->textureHandle());
	}

	void UITextureViewer::onContextDestroying()
	{
		this->sShader.fin();
		this->sShaderInput.fin();
		this->sVertexBuffer.fin();
		this->sTexCoordBuffer.fin();
	}
}