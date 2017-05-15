#version 450

uniform sampler2D uniform_texture;

layout(location=0) in vec4 vert_vertex;
layout(location=1) in vec2 vert_texcoord;

smooth out vec4 frag_position;
smooth out vec2 frag_texcoord;

void main()
{
	gl_Position = vert_vertex;
	frag_position = vert_vertex;
	frag_texcoord = vert_texcoord;
}