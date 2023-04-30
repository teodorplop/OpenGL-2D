#pragma once

#include <string>
#include <include\gl.h>

/// <summary>
/// OpenGL Texture Wrapper Class
/// </summary>
class Texture {
private:
	static const std::string K_TEXTURES_PATH;

	std::string m_FileName;
	GLuint m_TextureID;
	GLsizei m_Width, m_Height;

public:
	/// <summary>
	/// Loads a texture from a file
	/// </summary>
	Texture(const std::string& fileName);
	~Texture();

	/// <summary>
	/// Width of the texture, in pixels
	/// </summary>
	int GetWidth();

	/// <summary>
	/// Height of the texture, in pixels
	/// </summary>
	int GetHeight();

	/// <summary>
	/// Binds the texture to GPU
	/// </summary>
	void Bind(int index = 0);

	/// <summary>
	/// Unbinds the texture from GPU
	/// </summary>
	void Unbind();
};
