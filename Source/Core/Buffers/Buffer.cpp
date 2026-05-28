#include "Buffer.h"

Buffer::Buffer(const std::vector<float>& data) : m_ElementSize(1), m_NumberOfElements(data.size()) {
	m_BufferID = 0;
	glGenBuffers(1, &m_BufferID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
	Unbind();
}
Buffer::Buffer(const std::vector<glm::vec2>& data) : m_ElementSize(2), m_NumberOfElements(data.size()) {
	glGenBuffers(1, &m_BufferID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), &data[0], GL_STATIC_DRAW);
	Unbind();
}
Buffer::Buffer(const std::vector<glm::vec3>& data) : m_ElementSize(3), m_NumberOfElements(data.size()) {
	glGenBuffers(1, &m_BufferID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), &data[0], GL_STATIC_DRAW);
	Unbind();
}
Buffer::Buffer(const std::vector<glm::vec4>& data) : m_ElementSize(4), m_NumberOfElements(data.size()) {
	glGenBuffers(1, &m_BufferID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), &data[0], GL_STATIC_DRAW);
	Unbind();
}
Buffer::~Buffer() {
	glDeleteBuffers(1, &m_BufferID);
}

void Buffer::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void Buffer::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLsizei Buffer::GetElementSize() {
	return m_ElementSize;
}