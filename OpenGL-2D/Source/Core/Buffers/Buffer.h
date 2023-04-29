#pragma once

#include <glm\glm.hpp>

#include <GL/glew.h>
#include <vector>

// Simple buffer class used to store VBOs
class Buffer {
private:
	GLuint m_BufferID;
	GLsizei m_ElementSize;
	size_t m_NumberOfElements;

public:
	Buffer(const std::vector<float>& data);
	Buffer(const std::vector<glm::vec2>& data);
	Buffer(const std::vector<glm::vec3>& data);
	Buffer(const std::vector<glm::vec4>& data);
	~Buffer();

	void Bind();
	void Unbind();

	GLsizei GetElementSize();
};