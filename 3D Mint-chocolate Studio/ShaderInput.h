
/*
	2017.05.03
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_SHADER_INPUT_H

#define _CLASS_D3MCS_RENDER_SHADER_INPUT_H

#include "Texture.h"
#include "VideoBuffer.h"

#include <string>
#include <GL\glew.h>

namespace D3MCS::Render
{
	enum class IntegerElementType : GLenum
	{
		Char = GL_BYTE,
		Byte = GL_UNSIGNED_BYTE,
		Short = GL_SHORT,
		UnsignedShort = GL_UNSIGNED_SHORT,
		Int = GL_INT,
		UnsignedInt = GL_UNSIGNED_INT,
	};

	enum class FloatElementType : GLenum
	{
		Char = GL_BYTE,
		Byte = GL_UNSIGNED_BYTE,
		Short = GL_SHORT,
		UnsignedShort = GL_UNSIGNED_SHORT,
		Int = GL_INT,
		ReversedInt2101010 = GL_INT_2_10_10_10_REV,
		UnsignedInt = GL_UNSIGNED_INT,
		UnsignedInt101111F = GL_UNSIGNED_INT_10F_11F_11F_REV,
		ReversedUnsignedInt2101010 = GL_UNSIGNED_INT_2_10_10_10_REV,
		Fixed = GL_FIXED,
		Float = GL_FLOAT,
		Half = GL_HALF_FLOAT,
		Double = GL_DOUBLE
	};

	class ShaderInput final
	{
	public:
		static constexpr GLuint ZeroID{0u};

	private:
		GLuint nInputID;
		
	public:
		ShaderInput();
		ShaderInput(const ShaderInput &sSrc) = delete;
		ShaderInput(ShaderInput &&sSrc);
		~ShaderInput();
		
	public:
		ShaderInput &operator=(const ShaderInput &sSrc) = delete;
		ShaderInput &operator=(ShaderInput &&sSrc);

	public:
		inline operator GLuint() const;
		
	public:
		inline void specifyFormatAsDouble(GLuint nIndex, GLint nCount, GLuint nRelativeOffset) const;
		inline void specifyFormatAsInteger(GLuint nIndex, GLint nCount, IntegerElementType eIntegerElementType, GLuint nRelativeOffset) const;
		inline void specifyFormatAsFloat(GLuint nIndex, GLint nCount, FloatElementType eFloatElementType, GLboolean nNormalized, GLuint nRelativeOffset) const;
		inline void attachBuffer(const VideoBuffer &sVideoBuffer) const;
		inline void attachBuffer(GLuint nIndex, const VideoBuffer &sVideoBuffer, GLintptr nOffset = 0, GLsizei nStride = 0) const;
	};

	inline ShaderInput::operator GLuint() const
	{
		return this->nInputID;
	}

	inline void ShaderInput::specifyFormatAsDouble(GLuint nIndex, GLint nCount, GLuint nRelativeOffset) const
	{
		glVertexArrayAttribLFormat(this->nInputID, nIndex, nCount, GL_DOUBLE, nRelativeOffset);
	}

	inline void ShaderInput::specifyFormatAsInteger(GLuint nIndex, GLint nCount, IntegerElementType eElementType, GLuint nRelativeOffset) const
	{
		glVertexArrayAttribIFormat(this->nInputID, nIndex, nCount, static_cast<GLenum>(eElementType), nRelativeOffset);
	}

	inline void ShaderInput::specifyFormatAsFloat(GLuint nIndex, GLint nCount, FloatElementType eFloatElementType, GLboolean nNormalized, GLuint nRelativeOffset) const
	{
		glVertexArrayAttribFormat(this->nInputID, nIndex, nCount, static_cast<GLenum>(eFloatElementType), nNormalized, nRelativeOffset);
	}

	inline void ShaderInput::attachBuffer(const VideoBuffer &sVideoBuffer) const
	{
		glVertexArrayElementBuffer(this->nInputID, sVideoBuffer);
	}

	inline void ShaderInput::attachBuffer(GLuint nIndex, const VideoBuffer &sVideoBuffer, GLintptr nOffset, GLsizei nStride) const
	{
		glVertexArrayVertexBuffer(this->nInputID, nIndex, sVideoBuffer, nOffset, nStride);
	}
}

#endif