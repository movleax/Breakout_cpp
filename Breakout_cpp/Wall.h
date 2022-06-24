#pragma once

#include "Collidable.h"

class Wall : public Collidable
{
	// need to make a sf::RectangleShape object in constructor and assign that to *shape
public:
	Wall(const Vector2f& Position, const unsigned& Width, const unsigned& Height, sf::Color color);
	~Wall();
	//void Draw(sf::RenderWindow& window) override; // No need to override this one
};