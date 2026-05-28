#include "Window.h"

#include <cstdio>

Window::Window(const char* title, int width, int height) {
	m_Title = title, m_Width = width, m_Height = height;
	Init();
}

bool Window::Init() {
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window) {
		fprintf(stderr, "Failed to create GLFW window!");
		return false;
	}

	// Center window - because why not?
	GLFWvidmode *mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(m_Window, (mode->width - m_Width) / 2, (mode->height - m_Height) / 2);

	glfwMakeContextCurrent(m_Window);
	return true;
}

void Window::PollEvents() {
	glfwPollEvents();
}

void Window::SwapBuffers() {
	glfwSwapBuffers(m_Window);
}

bool Window::ShouldBeClosed() {
	return glfwWindowShouldClose(m_Window) == 1 ? true : false;
}

int Window::GetWidth() {
	return m_Width;
}
int Window::GetHeight() {
	return m_Height;
}
GLFWwindow* Window::GetGLFWWindow() {
	return m_Window;
}