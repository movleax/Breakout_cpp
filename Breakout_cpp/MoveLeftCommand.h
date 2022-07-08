#pragma once

#include "Command.h"
#include "Player.h"

class MoveLeftCommand : public Command
{

public:
	MoveLeftCommand(Player* player);
	~MoveLeftCommand();
	void Execute() override;
	bool CheckCondition() override; // use sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
};
