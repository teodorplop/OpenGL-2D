#pragma once

#include <include\glm.h>

/// <summary>
/// Responsible for holding information about the viewer of the scene
/// </summary>
class Camera {
private:
	float m_AspectRatio, m_NearClip, m_FarClip;
	float m_OrthographicSize;

	glm::vec3 m_Position;
	glm::vec3 m_Front, m_Up;

	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewMatrix;

	glm::vec3 m_ClearColor;

	void UpdateProjection();
	void UpdateView();

public:
	Camera(float aspectRatio, float orthographicSize = 10.0f, float nearClip = 0.1f, float farClip = 100.0f);

	/// <summary>
	/// Projection matrix, used for rendering
	/// </summary>
	glm::mat4 GetProjectionMatrix();

	/// <summary>
	/// View matrix, used for rendering
	/// </summary>
	glm::mat4 GetViewMatrix();

	void SetPosition(glm::vec3 position);
	glm::vec3 GetPosition();

	float GetOrthographicSize();
	void SetOrthographicSize(float orthographicSize);
	float GetAspectRatio();
	void SetAspectRatio(float aspectRatio);
	float GetNearClip();
	void SetNearClip(float nearClip);
	float GetFarClip();
	void SetFarClip(float farClip);

	/// <summary>
	/// What background color does this camera have?
	/// </summary>
	glm::vec3 GetClearColor();
	/// <summary>
	/// Sets the background color of the camera
	/// </summary>
	void SetClearColor(glm::vec3 color);
};