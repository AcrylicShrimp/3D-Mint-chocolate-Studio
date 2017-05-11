
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

	class VideoBuffer final
	{
	public:
		static constexpr GLuint ZeroID{0u};

	private:
		GLuint nBufferID;

	public:
		VideoBuffer();
		VideoBuffer(const VideoBuffer &sSrc) = delete;
		VideoBuffer(VideoBuffer &&sSrc);
		~VideoBuffer();

	public:
		VideoBuffer &operator=(const VideoBuffer &sSrc) = delete;
		VideoBuffer &operator=(VideoBuffer &&sSrc);

	public:
		inline operator GLuint() const;

	public:
		inline GLuint bufferID() const;
		inline void specifyData(BufferUsage eBufferUsage, GLsizeiptr nLength, const void *pData) const;
	};

	inline VideoBuffer::operator GLuint() const
	{
		return this->nBufferID;
	}

	inline GLuint VideoBuffer::bufferID() const
	{
		return this->nBufferID;
	}

	inline void VideoBuffer::specifyData(BufferUsage eBufferUsage, GLsizeiptr nLength, const void *pData) const
	{
		glNamedBufferData(this->nBufferID, nLength, pData, static_cast<GLenum>(eBufferUsage));
	}
}

#endif