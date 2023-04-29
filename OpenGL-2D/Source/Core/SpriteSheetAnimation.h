#pragma once

#include "SpriteSheet.h"
#include "ITickable.h"

class SpriteSheetAnimation : ITickable {
private:
	SpriteSheet* m_SpriteSheet;
	float m_FramesPerSecond;

	bool m_IsPlaying;
	int m_SpriteIndex;
	float m_Timer;

protected:
	void Tick(float deltaTime) override;

public:
	SpriteSheetAnimation(SpriteSheet* spriteSheet, float framesPerSecond);
	SpriteSheetAnimation(SpriteSheet* spriteSheet);

	float GetTicksPerSecond();
	void SetTicksPerSecond(float ticksPerSecond);

	void Start();
	void Pause();
	void Rewind();
	void Stop();
};
