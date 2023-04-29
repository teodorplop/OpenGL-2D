#include "Shader.h"
#include "Utils/FileIO.h"

const std::string Shader::K_SHADERS_PATH = "Resources/Shaders/";

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile) {
	std::string vertexCode = FileIO::GetFileContents(K_SHADERS_PATH + vertexFile);
	const char* vertexSource = vertexCode.c_str();

	std::string fragmentCode = FileIO::GetFileContents(K_SHADERS_PATH + fragmentFile);
	const char* fragmentSource = fragmentCode.c_str();

	CompileShaders(vertexSource, fragmentSource);
}

Shader::~Shader() {
	glDeleteProgram(m_ShaderProgram);
}

void Shader::Bind() {
	glUseProgram(m_ShaderProgram);
}
void Shader::Unbind() {
	glUseProgram(0);
}

void Shader::SetUniformMatrix4fv(const char* name, const glm::mat4& matrix) {
	GLint matrixID = glGetUniformLocation(m_ShaderProgram, name);
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix[0][0]);
}
void Shader::SetUniform1f(const char* name, const float& value) {
	GLint floatID = glGetUniformLocation(m_ShaderProgram, name);
	glUniform1f(floatID, value);
}
void Shader::SetUniform2f(const char* name, const glm::vec2& vector) {
	GLint vectorID = glGetUniformLocation(m_ShaderProgram, name);
	glUniform2f(vectorID, vector.x, vector.y);
}
void Shader::SetUniform3f(const char* name, const glm::vec3& vector) {
	GLint vectorID = glGetUniformLocation(m_ShaderProgram, name);
	glUniform3f(vectorID, vector.x, vector.y, vector.z);
}
void Shader::SetUniform4f(const char* name, const glm::vec4& vector) {
	GLint vectorID = glGetUniformLocation(m_ShaderProgram, name);
	glUniform4f(vectorID, vector.x, vector.y, vector.z, vector.w);
}
void Shader::SetUniform1i(const char* name, const int& value) {
	GLint intID = glGetUniformLocation(m_ShaderProgram, name);
	glUniform1i(intID, value);
}

void Shader::CompileShaders(const char* vertexSource, const char* fragmentSource) {
	m_VertexShader = Compile(GL_VERTEX_SHADER, vertexSource);
	m_FragmentShader = Compile(GL_FRAGMENT_SHADER, fragmentSource);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, m_VertexShader);
	glAttachShader(m_ShaderProgram, m_FragmentShader);
	glLinkProgram(m_ShaderProgram);

	GLint success;
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar errorLog[1024];
		glGetProgramInfoLog(m_ShaderProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", errorLog);
	}

	glDetachShader(m_ShaderProgram, m_VertexShader);
	glDetachShader(m_ShaderProgram, m_FragmentShader);

	glDeleteShader(m_VertexShader);
	glDeleteShader(m_FragmentShader);
}

GLuint Shader::Compile(GLuint type, const char* source) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLchar infoLog[1024];
		glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", type, infoLog);
	}

	return shader;
}