#pragma once

#include "Collidable.h"


class Moveable : public Collidable
{
	float speed;
protected:
	Vector2f Velocity;
public:
	Moveable(const Vector2f& Position);
	virtual ~Moveable();
	virtual void SetSpeed(const float& newSpeed);
	virtual void SetVelocity(const Vector2f& u_Direction); // take in a direction unit vector, scale by the speed, then assign to Velocity
	virtual void UpdatePosition(const Vector2f& newPosition);
	virtual void Update(); // add the velocity to the position vector. Keep this method virtual to allow children to override if needed.

};
