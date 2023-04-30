#include "SnakeGame.h"

#include "Snake.h"

SnakeGame::SnakeGame(Camera* camera) {
	// background color
	camera->SetClearColor(glm::vec3(0.815f, 0.925f, 0.992f));
	// adjust camera size
	camera->SetOrthographicSize(10);
	// push camera back
	camera->SetPosition(glm::vec3(0, 0, 10));

	m_Snake = new Snake();
}

SnakeGame::~SnakeGame() {
	delete m_Snake;
}