#pragma once

#include <SFML/Graphics.hpp>
#include "Command.h"
#include "MainGame.h"


class StartGameCommand : public Command
{
public:
	StartGameCommand(MainGame* mainGame);
	~StartGameCommand();
	void Execute() override;
	bool CheckCondition() override;
};


