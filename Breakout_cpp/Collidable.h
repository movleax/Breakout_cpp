#pragma once

#include "GameObject.h"

class Collidable : public GameObject
{

protected:
	sf::Shape* shape;

public:
	Collidable(const Vector2f& Position);
	virtual ~Collidable(); // need a destructor so that we can be sure the collisionObj pointer gets deleted from memory
	const Shape* GetShapeObject(); // returns the Shape pointer. NOTE I don't know if I have the constant keyword placed correctly
	virtual void Draw(sf::RenderWindow* window);
};