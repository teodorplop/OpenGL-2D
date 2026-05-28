#include "FileIO.h"

using namespace std;

string FileIO::GetFileContents(const char* filePath) {
	ifstream fileStream(filePath, ios::in);
	string content = "";
	if (fileStream.is_open()) {
		string line = "";
		while (getline(fileStream, line)) {
			content += line + "\n";
		}
		fileStream.close();
	}
	return content;
}
string FileIO::GetFileContents(const string& filePath) {
	return GetFileContents(filePath.c_str());
}

void FileIO::WriteContent(const char* filePath, const char* content) {
	ofstream fileStream(filePath, ios::out);
	if (fileStream.is_open()) {
		fileStream << content;
		fileStream.close();
	}
}
void FileIO::WriteContent(const char* filePath, const string& content) {
	WriteContent(filePath, content.c_str());
}
void FileIO::WriteContent(const string& filePath, const char* content) {
	WriteContent(filePath.c_str(), content);
}
void FileIO::WriteContent(const string& filePath, const string& content) {
	WriteContent(filePath.c_str(), content.c_str());
}

void FileIO::ClearFileContent(const char* filePath) {
	WriteContent(filePath, "");
}
void FileIO::ClearFileContent(const string& filePath) {
	WriteContent(filePath, "");
}