#pragma once

#include "Window.h"
#include <include\glm.h>
#include <unordered_map>

class Input {
private:
	static Window* s_Window;

	static float s_Scroll;
	static glm::vec2 s_MousePosition;

	static int s_KeysCount;
	static bool* s_KeysDown;
	static bool* s_Keys;
	static bool* s_KeysUp;

	static int s_MouseButtonsCount;
	static bool* s_MouseButtonsDown;
	static bool* s_MouseButtons;
	static bool* s_MouseButtonsUp;

	static void ScrollCallback(GLFWwindow* window, double xOffSet, double yOffSet);
	static void CursorPositionCallback(GLFWwindow* window, double x, double y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
	// Sets the window we want to handle input for
	static void Handle(Window* window);
	// Clear stuff at the end of frame
	static void EndOfFrame();

	// Returns true if we pressed the key THIS FRAME
	static bool GetKeyDown(int key);
	// Returns true if the key is pressed
	static bool GetKey(int key);
	// Returns true if we released the key THIS FRAME
	static bool GetKeyUp(int key);

	// Same, but for mouse buttons
	static bool GetMouseButtonDown(int button);
	static bool GetMouseButton(int button);
	static bool GetMouseButtonUp(int button);

	static float GetScrollWheel();
	// Returns mouse position in screen coordinates
	static glm::vec2 GetMousePosition();
};
