#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& Position)
{
	this->position = Position;
	isActive = true; // will be true by default
}

GameObject::~GameObject()
{

}

Vector2f GameObject::GetPosition()
{
	return position;
}

bool GameObject::GetIsActive()
{
	return isActive;
}

void GameObject::Deactivate()
{
	isActive = false;// set isActive boolean to false
}

