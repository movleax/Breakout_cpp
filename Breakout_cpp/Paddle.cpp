#include "Paddle.h"



Paddle::Paddle(const Vector2f& Position, const unsigned& Width, const unsigned& Height, sf::Color color)
	:Moveable(Position)
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
	
/*void Draw(sf::RenderWindow& window) override;
void Update() override;*/


// need to make a sf::RectangleShape object in constructor and assign that to *shape
