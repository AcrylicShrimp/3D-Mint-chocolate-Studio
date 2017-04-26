
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#include "Texture.h"

namespace D3MCS::Render
{
	Texture::Texture()
	{
		glGenTextures(1u, &this->nTextureID);
	}

	Texture::Texture(Texture &&sSrc) :
		nTextureID{sSrc.nTextureID}
	{
		sSrc.nTextureID = Texture::ZeroID;
	}

	Texture::~Texture()
	{
		if (this->nTextureID)
			glDeleteTextures(1u, &this->nTextureID);
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