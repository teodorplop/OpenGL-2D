#include "Snake.h"

Snake::Snake() {
	m_HeadTexture = new Texture("Snake/head.png");
	m_BodyTexture = new Texture("Snake/body.png");
	m_BodyCurveTexture = new Texture("Snake/body_curve.png");
	m_TailTexture = new Texture("Snake/tail.png");

	m_Head = new Sprite(m_HeadTexture);
	m_Body.push_back(new Sprite(m_BodyTexture));
	m_Body.push_back(new Sprite(m_BodyCurveTexture));
	m_Body.push_back(new Sprite(m_BodyTexture));
	m_Tail = new Sprite(m_TailTexture);

	m_Head->GetTransform()->TranslateBy(glm::vec3(0, 2, 0));
	m_Body[0]->GetTransform()->TranslateBy(glm::vec3(0, 1, 0));
	m_Body[1]->GetTransform()->TranslateBy(glm::vec3(0, 0, 0));
	m_Body[1]->GetTransform()->RotateBy(180, glm::vec3(0, 0, 1));
	m_Body[2]->GetTransform()->TranslateBy(glm::vec3(1, 0, 0));
	m_Body[2]->GetTransform()->RotateBy(90, glm::vec3(0, 0, 1));
	m_Tail->GetTransform()->TranslateBy(glm::vec3(2, 0, 0));
	m_Tail->GetTransform()->RotateBy(90, glm::vec3(0, 0, 1));

	m_Direction = Direction::Up;
}

Snake::~Snake() {
	delete m_Head;
	for (Sprite* body : m_Body)
		delete body;
	delete m_Tail;

	delete m_HeadTexture;
	delete m_BodyTexture;
	delete m_BodyCurveTexture;
	delete m_TailTexture;
}

void Snake::Tick(float deltaTime) {
	Direction newDirection;

	if (WasSwitchDrectionRequested(newDirection))
		SwitchDirection(newDirection);
}

bool Snake::WasSwitchDrectionRequested(Direction& newDirection) {
	if (Input::GetKeyDown(GLFW_KEY_A)) {
		newDirection = Direction::Left;
		return true;
	}
	if (Input::GetKeyDown(GLFW_KEY_D)) {
		newDirection = Direction::Right;
		return true;
	}
	if (Input::GetKeyDown(GLFW_KEY_W)) {
		newDirection = Direction::Up;
		return true;
	}
	if (Input::GetKeyDown(GLFW_KEY_S)) {
		newDirection = Direction::Down;
		return true;
	}

	return false;
}

bool Snake::CanSwitchDirection(Direction newDirection) {
	if (newDirection == Direction::Up || newDirection == Direction::Down)
		return m_Direction == Direction::Left || m_Direction == Direction::Right;
	return m_Direction == Direction::Up || m_Direction == Direction::Down;
}

void Snake::SwitchDirection(Direction newDirection) {
	if (!CanSwitchDirection(newDirection))
		return;

	if (newDirection == Direction::Up) {
		m_Head->GetTransform()->RotateBy(m_Direction == Direction::Left ? -90.0f : 90.0f, glm::vec3(0, 0, 1));
		m_Head->GetTransform()->TranslateBy(glm::vec3(0, 1, 0));
	}
	else if (newDirection == Direction::Down) {
		m_Head->GetTransform()->RotateBy(m_Direction == Direction::Left ? 90.0f : -90.0f, glm::vec3(0, 0, 1));
		m_Head->GetTransform()->TranslateBy(glm::vec3(0, 1, 0));
	}
	else if (newDirection == Direction::Left) {
		m_Head->GetTransform()->RotateBy(m_Direction == Direction::Up ? 90.0f : -90.0f, glm::vec3(0, 0, 1));
		m_Head->GetTransform()->TranslateBy(glm::vec3(0, 1, 0));
	}
	else if (newDirection == Direction::Right) {
		m_Head->GetTransform()->RotateBy(m_Direction == Direction::Up ? -90.0f : 90.0f, glm::vec3(0, 0, 1));
		m_Head->GetTransform()->TranslateBy(glm::vec3(0, 1, 0));
	}

	m_Direction = newDirection;
}