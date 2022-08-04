#include <SFML/Graphics.hpp>
#include "MoveRightCommand.h"

using namespace sf;



MoveRightCommand::MoveRightCommand(Player* player) 
	:Command(player)
{

}

MoveRightCommand::~MoveRightCommand()
{
	delete obj;
	obj = 0;
}

void MoveRightCommand::Execute()
{
	if (CheckCondition())
	{
		((Player*)obj)->SetVelocity(Vector2f(1, 0));
	}
}

bool MoveRightCommand::CheckCondition()
{
	return Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D);
}


