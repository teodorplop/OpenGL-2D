#include "Texture.h"
#include "Utils\ImageUtils.h"

const std::string Texture::K_TEXTURES_PATH = "Resources/Textures/";

Texture::Texture(const std::string& fileName) : m_FileName(fileName) {
	BYTE* pixels = ImageUtils::Load_Image((K_TEXTURES_PATH + fileName).c_str(), &m_Width, &m_Height);
	glGenTextures(1, &m_TextureID);
	Bind();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);

	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	Unbind();
}

Texture::~Texture() {
	glDeleteTextures(1, &m_TextureID);
}

void Texture::Bind(int index) {
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void Texture::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

int Texture::GetWidth() {
	return m_Width;
}

int Texture::GetHeight() {
	return m_Height;
}