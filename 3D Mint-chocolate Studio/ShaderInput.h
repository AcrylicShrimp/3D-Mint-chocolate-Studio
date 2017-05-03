
/*
	2017.05.03
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_RENDER_SHADER_INPUT_H

#define _CLASS_D3MCS_RENDER_SHADER_INPUT_H

#include <utility>
#include <GL\glew.h>

namespace D3MCS::Render
{
	class ShaderInput
	{
	private:

		
	public:
		ShaderInput();
		ShaderInput(const ShaderInput &sSrc);
		ShaderInput(ShaderInput &&sSrc);
		~ShaderInput();
		
	public:
		ShaderInput &operator=(const ShaderInput &sSrc);
		ShaderInput &operator=(ShaderInput &&sSrc);
		
	public:

	};
}

#endif