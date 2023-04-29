#pragma once

#include "ITickable.h"
#include <unordered_set>

// Responsible for calling the Tick function each frame on all registered ITickables
class TickEngine {
private:
	static std::unordered_set<ITickable*> s_Tickables;
public:
	static void Register(ITickable* tickable);
	static void Unregister(ITickable* tickable);

	static void Tick(float deltaTime);
};