#pragma once
#include "Moveable.h"


class Paddle : public Moveable {
public:
	Paddle(const Vector2f& Position, const unsigned& Width, const unsigned& Height, sf::Color color);
	~Paddle();
	/*void Draw(sf::RenderWindow& window) override;
	void Update() override;*/
};

// need to make a sf::RectangleShape object in constructor and assign that to *shape
