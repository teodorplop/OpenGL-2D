// Fragment Shader 

#version 400

in DATA {
	vec2 textureCoord;
} In;

uniform sampler2D _MainTexture;

out vec4 outColor;

void main() {
	outColor = texture(_MainTexture, In.textureCoord);
}