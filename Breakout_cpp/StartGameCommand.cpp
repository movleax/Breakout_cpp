#include <SFML/Graphics.hpp>
#include "StartGameCommand.h"

using namespace sf;


StartGameCommand::StartGameCommand(MainGame* mainGame)
	:Command(mainGame)
{

}

StartGameCommand::~StartGameCommand()
{
	delete obj;
	obj = 0;
}

void StartGameCommand::Execute()
{
	if (CheckCondition())
	{
		((MainGame*)obj)->StartGame();
	}
}

bool StartGameCommand::CheckCondition()
{
	return Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter);
}


