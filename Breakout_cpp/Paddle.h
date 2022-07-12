#pragma once
#include "Moveable.h"


class Paddle : public Moveable {
	const float width;
	const float height;
public:
	Paddle(const Vector2f& Position, const float& Width, const float& Height, sf::Color color);
	~Paddle();
	virtual Vector2f GetCenter() override;
	/*void Draw(sf::RenderWindow& window) override;
	void Update() override;*/
};

// need to make a sf::RectangleShape object in constructor and assign that to *shape
