#pragma once

#include <include\gl.h>

/// <summary>
/// OpenGL Window Wrapper Class
/// </summary>
class Window {
private:
	const char* m_Title;
	int m_Width, m_Height;
	GLFWwindow* m_Window;

	bool Init();

public:
	/// <summary>
	/// Creates a new Window, with title and resolution
	/// </summary>
	Window(const char* title, int width, int height);

	/// <summary>
	/// Returns whether there has been a request to close the window
	/// </summary>
	bool ShouldBeClosed();

	/// <summary>
	/// Polls input events
	/// </summary>
	void PollEvents();

	/// <summary>
	/// Swaps front and back buffers on the window
	/// </summary>
	void SwapBuffers();

	/// <summary>
	/// Width of the window, in pixels
	/// </summary>
	int GetWidth();

	/// <summary>
	/// Height of the window, in pixels
	/// </summary>
	int GetHeight();

	/// <summary>
	/// GLFW Window, which is wrapped inside this object
	/// </summary>
	GLFWwindow* GetGLFWWindow();
};

