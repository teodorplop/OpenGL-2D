#include "AnimationsExample.h"

AnimationsExample::AnimationsExample(Camera* camera) {
	// background color
	camera->SetClearColor(glm::vec3(0.815f, 0.925f, 0.992f));
	// adjust camera size
	camera->SetOrthographicSize(5);
	// push camera back
	camera->SetPosition(glm::vec3(0, 0, 10));

	// Create bird
	Texture* birdTexture = new Texture("bird.png");

	SpriteSheet* birdSpriteSheet = new SpriteSheet(birdTexture, 5, 3, 14);
	birdSpriteSheet->SetPreserveAspectRatio(true);

	SpriteSheetAnimation* birdAnimation = new SpriteSheetAnimation(birdSpriteSheet);
	birdAnimation->SetFramesPerSecond(20);
	birdAnimation->Start();

	// Create cat
	Texture* catTexture = new Texture("cat.png");

	SpriteSheet* catSpriteSheet = new SpriteSheet(catTexture, 4, 2, 8);
	catSpriteSheet->SetPreserveAspectRatio(true);
	catSpriteSheet->GetTransform()->TranslateBy(glm::vec3(2, 0, 0));

	SpriteSheetAnimation* catAnimation = new SpriteSheetAnimation(catSpriteSheet);
	catAnimation->SetFramesPerSecond(5);
	catAnimation->Start();
}
