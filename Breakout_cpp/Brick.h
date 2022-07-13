#pragma once
#include "Collidable.h"


class Brick :public Collidable
{
	const float width;
	const float height;
public:
	Brick(const Vector2f& Position, const float& Width, const float& Height, sf::Color color);
	~Brick();
	virtual Vector2f GetCenter() override;
	virtual void HandleCollision(Collidable* obj) override;

	//void Draw(sf::RenderWindow* window) override;

};

// need to make a sf::RectangleShape object in constructor and assign that to *shape

