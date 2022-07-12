#include "Wall.h"

Wall::Wall(const Vector2f& Position, const float& Width, const float& Height, sf::Color color)
	:Collidable(Position), width(Width), height(Height)
{
	shape = new RectangleShape(Vector2f(Width, Height));
	shape->setPosition(Position);
	shape->setFillColor(color);
}

Wall::~Wall()
{
	delete shape;
	shape = 0;
}

Vector2f Wall::GetCenter()
{
	Vector2f rectCenter = shape->getPosition();
	rectCenter.x = rectCenter.x + width / 2;
	rectCenter.y = rectCenter.y + height / 2;
	return rectCenter;
}

// No need to override Draw
//void Wall::Draw(sf::RenderWindow& window)
//{
//	
//}