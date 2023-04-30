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
	m_Position += distance;

	m_TranslationMatrix = glm::translate(m_TranslationMatrix, distance);
	RecomputeMatrix();
}

void Transform::ScaleBy(const glm::vec3& scale) {
	m_Scale *= scale;

	m_ScaleMatrix = glm::scale(m_ScaleMatrix, scale);
	RecomputeMatrix();
}

void Transform::RotateBy(float angle, const glm::vec3& axis) {
	m_Rotation += axis * angle;
	m_Rotation.x = fmod(m_Rotation.x + 360.0f, 360.0f);
	m_Rotation.y = fmod(m_Rotation.y + 360.0f, 360.0f);
	m_Rotation.z = fmod(m_Rotation.z + 360.0f, 360.0f);

	m_RotationMatrix = glm::rotate(m_RotationMatrix, glm::radians(angle), axis);
	RecomputeMatrix();
}

void Transform::RecomputeMatrix() {
	m_Matrix = m_TranslationMatrix * m_RotationMatrix * m_ScaleMatrix;
}