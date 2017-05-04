
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#include "VideoBuffer.h"

namespace D3MCS::Render
{
	VideoBuffer::VideoBuffer()
	{
		glGenBuffers(1u, &this->nBufferID);
	}

	VideoBuffer::VideoBuffer(VideoBuffer &&sSrc) :
		nBufferID{sSrc.nBufferID}
	{
		sSrc.nBufferID = VideoBuffer::ZeroID;
	}

	VideoBuffer::~VideoBuffer()
	{
		if (this->nBufferID != VideoBuffer::ZeroID)
			glDeleteBuffers(1u, &this->nBufferID);

		this->nBufferID = VideoBuffer::ZeroID;
	}

	VideoBuffer &VideoBuffer::operator=(VideoBuffer &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~VideoBuffer();

		this->nBufferID = sSrc.nBufferID;
		sSrc.nBufferID = VideoBuffer::ZeroID;

		return *this;
	}
}