
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
		glDeleteBuffers(1u, &this->nBufferID);
	}
	
	VideoBuffer &VideoBuffer::operator=(VideoBuffer &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->~VideoBuffer();

		this->nBufferID = sSrc.nBufferID;
		sSrc.nBufferID = VideoBuffer::ZeroID;
		
		return *this;
	}
}