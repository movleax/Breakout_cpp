#pragma once
#include "Moveable.h"
#include "Paddle.h"

class Player : public Moveable
{
	unsigned lives;
	Paddle* paddle;
	unsigned score;
public:
	Player(const Vector2f& Position);
	~Player();
	void DecrementLife();
	unsigned GetLives();
	unsigned GetScore();
	void AddToScore(unsigned points);
	void UpdatePosition(const Vector2f& newPosition) override;
	void Update() override;
	void Draw(sf::RenderWindow* window) override;
};


