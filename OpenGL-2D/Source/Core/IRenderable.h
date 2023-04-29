#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Transform.h"

// Class used for objects that need to be rendered.
class IRenderable {
private:
	bool m_IsActive;

protected:
	Mesh* m_Mesh;
	Material* m_Material;
	Transform* m_Transform;

	IRenderable(Mesh* mesh, Material* material);
	virtual ~IRenderable();

public:
	Mesh* GetMesh();
	Material* GetMaterial();
	virtual Transform* GetTransform();

	void SetActive(bool isActive);
	bool IsActive();
};