#include "Ball.h"
#include "Brick.h"
#include "Wall.h"
#include "Player.h"



Ball::Ball(const Vector2f& Position, const float& Radius, sf::Color color)
	:Moveable(Position), radius(Radius)
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

void Ball::HandleCollision(Collidable* obj)
{
	if (dynamic_cast<Brick*>(obj) != NULL
		|| dynamic_cast<Wall*>(obj) != NULL)
	{
		float scale_x = 1;
		float scale_y = 1;

		RectangleShape* rectShape = dynamic_cast<RectangleShape*> (obj->GetShapeObject());

		if (rectShape == NULL)
		{
			return;
		}

		Vector2f dimensions = rectShape->getSize();
		Vector2f ballCenter = this->GetCenter();
		if (ballCenter.x <= rectShape->getPosition().x + dimensions.x
			&& ballCenter.x >= rectShape->getPosition().x)
		{
			scale_y = -1;
		}

		if (ballCenter.y <= rectShape->getPosition().y + dimensions.y
			&& ballCenter.y >= rectShape->getPosition().y)
		{
			scale_x = -1;
		}

		Vector2f newVelocity = GetVelocity();
		float magnitude = sqrt(pow(newVelocity.x, 2) + pow(newVelocity.y, 2));
		newVelocity.x = scale_x * newVelocity.x / magnitude;
		newVelocity.y = scale_y * newVelocity.y / magnitude;
		SetVelocity(newVelocity);
	}
	else if (dynamic_cast<Player*>(obj) != NULL
		|| dynamic_cast<Paddle*>(obj) != NULL)
	{
		Vector2f newVelocity = obj->GetCenter() - this->GetCenter();
		float magnitude = sqrt(pow(newVelocity.x, 2) + pow(newVelocity.y, 2));
		newVelocity.x = -1 * newVelocity.x / magnitude;
		newVelocity.y = -1 * newVelocity.y / magnitude;
		SetVelocity(newVelocity);
	}

}

Vector2f Ball::GetCenter()
{
	Vector2f circleCenter = shape->getPosition();
	circleCenter.x = circleCenter.x + radius;
	circleCenter.y = circleCenter.y + radius;
	return circleCenter;
}

/*void Draw(sf::RenderWindow& window) override;
void Update() override;*/


// need to make a sf::RectangleShape object in constructor and assign that to *shape
