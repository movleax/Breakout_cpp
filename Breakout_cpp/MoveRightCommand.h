#pragma once
#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Player.h"


class MoveRightCommand:public Command
{
public:
	MoveRightCommand(Player* player);
	~MoveRightCommand();
	void Execute() override;
	bool CheckCondition() override; // use sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
};


