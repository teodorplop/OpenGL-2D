#include "Input.h"

Window* Input::s_Window = NULL;
float Input::s_Scroll;
glm::vec2 Input::s_MousePosition;

int Input::s_KeysCount = 512;
bool* Input::s_KeysDown = new bool[Input::s_KeysCount];
bool* Input::s_Keys = new bool[Input::s_KeysCount];
bool* Input::s_KeysUp = new bool[Input::s_KeysCount];

int Input::s_MouseButtonsCount = 3;
bool* Input::s_MouseButtonsDown = new bool[Input::s_MouseButtonsCount];
bool* Input::s_MouseButtons = new bool[Input::s_MouseButtonsCount];
bool* Input::s_MouseButtonsUp = new bool[Input::s_MouseButtonsCount];

void Input::Handle(Window* window) {
	if (Input::s_Window != NULL) {
		// If we have been handling input for some window, make sure we clear that.
		glfwSetScrollCallback(s_Window->GetGLFWWindow(), NULL);
		glfwSetCursorPosCallback(s_Window->GetGLFWWindow(), NULL);
		glfwSetMouseButtonCallback(s_Window->GetGLFWWindow(), NULL);
		glfwSetKeyCallback(s_Window->GetGLFWWindow(), NULL);

		s_Window = NULL;
	}

	s_Window = window;
	GLFWwindow *glWindow = window->GetGLFWWindow();

	// Make sure we clear input when changing windows
	s_Scroll = 0.0f;
	for (int i = 0; i < s_KeysCount; ++i) {
		s_KeysDown[i] = s_Keys[i] = s_KeysUp[i] = false;
	}
	for (int i = 0; i < s_MouseButtonsCount; ++i) {
		s_MouseButtonsDown[i] = s_MouseButtons[i] = s_MouseButtonsUp[i] = false;
	}

	glfwSetScrollCallback(glWindow, ScrollCallback);
	glfwSetCursorPosCallback(glWindow, CursorPositionCallback);
	glfwSetMouseButtonCallback(glWindow, MouseButtonCallback);
	glfwSetKeyCallback(glWindow, KeyCallback);
}
void Input::EndOfFrame() {
	// We are safe to clear there at the end of a frame.
	s_Scroll = 0.0f;
	for (int i = 0; i < s_KeysCount; ++i) {
		s_KeysDown[i] = s_KeysUp[i] = false;
	}
	for (int i = 0; i < s_MouseButtonsCount; ++i) {
		s_MouseButtonsDown[i] = s_MouseButtonsUp[i] = false;
	}
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == 0 && s_Keys[key]) {
		s_Keys[key] = s_KeysDown[key] = false;
		s_KeysUp[key] = true;
	} else if (action == 1) {
		s_Keys[key] = s_KeysDown[key] = true;
	}
}
bool Input::GetKeyDown(int key) {
	return s_KeysDown[key];
}
bool Input::GetKey(int key) {
	return s_Keys[key];
}
bool Input::GetKeyUp(int key) {
	return s_KeysUp[key];
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (action == 0) {
		s_MouseButtons[button] = s_MouseButtonsDown[button] = false;
		s_MouseButtonsUp[button] = true;
	}
	else if (action == 1) {
		s_MouseButtons[button] = s_MouseButtonsDown[button] = true;
	}
}
bool Input::GetMouseButtonDown(int button) {
	return s_MouseButtonsDown[button];
}
bool Input::GetMouseButton(int button) {
	return s_MouseButtons[button];
}
bool Input::GetMouseButtonUp(int button) {
	return s_MouseButtonsUp[button];
}

void Input::ScrollCallback(GLFWwindow* window, double xOffSet, double yOffSet) {
	s_Scroll = (float)yOffSet;
}
float Input::GetScrollWheel() {
	return s_Scroll;
}

void Input::CursorPositionCallback(GLFWwindow* window, double x, double y) {
	s_MousePosition.x = (float)x, s_MousePosition.y = (float)y;
}
glm::vec2 Input::GetMousePosition() {
	return s_MousePosition;
}