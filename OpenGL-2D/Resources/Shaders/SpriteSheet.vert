// Vertex Shader

#version 400

uniform mat4 _ModelMatrix;
uniform mat4 _ViewMatrix;
uniform mat4 _ProjMatrix;

uniform int _SpriteIndex = 0;
uniform int _SpritesPerRow = 1;
uniform int _SpritesPerColumn = 1;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec2 inTextureCoord;

out DATA {
	vec2 textureCoord;
} Out;

void main() {
	int row = _SpriteIndex / _SpritesPerRow;
	int column = _SpriteIndex % _SpritesPerRow;

	vec2 offset = vec2(1.0 / _SpritesPerRow * column, 1.0 / _SpritesPerColumn * (_SpritesPerColumn - row - 1));
	vec2 textureCoord = offset + vec2(inTextureCoord.x / _SpritesPerRow, inTextureCoord.y / _SpritesPerColumn);

	gl_Position = _ProjMatrix * _ViewMatrix * _ModelMatrix * inPosition;
	Out.textureCoord = textureCoord;
}