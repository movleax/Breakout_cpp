#include "Collidable.h"

Collidable::Collidable(const Vector2f& Position)
	:GameObject(Position)
{
	
}

Collidable::~Collidable() // need a destructor so that we can be sure the collisionObj pointer gets deleted from memory
{
	if(shape != 0)
	{
		delete shape;
		shape = 0;
	}
}

Shape* Collidable::GetShapeObject() // returns the Shape pointer. NOTE I don't know if I have the constant keyword placed correctly
{
	return shape;
}

void Collidable::Draw(sf::RenderWindow* window)
{
	//if (this->GetIsActive())
	{
		window->draw(*shape);
	}
}

void Collidable::HandleCollision(Collidable* obj)
{
	int nop = 0;
}