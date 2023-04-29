#pragma once

#include <string>
#include <include\gl.h>

// OpenGL texture class
class Texture {
private:
	static const std::string K_TEXTURES_PATH;

	std::string m_FileName;
	GLuint m_TextureID;
	GLsizei m_Width, m_Height;

public:
	Texture(const std::string& fileName);
	~Texture();

	int GetWidth();
	int GetHeight();

	void Bind(int index = 0);
	void Unbind();
};
