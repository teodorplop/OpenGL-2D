#pragma once

#include "IRenderable.h"

#include <string>

/// <summary>
/// Renders a texture on the screen
/// </summary>
class Sprite : public IRenderable {
private:
	Mesh* GenerateMesh();
	std::vector<glm::vec4> ComputeVertices();
	std::vector<glm::vec2> ComputeUvs();
	std::vector<unsigned int> ComputeIndices();

protected:
	Texture* m_Texture;
	bool m_PreserveAspectRatio;

public:
	Sprite(Texture* texture);
	Sprite(Texture* texture, Material* material);
	virtual ~Sprite();

	virtual Transform* GetTransform() override;

	/// <summary>
	/// If set to true, no matter how we rescale the sprite, it will always preserve its aspect ratio
	/// </summary>
	void SetPreserveAspectRatio(bool preserveAspectRatio);
};