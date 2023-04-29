#include "Core\Engine.h"
#include "Game\Examples\AnimationsExample.h"
#include "Game\Snake\SnakeGame.h"

int main(int argc, char** argv) {
	Engine* engine = new Engine();
	AnimationsExample* animationsExample = new AnimationsExample(engine->GetCamera());
	SnakeGame* snakeGame = new SnakeGame(engine->GetCamera());

	engine->Run();

	delete animationsExample;
	delete snakeGame;
	delete engine;
}
