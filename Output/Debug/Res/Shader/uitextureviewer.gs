#version 450

uniform sampler2D uniform_texture;

layout(triangles) in;
layout(triangle_strip, max_vertices=6) out;

in vec4 geom_position[];
in vec2 geom_texcoord[];

out vec4 frag_position;
out vec2 frag_texcoord;

void main()
{
	gl_Position = vec4(-1.0, 1.0, 0.0, 1.0);
	frag_position = geom_position[0];
	frag_texcoord = vec2(0.0, 0.0);
	EmitVertex();
	
	gl_Position = vec4(-1.0, -1.0, 0.0, 1.0);
	frag_position = geom_position[1];
	frag_texcoord = vec2(0.0, 1.0);
	EmitVertex();
	
	gl_Position = vec4(1.0, 1.0, 0.0, 1.0);
	frag_position = geom_position[2];
	frag_texcoord = vec2(1.0, 0.0);
	EmitVertex();
	
	EndPrimitive();
	
	gl_Position = vec4(1.0, 1.0, 0.0, 1.0);
	frag_position = geom_position[0];
	frag_texcoord = vec2(1.0, 0.0);
	EmitVertex();
	
	gl_Position = vec4(-1.0, -1.0, 0.0, 1.0);
	frag_position = geom_position[1];
	frag_texcoord = vec2(0.0, 1.0);
	EmitVertex();
	
	gl_Position = vec4(1.0, -1.0, 0.0, 1.0);
	frag_position = geom_position[2];
	frag_texcoord = vec2(1.0, 1.0);
	EmitVertex();
	
	EndPrimitive();
}