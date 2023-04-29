#pragma once

#include "Camera.h"
#include "Window.h"

class Engine {
private:
	Window* m_Window;
	Camera* m_Camera;
	float m_DesiredDeltaTime;

public:
	Engine();
	~Engine();

	Camera* GetCamera();

	// function which does the whole thing
	void Run();
};