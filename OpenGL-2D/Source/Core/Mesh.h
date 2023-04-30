#pragma once

#include <include\gl.h>

#include <vector>
#include "Buffers\Buffer.h"
#include "Buffers\IndexBuffer.h"
#include "Buffers\VertexArray.h"

/// <summary>
/// Holds information about a mesh, using buffer objects stored into array objects, and index buffers
/// </summary>
class Mesh {
	std::vector<glm::vec4> m_Vertices;
	std::vector<glm::vec2> m_UVs;
	std::vector<unsigned int> m_Indices;

	VertexArray* m_VertexArray;
	IndexBuffer* m_IndexBuffer;
public:
	Mesh(const std::vector<glm::vec4>& vertices, const std::vector<glm::vec2>& uvs, const std::vector<unsigned int>& indices);
	~Mesh();

	/// <summary>
	/// Vertex Array Object in which all Buffers have been stored
	/// </summary>
	VertexArray* GetVertexArray();

	/// <summary>
	/// Index Buffer Object
	/// </summary>
	IndexBuffer* GetIndexBuffer();
};
