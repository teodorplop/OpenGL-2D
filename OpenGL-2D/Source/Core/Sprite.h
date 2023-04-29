#pragma once

#include "IRenderable.h"

#include <string>

// Class used to display a texture
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

	void SetPreserveAspectRatio(bool preserveAspectRatio);
};