#pragma once

#include "../Engine.h"

class Snake : public ITickable {
private:
	Texture* m_HeadTexture;
	Texture* m_BodyTexture;
	Texture* m_BodyCurveTexture;
	Texture* m_TailTexture;

	Sprite* m_Head;
	std::vector<Sprite*> m_Body;
	Sprite* m_Tail;

protected:
	void Tick(float deltaTime) override;

public:
	Snake();
	~Snake();
};