#pragma once

#include "../Engine.h"

class SnakePart {
public:	
	enum Type { Head, Body, Curve, Tail };

private:
	Texture* m_HeadTexture;
	Texture* m_BodyTexture;
	Texture* m_CurveTexture;
	Texture* m_TailTexture;
	Sprite* m_Sprite;

	Type m_Type;

public:
	SnakePart(Texture* head, Texture* body, Texture* curve, Texture* tail);

	void SetType(Type type);
	Type GetType();

	Transform* GetTransform();
};