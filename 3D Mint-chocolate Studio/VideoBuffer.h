
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_VIDEO_BUFFER_H

#define _CLASS_D3MCS_RENDER_VIDEO_BUFFER_H

#include <GL\glew.h>
#include <utility>

namespace D3MCS::Render
{
	enum class BufferUsage : GLenum
	{
		StaticDraw = GL_STATIC_DRAW,
		StaticRead = GL_STATIC_READ,
		StaticCopy = GL_STATIC_COPY,

		DynamicDraw = GL_DYNAMIC_DRAW,
		DynamicRead = GL_DYNAMIC_READ,
		DynamicCopy = GL_DYNAMIC_COPY,

		StreamDraw = GL_STREAM_DRAW,
		StreamRead = GL_STREAM_READ,
		StreamCopy = GL_STREAM_COPY
	};

	class ArrayBuffer final
	{
	public:
		static constexpr GLuint ZeroID{0u};

	private:
		GLuint nBufferID;

	public:
		ArrayBuffer();
		ArrayBuffer(const ArrayBuffer &sSrc) = delete;
		ArrayBuffer(ArrayBuffer &&sSrc);
		~ArrayBuffer();

	public:
		ArrayBuffer &operator=(const ArrayBuffer &sSrc) = delete;
		ArrayBuffer &operator=(ArrayBuffer &&sSrc);

	public:
		inline operator GLuint() const;

	public:
		inline GLuint bufferID() const;
		inline void specifyData(BufferUsage eBufferUsage, GLsizei nLength, const void *pData);
	};

	inline ArrayBuffer::operator GLuint() const
	{
		return this->nBufferID;
	}

	inline GLuint ArrayBuffer::bufferID() const
	{
		return this->nBufferID;
	}

	inline void ArrayBuffer::specifyData(BufferUsage eBufferUsage, GLsizei nLength, const void *pData)
	{
		glNamedBufferData(this->nBufferID, nLength, pData, static_cast<GLenum>(eBufferUsage));
	}

	class ElementBuffer final
	{
	public:
		static constexpr GLuint ZeroID{0u};

	private:
		GLuint nBufferID;

	public:
		ElementBuffer();
		ElementBuffer(const ElementBuffer &sSrc) = delete;
		ElementBuffer(ElementBuffer &&sSrc);
		~ElementBuffer();

	public:
		ElementBuffer &operator=(const ElementBuffer &sSrc) = delete;
		ElementBuffer &operator=(ElementBuffer &&sSrc);

	public:
		inline operator GLuint() const;

	public:
		inline GLuint bufferID() const;
		inline void specifyData(BufferUsage eBufferUsage, GLsizei nLength, const void *pData);
	};

	inline ElementBuffer::operator GLuint() const
	{
		return this->nBufferID;
	}

	inline GLuint ElementBuffer::bufferID() const
	{
		return this->nBufferID;
	}

	inline void ElementBuffer::specifyData(BufferUsage eBufferUsage, GLsizei nLength, const void *pData)
	{
		glNamedBufferData(this->nBufferID, nLength, pData, static_cast<GLenum>(eBufferUsage));
	}
}

#endif