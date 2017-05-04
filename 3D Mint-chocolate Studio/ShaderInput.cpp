
/*
	2017.05.03
	Created by AcrylicShrimp.
*/

#include "ShaderInput.h"

namespace D3MCS::Render
{
	ShaderInput::ShaderInput()
	{
		glGenVertexArrays(1u, &this->nInputID);
	}

	ShaderInput::ShaderInput(ShaderInput &&sSrc) :
		nInputID{sSrc.nInputID}
	{
		sSrc.nInputID = ShaderInput::ZeroID;
	}
	
	ShaderInput::~ShaderInput()
	{
		if (this->nInputID != ShaderInput::ZeroID)
			glDeleteVertexArrays(1u, &this->nInputID);

		this->nInputID = ShaderInput::ZeroID;
	}

	ShaderInput &ShaderInput::operator=(ShaderInput &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->~ShaderInput();

		this->nInputID = sSrc.nInputID;
		sSrc.nInputID = ShaderInput::ZeroID;
		
		return *this;
	}
}