#include "LivesText.h"

using namespace std;

LivesText::LivesText(const Vector2f& Position, PlayerProxy* PlayerProxy)
	:GameText(Position, "Lives: ", "arial.ttf", true, 50, sf::Color::White)
{
	playerProxy = PlayerProxy;
	text->setString("Lives: " + std::to_string(playerProxy->GetLives()));

}

LivesText::~LivesText()
{


}

void LivesText::Update()
{
	text->setString("Lives: " + std::to_string(playerProxy->GetLives()));

}
