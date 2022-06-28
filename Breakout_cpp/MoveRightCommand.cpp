#include <SFML/Graphics.hpp>
#include "MoveRightCommand.h"

using namespace sf;



MoveRightCommand::MoveRightCommand(GameObject* GameObject) :Command(GameObject)
{

}

MoveRightCommand::~MoveRightCommand()
{
	delete gameObj;
	gameObj = 0;
}

void MoveRightCommand::Execute()
{
	gameObj->Deactivate();
}

bool MoveRightCommand::CheckCondition()
{
	return Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D);
}


