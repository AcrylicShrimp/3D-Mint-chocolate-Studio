#version 450

uniform sampler2D uniform_texture;

smooth in vec4 frag_position;
smooth in vec2 frag_texcoord;

out vec4 frag_output;

float rand(vec2 co)
{
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
	frag_output = vec4(rand(frag_texcoord), rand(frag_position.xy), rand(frag_position.zw), texture(uniform_texture, frag_texcoord).r);
}