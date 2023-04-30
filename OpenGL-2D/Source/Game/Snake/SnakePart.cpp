#include "SnakePart.h"

SnakePart::SnakePart(Texture* head, Texture* body, Texture* curve, Texture* tail) {
	m_HeadTexture = head;
	m_BodyTexture = body;
	m_CurveTexture = curve;
	m_TailTexture = tail;

	m_Sprite = new Sprite(m_BodyTexture);
	SetType(Type::Body);
}

SnakePart::~SnakePart() {
	delete m_Sprite;
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

void SnakePart::SetPrevious(SnakePart* snakePart) {
	m_PreviousPart = snakePart;
	if (m_PreviousPart == nullptr)
		SetType(Type::Head);
}

void SnakePart::SetNext(SnakePart* snakePart) {
	m_NextPart = snakePart;
	if (m_NextPart == nullptr)
		SetType(Type::Tail);
}

Direction SnakePart::GetDirection() {
	return m_Direction;
}

void SnakePart::SetDirection(Direction direction) {
	m_Direction = direction;
}

glm::vec3 SnakePart::GetMovementDelta(float deltaTime) {
	glm::vec3 movementDelta;
	if (m_Direction == Direction::Up)
		movementDelta.y = 1;
	else if (m_Direction == Direction::Down)
		movementDelta.y = -1;
	else if (m_Direction == Direction::Left)
		movementDelta.x = -1;
	else if (m_Direction == Direction::Right)
		movementDelta.x = 1;

	return movementDelta;
}

void SnakePart::Move(float deltaTime) {
	GetTransform()->TranslateBy(GetMovementDelta(deltaTime));
	if (m_PreviousPart != nullptr)
		SetDirection(m_PreviousPart->GetDirection());
}

void SnakePart::UpdateGraphic() {
	if (m_NextPart == nullptr) {
		SetType(Type::Tail);
		GetTransform()->RotateTo(glm::vec3(0, 0, 90) * (float)m_Direction);
		return;
	}

	if (m_PreviousPart == nullptr) {
		SetType(Type::Head);
		GetTransform()->RotateTo(glm::vec3(0, 0, 90) * (float)m_Direction);
		return;
	}

	if (m_NextPart->GetDirection() != GetDirection()) {
		SetType(Type::Curve);
		if ((m_NextPart->GetDirection() == Direction::Up && GetDirection() == Direction::Left)
		||  (m_NextPart->GetDirection() == Direction::Right && GetDirection() == Direction::Down))
			GetTransform()->RotateTo(glm::vec3(0, 0, 0));
		else if ((m_NextPart->GetDirection() == Direction::Up && GetDirection() == Direction::Right)
			|| (m_NextPart->GetDirection() == Direction::Left && GetDirection() == Direction::Down))
			GetTransform()->RotateTo(glm::vec3(0, 0, 90));
		else if ((m_NextPart->GetDirection() == Direction::Left && GetDirection() == Direction::Up)
			|| (m_NextPart->GetDirection() == Direction::Down && GetDirection() == Direction::Right))
			GetTransform()->RotateTo(glm::vec3(0, 0, 180));
		else if ((m_NextPart->GetDirection() == Direction::Right && GetDirection() == Direction::Up)
			 ||  (m_NextPart->GetDirection() == Direction::Down && GetDirection() == Direction::Left))
			GetTransform()->RotateTo(glm::vec3(0, 0, 270));
	}
	else {
		SetType(Type::Body);
		GetTransform()->RotateTo(glm::vec3(0, 0, 90) * (float)m_Direction);
	}
}

Transform* SnakePart::GetTransform() {
	return m_Sprite->GetTransform();
}