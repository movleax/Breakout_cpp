#include <SFML/Graphics.hpp>
#include "StopCommand.h"

StopCommand::StopCommand(Player* player)
	:Command(player)
{

}

StopCommand::~StopCommand()
{
	delete obj;
	obj = 0;
}

void StopCommand::Execute()
{
	if (CheckCondition())
	{
		((Player*)obj)->SetVelocity(Vector2f(0, 0));
	}
}
bool StopCommand::CheckCondition() // use sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
{
	return !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D));
}