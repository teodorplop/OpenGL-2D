// Fragment Shader 

#version 400

uniform sampler2D _MainTexture;

in DATA {
	vec2 textureCoord;
} In;

out vec4 outColor;

void main() {
	outColor = texture(_MainTexture, In.textureCoord);
}