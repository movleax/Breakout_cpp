#include <SFML/Graphics.hpp>
#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(GameObject* gameObj/*const Player* player*/)
	:Command(gameObj)
{

}

MoveLeftCommand::~MoveLeftCommand()
{
	delete gameObj;
	gameObj = 0;
}

void MoveLeftCommand::Execute()
{
	gameObj->Deactivate();
	// Player->MoveLeft()
}
bool MoveLeftCommand::CheckCondition() // use sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}