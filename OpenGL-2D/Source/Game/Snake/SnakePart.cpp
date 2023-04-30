#include "SnakePart.h"

SnakePart::SnakePart(Texture* head, Texture* body, Texture* curve, Texture* tail) {
	m_HeadTexture = head;
	m_BodyTexture = body;
	m_CurveTexture = curve;
	m_TailTexture = tail;

	m_Sprite = new Sprite(m_BodyTexture);
	SetType(Type::Body);
}

void SnakePart::SetType(Type type) {
	m_Type = type;
	if (m_Type == Type::Head)
		m_Sprite->SetTexture(m_HeadTexture);
	else if (m_Type == Type::Body)
		m_Sprite->SetTexture(m_BodyTexture);
	else if (m_Type == Type::Curve)
		m_Sprite->SetTexture(m_CurveTexture);
	else if (m_Type == Type::Tail)
		m_Sprite->SetTexture(m_TailTexture);
}

SnakePart::Type SnakePart::GetType() {
	return m_Type;
}

Transform* SnakePart::GetTransform() {
	return m_Sprite->GetTransform();
}