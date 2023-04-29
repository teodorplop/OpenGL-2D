#pragma once

#include <include\glm.h>

// Orthographic only, for 2D
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

	glm::mat4 GetProjectionMatrix();
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

	glm::vec3 GetClearColor();
	void SetClearColor(glm::vec3 color);
};