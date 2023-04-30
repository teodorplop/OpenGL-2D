#include "Transform.h"

Transform::Transform() {
	m_Position = m_Rotation = glm::vec3();
	m_Scale = glm::vec3(1.0f);
	m_Matrix = glm::mat4(1.0f);
}

Transform::~Transform() {
}

glm::vec3 Transform::GetPosition() {
	return m_Position;
}
glm::vec3 Transform::GetRotation() {
	return m_Rotation;
}
glm::vec3 Transform::GetScale() {
	return m_Scale;
}
glm::mat4 Transform::GetMatrix() {
	return m_Matrix;
}

void Transform::TranslateBy(const glm::vec3& distance) {
	m_Matrix = glm::translate(m_Matrix, distance);
	m_Position += distance;
}

void Transform::ScaleBy(const glm::vec3& scale) {
	m_Matrix = glm::scale(m_Matrix, scale);
	m_Scale *= scale;
}

void Transform::RotateBy(float angle, const glm::vec3& axis) {
	m_Matrix = glm::rotate(m_Matrix, glm::radians(angle), axis);

	m_Rotation += axis * angle;
	m_Rotation.x = fmod(m_Rotation.x + 360.0f, 360.0f);
	m_Rotation.y = fmod(m_Rotation.y + 360.0f, 360.0f);
	m_Rotation.z = fmod(m_Rotation.z + 360.0f, 360.0f);
}