#include "ScoreText.h"
#include <string>

ScoreText::ScoreText(const Vector2f& Position, PlayerProxy* PlayerProxy)
	:GameText(Position, "Score: ", "arial.ttf", true, 55, sf::Color::White)
{
	playerProxy = PlayerProxy;
	text->setString("Score: " + std::to_string(playerProxy->GetScore()));
}

ScoreText::~ScoreText()
{

}

void ScoreText::Update()
{
	text->setString("Score: " + std::to_string(playerProxy->GetScore()));
}