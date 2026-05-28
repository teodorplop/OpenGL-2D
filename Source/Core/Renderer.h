#pragma once

#include "Camera.h"
#include "IRenderable.h"
#include <unordered_set>

/// <summary>
/// Responsible for rendering all IRenderable objects
/// </summary>
class Renderer {
private:
	static std::unordered_set<IRenderable*> s_Renderables;

public:
	/// <summary>
	/// Registers an IRenderable object for drawing
	/// </summary>
	static void Register(IRenderable* renderable);

	/// <summary>
	/// Removes an IRenderable object from being drawn
	/// </summary>
	static void Unregister(IRenderable* renderable);

	/// <summary>
	/// Initial OpenGL Setup
	/// </summary>
	static void Setup();

	/// <summary>
	/// Renders all IRenderable objects, from the perspective of a given camera
	/// </summary>
	static void Render(Camera* camera);
};