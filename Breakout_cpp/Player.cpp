#include "Player.h"

Player::Player(const Vector2f& Position)
	:Moveable(Position)
{
	paddle = new Paddle(Position, 50, 20, sf::Color::Blue);
	lives = 3;
	score = 0;
	SetSpeed(0.5);
}

Player::~Player()
{
	delete paddle;
	paddle = 0;
}

void Player::DecrementLife()
{
	lives = lives > 0 ? lives - 1 : 0;
}

unsigned Player::GetLives()
{
	return lives;
}

unsigned Player::GetScore()
{
	return score;
}

void Player::AddToScore(unsigned points)
{
	score += points;
}

void Player::Draw(sf::RenderWindow* window)
{
	paddle->Draw(window);
}

void Player::UpdatePosition(const Vector2f& newPosition)
{
	position = newPosition;
	paddle->UpdatePosition(newPosition);
}

void Player::Update() // add the velocity to the position vector. Keep this method virtual to allow children to override if needed.
{
	UpdatePosition(position + Velocity);
}
