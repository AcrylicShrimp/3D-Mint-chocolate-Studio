
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
	enum class ShaderType
	{
		Vertex = GL_VERTEX_SHADER,
		Geometry = GL_GEOMETRY_SHADER,
		Fragment = GL_FRAGMENT_SHADER,
		TessellationControl = GL_TESS_CONTROL_SHADER,
		TessellationEvaluation = GL_TESS_EVALUATION_SHADER,
		Compute = GL_COMPUTE_SHADER
	};

	class Shader final
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
		inline void setUniform(const GLchar *pUniformName, GLfloat nX);
		inline void setUniform(const GLchar *pUniformName, GLfloat nX, GLfloat nY);
		inline void setUniform(const GLchar *pUniformName, GLfloat nX, GLfloat nY, GLfloat nZ);
		inline void setUniform(const GLchar *pUniformName, GLfloat nX, GLfloat nY, GLfloat nZ, GLfloat nW);
		inline void setUniform(const GLchar *pUniformName, GLdouble nX);
		inline void setUniform(const GLchar *pUniformName, GLdouble nX, GLdouble nY);
		inline void setUniform(const GLchar *pUniformName, GLdouble nX, GLdouble nY, GLdouble nZ);
		inline void setUniform(const GLchar *pUniformName, GLdouble nX, GLdouble nY, GLdouble nZ, GLdouble nW);
		inline void setUniform(const GLchar *pUniformName, GLint nX);
		inline void setUniform(const GLchar *pUniformName, GLint nX, GLint nY);
		inline void setUniform(const GLchar *pUniformName, GLint nX, GLint nY, GLint nZ);
		inline void setUniform(const GLchar *pUniformName, GLint nX, GLint nY, GLint nZ, GLint nW);
		inline void setUniform(const GLchar *pUniformName, GLuint nX);
		inline void setUniform(const GLchar *pUniformName, GLuint nX, GLuint nY);
		inline void setUniform(const GLchar *pUniformName, GLuint nX, GLuint nY, GLuint nZ);
		inline void setUniform(const GLchar *pUniformName, GLuint nX, GLuint nY, GLuint nZ, GLuint nW);
		inline void setUniform(const GLchar *pUniformName, GLuint64 nTextureHandle);
		inline void setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue);
		inline void setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue);
		inline void setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue);
		inline void setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue);
		inline void setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue);
		inline void setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue);
		inline void setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue);
		inline void setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue);
		inline void setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue);
		inline void setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue);
		inline void setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue);
		inline void setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue);
		inline void setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue);
		inline void setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue);
		inline void setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue);
		inline void setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue);
		inline void setUniformArray(const GLchar *pUniformName, GLsizei nCount, const GLuint64 *pTextureHandle);
		inline void setUniformMatrix22(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix23(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix24(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix32(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix33(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix34(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix42(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix43(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix44(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue);
		inline void setUniformMatrix22(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix23(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix24(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix32(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix33(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix34(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix42(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix43(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);
		inline void setUniformMatrix44(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue);

		void resetProgram();
		bool attachShader(ShaderType eShaderType, const GLchar *pShaderSource) const;
		bool attachShader(ShaderType eShaderType, const GLchar *pShaderSource, std::string &sLog) const;
		bool linkShader() const;
		bool linkShader(std::string &sLog) const;
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

	inline void Shader::setUniform(const GLchar *pUniformName, GLfloat nX)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1f(this->nProgramID, nLocation, nX);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLfloat nX, GLfloat nY)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2f(this->nProgramID, nLocation, nX, nY);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLfloat nX, GLfloat nY, GLfloat nZ)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3f(this->nProgramID, nLocation, nX, nY, nZ);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLfloat nX, GLfloat nY, GLfloat nZ, GLfloat nW)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4f(this->nProgramID, nLocation, nX, nY, nZ, nW);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLdouble nX)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1d(this->nProgramID, nLocation, nX);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLdouble nX, GLdouble nY)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2d(this->nProgramID, nLocation, nX, nY);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLdouble nX, GLdouble nY, GLdouble nZ)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3d(this->nProgramID, nLocation, nX, nY, nZ);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLdouble nX, GLdouble nY, GLdouble nZ, GLdouble nW)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4d(this->nProgramID, nLocation, nX, nY, nZ, nW);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLint nX)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1i(this->nProgramID, nLocation, nX);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLint nX, GLint nY)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2i(this->nProgramID, nLocation, nX, nY);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLint nX, GLint nY, GLint nZ)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3i(this->nProgramID, nLocation, nX, nY, nZ);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLint nX, GLint nY, GLint nZ, GLint nW)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4i(this->nProgramID, nLocation, nX, nY, nZ, nW);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLuint nX)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1ui(this->nProgramID, nLocation, nX);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLuint nX, GLuint nY)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2ui(this->nProgramID, nLocation, nX, nY);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLuint nX, GLuint nY, GLuint nZ)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3ui(this->nProgramID, nLocation, nX, nY, nZ);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLuint nX, GLuint nY, GLuint nZ, GLuint nW)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4ui(this->nProgramID, nLocation, nX, nY, nZ, nW);
	}

	inline void Shader::setUniform(const GLchar *pUniformName, GLuint64 nTextureHandle)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformHandleui64ARB(this->nProgramID, nLocation, nTextureHandle);
	}

	inline void Shader::setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1fv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2fv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3fv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4fv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1dv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2dv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3dv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4dv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1iv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2iv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3iv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4iv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform1Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform1uiv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform2Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform2uiv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform3Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform3uiv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniform4Array(const GLchar *pUniformName, GLsizei nCount, const GLuint *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniform4uiv(this->nProgramID, nLocation, nCount, pValue);
	}

	inline void Shader::setUniformArray(const GLchar *pUniformName, GLsizei nCount, const GLuint64 *pTextureHandle)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformHandleui64vARB(this->nProgramID, nLocation, nCount, pTextureHandle);
	}

	inline void Shader::setUniformMatrix22(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix2fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix23(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix2x3fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix24(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix2x4fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix32(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix3x2fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix33(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix3fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix34(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix3x4fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix42(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix4x2fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix43(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix4x3fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix44(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLfloat *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix4fv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix22(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix2dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix23(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix2x3dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix24(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix2x4dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix32(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix3x2dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix33(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix3dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix34(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix3x4dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix42(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix4x2dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix43(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix4x3dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}

	inline void Shader::setUniformMatrix44(const GLchar *pUniformName, GLsizei nCount, GLboolean nTranspose, const GLdouble *pValue)
	{
		auto nLocation{glGetUniformLocation(this->nProgramID, pUniformName)};

		if (nLocation != Shader::InvalidUniformLocation)
			glProgramUniformMatrix4dv(this->nProgramID, nLocation, nCount, nTranspose, pValue);
	}
}

#endif