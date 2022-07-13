#pragma once
#include "Moveable.h"
#include "PlayerProxy.h"


class Ball : public Moveable {
	const float radius;
	PlayerProxy* playerProxy;
public:
	Ball(const Vector2f& Position, const float& Radius, sf::Color color, PlayerProxy* ptrPlayerProxy);
	~Ball();
	/*void Draw(sf::RenderWindow& window) override;
	void Update() override;*/
	void HandleCollision(Collidable* obj) override;
	virtual Vector2f GetCenter() override;
};