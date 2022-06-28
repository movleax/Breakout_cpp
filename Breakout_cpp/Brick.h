#pragma once
#include "Collidable.h"


class Brick :public Collidable
{
public:
	Brick(const Vector2f& Position, const unsigned& Width, const unsigned& Height, sf::Color color);
	~Brick();
	//void Draw(sf::RenderWindow* window) override;

};

// need to make a sf::RectangleShape object in constructor and assign that to *shape

