#include "Command.h"

Command::Command(void* OBJ)
{
	this->obj = OBJ;
}

Command::~Command()
{
	delete obj;
	obj = 0;
}
