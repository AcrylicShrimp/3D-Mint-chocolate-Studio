
/*
	2017.05.04
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_SHADER_H

#define _CLASS_D3MCS_RENDER_SHADER_H

#include <GL\glew.h>

namespace D3MCS::Render
{
	class Shader
	{
	public:
		static constexpr GLuint ZeroID{0u};

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

	};

	inline Shader::operator GLuint() const
	{
		return this->nProgramID;
	}
}

#endif