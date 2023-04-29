#include "Engine.h"

#include <iostream>
#include <include\gl.h>

#include "Input.h"
#include "Time.h"
#include "TickEngine.h"
#include "Renderer.h"
#include "Settings.h"
#include "Logger.h"

Engine::Engine() {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize glfw.");
		Sleep(2000);
		exit(0);
	}

	std::string windowName = Settings::GetString("WINDOW_NAME", "OpenGL-2D");
	int width = Settings::GetInt("WINDOW_WIDTH", 1024);
	int height = Settings::GetInt("WINDOW_HEIGHT", 768);
	int targetFrameRate = Settings::GetInt("TARGET_FRAMERATE", 60);

	m_Camera = new Camera((float)width / height);
	m_Window = new Window(windowName.c_str(), width, height);
	m_DesiredDeltaTime = 1.0f / targetFrameRate;

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Failed to initialize glew. Error: %s\n", glewGetErrorString(err));
		Sleep(2000);
		exit(0);
	}
}

Engine::~Engine() {
	delete m_Camera;
	delete m_Window;
	glfwTerminate();
}

Camera* Engine::GetCamera() { 
	return m_Camera; 
}

void Engine::Run() {
	Input::Handle(m_Window);
	Renderer::Setup();

	while (!m_Window->ShouldBeClosed()) {
		float time = (float)glfwGetTime();
		if (time - Time::s_LastUpdate < m_DesiredDeltaTime) {
			// Update only if we reached our desired delta time
			continue;
		}

		// First update the time
		Time::Tick((float)glfwGetTime());
		// Then we update each registered object
		TickEngine::Tick(Time::DeltaTime());

		// Render all registered renderables using this camera
		Renderer::Render(m_Camera);

		// Input needs to know when the frame ends, in order to clear its stuff
		Input::EndOfFrame();

		m_Window->PollEvents();
		m_Window->SwapBuffers();
	}
}