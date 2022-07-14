#include "GameText.h"
#include "GameObject.h"
#include <string.h>


using namespace std;

GameText::GameText(const Vector2f& Position, string Text, string fontFileName, bool Bold, unsigned Size, sf::Color color)
	:GameObject(Position)
{
	font.loadFromFile(fontFileName);

	text = new sf::Text(Text, font);
	text->setCharacterSize(Size);
	if (Bold) 
	{
		text->setStyle(sf::Text::Bold);
	}
	text->setFillColor(color);
	text->setPosition(Position);
}
GameText::~GameText()
{

}

Vector2f GameText::GetCenter()
{
	return GetPosition();
}

void GameText::Draw(sf::RenderWindow* window)
{
	window->draw(*text);
}
