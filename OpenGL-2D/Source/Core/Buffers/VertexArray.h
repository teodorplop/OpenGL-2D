#pragma once

#include <GL/glew.h>
#include <unordered_map>
#include "Buffer.h"

/// <summary>
/// Vertex Array Object
/// </summary>
class VertexArray {
private:
	GLuint m_ArrayID;
	std::unordered_map<GLuint, Buffer*> m_Buffers;
public:
	VertexArray();
	~VertexArray();

	/// <summary>
	/// Adds a buffer to this Array
	/// </summary>
	void AddBuffer(Buffer* buffer, GLuint index);

	/// <summary>
	/// Gets buffer stored at a given index
	/// </summary>
	Buffer* GetBuffer(GLuint index);

	/// <summary>
	/// Binds the array to the GPU
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the array from the GPU
	/// </summary>
	void Unbind();
};