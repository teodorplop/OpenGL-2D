// Vertex Shader

#version 400

uniform mat4 _ModelMatrix;
uniform mat4 _ViewMatrix;
uniform mat4 _ProjMatrix;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec2 inTextureCoord;

out DATA {
	vec2 textureCoord;
} Out;

void main() {
	gl_Position = _ProjMatrix * _ViewMatrix * _ModelMatrix * inPosition;
	Out.textureCoord = inTextureCoord;
}