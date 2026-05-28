#include "Material.h"

using namespace std;

Material::Material(Shader* shader) {
	m_Shader = shader;
}

Shader* Material::GetShader() {
	return m_Shader;
}

void Material::SetProperty(string name, int value) {
	m_IntProperties[name] = value;
}

void Material::SetProperty(string name, float value) {
	m_FloatProperties[name] = value;
}

void Material::SetProperty(string name, glm::vec2 value) {
	m_Vec2Properties[name] = value;
}

void Material::SetProperty(string name, Texture* value) {
	m_TextureProperties[name] = value;
}

void Material::Bind() {
	m_Shader->Bind();

	for (auto prop : m_IntProperties) {
		m_Shader->SetUniform1i(prop.first.c_str(), prop.second);
	}
	for (auto prop : m_FloatProperties) {
		m_Shader->SetUniform1f(prop.first.c_str(), prop.second);
	}
	for (auto prop : m_Vec2Properties) {
		m_Shader->SetUniform2f(prop.first.c_str(), prop.second);
	}

	int textureIndex = 0;
	for (auto prop : m_TextureProperties) {
		m_Shader->SetUniform1i(prop.first.c_str(), textureIndex);
		prop.second->Bind(textureIndex);

		++textureIndex;
	}
}

void Material::Unbind() {
	for (auto prop : m_TextureProperties)
		prop.second->Unbind();

	m_Shader->Unbind();
}