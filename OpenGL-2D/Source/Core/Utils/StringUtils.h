#pragma once

#include <string>

class StringUtils {
private:
	static const std::string TRIM;

public:
	static std::string TrimStart(const std::string& string);
	static std::string TrimEnd(const std::string& string);
	static std::string Trim(const std::string& string);
};