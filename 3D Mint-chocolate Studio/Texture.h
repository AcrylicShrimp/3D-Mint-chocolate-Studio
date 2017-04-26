
/*
	2017.04.26
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_TEXTURE_H

#define _CLASS_D3MCS_RENDER_TEXTURE_H

#include <cstdint>
#include <utility>
#include <GL\glew.h>

namespace D3MCS::Render
{
	enum class TexelFilter : int32_t
	{
		Linear = GL_LINEAR,
		Nearest = GL_NEAREST
	};

	enum class MipmapFilter : int32_t
	{
		None,
		Linear,
		Nearest
	};

	enum class WrappingMode : int32_t
	{
		Repeat = GL_REPEAT,
		RepeatMirrored = GL_MIRRORED_REPEAT,
		ClampBorder = GL_CLAMP_TO_BORDER,
		ClampEdge = GL_CLAMP_TO_EDGE,
		ClampEdgeMirrored = GL_MIRROR_CLAMP_TO_EDGE
	};

	enum class ExternalFormat : int32_t
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

	enum class InternalFormat : int32_t
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

	class Texture final
	{
	public:
		static constexpr GLuint ZeroID{0u};

	private:
		GLuint nTextureID;
		
	public:
		Texture();
		Texture(const Texture &sSrc) = delete;
		Texture(Texture &&sSrc);
		~Texture();
		
	public:
		Texture &operator=(const Texture &sSrc) = delete;
		Texture &operator=(Texture &&sSrc);

	public:
		inline operator GLuint() const;
		
	public:
		inline static void activeTextureSlot(GLenum nSlotID);
		inline GLuint textureID() const;

		void setFilteringMode(TexelFilter eTexelFilter, MipmapFilter eMipmapFilter) const;
		inline void setFilteringMode(TexelFilter eTexelFilter) const;
		inline void setSWrappingMode(WrappingMode eWrappingMode) const;
		inline void setTWrappingMode(WrappingMode eWrappingMode) const;
		inline void setAnisotropicMode(float nAnisotropicMode) const;
		inline void specifyTexel(GLsizei nWidth, GLsizei nHeight, InternalFormat eInternalFormat) const;
		inline void specifyTexel() const;
	};

	inline Texture::operator GLuint() const
	{
		return this->nTextureID;
	}

	inline void Texture::activeTextureSlot(GLenum nSlotID)
	{
		glActiveTexture(GL_TEXTURE0 + nSlotID);
	}

	inline GLuint Texture::textureID() const
	{
		return this->nTextureID;
	}
}

#endif