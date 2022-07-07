#include "Moveable.h"

Moveable::Moveable(const Vector2f& Position)
	:Collidable(Position)
{
	speed = 0;
}

Moveable::~Moveable()
{

}

void Moveable::SetSpeed(const float& newSpeed)
{
	speed = newSpeed;
}

void Moveable::SetVelocity(const Vector2f& u_Direction) // take in a direction unit vector, scale by the speed, then assign to Velocity
{
	Velocity = u_Direction;
	Velocity.x *= speed;
	Velocity.y *= speed;

}

void Moveable::UpdatePosition(const Vector2f& newPosition)
{
	position = newPosition;
}

void Moveable::Update() // add the velocity to the position vector. Keep this method virtual to allow children to override if needed.
{
	UpdatePosition(position + Velocity);
	shape->setPosition(position);
}
