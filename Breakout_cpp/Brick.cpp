#include "Brick.h"



Brick::Brick(const Vector2f& Position, const float& Width, const float& Height, sf::Color color)
	:Collidable(Position), width(Width), height(Height)
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

Vector2f Brick::GetCenter()
{
	Vector2f rectCenter = shape->getPosition();
	rectCenter.x = rectCenter.x + width / 2;
	rectCenter.y = rectCenter.y + height / 2;
	return rectCenter;
}

//void Brick::Draw(sf::RenderWindow* window) 
//{
//
//}
