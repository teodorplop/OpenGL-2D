#pragma once

#include "Sprite.h"

/// <summary>
/// Used to display a certain Texture from a sheet with multiple textures (matrix of textures)
/// </summary>
class SpriteSheet : public Sprite {
private:
	int m_SpritesPerRow, m_SpritesPerColumn;
	int m_NoSprites;

public:
	SpriteSheet(Texture* texture, int spritesPerRow, int spritesPerColumn, int noSprites);

	/// <summary>
	/// Sets the index of the texture to be displayed, starting from the top left corner
	/// </summary>
	void SetSprite(int index);

	/// <summary>
	/// Sets the exact row and column of the texture to be displayed
	/// </summary>
	void SetSprite(int row, int column);

	Transform* GetTransform() override;

	/// <summary>
	/// Number of sprites per each row
	/// </summary>
	int GetSpritesPerRow();

	/// <summary>
	/// Number of sprites per each column
	/// </summary>
	int GetSpritesPerColumn();

	/// <summary>
	/// Number of sprites in the sheet
	/// </summary>
	int GetSpritesCount();
};