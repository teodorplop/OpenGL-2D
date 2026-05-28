#pragma once

#include "SpriteSheet.h"
#include "ITickable.h"

/// <summary>
/// Sprite animation using SpriteSheet object
/// </summary>
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

	/// <summary>
	/// How many frames does the animation have per each second
	/// </summary>
	float GetFramesPerSecond();

	/// <summary>
	/// Set the number of frames the animation plays per second
	/// </summary>
	void SetFramesPerSecond(float framesPerSecond);

	/// <summary>
	/// Starts the animation. Does nothing if it already started.
	/// </summary>
	void Start();

	/// <summary>
	/// Pauses the animation.
	/// </summary>
	void Pause();

	/// <summary>
	/// Rewinds the animation to the first frame. Does not pause, nor start it.
	/// </summary>
	void Rewind();

	/// <summary>
	/// Pauses the animation and rewinds to the first frame.
	/// </summary>
	void Stop();
};
