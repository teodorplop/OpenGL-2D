#pragma once

#include "Camera.h"
#include "Window.h"

/// <summary>
/// Responsible for initializing OpenGL and running the App
/// </summary>
class Engine {
private:
	Window* m_Window;
	Camera* m_Camera;
	float m_DesiredDeltaTime;

public:
	Engine();
	~Engine();

	/// <summary>
	/// Returns the camera created for rendering
	/// </summary>
	Camera* GetCamera();

	/// <summary>
	/// Do the thing!
	/// </summary>
	void Run();
};