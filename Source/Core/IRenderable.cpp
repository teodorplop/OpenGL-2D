#include "IRenderable.h"

#include "Renderer.h"

IRenderable::IRenderable(Mesh* mesh, Material* material) {
	m_Mesh = mesh;
	m_Material = material;

	m_Transform = new Transform();

	m_IsActive = true;

	// Make sure renderer knows that this needs to be rendered
	Renderer::Register(this);
}

IRenderable::~IRenderable() {
	// Make sure we unregister when we destroy the object
	Renderer::Unregister(this);

	delete m_Transform;
}

Mesh* IRenderable::GetMesh() {
	return m_Mesh;
}

Material* IRenderable::GetMaterial() {
	return m_Material;
}

Transform* IRenderable::GetTransform() {
	return m_Transform;
}

void IRenderable::SetActive(bool isActive) {
	m_IsActive = isActive;
}

bool IRenderable::IsActive() {
	return m_IsActive;
}