#include <SFML/Graphics.hpp>
#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(Player* player)
	:Command(player)
{

}

MoveLeftCommand::~MoveLeftCommand()
{
	delete gameObj;
	gameObj = 0;
}

void MoveLeftCommand::Execute()
{
	if (CheckCondition())
	{
		((Player*)gameObj)->SetVelocity(Vector2f(-1, 0));
	}
}
bool MoveLeftCommand::CheckCondition() // use sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}