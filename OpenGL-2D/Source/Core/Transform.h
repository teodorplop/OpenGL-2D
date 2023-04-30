#pragma once

#include <include\glm.h>

/// <summary>
/// Holds information about an object position, rotation and scale
/// </summary>
class Transform {
private:
	glm::vec3 m_Position, m_Rotation, m_Scale;

	glm::mat4 m_TranslationMatrix, m_RotationMatrix, m_ScaleMatrix;
	glm::mat4 m_Matrix;

	void RecomputeMatrix();

public:
	Transform();
	~Transform();

	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

	/// <summary>
	/// Transformation matrix, based on translation, scale and rotation
	/// </summary>
	glm::mat4 GetMatrix();

	/// <summary>
	/// Translates the object by a given distance
	/// </summary>
	void TranslateBy(const glm::vec3& distance);

	/// <summary>
	/// Scales by a certain amount on each axis
	/// </summary>
	void ScaleBy(const glm::vec3& scale);

	/// <summary>
	/// Rotates by a certain amount on one axis
	/// </summary>
	void RotateBy(float angle, const glm::vec3& axis);
};