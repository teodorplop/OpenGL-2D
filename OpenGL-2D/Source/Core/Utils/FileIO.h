#pragma once

#include<string>
#include<iostream>
#include<fstream>

/// <summary>
/// Utils class, helps with reading and writing to files
/// </summary>
class FileIO {
public:
	/// <summary>
	/// Reads the file and returns its contents as a string
	/// </summary>
	static std::string GetFileContents(const char* filePath);
	/// <summary>
	/// Reads the file and returns its contents as a string
	/// </summary>
	static std::string GetFileContents(const std::string& filePath);

	/// <summary>
	/// Clears all content from a file
	/// </summary>
	static void ClearFileContent(const char* filePath);
	/// <summary>
	/// Clears all content from a file
	/// </summary>
	static void ClearFileContent(const std::string& filePath);

	/// <summary>
	/// Write content to a file
	/// </summary>
	static void WriteContent(const char* filePath, const std::string& content);
	/// <summary>
	/// Write content to a file
	/// </summary>
	static void WriteContent(const char* filePath, const char* content);
	/// <summary>
	/// Write content to a file
	/// </summary>
	static void WriteContent(const std::string& filePath, const std::string& content);
	/// <summary>
	/// Write content to a file
	/// </summary>
	static void WriteContent(const std::string& filePath, const char* content);
};