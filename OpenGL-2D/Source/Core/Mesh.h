#pragma once

#include <include\gl.h>

#include <vector>
#include "Buffers\Buffer.h"
#include "Buffers\IndexBuffer.h"
#include "Buffers\VertexArray.h"

// Simple mesh class
// Think about adding normals here, if we are working with 3D
class Mesh {
	std::vector<glm::vec4> m_Vertices;
	std::vector<glm::vec2> m_UVs;
	std::vector<unsigned int> m_Indices;

	VertexArray* m_VertexArray;
	IndexBuffer* m_IndexBuffer;
public:
	Mesh(const std::vector<glm::vec4>& vertices, const std::vector<glm::vec2>& uvs, const std::vector<unsigned int>& indices);
	~Mesh();

	VertexArray* GetVertexArray();
	IndexBuffer* GetIndexBuffer();
};
