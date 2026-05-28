#include "TickEngine.h"

std::unordered_set<ITickable*> TickEngine::s_Tickables;

void TickEngine::Register(ITickable* tickable) {
	s_Tickables.insert(tickable);
}

void TickEngine::Unregister(ITickable* tickable) {
	s_Tickables.erase(tickable);
}

void TickEngine::Tick(float deltaTime) {
	for (ITickable* tickable : s_Tickables) {
		tickable->Tick(deltaTime);
	}
}