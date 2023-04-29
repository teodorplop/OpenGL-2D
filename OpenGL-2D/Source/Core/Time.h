#pragma once

// Returns informations like deltaTime (used for animations) and FPS
class Time {
	// kind of ugly, used to cap the fps at 60
	friend class Engine;

private:
	static float s_LastUpdate;
	static float s_LastFPSCheck;
	static int s_Frames;

	static float s_DeltaTime;
	static float s_FPS;

	static void Tick(float time);

public:
	static float DeltaTime();
	static float FPS();
};
