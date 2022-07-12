#include "Paddle.h"



Paddle::Paddle(const Vector2f& Position, const float& Width, const float& Height, sf::Color color)
	:Moveable(Position), width(Width), height(Height)
{
	shape = new RectangleShape(Vector2f(Width, Height));
	shape->setPosition(Position);
	shape->setFillColor(color);
}

Paddle::~Paddle()
{
	delete shape;
	shape = 0;
}

Vector2f Paddle::GetCenter()
{
	Vector2f rectCenter = shape->getPosition();
	rectCenter.x = rectCenter.x + width / 2;
	rectCenter.y = rectCenter.y + height / 2;
	return rectCenter;
}
/*void Draw(sf::RenderWindow& window) override;
void Update() override;*/


// need to make a sf::RectangleShape object in constructor and assign that to *shape
