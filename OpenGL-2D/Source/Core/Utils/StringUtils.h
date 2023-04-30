#pragma once

#include <string>

/// <summary>
/// Utils for string type
/// </summary>
class StringUtils {
private:
	static const std::string TRIM;

public:
	/// <summary>
	/// Removes whitespaces from the start of the string
	/// </summary>
	static std::string TrimStart(const std::string& string);

	/// <summary>
	/// Removes whitespaces from the end of the string
	/// </summary>
	static std::string TrimEnd(const std::string& string);

	/// <summary>
	/// Removes whitespaces from both the start and the end of the string
	/// </summary>
	static std::string Trim(const std::string& string);
};