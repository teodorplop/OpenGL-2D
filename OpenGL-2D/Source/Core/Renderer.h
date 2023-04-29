#pragma once

#include "Camera.h"
#include "IRenderable.h"
#include <unordered_set>

// Class responsible for rendering all IRenderable objects
class Renderer {
private:
	static std::unordered_set<IRenderable*> s_Renderables;

public:
	static void Register(IRenderable* renderable);
	static void Unregister(IRenderable* renderable);

	static void Setup();
	static void Render(Camera* camera);
};