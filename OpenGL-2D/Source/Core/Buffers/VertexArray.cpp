#include "VertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &m_ArrayID);
}

VertexArray::~VertexArray() {
	for (auto entry : m_Buffers)
		delete entry.second;

	glDeleteVertexArrays(1, &m_ArrayID);
}

void VertexArray::AddBuffer(Buffer* buffer, GLuint index) {
	Bind();
	buffer->Bind();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->GetElementSize(), GL_FLOAT, GL_FALSE, 0, 0);

	buffer->Unbind();
	Unbind();

	m_Buffers[index] = buffer;
}

Buffer* VertexArray::GetBuffer(GLuint index) {
	return m_Buffers[index];
}

void VertexArray::Bind() {
	glBindVertexArray(m_ArrayID);
}
void VertexArray::Unbind() {
	glBindVertexArray(0);
}