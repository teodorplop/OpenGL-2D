#include "Mesh.h"

Mesh::Mesh(const std::vector<glm::vec4>& vertices, const std::vector<glm::vec2>& uvs, const std::vector<unsigned int>& indices) {
	Buffer* vertexBuffer = new Buffer(vertices);
	Buffer* uvBuffer = new Buffer(uvs);

	m_VertexArray = new VertexArray();
	m_VertexArray->AddBuffer(vertexBuffer, 0);
	m_VertexArray->AddBuffer(uvBuffer, 1);

	m_IndexBuffer = new IndexBuffer(indices);
}
Mesh::~Mesh() {
	delete m_VertexArray;
	delete m_IndexBuffer;
}

VertexArray* Mesh::GetVertexArray() {
	return m_VertexArray;
}
IndexBuffer* Mesh::GetIndexBuffer() {
	return m_IndexBuffer;
}