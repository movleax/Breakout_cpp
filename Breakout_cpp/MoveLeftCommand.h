#pragma once

#include "Command.h"

class MoveLeftCommand : public Command
{

public:
	MoveLeftCommand(GameObject* gameObj/*const Player* player*/);
	~MoveLeftCommand();
	void Execute() override;
	bool CheckCondition() override; // use sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
};
