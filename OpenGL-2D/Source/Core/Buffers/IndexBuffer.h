#pragma once

#include <GL/glew.h>
#include <vector>

/// <summary>
/// Index Buffer Object
/// </summary>
class IndexBuffer {
private:
	GLuint bufferID;
	GLsizei count;
public:
	IndexBuffer(GLuint* data, GLsizei count);
	IndexBuffer(const std::vector<unsigned int>& data);
	~IndexBuffer();

	/// <summary>
	/// Binds the buffer to the GPU
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the buffer from the GPU
	/// </summary>
	void Unbind();

	/// <summary>
	/// Returns the number of indices stored
	/// </summary>
	GLsizei GetCount();
};