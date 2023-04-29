#pragma once

#include <include\glm.h>

// Responsible for transformation on all IRenderable objects
class Transform {
private:
	glm::vec3 m_Position, m_Rotation, m_Scale;
	glm::mat4 m_Matrix;

public:
	Transform();
	~Transform();

	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();
	glm::mat4 GetMatrix();

	void TranslateTo(const glm::vec3& position);
	void ScaleTo(const glm::vec3& scale);
	void RotateTo(const glm::vec3& rotation);

	void TranslateBy(const glm::vec3& distance);
	void ScaleBy(const glm::vec3& scale);
	void RotateBy(float angle, const glm::vec3& axis);
};