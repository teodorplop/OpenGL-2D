#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Transform.h"

/// <summary>
/// Used by Renderer. Any object inheriting this can be rendered.
/// </summary>
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

	/// <summary>
	/// Sets whether this object will be rendered or not
	/// </summary>
	void SetActive(bool isActive);

	/// <summary>
	/// Returns whether the object will be rendered or not
	/// </summary>
	bool IsActive();
};