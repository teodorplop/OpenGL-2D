#pragma once

#include "../Engine.h"
#include "Direction.h"

class SnakePart {
private:
	enum Type { Head, Body, Curve, Tail };

	Texture* m_HeadTexture;
	Texture* m_BodyTexture;
	Texture* m_CurveTexture;
	Texture* m_TailTexture;
	Sprite* m_Sprite;

	Direction m_Direction;

	SnakePart* m_PreviousPart;
	SnakePart* m_NextPart;
	Type m_Type;

	void SetType(Type type);

	glm::vec3 GetMovementDelta(float deltaTime);

public:
	SnakePart(Texture* head, Texture* body, Texture* curve, Texture* tail);
	~SnakePart();

	void SetPrevious(SnakePart* snakePart);
	void SetNext(SnakePart* snakePart);

	Direction GetDirection();
	void SetDirection(Direction direction);

	void Move(float deltaTime);
	void UpdateGraphic();

	Transform* GetTransform();
};