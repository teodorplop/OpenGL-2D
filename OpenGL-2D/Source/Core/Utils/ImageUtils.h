#pragma once

#include<GL\glew.h>
#include<GL\freeglut.h>
#include<FreeImage.h>

/// <summary>
/// Utils class, can load and unload images from files.
/// </summary>
class ImageUtils {
public:
	/// <summary>
	/// Load image file, and retain resolution
	/// </summary>
	static BYTE* Load_Image(const char* filename, GLsizei* width, GLsizei* height);

	/// <summary>
	/// Load image file into a FreeImage object type
	/// </summary>
	static FIBITMAP* Load_Image(const char* filename);

	/// <summary>
	/// Unload image from memory
	/// </summary>
	static void Unload_Image(FIBITMAP* image);
};