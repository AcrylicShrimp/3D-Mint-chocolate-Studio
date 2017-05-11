#version 450

uniform sampler2D uniform_texture;

layout(location=0) in vec4 vert_vertex;
layout(location=1) in vec2 vert_texcoord;

out vec4 geom_position;
out vec2 geom_texcoord;

void main()
{
	gl_Position = vert_vertex;
	geom_position = vert_vertex;
	geom_texcoord = vert_texcoord;
}