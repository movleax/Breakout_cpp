#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class GameObject
{
	sf::Vector2f position;
	bool isActive; // will be true by default

public:
	GameObject(const sf::Vector2f& Position);
	virtual ~GameObject();
	sf::Vector2f GetPosition();
	bool GetIsActive();
	void Deactivate(); // set isActive boolean to false;
	virtual void Draw(sf::RenderWindow* window) = 0; // pure virtual
	//virtual void Update() = 0; // pure virtual
};
