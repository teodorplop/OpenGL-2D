#pragma once

/// <summary>
/// Helper class, used to generate random numbers
/// </summary>
struct Random {
private:
	static bool m_IsInitialized;
	static void Init();

public:
	/// <summary>
	/// Sets the seed used to generate random numbers
	/// </summary>
	static void SetSeed(int seed);

	/// <summary>
	/// Returns a value between [left, right)
	/// </summary>
	static int Range(int left, int right);

	/// <summary>
	/// Returns a value between [left, right]
	/// </summary>
	static float Range(float left, float right);

	/// <summary>
	/// Returns a value between [0, 1]
	/// </summary>
	static float Next();
};
