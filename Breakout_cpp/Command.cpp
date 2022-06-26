#include "Command.h"

Command::Command(GameObject* gameObj)
{
	this->gameObj = gameObj;
}

Command::~Command()
{
	delete gameObj;
	gameObj = 0;
}
