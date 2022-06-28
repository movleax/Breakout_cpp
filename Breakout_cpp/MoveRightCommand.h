#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Command.h"



class MoveRightCommand:public Command
{
public:
	MoveRightCommand(GameObject* GameObject);
	~MoveRightCommand();
	void Execute() override;
	bool CheckCondition() override; // use sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
};


