#pragma once

#include "Command.h"

class Input
{
	std::vector<Command*> commands;
public:
	Input();
	~Input();
	void AddCommand(Command* command);
	void HandleInput();
};

