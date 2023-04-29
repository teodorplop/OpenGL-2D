#pragma once

#include <GL/glew.h>
#include <unordered_map>
#include "Buffer.h"

// VAO
class VertexArray {
private:
	GLuint m_ArrayID;
	std::unordered_map<GLuint, Buffer*> m_Buffers;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(Buffer* buffer, GLuint index);
	Buffer* GetBuffer(GLuint index);

	void Bind();
	void Unbind();
};