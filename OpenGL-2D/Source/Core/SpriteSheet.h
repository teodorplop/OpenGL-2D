#pragma once

#include "Sprite.h"

class SpriteSheet : public Sprite {
private:
	int m_SpritesPerRow, m_SpritesPerColumn;
	int m_NoSprites;

public:
	SpriteSheet(Texture* texture, int spritesPerRow, int spritesPerColumn, int noSprites);

	void SetSprite(int index);
	void SetSprite(int row, int column);

	Transform* GetTransform() override;

	int GetSpritesPerRow();
	int GetSpritesPerColumn();
	int GetSpritesCount();
};