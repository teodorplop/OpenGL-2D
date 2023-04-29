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
	if (Input::GetKeyDown(GLFW_KEY_A)) {
		m_Head->GetTransform()->TranslateBy(glm::vec3(-1, 0, 0));
	}
	else if (Input::GetKeyDown(GLFW_KEY_D)) {
		m_Head->GetTransform()->TranslateBy(glm::vec3(1, 0, 0));
	}
	else if (Input::GetKeyDown(GLFW_KEY_W)) {
		m_Head->GetTransform()->TranslateBy(glm::vec3(0, 1, 0));
	}
	else if (Input::GetKeyDown(GLFW_KEY_S)) {
		m_Head->GetTransform()->TranslateBy(glm::vec3(0, -1, 0));
	}
}