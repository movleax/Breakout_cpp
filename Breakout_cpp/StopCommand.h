#pragma once

#include "Command.h"
#include "Player.h"

class StopCommand : public Command
{

public:
	StopCommand(Player* player);
	~StopCommand();
	void Execute() override;
	bool CheckCondition() override; // use sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
};
