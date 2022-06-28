#include "Brick.h"



Brick::Brick(const Vector2f& Position, const unsigned& Width, const unsigned& Height, sf::Color color)
	:Collidable(Position)
{
	shape = new RectangleShape(Vector2f(Width, Height));
	shape->setPosition(Position);
	shape->setFillColor(color);
}

Brick::~Brick()
{
	delete shape;
	shape = 0;
}

//void Brick::Draw(sf::RenderWindow* window) 
//{
//
//}
