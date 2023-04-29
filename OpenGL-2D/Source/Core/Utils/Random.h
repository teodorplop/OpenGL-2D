#pragma once

// Random class
struct Random {
private:
	static bool init;
	static void Init();

public:
	static void SetSeed(int seed);
	// Returns a value between [left, right].
	static int Range(int left, int right);
	static float Range(float left, float right);

	// Returns a value between [0, 1].
	static float Next();
};
