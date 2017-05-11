
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#include "Texture.h"

namespace D3MCS::Render
{
	Texture::Texture(GLsizei nWidth, GLsizei nHeight, InternalFormat eInternalFormat, GLint nMaxLevel, TexelFilter eTexelMagFilter, TexelFilter eTexelMinFilter, MipmapFilter eMipmapMinFilter, WrappingMode eSWrappingMode, WrappingMode eTWrappingMode, float nAnisotropicMode)
	{
		glCreateTextures(GL_TEXTURE_2D, 1u, &this->nTextureID);

		glTextureParameteri(this->nTextureID, GL_TEXTURE_MAX_LEVEL, nMaxLevel);
		glTextureParameteri(this->nTextureID, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(eTexelMagFilter));
		glTextureParameteri(this->nTextureID, GL_TEXTURE_WRAP_S, static_cast<GLint>(eSWrappingMode));
		glTextureParameteri(this->nTextureID, GL_TEXTURE_WRAP_T, static_cast<GLint>(eTWrappingMode));
		glTextureParameterf(this->nTextureID, GL_TEXTURE_MAX_ANISOTROPY_EXT, fmin(nAnisotropicMode, OpenGLManager::instance().maxAnisotropic()));

		switch (eMipmapMinFilter)
		{
		case MipmapFilter::None:
			glTextureParameteri(this->nTextureID, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(eTexelMinFilter));
			break;
		case MipmapFilter::Linear:
			glTextureParameteri(this->nTextureID, GL_TEXTURE_MIN_FILTER, eTexelMinFilter == TexelFilter::Linear ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_LINEAR);
			break;
		case MipmapFilter::Nearest:
			glTextureParameteri(this->nTextureID, GL_TEXTURE_MIN_FILTER, eTexelMinFilter == TexelFilter::Linear ? GL_LINEAR_MIPMAP_NEAREST : GL_NEAREST_MIPMAP_NEAREST);
			break;
		default:
			break;
		}

		glTextureStorage2D(this->nTextureID, nMaxLevel, static_cast<GLenum>(eInternalFormat), nWidth, nHeight);
		this->nTextureHandle = glGetTextureHandleARB(this->nTextureID);
	}

	Texture::Texture(Texture &&sSrc) :
		nTextureID{sSrc.nTextureID},
		nTextureHandle{sSrc.nTextureHandle}
	{
		sSrc.nTextureID = Texture::ZeroID;
		sSrc.nTextureHandle = Texture::ZeroHandle;
	}

	Texture::~Texture()
	{
		if (this->nTextureID != Texture::ZeroID)
			glDeleteTextures(1u, &this->nTextureID);
		
		this->nTextureID = Texture::ZeroID;
		this->nTextureHandle = Texture::ZeroHandle;
	}

	Texture &Texture::operator=(Texture &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~Texture();

		this->nTextureID = sSrc.nTextureID;
		sSrc.nTextureID = Texture::ZeroID;

		return *this;
	}
}