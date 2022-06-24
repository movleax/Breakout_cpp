#include "Wall.h"

Wall::Wall(const Vector2f& Position, const unsigned& Width, const unsigned& Height, sf::Color color)
	:Collidable(Position)
{
	shape = new RectangleShape(Vector2f(Width, Height));
	shape->setPosition(Position);
	shape->setFillColor(color);
}

Wall::~Wall()
{
	delete shape;
}

// No need to override Draw
//void Wall::Draw(sf::RenderWindow& window)
//{
//	
//}