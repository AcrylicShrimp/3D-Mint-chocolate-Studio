
/*
	2017.05.04
	Created by AcrylicShrimp.
*/

#include "Shader.h"

namespace D3MCS::Render
{
	Shader::Shader()
	{
		//TODO : Place your implementation of default constructor here.
		
	}
	
	Shader::Shader(Shader &&sSrc)
	{
		//TODO : Place your implementation of move constructor here.
		
	}
	
	Shader::~Shader()
	{

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