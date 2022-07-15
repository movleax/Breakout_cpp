#include <SFML/System/Vector2.hpp>
#include "Player.h"
#include "Wall.h"

Player::Player(const Vector2f& Position)
	:Moveable(Position)
{
	paddle = new Paddle(Position, 150, 15, sf::Color::Blue);
	lives = 3;
	score = 0;
	SetSpeed(15);
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

Shape* Player::GetShapeObject()
{
	return paddle->GetShapeObject();
}

void Player::HandleCollision(Collidable* obj)
{
	if (dynamic_cast<Wall*> (obj) != NULL)
	{
		Vector2f inverse = GetVelocity();
		float magnitude = sqrt(pow(inverse.x, 2) + pow(inverse.y, 2));
		inverse.x = -1 * inverse.x/magnitude;
		inverse.y = -1 * inverse.y/magnitude;
		SetVelocity(inverse);
		UpdatePosition(position + Velocity);
	}
}

Vector2f Player::GetCenter()
{
	return paddle->GetCenter();
}