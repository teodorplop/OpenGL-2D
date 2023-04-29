#pragma once

#include <string>
#include <unordered_map>

class Settings {
private:
	static const std::string K_SETTINGS_PATH;
	static const char K_SEPARATOR;
	static Settings* s_Instance;

	static Settings* GetInstance();

	std::unordered_map<std::string, std::string> m_SettingsMap;

	Settings(const std::string& filePath);

public:
	static int GetInt(const std::string& key, int defaultValue = 0);
	static float GetFloat(const std::string& key, float defaultValue = 0);
	static std::string GetString(const std::string& key, std::string defaultValue = "");
};

