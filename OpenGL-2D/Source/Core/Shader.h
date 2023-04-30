#pragma once

#include <include\gl.h>
#include <include\glm.h>

/// <summary>
/// Responsible for compiling, binding and sending uniforms to shaders.
/// </summary>
class Shader {
private:
	static const std::string K_SHADERS_PATH;

	GLuint m_VertexShader, m_FragmentShader, m_GeometryShader, m_ShaderProgram;

	void CompileShaders(const char* vertexSource, const char* fragmentSource);
	GLuint Compile(GLuint type, const char* source);

public:
	Shader(const std::string& vertexFile, const std::string& fragmentFile);
	~Shader();

	/// <summary>
	/// Binds the shader to GPU
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the shader from GPU
	/// </summary>
	void Unbind();

	void SetUniformMatrix4fv(const char* name, const glm::mat4& matrix);
	void SetUniform1f(const char* name, const float& value);
	void SetUniform2f(const char* name, const glm::vec2& vector);
	void SetUniform3f(const char* name, const glm::vec3& vector);
	void SetUniform4f(const char* name, const glm::vec4& vector);
	void SetUniform1i(const char* name, const int& value);
};