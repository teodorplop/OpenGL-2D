#include "Time.h"

float Time::s_LastUpdate = 0.0f;
float Time::s_LastFPSCheck = 0.0f;
int Time::s_Frames = 0;

float Time::s_DeltaTime = 0.0f;
float Time::s_FPS = 0.0f;

void Time::Tick(float time) {
	++s_Frames;

	s_DeltaTime = time - s_LastUpdate;
	s_LastUpdate = time;

	if (time - s_LastFPSCheck >= 1.0f) {
		s_FPS = (float)s_Frames / (time - s_LastFPSCheck);
		s_LastFPSCheck = time;
		s_Frames = 0;
	}
}
float Time::DeltaTime() {
	return s_DeltaTime;
}
float Time::FPS() {
	return s_FPS;
}