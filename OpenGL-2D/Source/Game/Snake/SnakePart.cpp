#include "SnakePart.h"

SnakePart::SnakePart(Type type) {
	m_HeadTexture = new Texture("Snake/head.png");
	m_BodyTexture = new Texture("Snake/body.png");
	m_CurveTexture = new Texture("Snake/body_curve.png");
	m_TailTexture = new Texture("Snake/tail.png");
}

void SnakePart::SetType(Type type) {
	m_Type = type;
}

SnakePart::Type SnakePart::GetType() {
	return m_Type;
}

Transform* SnakePart::GetTransform() {
	return m_Sprite->GetTransform();
}