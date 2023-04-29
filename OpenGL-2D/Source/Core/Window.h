#pragma once

#include <include\gl.h>

// Simple window class, contains a title, width and height.
class Window {
private:
	const char* m_Title;
	int m_Width, m_Height;
	GLFWwindow* m_Window;

	bool Init();

public:
	Window(const char* title, int width, int height);

	// Returns true if we received a close window action
	bool ShouldBeClosed();

	// Things used for rendering
	void PollEvents();
	void SwapBuffers();

	int GetWidth();
	int GetHeight();
	GLFWwindow* GetGLFWWindow();
};

