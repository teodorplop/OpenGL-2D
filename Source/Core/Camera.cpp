#include "Camera.h"

#include "Engine.h"

Camera::Camera(float aspectRatio, float orthographicSize, float nearClip, float farClip) {
	m_OrthographicSize = orthographicSize;
	m_AspectRatio = aspectRatio;
	m_NearClip = nearClip;
	m_FarClip = farClip;
	UpdateProjection();

	m_Position = glm::vec3(0, 0, 0);
	m_Front = glm::vec3(0, 0, -1);
	m_Up = glm::vec3(0, 1, 0);
	UpdateView();
}

void Camera::UpdateProjection() {
	float left, right, bottom, top;
	left = -m_OrthographicSize * m_AspectRatio;
	right = m_OrthographicSize * m_AspectRatio;
	bottom = -m_OrthographicSize;
	top = m_OrthographicSize;

	m_ProjectionMatrix = glm::ortho(left, right, bottom, top, m_NearClip, m_FarClip);
}
void Camera::UpdateView() {
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Camera::GetProjectionMatrix() {
	return m_ProjectionMatrix;
}
glm::mat4 Camera::GetViewMatrix() {
	return m_ViewMatrix;
}

// getters
glm::vec3 Camera::GetPosition() {
	return m_Position;
}
float Camera::GetOrthographicSize() {
	return m_OrthographicSize;
}
float Camera::GetAspectRatio() {
	return m_AspectRatio;
}
float Camera::GetNearClip() {
	return m_NearClip;
}
float Camera::GetFarClip() {
	return m_FarClip;
}
glm::vec3 Camera::GetClearColor() {
	return m_ClearColor;
}

// setters
void Camera::SetPosition(glm::vec3 position) {
	m_Position = position;
	UpdateView();
}
void Camera::SetOrthographicSize(float orthographicSize) {
	m_OrthographicSize = orthographicSize;
	UpdateProjection();
}
void Camera::SetAspectRatio(float aspectRatio) {
	m_AspectRatio = aspectRatio;
	UpdateProjection();
}
void Camera::SetNearClip(float nearClip) {
	m_NearClip = nearClip;
	UpdateProjection();
}
void Camera::SetFarClip(float farClip) {
	m_FarClip = farClip;
	UpdateProjection();
}
void Camera::SetClearColor(glm::vec3 color) {
	m_ClearColor = color;
}