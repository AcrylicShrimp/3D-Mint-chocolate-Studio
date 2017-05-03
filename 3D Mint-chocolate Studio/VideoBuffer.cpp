
/*
	2017.04.27
	Created by AcrylicShrimp.
*/

#include "VideoBuffer.h"

namespace D3MCS::Render
{
	ArrayBuffer::ArrayBuffer()
	{
		glGenBuffers(1u, &this->nBufferID);
	}

	ArrayBuffer::ArrayBuffer(ArrayBuffer &&sSrc) :
		nBufferID{sSrc.nBufferID}
	{
		sSrc.nBufferID = ArrayBuffer::ZeroID;
	}

	ArrayBuffer::~ArrayBuffer()
	{
		if (this->nBufferID)
			glDeleteBuffers(1u, &this->nBufferID);
	}

	ArrayBuffer &ArrayBuffer::operator=(ArrayBuffer &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~ArrayBuffer();

		this->nBufferID = sSrc.nBufferID;
		sSrc.nBufferID = ArrayBuffer::ZeroID;

		return *this;
	}

	ElementBuffer::ElementBuffer()
	{
		glGenBuffers(1u, &this->nBufferID);
	}

	ElementBuffer::ElementBuffer(ElementBuffer &&sSrc) :
		nBufferID{sSrc.nBufferID}
	{
		sSrc.nBufferID = ElementBuffer::ZeroID;
	}

	ElementBuffer::~ElementBuffer()
	{
		if (this->nBufferID)
			glDeleteBuffers(1u, &this->nBufferID);
	}

	ElementBuffer &ElementBuffer::operator=(ElementBuffer &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~ElementBuffer();

		this->nBufferID = sSrc.nBufferID;
		sSrc.nBufferID = ElementBuffer::ZeroID;

		return *this;
	}
}