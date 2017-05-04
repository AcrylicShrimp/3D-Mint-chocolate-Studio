
/*
	2017.05.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_SHADER_H

#define _CLASS_D3MCS_RENDER_SHADER_H

#include "Texture.h"
#include "VideoBuffer.h"

#include <string>
#include <GL\glew.h>

namespace D3MCS::Render
{
	class Shader
	{
	public:
		static constexpr GLuint ZeroID{0u};
		static constexpr GLuint InvalidUniformLocation{GL_INVALID_INDEX};

	private:
		GLuint nProgramID;

	public:
		Shader();
		Shader(const Shader &sSrc) = delete;
		Shader(Shader &&sSrc);
		~Shader();

	public:
		Shader &operator=(const Shader &sSrc) = delete;
		Shader &operator=(Shader &&sSrc);

	public:
		inline operator GLuint() const;

	public:
		inline GLuint programID() const;
		inline void useShader() const;
		inline void bindUniformBlock(const GLchar *pUniformBlockName, GLint nBindingIndex);
		inline void bindUniformBuffer(const VideoBuffer &sVideoBuffer, GLint nBindingIndex);
		inline void setUniform(const GLchar *pUniformName, float nX);
		inline void setUniform(const GLchar *pUniformName, float nX, float nY);
		inline void setUniform(const GLchar *pUniformName, float nX, float nY, float nZ);
		inline void setUniform(const GLchar *pUniformName, float nX, float nY, float nZ, float nW);
		inline void setUniform(const GLchar *pUniformName, const Texture &sTexture);
		inline void setUniformArray(const GLchar *pUniformName, GLsizei nCount, const float *pValue);
	};

	inline Shader::operator GLuint() const
	{
		return this->nProgramID;
	}

	inline GLuint Shader::programID() const
	{
		return this->nProgramID;
	}

	inline void Shader::useShader() const
	{
		glUseProgram(this->nProgramID);
	}

	inline void Shader::bindUniformBlock(const GLchar *pUniformBlockName, GLint nBindingIndex)
	{
		auto nIndex{glGetUniformBlockIndex(this->nProgramID, pUniformBlockName)};

		if (nIndex != Shader::InvalidUniformLocation)
			glUniformBlockBinding(this->nProgramID, nIndex, nBindingIndex);
	}

	inline void Shader::bindUniformBuffer(const VideoBuffer &sVideoBuffer, GLint nBindingIndex)
	{
		glBindBufferBase(GL_UNIFORM_BUFFER, nBindingIndex, sVideoBuffer);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, float nX)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1f(this->nProgramID, nLocation, nX);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, float nX, float nY)
	{

	}

	inline void Shader::setUniform(const GLchar *pUniformName, float nX, float nY, float nZ)
	{

	}

	inline void Shader::setUniform(const GLchar *pUniformName, float nX, float nY, float nZ, float nW)
	{

	}

	inline void Shader::setUniform(const GLchar *pUniformName, const Texture &sTexture)
	{

	}

	inline void Shader::setUniformArray(const GLchar *pUniformName, GLsizei nCount, const float * pValue)
	{

	}
}

#endif