#pragma once

#include <glm\glm.hpp>

#include <GL/glew.h>
#include <vector>

/// <summary>
/// Vertex Buffer Object
/// </summary>
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

	/// <summary>
	/// Binds the buffer to the GPU
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the buffer from the GPU
	/// </summary>
	void Unbind();

	/// <summary>
	/// Size of 1 element stored in the buffer
	/// </summary>
	GLsizei GetElementSize();
};