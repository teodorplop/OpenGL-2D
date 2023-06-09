#include "SnakeGame.h"

#include "Snake.h"

SnakeGame::SnakeGame(Camera* camera) {
	// background color
	camera->SetClearColor(glm::vec3(0.815f, 0.925f, 0.992f));
	// adjust camera size
	camera->SetOrthographicSize(15);
	// push camera back
	camera->SetPosition(glm::vec3(0, 0, 10));

	m_Snake = new Snake(Settings::GetInt("SNAKE_LENGTH", 4), Settings::GetFloat("SNAKE_SPEED", 3));
}

SnakeGame::~SnakeGame() {
	delete m_Snake;
}