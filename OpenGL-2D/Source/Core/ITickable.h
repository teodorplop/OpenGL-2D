#pragma once

/// <summary>
/// Used by TickEngine. Any object inheriting this will have access to the Tick method, called each frame.
/// </summary>
class ITickable {
	friend class TickEngine;

protected:
	virtual void Tick(float deltaTime) = 0;

public:
	ITickable();
	virtual ~ITickable();
};