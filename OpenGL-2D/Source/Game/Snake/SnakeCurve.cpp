#include "SnakeCurve.h"

SnakeCurve::SnakeCurve(Texture* texture) {
	m_Sprite = new Sprite(texture);
	m_Sprite->SetPreserveAspectRatio(true);
}

void SnakeCurve::SetPosition(glm::vec3 position) {
	m_Sprite->GetTransform()->TranslateTo(position);
}

void SnakeCurve::SetRotation(float angle) {
	m_Sprite->GetTransform()->RotateBy(angle, glm::vec3(0, 0, 1));
}