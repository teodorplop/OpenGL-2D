#pragma once

#include "Texture.h"
#include "Shader.h"

#include <include\glm.h>
#include <unordered_map>

// Class which holds properties (uniforms) that need to be passed into the shader
// maybe add a templates here?
class Material {
private:
	Shader* m_Shader;

	std::unordered_map<std::string, int> m_IntProperties;
	std::unordered_map<std::string, float> m_FloatProperties;
	std::unordered_map<std::string, glm::vec2> m_Vec2Properties;
	std::unordered_map<std::string, Texture*> m_TextureProperties;

public:
	Material(Shader* shader);

	Shader* GetShader();

	void SetProperty(std::string name, int value);
	void SetProperty(std::string name, float value);
	void SetProperty(std::string name, glm::vec2 value);
	void SetProperty(std::string name, Texture* value);

	void Bind();
	void Unbind();
};