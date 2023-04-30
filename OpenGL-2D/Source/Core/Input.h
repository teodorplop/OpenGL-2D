#pragma once

#include "Window.h"
#include <include\glm.h>
#include <unordered_map>

/// <summary>
/// Helper class, used to query input actions
/// </summary>
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
	/// <summary>
	/// Sets the window we want to handle input for
	/// </summary>
	static void Handle(Window* window);

	/// <summary>
	/// Called to clear input actions at the end of a frame
	/// </summary>
	static void EndOfFrame();

	/// <summary>
	/// Returns true if the user pressed the key THIS FRAME
	/// </summary>
	static bool GetKeyDown(int key);
	/// <summary>
	/// Returns true if the key is pressed
	/// </summary>
	static bool GetKey(int key);
	/// <summary>
	/// Returns true if the user released the key THIS FRAME
	/// </summary>
	static bool GetKeyUp(int key);

	/// <summary>
	/// Returns true if the user pressed this mouse button THIS FRAME
	/// </summary>
	static bool GetMouseButtonDown(int button);
	/// <summary>
	/// Returns true if this mouse button is pressed
	/// </summary>
	static bool GetMouseButton(int button);
	/// <summary>
	/// Returns true if the user released this mouse button THIS FRAME
	/// </summary>
	static bool GetMouseButtonUp(int button);

	/// <summary>
	/// Returns value of the scroll wheel for this frame
	/// </summary>
	static float GetScrollWheel();

	/// <summary>
	/// Returns the mouse position, in screen coordinates
	/// </summary>
	static glm::vec2 GetMousePosition();
};
