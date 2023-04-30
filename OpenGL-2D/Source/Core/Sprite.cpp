#include "Sprite.h"

// TODO: Memory leaks here

Shader* GetSpriteDefaultShader() {
	return new Shader("Sprite.vert", "Sprite.frag");
}

Material* GetSpriteDefaultMaterial() {
	return new Material(GetSpriteDefaultShader());
}

Sprite::Sprite(Texture* texture) : Sprite(texture, GetSpriteDefaultMaterial()) {}

Sprite::Sprite(Texture* texture, Material* material) : IRenderable(GenerateMesh(), material) {
	m_Material = material;
	SetTexture(texture);
}
Sprite::~Sprite() {
	delete m_Mesh;
}

Texture* Sprite::GetTexture() {
	return m_Texture;
}
void Sprite::SetTexture(Texture* texture) {
	m_Material->SetProperty("_MainTexture", m_Texture = texture);
}

Transform* Sprite::GetTransform() {
	if (m_PreserveAspectRatio) {
		float textureAspectRatio = (float)m_Texture->GetWidth() / m_Texture->GetHeight();
		float transformAspectRatio = m_Transform->GetScale().x / m_Transform->GetScale().y;

		m_Transform->ScaleBy(glm::vec3(glm::min(1.0f, textureAspectRatio / transformAspectRatio), glm::min(1.0f, transformAspectRatio / textureAspectRatio), 1));
	}

	return m_Transform;
}

void Sprite::SetPreserveAspectRatio(bool preserveAspectRatio) {
	m_PreserveAspectRatio = preserveAspectRatio;
}

/*          maxUV
*   3 ----- 2
*     |  /|
*     | / |
*     |/  |
*   0 ----- 1
*   minUV
*/

Mesh* Sprite::GenerateMesh() {
	return new Mesh(ComputeVertices(), ComputeUvs(), ComputeIndices());
}

std::vector<glm::vec4> Sprite::ComputeVertices() {
	std::vector<glm::vec4> vertices;

	vertices.push_back(glm::vec4(-0.5f, -0.5f, 0, 1));
	vertices.push_back(glm::vec4(0.5f, -0.5f, 0, 1));
	vertices.push_back(glm::vec4(0.5f, 0.5f, 0, 1));
	vertices.push_back(glm::vec4(-0.5f, 0.5f, 0, 1));

	return vertices;
}

std::vector<glm::vec2> Sprite::ComputeUvs() {
	std::vector<glm::vec2> uvs;

	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(0, 1));

	return uvs;
}

std::vector<unsigned int> Sprite::ComputeIndices() {
	std::vector<unsigned int> indices;

	// CCW orientation
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	return indices;
}