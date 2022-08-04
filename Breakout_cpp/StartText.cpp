#include "StartText.h"



StartText::StartText(const Vector2f& Position)
	:GameText(Position, "Press Enter To Start", "arial.ttf", true, 50, sf::Color::White)
{
	isShown = false;
}

StartText::~StartText()
{

}

void StartText::Show()
{
	isShown = true;
}

void StartText::Hide()
{
	isShown = false;
}

void StartText::Draw(sf::RenderWindow* window)
{
	if (isShown)
	{
		GameText::Draw(window);
	}
}


void StartText::Update()
{

}