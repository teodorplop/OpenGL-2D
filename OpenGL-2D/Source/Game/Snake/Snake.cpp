#include "Snake.h"

Snake::Snake(int length, float speed) {
	m_HeadTexture = new Texture("Snake/head.png");
	m_BodyTexture = new Texture("Snake/body.png");
	m_CurveTexture = new Texture("Snake/body_curve.png");
	m_TailTexture = new Texture("Snake/tail.png");

	for (int i = 0; i < length; ++i) {
		m_Body.push_back(CreatePart());
		m_Body[i]->GetTransform()->TranslateBy(glm::vec3(0, -i, 0));
	}
	m_Body[0]->SetType(SnakePart::Type::Head);
	m_Body.back()->SetType(SnakePart::Type::Tail);

	m_NewDirection = m_Direction = Direction::Up;
	m_HasRequestedNewDirection = false;

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

SnakePart* Snake::CreatePart() {
	return new SnakePart(m_HeadTexture, m_BodyTexture, m_CurveTexture, m_TailTexture);
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

glm::vec3 Snake::GetMovementDelta() {
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

void Snake::Move(float deltaTime) {
	m_Timer -= deltaTime;

	if (m_Timer <= 0) {
		BodyFollow();
		SwitchDirection();
		m_Body[0]->GetTransform()->TranslateBy(GetMovementDelta());

		Logger::Log("(%f, %f, %f)", m_Body[0]->GetTransform()->GetPosition().x, m_Body[0]->GetTransform()->GetPosition().y, m_Body[0]->GetTransform()->GetPosition().z);

		m_Timer += 1.0f / m_Speed;
	}
}

void Snake::BodyFollow() {
	m_Body[m_Body.size() - 1]->GetTransform()->TranslateTo(m_Body[m_Body.size() - 2]->GetTransform()->GetPosition());

	for (auto i = m_Body.size() - 2; i > 1; --i) {
		m_Body[i]->GetTransform()->TranslateTo(m_Body[i - 1]->GetTransform()->GetPosition());
		m_Body[i]->GetTransform()->RotateTo(m_Body[i - 1]->GetTransform()->GetRotation());
		m_Body[i]->SetType(m_Body[i - 1]->GetType());
	}

	m_Body[1]->GetTransform()->TranslateTo(m_Body[0]->GetTransform()->GetPosition());
	m_Body[1]->SetType(SnakePart::Type::Body);
}

bool Snake::SwitchDirection() {
	if (!m_HasRequestedNewDirection)
		return false;

	m_Body[1]->SetType(SnakePart::Type::Curve);

	if (m_NewDirection == Direction::Up) {
		m_Body[0]->GetTransform()->RotateBy(m_Direction == Direction::Left ? -90.0f : 90.0f, glm::vec3(0, 0, 1));
		m_Body[1]->GetTransform()->RotateTo(glm::vec3(0, 0, m_Direction == Direction::Left ? 180 : 270));
	}
	else if (m_NewDirection == Direction::Down) {
		m_Body[0]->GetTransform()->RotateBy(m_Direction == Direction::Left ? 90.0f : -90.0f, glm::vec3(0, 0, 1));
		m_Body[1]->GetTransform()->RotateTo(glm::vec3(0, 0, m_Direction == Direction::Left ? 90 : 0));
	}
	else if (m_NewDirection == Direction::Left) {
		m_Body[0]->GetTransform()->RotateBy(m_Direction == Direction::Up ? 90.0f : -90.0f, glm::vec3(0, 0, 1));
		m_Body[1]->GetTransform()->RotateTo(glm::vec3(0, 0, m_Direction == Direction::Up ? 0 : 270));
	}
	else if (m_NewDirection == Direction::Right) {
		m_Body[0]->GetTransform()->RotateBy(m_Direction == Direction::Up ? -90.0f : 90.0f, glm::vec3(0, 0, 1));
		m_Body[1]->GetTransform()->RotateTo(glm::vec3(0, 0, m_Direction == Direction::Up ? 90 : 180));
	}

	m_Direction = m_NewDirection;
	m_HasRequestedNewDirection = false;

	return true;
}