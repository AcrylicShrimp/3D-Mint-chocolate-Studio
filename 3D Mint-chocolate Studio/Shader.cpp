
/*
	2017.05.04
	Created by AcrylicShrimp.
*/

#include "Shader.h"

namespace D3MCS::Render
{
	Shader::Shader() :
		nProgramID{Shader::ZeroID}
	{
		//Empty.
	}
	
	Shader::Shader(Shader &&sSrc) :
		nProgramID{sSrc.nProgramID}
	{
		sSrc.nProgramID = Shader::ZeroID;
	}
	
	Shader::~Shader()
	{
		if (this->nProgramID != Shader::ZeroID)
			glDeleteProgram(this->nProgramID);

		this->nProgramID = Shader::ZeroID;
	}
	
	Shader &Shader::operator=(Shader &&sSrc)
	{
		if(&sSrc == this)
			return *this;
		
		this->~Shader();

		this->nProgramID = sSrc.nProgramID;
		sSrc.nProgramID = Shader::ZeroID;
		
		return *this;
	}
}