#pragma once

/// <summary>
/// Responsible for managing time
/// </summary>
class Time {
	friend class Engine;

private:
	static float s_LastUpdate;
	static float s_LastFPSCheck;
	static int s_Frames;

	static float s_DeltaTime;
	static float s_FPS;

	static void Tick(float time);

public:
	/// <summary>
	/// Time since last frame
	/// </summary>
	static float DeltaTime();

	/// <summary>
	/// Current FPS, refreshed each second
	/// </summary>
	static float FPS();
};
