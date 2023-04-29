#include "SpriteSheetAnimation.h"

SpriteSheetAnimation::SpriteSheetAnimation(SpriteSheet* spriteSheet) : SpriteSheetAnimation(spriteSheet, 1) {}

SpriteSheetAnimation::SpriteSheetAnimation(SpriteSheet* spriteSheet, float framesPerSecond) {
	m_SpriteSheet = spriteSheet;
	m_FramesPerSecond = 1;

	m_Timer = 1.0f / framesPerSecond;
	m_SpriteIndex = 0;
	m_SpriteSheet->SetSprite(m_SpriteIndex);
	m_IsPlaying = false;
}

void SpriteSheetAnimation::SetTicksPerSecond(float framesPerSecond) {
	m_FramesPerSecond = framesPerSecond;
}

float SpriteSheetAnimation::GetTicksPerSecond() {
	return m_FramesPerSecond;
}

void SpriteSheetAnimation::Tick(float deltaTime) {
	if (!m_IsPlaying) 
		return;

	m_Timer -= deltaTime;
	if (m_Timer <= 0) {
		m_SpriteIndex = (m_SpriteIndex + 1) % m_SpriteSheet->GetSpritesCount();
		m_SpriteSheet->SetSprite(m_SpriteIndex);

		m_Timer += 1.0f / m_FramesPerSecond;
	}
}

void SpriteSheetAnimation::Start() {
	if (m_IsPlaying)
		return;

	m_Timer = 1.0f / m_FramesPerSecond;
	Rewind();

	m_IsPlaying = true;
}
void SpriteSheetAnimation::Pause() {
	m_IsPlaying = false;
}
void SpriteSheetAnimation::Rewind() {
	m_SpriteIndex = 0;
	m_SpriteSheet->SetSprite(m_SpriteIndex);
}
void SpriteSheetAnimation::Stop() {
	Rewind();
	m_IsPlaying = false;
}