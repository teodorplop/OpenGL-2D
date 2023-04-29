#pragma once

#include<string>
#include<iostream>
#include<fstream>

class FileIO {
public:
	// Reads the file and returns its contents as a string
	static std::string GetFileContents(const char* filePath);
	static std::string GetFileContents(const std::string& filePath);

	// Clears all content from a file
	static void ClearFileContent(const char* filePath);
	static void ClearFileContent(const std::string& filePath);

	// Write something to a file
	static void WriteContent(const char* filePath, const std::string& content);
	static void WriteContent(const char* filePath, const char* content);
	static void WriteContent(const std::string& filePath, const std::string& content);
	static void WriteContent(const std::string& filePath, const char* content);
};