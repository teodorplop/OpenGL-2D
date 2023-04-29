#include "Settings.h"

#include <iostream>
#include <sstream>

#include "Utils/FileIO.h"
#include "Utils/StringUtils.h"

const std::string Settings::K_SETTINGS_PATH = "Resources/Settings/Settings.txt";

const char Settings::K_SEPARATOR = '=';

Settings* Settings::s_Instance = nullptr;

Settings* Settings::GetInstance() {
	if (s_Instance == nullptr)
		s_Instance = new Settings(K_SETTINGS_PATH);

	return s_Instance;
}

Settings::Settings(const std::string& filePath) {
	std::string content = FileIO::GetFileContents(filePath);
	std::stringstream stream(content);

	std::string line;
	std::size_t separatorPosition;
	while (getline(stream, line)) {
		separatorPosition = line.find(K_SEPARATOR);
		if (separatorPosition != std::string::npos) {
			try {
				std::string key = line.substr(0, separatorPosition);
				std::string value = line.substr(separatorPosition + 1, line.size() - separatorPosition - 1);

				key = StringUtils::Trim(key);
				value = StringUtils::Trim(value);

				m_SettingsMap[key] = value;
			}
			catch (...) {

			}
		}
	}
}

int Settings::GetInt(const std::string& key, int defaultValue) {
	try {
		return stoi(GetInstance()->m_SettingsMap[key]);
	}
	catch (...) {
		return defaultValue;
	}
}

float Settings::GetFloat(const std::string& key, float defaultValue) {
	try {
		return stof(GetInstance()->m_SettingsMap[key]);
	}
	catch (...) {
		return defaultValue;
	}
}

std::string Settings::GetString(const std::string& key, std::string defaultValue) {
	try {
		return GetInstance()->m_SettingsMap[key];
	}
	catch (...) {
		return defaultValue;
	}
}
