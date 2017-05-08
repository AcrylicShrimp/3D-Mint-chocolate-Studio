
/*
	2017.05.04
	Created by AcrylicShrimp.
*/

#include "Shader.h"

namespace D3MCS::Render
{
	Shader::Shader() :
		nProgramID{glCreateProgram()}
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
		if (&sSrc == this)
			return *this;

		this->~Shader();

		this->nProgramID = sSrc.nProgramID;
		sSrc.nProgramID = Shader::ZeroID;

		return *this;
	}

	void Shader::resetProgram()
	{
		this->~Shader();
		this->nProgramID = glCreateProgram();
	}

	bool Shader::attachShader(ShaderType eShaderType, const GLchar *pShaderSource) const
	{
		auto nShader{glCreateShader(static_cast<GLenum>(eShaderType))};

		glShaderSource(nShader, 1u, &pShaderSource, nullptr);
		glCompileShader(nShader);

		GLint nSuccess;
		glGetShaderiv(nShader, GL_COMPILE_STATUS, &nSuccess);

		if (nSuccess == GL_TRUE)
			glAttachShader(this->nProgramID, nShader);

		glDeleteShader(nShader);

		return nSuccess == GL_TRUE;
	}

	bool Shader::attachShader(ShaderType eShaderType, const GLchar *pShaderSource, std::string &sLog) const
	{
		auto nShader{glCreateShader(static_cast<GLenum>(eShaderType))};

		glShaderSource(nShader, 1u, &pShaderSource, nullptr);
		glCompileShader(nShader);

		GLint nSuccess;
		GLint nLogLength;
		glGetShaderiv(nShader, GL_COMPILE_STATUS, &nSuccess);
		glGetShaderiv(nShader, GL_INFO_LOG_LENGTH, &nLogLength);

		sLog.resize(nLogLength, '\0');
		glGetShaderInfoLog(nShader, nLogLength, nullptr, sLog.data());

		if (nSuccess == GL_TRUE)
			glAttachShader(this->nProgramID, nShader);

		glDeleteShader(nShader);

		return nSuccess == GL_TRUE;
	}

	bool Shader::linkShader() const
	{
		glLinkProgram(this->nProgramID);

		GLint nSuccess;
		glGetProgramiv(this->nProgramID, GL_LINK_STATUS, &nSuccess);

		return nSuccess == GL_TRUE;
	}

	bool Shader::linkShader(std::string &sLog) const
	{
		glLinkProgram(this->nProgramID);

		GLint nSuccess;
		GLint nLogLength;
		glGetProgramiv(this->nProgramID, GL_LINK_STATUS, &nSuccess);
		glGetProgramiv(this->nProgramID, GL_INFO_LOG_LENGTH, &nLogLength);

		sLog.resize(nLogLength, '\0');
		glGetProgramInfoLog(this->nProgramID, nLogLength, nullptr, sLog.data());

		return nSuccess == GL_TRUE;
	}
}