#pragma once

#include <string>
#include <unordered_map>

/// <summary>
/// Responsible for reading Settings file
/// </summary>
class Settings {
private:
	static const std::string K_SETTINGS_PATH;
	static const char K_SEPARATOR;
	static Settings* s_Instance;

	static Settings* GetInstance();

	std::unordered_map<std::string, std::string> m_SettingsMap;

	Settings(const std::string& filePath);

public:
	/// <summary>
	/// Returns an integer value from settings key, or a default value if it fails to
	/// </summary>
	static int GetInt(const std::string& key, int defaultValue = 0);

	/// <summary>
	/// Returns a float value from settings key, or a default value if it fails to
	/// </summary>
	static float GetFloat(const std::string& key, float defaultValue = 0);

	/// <summary>
	/// Returns a string value from settings key, or a default value if it fails to
	/// </summary>
	static std::string GetString(const std::string& key, std::string defaultValue = "");
};

