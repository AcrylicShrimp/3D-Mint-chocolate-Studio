
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_TEXTURE_H

#define _CLASS_D3MCS_RENDER_TEXTURE_H

#include "OpenGLManager.h"

#include <GL\glew.h>

namespace D3MCS::Render
{
	enum class TexelFilter : GLint
	{
		Linear = GL_LINEAR,
		Nearest = GL_NEAREST
	};

	enum class MipmapFilter : GLint
	{
		None,
		Linear,
		Nearest
	};

	enum class WrappingMode : GLint
	{
		Repeat = GL_REPEAT,
		RepeatMirrored = GL_MIRRORED_REPEAT,
		ClampBorder = GL_CLAMP_TO_BORDER,
		ClampEdge = GL_CLAMP_TO_EDGE,
		ClampEdgeMirrored = GL_MIRROR_CLAMP_TO_EDGE
	};

	enum class ExternalFormat : GLenum
	{
		R = GL_RED,
		RG = GL_RG,
		RGB = GL_RGB,
		BGR = GL_BGR,
		RGBA = GL_RGBA,
		BGRA = GL_BGRA,

		IntegerR = GL_RED_INTEGER,
		IntegerRG = GL_RG_INTEGER,
		IntegerRGB = GL_RGB_INTEGER,
		IntegerBGR = GL_BGR_INTEGER,
		IntegerRGBA = GL_RGBA_INTEGER,
		IntegerBGRA = GL_BGRA_INTEGER,

		Depth = GL_DEPTH_COMPONENT,
		DepthStencil = GL_DEPTH_STENCIL,
		StencilIndex = GL_STENCIL_INDEX
	};

	enum class InternalFormat : GLint
	{
		Depth = GL_DEPTH_COMPONENT,
		DepthStencil = GL_DEPTH_STENCIL,

		R = GL_RED,
		R8 = GL_R8,
		R8I = GL_R8I,
		R8UI = GL_R8UI,
		SignedNormalizedR8 = GL_R8_SNORM,
		R16 = GL_R16,
		R16I = GL_R16I,
		R16UI = GL_R16UI,
		R16F = GL_R16F,
		SignedNormalizedR16 = GL_R16_SNORM,
		R32F = GL_R32F,
		R32I = GL_R32I,
		R32UI = GL_R32UI,

		RG = GL_RG,
		RG8 = GL_RG8,
		RG8I = GL_RG8I,
		RG8UI = GL_RG8UI,
		SignedNormalizedRG8 = GL_RG8_SNORM,
		RG16 = GL_RG16,
		RG16I = GL_RG16I,
		RG16UI = GL_RG16UI,
		RG16F = GL_RG16F,
		SignedNormalizedRG16 = GL_RG16_SNORM,
		RG32F = GL_RG32F,
		RG32I = GL_RG32I,
		RG32UI = GL_RG32UI,

		RGB = GL_RGB,
		R3G3B2 = GL_R3_G3_B2,
		RGB4 = GL_RGB4,
		RGB5 = GL_RGB5,
		RGB8 = GL_RGB8,
		RGB8I = GL_RGB8I,
		RGB8UI = GL_RGB8UI,
		SRGB8 = GL_SRGB8,
		SRGBA8 = GL_SRGB8_ALPHA8,
		SignedNormalizedRGB8 = GL_RGB8_SNORM,
		RGB10 = GL_RGB10,
		RGB12 = GL_RGB12,
		RGB16 = GL_RGB16,
		RGB16I = GL_RGB16I,
		RGB16UI = GL_RGB16UI,
		RGB16F = GL_RGB16F,
		SignedNormalizedRGB16 = GL_RGB16_SNORM,
		RGB32I = GL_RGB32I,
		RGB32UI = GL_RGB32UI,
		RGB32F = GL_RGB32F,

		RGBA = GL_RGBA,
		RGBA2 = GL_RGBA2,
		RGBA4 = GL_RGBA4,
		RGB5A1 = GL_RGB5_A1,
		RGBA8 = GL_RGBA8,
		RGBA8I = GL_RGBA8I,
		RGBA8UI = GL_RGBA8UI,
		SignedNormalizedRGBA8 = GL_RGBA8_SNORM,
		RGB10A2 = GL_RGB10_A2,
		RGB10A2UI = GL_RGB10_A2UI,
		RGBA12 = GL_RGBA12,
		RGBA16 = GL_RGBA16,
		RGBA16I = GL_RGBA16I,
		RGBA16UI = GL_RGBA16UI,
		RGBA16F = GL_RGBA16F,
		RGBA32I = GL_RGBA32I,
		RGBA32UI = GL_RGBA32UI,
		RGBA32F = GL_RGBA32F,
		RG11B10F = GL_R11F_G11F_B10F,
		RGB9E5 = GL_RGB9_E5,

