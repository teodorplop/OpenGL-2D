#include "Snake.h"

Snake::Snake(int length, float speed) {
	m_HeadTexture = new Texture("Snake/head.png");
	m_BodyTexture = new Texture("Snake/body.png");
	m_CurveTexture = new Texture("Snake/body_curve.png");
	m_TailTexture = new Texture("Snake/tail.png");

	m_NewDirection = m_Direction = Direction::Up;
	m_HasRequestedNewDirection = false;

	CreateParts(length);

	m_Speed = speed;
	m_Timer = 1.0f / m_Speed;
}

Snake::~Snake() {
	for (SnakePart* body : m_Body)
		delete body;

	delete m_HeadTexture;
	delete m_BodyTexture;
	delete m_CurveTexture;
	delete m_TailTexture;
}

void Snake::CreateParts(int length) {
	for (int i = 0; i < length; ++i)
		CreatePart()->GetTransform()->TranslateTo(glm::vec3(0, -i, 0));
}

SnakePart* Snake::CreatePart() {
	SnakePart* part = new SnakePart(m_HeadTexture, m_BodyTexture, m_CurveTexture, m_TailTexture);

	if (!m_Body.empty()) {
		m_Body.back()->SetNext(part);
		part->SetPrevious(m_Body.back());
		part->SetDirection(m_Body.back()->GetDirection());
	}
	else {
		part->SetDirection(m_Direction);
	}
	part->SetNext(nullptr);

	m_Body.push_back(part);

	return part;
}

void Snake::Tick(float deltaTime) {
	if (!m_HasRequestedNewDirection)
		m_HasRequestedNewDirection = WasSwitchDirectionRequested(m_NewDirection);

	Move(deltaTime);
}

bool Snake::WasSwitchDirectionRequested(Direction& newDirection) {
	if (Input::GetKeyDown(GLFW_KEY_A)) {
		newDirection = Direction::Left;
		return CanSwitchDirection(newDirection);
	}
	if (Input::GetKeyDown(GLFW_KEY_D)) {
		newDirection = Direction::Right;
		return CanSwitchDirection(newDirection);
	}
	if (Input::GetKeyDown(GLFW_KEY_W)) {
		newDirection = Direction::Up;
		return CanSwitchDirection(newDirection);
	}
	if (Input::GetKeyDown(GLFW_KEY_S)) {
		newDirection = Direction::Down;
		return CanSwitchDirection(newDirection);
	}

	return false;
}

bool Snake::CanSwitchDirection(Direction newDirection) {
	if (newDirection == Direction::Up || newDirection == Direction::Down)
		return m_Direction == Direction::Left || m_Direction == Direction::Right;
	return m_Direction == Direction::Up || m_Direction == Direction::Down;
}

void Snake::Move(float deltaTime) {
	m_Timer -= deltaTime;

	if (m_Timer <= 0) {
		if (m_HasRequestedNewDirection) {
			m_Body[0]->SetDirection(m_Direction = m_NewDirection);
			m_HasRequestedNewDirection = false;
		}

		for (int i = (int)m_Body.size() - 1; i >= 0; --i)
			m_Body[i]->Move(deltaTime);
		for (int i = (int)m_Body.size() - 1; i >= 0; --i)
			m_Body[i]->UpdateGraphic();

		m_Timer += 1.0f / m_Speed;
	}
}