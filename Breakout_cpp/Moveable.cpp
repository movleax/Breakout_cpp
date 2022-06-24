#include "Moveable.h"

Moveable::Moveable(const Vector2f& Position)
	:Collidable(Position)
{

}

Moveable::~Moveable()
{

}

void Moveable::SetSpeed(const float& newSpeed)
{

}

void Moveable::SetVelocity(const Vector2f& u_Direction) // take in a direction unit vector, scale by the speed, then assign to Velocity
{

}

void Moveable::UpdatePosition(const Vector2f& newPosition)
{

}

void Moveable::Update() // add the velocity to the position vector. Keep this method virtual to allow children to override if needed.
{

}
