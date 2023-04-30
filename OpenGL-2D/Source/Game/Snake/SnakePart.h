#pragma once

#include "../Engine.h"

class SnakePart {
public:	
	enum Type { Head, Body, Curve, Tail };

private:
	Sprite* m_Sprite;
	Type m_Type;

public:
	SnakePart(Type type);

	void SetType(Type type);
	Type GetType();

	Transform* GetTransform();
};