#pragma once

#include "../Engine.h"
#include "SnakePart.h"
#include "Direction.h"

class Snake : public ITickable {
private:
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

	void CreateParts(int length);
	SnakePart* CreatePart();

	bool WasSwitchDirectionRequested(Direction& newDirection);
	bool CanSwitchDirection(Direction newDirection);

	void Move(float deltaTime);

protected:
	void Tick(float deltaTime) override;

public:
	Snake(int length, float speed);
	~Snake();
};