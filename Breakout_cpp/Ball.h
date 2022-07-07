#pragma once
#include "Moveable.h"


class Ball : public Moveable {
public:
	Ball(const Vector2f& Position, const unsigned& Radius, sf::Color color);
	~Ball();
	/*void Draw(sf::RenderWindow& window) override;
	void Update() override;*/
};