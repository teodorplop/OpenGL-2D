#pragma once

#include "../Engine.h"

class Snake : public ITickable {
private:
	enum Direction {Up, Down, Left, Right};

	Texture* m_HeadTexture;
	Texture* m_BodyTexture;
	Texture* m_BodyCurveTexture;
	Texture* m_TailTexture;

	Direction m_Direction;

	Sprite* m_Head;
	std::vector<Sprite*> m_Body;
	Sprite* m_Tail;

	bool WasSwitchDrectionRequested(Direction& newDirection);
	bool CanSwitchDirection(Direction newDirection);
	void SwitchDirection(Direction newDirection);

protected:
	void Tick(float deltaTime) override;

public:
	Snake();
	~Snake();
};