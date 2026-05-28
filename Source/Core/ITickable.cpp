#include "ITickable.h"
#include "TickEngine.h"

ITickable::ITickable() {
	TickEngine::Register(this);
}
ITickable::~ITickable() {
	TickEngine::Unregister(this);
}