#pragma once

#include "Collidable.h"

class Wall : public Collidable
{
	const float width;
	const float height;
public:
	Wall(const Vector2f& Position, const float& Width, const float& Height, sf::Color color);
	~Wall();
	virtual Vector2f GetCenter() override;
	//void Draw(sf::RenderWindow& window) override; // No need to override this one
};