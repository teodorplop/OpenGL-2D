#pragma once

#include "Texture.h"
#include "Shader.h"

#include <include\glm.h>
#include <unordered_map>

/// <summary>
/// Holds and sets properties to a given shader, when rendering
/// </summary>
class Material {
private:
	Shader* m_Shader;

	std::unordered_map<std::string, int> m_IntProperties;
	std::unordered_map<std::string, float> m_FloatProperties;
	std::unordered_map<std::string, glm::vec2> m_Vec2Properties;
	std::unordered_map<std::string, Texture*> m_TextureProperties;

public:
	Material(Shader* shader);

	/// <summary>
	/// Underlying shader
	/// </summary>
	Shader* GetShader();

	void SetProperty(std::string name, int value);
	void SetProperty(std::string name, float value);
	void SetProperty(std::string name, glm::vec2 value);
	void SetProperty(std::string name, Texture* value);

	/// <summary>
	/// Binds the shader to GPU and sets all properties
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the shader from GPU
	/// </summary>
	void Unbind();
};