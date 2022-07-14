#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class GameObject
{
	bool isActive; // will be true by default

protected:
	sf::Vector2f position;

public:
	GameObject(const sf::Vector2f& Position);
	virtual ~GameObject();
	sf::Vector2f GetPosition();
	virtual Vector2f GetCenter() = 0;
	bool GetIsActive();
	void Deactivate(); // set isActive boolean to false;
	virtual void Draw(sf::RenderWindow* window) = 0; // pure virtual
	virtual void Update();
};
