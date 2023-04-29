#include "SpriteSheet.h"

// TODO: Memory leaks here

Shader* GetSpriteSheetDefaultShader() {
	return new Shader("SpriteSheet.vert", "SpriteSheet.frag");
}

Material* GetSpriteSheetDefaultMaterial() {
	return new Material(GetSpriteSheetDefaultShader());
}

SpriteSheet::SpriteSheet(Texture* texture, int spritesPerRow, int spritesPerColumn, int noSprites) : Sprite(texture, GetSpriteSheetDefaultMaterial()) {
	m_SpritesPerRow = spritesPerRow;
	m_SpritesPerColumn = spritesPerColumn;

	m_NoSprites = noSprites;

	m_Material->SetProperty("_SpriteIndex", 0);
	m_Material->SetProperty("_SpritesPerRow", m_SpritesPerRow);
	m_Material->SetProperty("_SpritesPerColumn", m_SpritesPerColumn);
}

void SpriteSheet::SetSprite(int index) {
	m_Material->SetProperty("_SpriteIndex", index);
}

void SpriteSheet::SetSprite(int row, int column) {
	m_Material->SetProperty("_SpriteIndex", row * m_SpritesPerRow + column);
}

Transform* SpriteSheet::GetTransform() {
	if (m_PreserveAspectRatio) {
		float textureAspectRatio = ((float)m_Texture->GetWidth() / m_SpritesPerRow) / ((float)m_Texture->GetHeight() / m_SpritesPerColumn);
		float transformAspectRatio = m_Transform->GetScale().x / m_Transform->GetScale().y;

		m_Transform->ScaleBy(glm::vec3(glm::min(1.0f, textureAspectRatio / transformAspectRatio), glm::min(1.0f, transformAspectRatio / textureAspectRatio), 1));
	}

	return m_Transform;
}

int SpriteSheet::GetSpritesPerRow() {
	return m_SpritesPerRow;
}
int SpriteSheet::GetSpritesPerColumn() {
	return m_SpritesPerColumn;
}
int SpriteSheet::GetSpritesCount() {
	return m_NoSprites;
}