		CompressedR = GL_COMPRESSED_RED,
		CompressedRG = GL_COMPRESSED_RG,
		CompressedRGB = GL_COMPRESSED_RGB,
		CompressedRGBA = GL_COMPRESSED_RGBA,
		CompressedSRGB = GL_COMPRESSED_SRGB,
		CompressedSRGBA = GL_COMPRESSED_SRGB_ALPHA,
		RGTC1CompressedR = GL_COMPRESSED_RED_RGTC1,
		SignedRGTC1CompressedR = GL_COMPRESSED_SIGNED_RED_RGTC1,
		RGTC2CompressedRG = GL_COMPRESSED_RG_RGTC2,
		SignedRGTC2CompressedRG = GL_COMPRESSED_SIGNED_RG_RGTC2,
		BPTCCompressedRGBF = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
		SignedBPTCCompressedRGBF = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
		BPTCCompressedRGBA = GL_COMPRESSED_RGBA_BPTC_UNORM,
		BPTCCompressedSRGBA = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	};

	enum class TexelType : GLenum
	{
		Char = GL_BYTE,
		Byte = GL_UNSIGNED_BYTE,
		Byte332 = GL_UNSIGNED_BYTE_3_3_2,
		ReversedByte233 = GL_UNSIGNED_BYTE_2_3_3_REV,
		Short = GL_SHORT,
		UnsignedShort = GL_UNSIGNED_SHORT,
		UnsignedShort565 = GL_UNSIGNED_SHORT_5_6_5,
		ReversedUnsignedShort565 = GL_UNSIGNED_SHORT_5_6_5_REV,
		UnsignedShort4444 = GL_UNSIGNED_SHORT_4_4_4_4,
		ReversedUnsignedShort4444 = GL_UNSIGNED_SHORT_4_4_4_4_REV,
		UnsignedShort5551 = GL_UNSIGNED_SHORT_5_5_5_1,
		ReversedUnsignedShort1555 = GL_UNSIGNED_SHORT_1_5_5_5_REV,
		Int = GL_INT,
		UnsignedInt = GL_UNSIGNED_INT,
		UnsignedInt8888 = GL_UNSIGNED_INT_8_8_8_8,
		ReversedUnsignedInt8888 = GL_UNSIGNED_INT_8_8_8_8_REV,
		UnsignedInt1010102 = GL_UNSIGNED_INT_10_10_10_2,
		ReversedUnsignedInt2101010 = GL_UNSIGNED_INT_2_10_10_10_REV,
		Float = GL_FLOAT,
	};

	class Texture final
	{
	public:
		static constexpr GLuint ZeroID{0u};
		static constexpr GLuint64 ZeroHandle{0ui64};

	private:
		GLuint nTextureID;
		GLuint64 nTextureHandle;

	public:
		Texture(GLsizei nWidth, GLsizei nHeight, InternalFormat eInternalFormat, GLint nMaxLevel, TexelFilter eTexelMagFilter, TexelFilter eTexelMinFilter, MipmapFilter eMipmapMinFilter, WrappingMode eSWrappingMode, WrappingMode eTWrappingMode, float nAnisotropicMode);
		Texture(const Texture &sSrc) = delete;
		Texture(Texture &&sSrc);
		~Texture();

	public:
		Texture &operator=(const Texture &sSrc) = delete;
		Texture &operator=(Texture &&sSrc);

	public:
		inline operator GLuint() const;

	public:
		inline GLuint textureID() const;
		inline GLuint64 textureHandle() const;
		inline void makeActive() const;
		inline void makeInactive() const;
		inline void updateTexel(GLint nX, GLint nY, GLsizei nWidth, GLsizei nHeight, ExternalFormat eExternalFormat, TexelType eTexelType, const GLvoid *pTexel) const;
		inline void updateMipmap() const;
	};

	inline Texture::operator GLuint() const
	{
		return this->nTextureID;
	}

	inline GLuint Texture::textureID() const
	{
		return this->nTextureID;
	}

	inline GLuint64 Texture::textureHandle() const
	{
		return this->nTextureHandle;
	}

	inline void Texture::makeActive() const
	{
		glMakeTextureHandleResidentARB(this->nTextureHandle);
	}

	inline void Texture::makeInactive() const
	{
		glMakeTextureHandleNonResidentARB(this->nTextureHandle);
	}

	inline void Texture::updateTexel(GLint nX, GLint nY, GLsizei nWidth, GLsizei nHeight, ExternalFormat eExternalFormat, TexelType eTexelType, const GLvoid *pTexel) const
	{
		glTextureSubImage2D(this->nTextureID, 0, nX, nY, nWidth, nHeight, static_cast<GLenum>(eExternalFormat), static_cast<GLenum>(eTexelType), pTexel);
	}

	inline void Texture::updateMipmap() const
	{
		glGenerateTextureMipmap(this->nTextureID);
	}
}

#endif