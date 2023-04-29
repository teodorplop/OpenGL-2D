#pragma once

#include "../Engine.h"

class SnakeGame {
private:
	Snake* m_Snake;

public:
	SnakeGame(Camera* camera);
	~SnakeGame();
};