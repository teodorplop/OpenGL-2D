#include "StringUtils.h"

const std::string StringUtils::TRIM = " \n\r\t\f\v";

std::string StringUtils::TrimStart(const std::string& string) {
	size_t start = string.find_first_not_of(TRIM);
	return (start == std::string::npos) ? "" : string.substr(start);
}

std::string StringUtils::TrimEnd(const std::string& string) {
	size_t end = string.find_last_not_of(TRIM);
	return (end == std::string::npos) ? "" : string.substr(0, end + 1);
}

std::string StringUtils::Trim(const std::string &string) {
	return TrimEnd(TrimStart(string));
}