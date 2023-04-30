#pragma once

#include "ITickable.h"
#include <unordered_set>

// Responsible for calling the Tick function each frame on all registered ITickables
class TickEngine {
private:
	static std::unordered_set<ITickable*> s_Tickables;
public:
	/// <summary>
	/// Registers an object for Tick function
	/// </summary>
	static void Register(ITickable* tickable);

	/// <summary>
	/// Unregisters an object for Tick function
	/// </summary>
	static void Unregister(ITickable* tickable);

	/// <summary>
	/// Tick method, called each frame
	/// </summary>
	static void Tick(float deltaTime);
};