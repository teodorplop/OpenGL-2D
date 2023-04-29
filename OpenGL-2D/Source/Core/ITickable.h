#pragma once

// Any object inheriting from this will have access to the Tick function, which is called each frame before rendering
class ITickable {
	friend class TickEngine;

protected:
	virtual void Tick(float deltaTime) = 0;

public:
	ITickable();
	virtual ~ITickable();
};