#pragma once

#include "../Engine.h"
#include "SnakePart.h"

class Snake : public ITickable {
private:
	enum Direction {Up, Down, Left, Right};

	Texture* m_HeadTexture;
	Texture* m_BodyTexture;
	Texture* m_CurveTexture;
	Texture* m_TailTexture;

	Direction m_Direction;
	bool m_HasRequestedNewDirection;
	Direction m_NewDirection;

	float m_Speed;
	float m_Timer;

	std::vector<SnakePart*> m_Body;

	bool WasSwitchDirectionRequested(Direction& newDirection);
	bool CanSwitchDirection(Direction newDirection);

	bool SwitchDirection();
	void Move(float deltaTime);

	void BodyFollow();
	void RemoveCurve();

protected:
	void Tick(float deltaTime) override;

public:
	Snake();
	~Snake();
};