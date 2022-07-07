#include "Ball.h"



Ball::Ball(const Vector2f& Position, const unsigned& Radius, sf::Color color)
	:Moveable(Position)
{
	shape = new CircleShape(Radius);
	shape->setPosition(Position);
	shape->setFillColor(color);
}

Ball::~Ball()
{
	delete shape;
	shape = 0;
}

/*void Draw(sf::RenderWindow& window) override;
void Update() override;*/


// need to make a sf::RectangleShape object in constructor and assign that to *shape
