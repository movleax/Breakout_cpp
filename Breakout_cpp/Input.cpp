#include "Input.h"
#include "Command.h"

Input::Input()
{

}

Input::~Input()
{

}

void Input::AddCommand(Command* command)
{
	commands.push_back(command);
}

void Input::HandleInput()
{
	std::vector<Command*>::iterator it;

	for (it = commands.begin(); it != commands.end(); it++)
	{
		if ((*it)->CheckCondition())
		{
			(*it)->Execute();
		}
	}
}
