#pragma once

#include "../Engine.h"

class SnakeCurve {
private:
	Sprite* m_Sprite;
	float m_Lifetime;

public:
	SnakeCurve(Texture* texture);

	void SetPosition(glm::vec3 position);
	void SetRotation(float angle);
};
